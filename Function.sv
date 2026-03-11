`timescale 1ns/1ps
module Function (
    input  logic        clk, //clock cycle
    input  logic        rst, 
    input  logic        start,
    input  logic [9:0]  pixelAddr, //pixel address
    input  logic [31:0] pixelData, //pixel value
    input  logic        pixelWr, 
    output logic        done, //end signal 
    output logic [3:0]  prediction //the predicted value
);
    logic [2:0] phase; //state machine states: 0, 1, 2, 3, 4, 5, 6... stores up to 8. 

    logic signed [31:0] W1 [0:100351]; //entries, there are 784 * 128 entries and init array of that size here for 32 bit ints. 
    logic signed [31:0] b1 [0:127]; // 128 biases for 2nd layer
    logic signed [31:0] W2 [0:1279]; //1280 weights
    logic signed [31:0] b2 [0:9]; // holds 10 output neurons, we pick best one
    logic signed [31:0] inputPixels [0:783]; //784 pixls
    logic signed [31:0] hidden  [0:127]; //layer 2, shrunk from 784 to 128
    logic [7:0]         neuronIdx; // neuronID, simple int size 8 bits
    logic [9:0]         weightIdx; //we store the 784 weights
    logic signed [63:0] runningSum; //dot product 
    logic signed [31:0] maxLogit; // we pick the best fit 
    logic [3:0]         predictedClass; //digit

    // suppressing unused bits warning - we only slice [47:16] intentionally
    /* verilator lint_off UNUSEDSIGNAL */  
    logic signed [63:0] temp1, temp2;
    /* verilator lint_on UNUSEDSIGNAL */

    initial begin
        $readmemh("W1.mem", W1);
        $readmemh("b1.mem", b1);
        $readmemh("W2.mem", W2);
        $readmemh("b2.mem", b2);
    end
    //reads all the files into the arrays that were made. This is just init. 


    logic [16:0] InputToHiddenLayer; // 2^17 to hold all the W1 
    logic [10:0] HiddenToOutput; //2^11 to hold all the W2

    always_comb begin
        InputToHiddenLayer = 17'(neuronIdx) * 17'd784 + 17'(weightIdx);
        HiddenToOutput = 11'(neuronIdx) * 11'd128 + 11'(weightIdx); 
        //So to "simulate" the hardware, this does it all at once, in 1 cycle. It's the first step. Just propogates the required numbers.
    end

    logic signed [31:0] inputToHiddenProduct, HiddenToOutputProduct;
    logic signed [31:0] InputToHiddenDot, HiddenToOutputDOT;
    always_comb begin
        temp1 = $signed(W1[InputToHiddenLayer]) * $signed(inputPixels[weightIdx]); //multipliction
        inputToHiddenProduct = temp1[47:16]; //bit manipulation to get the ints that are needed for input to hidden

        temp2 = $signed(W2[HiddenToOutput]) * $signed(hidden[weightIdx[6:0]]);
        HiddenToOutputProduct = temp2[47:16];  ///bit manipulation to get the ints that are needed for hidden to output
        InputToHiddenDot = runningSum[31:0] + b1[neuronIdx[6:0]]; //dot product + bias for input to hidden
        HiddenToOutputDOT = runningSum[31:0] + b2[neuronIdx[3:0]]; //dot product + bias for hidden to output
    end

//accept pixel
    always_ff @(posedge clk) begin
        if (pixelWr)
            inputPixels[pixelAddr] <= pixelData;
    end

// First phase: reset, it resets everything and starts. 
    always_ff @(posedge clk) begin
        if (rst) begin
            phase          <= 3'd0;
            done           <= 1'b0;
            prediction     <= 4'd0;
            neuronIdx      <= '0;
            weightIdx      <= '0;
            runningSum    <= '0;
        end else begin
            done <= 1'b0;
            case (phase)
                3'd0: begin
                    if (start) begin
                        phase       <= 3'd1;
                        neuronIdx   <= '0;
                        weightIdx   <= '0;
                        runningSum <= '0;
                    end
                end

                // This is phase "2", here we are doing the dot product by multiplying 
                3'd1: begin
                    runningSum <= runningSum + 64'($signed(inputToHiddenProduct));
                    if (weightIdx == 10'd783) begin //once we have gotten through 784 pixels, we stop. reset weightIdx to 0;
                        weightIdx <= '0;            //after the reset, we then switch to phase 3, replicating a state machine.
                        phase     <= 3'd2;
                    end else begin
                        weightIdx <= weightIdx + 1'b1;
                    end
                end
                3'd2: begin //this is the 3rd state. 
                    if (InputToHiddenDot > 0) //set value to 0 if negative
                        hidden[neuronIdx[6:0]] <= InputToHiddenDot; //set value to 0 if negative
                    else
                        hidden[neuronIdx[6:0]] <= 0; //set value to 0 if negative
                    runningSum  <= '0;

                    if (neuronIdx == 8'd127) begin //if we went through all the neurons from hidden layer
                        neuronIdx <= '0;          // then reset the index for neurons to 0 and start the next phase
                        phase <= 3'd3;
                    end else begin
                        neuronIdx <= neuronIdx + 1'b1;
                        phase <= 3'd1;
                    end
                end
                3'd3: begin //last computational phase
                    runningSum <= runningSum + 64'($signed(HiddenToOutputProduct)); 
                    //wrapped it to 64 bits to make addition easier, verilog was throwing errors.
                    if (weightIdx == 10'd127) begin //if we get through all the weights, then move on to output layer
                        weightIdx <= '0;
                        phase     <= 3'd4;
              end else begin
                        weightIdx <= weightIdx + 1'b1;
                    end
                end
                3'd4: begin //last layer, outputs. 
                    runningSum <= '0;
                    if (neuronIdx == 8'd0 || HiddenToOutputDOT > maxLogit) begin 
                        maxLogit       <= HiddenToOutputDOT; //highest current value for prediction 
                        predictedClass <= neuronIdx[3:0]; //store prediction
                    end
                    if (neuronIdx == 8'd9) begin //once we went through all the 10 possible digits. 
                        phase <= 3'd5;
                    end else begin
                        neuronIdx <= neuronIdx + 1'b1; //i++
                        phase     <= 3'd3;
                    end
                end
                3'd5: begin //output the digit
                    prediction <= predictedClass;
                    done       <= 1'b1;
                    phase      <= 3'd0;
                end
                default: phase <= 3'd0; //start agagin
            endcase
        end
    end
endmodule
