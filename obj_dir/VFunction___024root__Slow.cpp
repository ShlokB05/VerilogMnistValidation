// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFunction.h for the primary calling header

#include "VFunction__pch.h"

void VFunction___024root___ctor_var_reset(VFunction___024root* vlSelf);

VFunction___024root::VFunction___024root(VFunction__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VFunction___024root___ctor_var_reset(this);
}

void VFunction___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VFunction___024root::~VFunction___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
