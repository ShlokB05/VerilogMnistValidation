#include "verilated.h"
#include "VFunction.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>
static uint32_t read_be32(std::ifstream& f) {
uint8_t b[4];
    f.read(reinterpret_cast<char*>(b), 4);
return (b[0]<<24)|(b[1]<<16)|(b[2]<<8)|b[3];
}

int counters = 0; 
static void tick(VFunction* model) {
    model->clk = 0; model->eval();
    model->clk = 1; model->eval();
    counters++;
}
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    std::ifstream image("data/MNIST/raw/t10k-images-idx3-ubyte", std::ios::binary);
    std::ifstream label("data/MNIST/raw/t10k-labels-idx1-ubyte", std::ios::binary);
if (!image || !label) { std::cout << "Cannot open MNIST files\n"; return 1; }
for (int i = 0; i < 4; i++) read_be32(image);
for (int i = 0; i < 2; i++) read_be32(label);
    VFunction* model = new VFunction();
    model->rst = 1; model->start = 0; model->pixelWr = 0;
for (int i = 0; i < 5; i++) tick(model);
    model->rst = 0; tick(model);
const float SCALE = (float)(1 << 16);
int correct = 0, numImages = 1000;
for (int idx = 0; idx < numImages; idx++) {
uint8_t img[784], lbl;
        image.read(reinterpret_cast<char*>(img), 784);
        label.read(reinterpret_cast<char*>(&lbl), 1);
for (int i = 0; i < 784; i++) {
            model->pixelAddr = i;
            model->pixelData = (uint32_t)(int32_t)(img[i] / 255.0f * SCALE);
            model->pixelWr = 1; tick(model);
        }
        model->pixelWr = 0; tick(model);
        model->start = 1; tick(model);
        model->start = 0;

while (!model->done) tick(model);
int pred = model->prediction;
if (pred == lbl) correct++;
        std::cout << idx << ":" << (int)lbl << " pred=" << pred << "\n" ;
        tick(model);
    }
    std::cout << "\nAccuracy: " << correct << "/" << numImages << " = " << (100.0*correct/numImages) << "%\n";
    std::cout<< counters;
delete model;
return 0;
}