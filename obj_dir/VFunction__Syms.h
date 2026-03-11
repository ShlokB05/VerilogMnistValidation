// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFUNCTION__SYMS_H_
#define VERILATED_VFUNCTION__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VFunction.h"

// INCLUDE MODULE CLASSES
#include "VFunction___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VFunction__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VFunction* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VFunction___024root            TOP;

    // CONSTRUCTORS
    VFunction__Syms(VerilatedContext* contextp, const char* namep, VFunction* modelp);
    ~VFunction__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
