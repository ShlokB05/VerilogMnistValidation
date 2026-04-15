`timescale 1ns/1ps
module Function2(
    input  logic        clk, //clock cycle
    input  logic        rst, 
    input  logic        start,
    input  logic [9:0]  pixelAddr, //pixel address
    input  logic [31:0] pixelData, //pixel value
    input  logic        pixelWr, 
    output logic        done, //end signal 
    output logic [3:0]  prediction //the predicted value
);
    logic signed [31:0] InputToMiddleWeights [0:100351]; //entries, there are 784 * 128 entries and init array of that size here for 32 bit ints. 
    logic signed [31:0] MiddleBiases [0:127]; // 128 biases for middle layer
    logic signed [31:0] MiddleToOutputWeights [0:1279]; //1280 weights
    logic signed [31:0] OutputBiases [0:9]; // 10 biases for output layer
    logic signed [31:0] inputPixels [0:783]; //784 pixels
    logic signed [31:0] Middle [0:127]; // activated outputs of middle layer, read by output layer

    initial begin
        $readmemh("W1.mem", InputToMiddleWeights);
        $readmemh("b1.mem", MiddleBiases);
        $readmemh("W2.mem", MiddleToOutputWeights);
        $readmemh("b2.mem", OutputBiases);
    end
    //reads all the files into the arrays that were made. This is just init. 

//accept pixel
    always_ff @(posedge clk) begin
        if (pixelWr)
            inputPixels[pixelAddr] <= pixelData;
    end

    logic [2:0] state; //state machine states: 0, 1, 2, 3, 4, 5, 6... stores up to 8. 
    logic [6:0] neuronIndex; // neuronID, 2^7 holds 128
    logic [9:0] inputIndex; // input counter, 2^10 holds 784
    logic signed [63:0] runningSum; //dot product 
    logic signed [31:0] bestMax; // we pick the best fit 
    logic [3:0] WinningNeuron; //index of output neuron with highest score
    logic signed [31:0] L2scores [0:9];

    // suppressing unused bits warning - we only slice [47:16] intentionally
    /* verilator lint_off UNUSEDSIGNAL */
    logic signed [63:0] mulRaw;
    /* verilator lint_on UNUSEDSIGNAL */
    logic signed [31:0] mulProduct;
    logic signed [31:0] dotPlusBias;

    /* verilator lint_off BLKSEQ */
    always_ff @(posedge clk) begin

        mulRaw = 64'($signed(InputToMiddleWeights[neuronIndex * 784 + inputIndex])) * 64'($signed(inputPixels[inputIndex])); //multiplication
        mulProduct = mulRaw[47:16]; //truncate back to 32 bits Q16.16
        dotPlusBias = runningSum[31:0] + MiddleBiases[neuronIndex]; //dot product + bias for input to middle

        if (rst) begin
            state <= 3'd0;
            neuronIndex <= '0;
            inputIndex <= '0;
            runningSum <= '0;
            bestMax <= '0;
            WinningNeuron <= '0;
            done <= 1'b0;
            prediction <= '0;
        end else begin

            case (state)
                3'd0: begin
                    done <= 1'b0;
                    if (start) begin
                        neuronIndex <= '0;
                        inputIndex <= '0;
                        runningSum <= '0;
                        state <= 3'd1;
                    end
                end

                3'd1: begin
                    runningSum <= runningSum + 64'($signed(mulProduct));
                    if (inputIndex == 10'd783) begin //once we have gotten through 784 pixels
                        state <= 3'd2;
                    end else begin
                        inputIndex <= inputIndex + 10'd1; //i++
                    end
                end

                3'd2: begin
                    //set value to 0 if negative
                    if (dotPlusBias > 0)
                        Middle[neuronIndex] <= dotPlusBias;
                    else
                        Middle[neuronIndex] <= 32'sd0; //ReLU clamp
                    runningSum <= '0;
                    inputIndex <= '0;
                    if (neuronIndex == 7'd127) begin //if we went through all neurons from middle layer
                        neuronIndex <= '0;
                        state <= 3'd3;
                    end else begin
                        neuronIndex <= neuronIndex + 7'd1;
                        state <= 3'd1;
                    end
                end

                3'd3: begin
                    mulRaw = 64'($signed(MiddleToOutputWeights[neuronIndex * 128 + inputIndex])) * 64'($signed(Middle[inputIndex[6:0]]));
                    mulProduct = mulRaw[47:16];
                    runningSum <= runningSum + 64'($signed(mulProduct));
                    if (inputIndex == 10'd127) begin //if we get through all the weights
                        state <= 3'd4;
                    end else begin
                        inputIndex <= inputIndex + 10'd1;
                    end
                end

                3'd4: begin
                    dotPlusBias = runningSum[31:0] + OutputBiases[neuronIndex[3:0]]; //dot product + bias for middle to output
                    L2scores[neuronIndex[3:0]] <= dotPlusBias;
                    runningSum <= '0;
                    inputIndex <= '0;
                    if (neuronIndex == 7'd9) begin //once we went through all the 10 possible digits. 
                        neuronIndex <= '0;
                        state <= 3'd5;
                    end else begin
                        neuronIndex <= neuronIndex + 7'd1; //i++
                        state <= 3'd3;
                    end
                end

                //last layer, outputs. pick the best one
                3'd5: begin
                    bestMax = L2scores[0];
                    WinningNeuron = 4'd0;
                    for (int k = 1; k < 10; k = k + 1) begin
                        if (L2scores[k] > bestMax) begin
                            bestMax = L2scores[k];
                            WinningNeuron = k[3:0]; //highest current value for prediction
                        end
                    end
                    prediction <= WinningNeuron; //store prediction
                    done <= 1'b1;
                    state <= 3'd0;
                end

                default: state <= 3'd0;
            endcase
        end
    end
    /* verilator lint_on BLKSEQ */
endmodule
