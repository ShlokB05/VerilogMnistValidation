// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VFunction__pch.h"

//============================================================
// Constructors

VFunction::VFunction(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VFunction__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , start{vlSymsp->TOP.start}
    , pixelWr{vlSymsp->TOP.pixelWr}
    , done{vlSymsp->TOP.done}
    , prediction{vlSymsp->TOP.prediction}
    , pixelAddr{vlSymsp->TOP.pixelAddr}
    , pixelData{vlSymsp->TOP.pixelData}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VFunction::VFunction(const char* _vcname__)
    : VFunction(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VFunction::~VFunction() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VFunction___024root___eval_debug_assertions(VFunction___024root* vlSelf);
#endif  // VL_DEBUG
void VFunction___024root___eval_static(VFunction___024root* vlSelf);
void VFunction___024root___eval_initial(VFunction___024root* vlSelf);
void VFunction___024root___eval_settle(VFunction___024root* vlSelf);
void VFunction___024root___eval(VFunction___024root* vlSelf);

void VFunction::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFunction::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VFunction___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VFunction___024root___eval_static(&(vlSymsp->TOP));
        VFunction___024root___eval_initial(&(vlSymsp->TOP));
        VFunction___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VFunction___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VFunction::eventsPending() { return false; }

uint64_t VFunction::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VFunction::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VFunction___024root___eval_final(VFunction___024root* vlSelf);

VL_ATTR_COLD void VFunction::final() {
    VFunction___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VFunction::hierName() const { return vlSymsp->name(); }
const char* VFunction::modelName() const { return "VFunction"; }
unsigned VFunction::threads() const { return 1; }
void VFunction::prepareClone() const { contextp()->prepareClone(); }
void VFunction::atClone() const {
    contextp()->threadPoolpOnClone();
}
