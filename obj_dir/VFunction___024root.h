// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VFunction.h for the primary calling header

#ifndef VERILATED_VFUNCTION___024ROOT_H_
#define VERILATED_VFUNCTION___024ROOT_H_  // guard

#include "verilated.h"


class VFunction__Syms;

class alignas(VL_CACHE_LINE_BYTES) VFunction___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(start,0,0);
    VL_IN8(pixelWr,0,0);
    VL_OUT8(done,0,0);
    VL_OUT8(prediction,3,0);
    CData/*2:0*/ Function__DOT__phase;
    CData/*7:0*/ Function__DOT__neuronIdx;
    CData/*3:0*/ Function__DOT__predictedClass;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    VL_IN16(pixelAddr,9,0);
    SData/*9:0*/ Function__DOT__weightIdx;
    VL_IN(pixelData,31,0);
    IData/*31:0*/ Function__DOT____Vlvbound_hc9e37fe2__0;
    IData/*31:0*/ Function__DOT__maxLogit;
    IData/*31:0*/ Function__DOT__inputToHiddenProduct;
    IData/*31:0*/ Function__DOT__HiddenToOutputProduct;
    IData/*31:0*/ Function__DOT__InputToHiddenDot;
    IData/*31:0*/ Function__DOT__HiddenToOutputDOT;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ Function__DOT__runningSum;
    VlUnpacked<IData/*31:0*/, 100352> Function__DOT__W1;
    VlUnpacked<IData/*31:0*/, 128> Function__DOT__b1;
    VlUnpacked<IData/*31:0*/, 1280> Function__DOT__W2;
    VlUnpacked<IData/*31:0*/, 10> Function__DOT__b2;
    VlUnpacked<IData/*31:0*/, 784> Function__DOT__inputPixels;
    VlUnpacked<IData/*31:0*/, 128> Function__DOT__hidden;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VFunction__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VFunction___024root(VFunction__Syms* symsp, const char* namep);
    ~VFunction___024root();
    VL_UNCOPYABLE(VFunction___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
