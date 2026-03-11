// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFunction.h for the primary calling header

#include "VFunction__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VFunction___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VFunction___024root___eval_triggers__act(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_triggers__act\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VFunction___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool VFunction___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void VFunction___024root___nba_sequent__TOP__0(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___nba_sequent__TOP__0\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*63:0*/ Function__DOT__temp1;
    Function__DOT__temp1 = 0;
    QData/*63:0*/ Function__DOT__temp2;
    Function__DOT__temp2 = 0;
    IData/*16:0*/ Function__DOT__InputToHiddenLayer;
    Function__DOT__InputToHiddenLayer = 0;
    SData/*10:0*/ Function__DOT__HiddenToOutput;
    Function__DOT__HiddenToOutput = 0;
    CData/*2:0*/ __Vdly__Function__DOT__phase;
    __Vdly__Function__DOT__phase = 0;
    CData/*7:0*/ __Vdly__Function__DOT__neuronIdx;
    __Vdly__Function__DOT__neuronIdx = 0;
    SData/*9:0*/ __Vdly__Function__DOT__weightIdx;
    __Vdly__Function__DOT__weightIdx = 0;
    QData/*63:0*/ __Vdly__Function__DOT__runningSum;
    __Vdly__Function__DOT__runningSum = 0;
    IData/*31:0*/ __VdlyVal__Function__DOT__inputPixels__v0;
    __VdlyVal__Function__DOT__inputPixels__v0 = 0;
    SData/*9:0*/ __VdlyDim0__Function__DOT__inputPixels__v0;
    __VdlyDim0__Function__DOT__inputPixels__v0 = 0;
    CData/*0:0*/ __VdlySet__Function__DOT__inputPixels__v0;
    __VdlySet__Function__DOT__inputPixels__v0 = 0;
    IData/*31:0*/ __VdlyVal__Function__DOT__hidden__v0;
    __VdlyVal__Function__DOT__hidden__v0 = 0;
    CData/*6:0*/ __VdlyDim0__Function__DOT__hidden__v0;
    __VdlyDim0__Function__DOT__hidden__v0 = 0;
    CData/*0:0*/ __VdlySet__Function__DOT__hidden__v0;
    __VdlySet__Function__DOT__hidden__v0 = 0;
    // Body
    __VdlySet__Function__DOT__inputPixels__v0 = 0U;
    __Vdly__Function__DOT__phase = vlSelfRef.Function__DOT__phase;
    __Vdly__Function__DOT__runningSum = vlSelfRef.Function__DOT__runningSum;
    __VdlySet__Function__DOT__hidden__v0 = 0U;
    __Vdly__Function__DOT__neuronIdx = vlSelfRef.Function__DOT__neuronIdx;
    __Vdly__Function__DOT__weightIdx = vlSelfRef.Function__DOT__weightIdx;
    if (vlSelfRef.pixelWr) {
        vlSelfRef.Function__DOT____Vlvbound_hc9e37fe2__0 
            = vlSelfRef.pixelData;
        if ((0x030fU >= (IData)(vlSelfRef.pixelAddr))) {
            __VdlyVal__Function__DOT__inputPixels__v0 
                = vlSelfRef.Function__DOT____Vlvbound_hc9e37fe2__0;
            __VdlyDim0__Function__DOT__inputPixels__v0 
                = vlSelfRef.pixelAddr;
            __VdlySet__Function__DOT__inputPixels__v0 = 1U;
        }
    }
    if (vlSelfRef.rst) {
        __Vdly__Function__DOT__phase = 0U;
        vlSelfRef.done = 0U;
        vlSelfRef.prediction = 0U;
        __Vdly__Function__DOT__neuronIdx = 0U;
        __Vdly__Function__DOT__weightIdx = 0U;
        __Vdly__Function__DOT__runningSum = 0ULL;
    } else {
        vlSelfRef.done = 0U;
        if ((4U & (IData)(vlSelfRef.Function__DOT__phase))) {
            if ((2U & (IData)(vlSelfRef.Function__DOT__phase))) {
                __Vdly__Function__DOT__phase = 0U;
            } else if ((1U & (IData)(vlSelfRef.Function__DOT__phase))) {
                vlSelfRef.prediction = vlSelfRef.Function__DOT__predictedClass;
                vlSelfRef.done = 1U;
                __Vdly__Function__DOT__phase = 0U;
            } else {
                __Vdly__Function__DOT__runningSum = 0ULL;
                if (((0U == (IData)(vlSelfRef.Function__DOT__neuronIdx)) 
                     | VL_GTS_III(32, vlSelfRef.Function__DOT__HiddenToOutputDOT, vlSelfRef.Function__DOT__maxLogit))) {
                    vlSelfRef.Function__DOT__maxLogit 
                        = vlSelfRef.Function__DOT__HiddenToOutputDOT;
                    vlSelfRef.Function__DOT__predictedClass 
                        = (0x0000000fU & (IData)(vlSelfRef.Function__DOT__neuronIdx));
                }
                if ((9U == (IData)(vlSelfRef.Function__DOT__neuronIdx))) {
                    __Vdly__Function__DOT__phase = 5U;
                } else {
                    __Vdly__Function__DOT__neuronIdx 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.Function__DOT__neuronIdx)));
                    __Vdly__Function__DOT__phase = 3U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.Function__DOT__phase))) {
            if ((1U & (IData)(vlSelfRef.Function__DOT__phase))) {
                __Vdly__Function__DOT__runningSum = 
                    (vlSelfRef.Function__DOT__runningSum 
                     + VL_EXTENDS_QI(64,32, vlSelfRef.Function__DOT__HiddenToOutputProduct));
                if ((0x007fU == (IData)(vlSelfRef.Function__DOT__weightIdx))) {
                    __Vdly__Function__DOT__weightIdx = 0U;
                    __Vdly__Function__DOT__phase = 4U;
                } else {
                    __Vdly__Function__DOT__weightIdx 
                        = (0x000003ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.Function__DOT__weightIdx)));
                }
            } else {
                __VdlyVal__Function__DOT__hidden__v0 
                    = (VL_LTS_III(32, 0U, vlSelfRef.Function__DOT__InputToHiddenDot)
                        ? vlSelfRef.Function__DOT__InputToHiddenDot
                        : 0U);
                __VdlyDim0__Function__DOT__hidden__v0 
                    = (0x0000007fU & (IData)(vlSelfRef.Function__DOT__neuronIdx));
                __VdlySet__Function__DOT__hidden__v0 = 1U;
                __Vdly__Function__DOT__runningSum = 0ULL;
                if ((0x7fU == (IData)(vlSelfRef.Function__DOT__neuronIdx))) {
                    __Vdly__Function__DOT__neuronIdx = 0U;
                    __Vdly__Function__DOT__phase = 3U;
                } else {
                    __Vdly__Function__DOT__neuronIdx 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.Function__DOT__neuronIdx)));
                    __Vdly__Function__DOT__phase = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.Function__DOT__phase))) {
            __Vdly__Function__DOT__runningSum = (vlSelfRef.Function__DOT__runningSum 
                                                 + 
                                                 VL_EXTENDS_QI(64,32, vlSelfRef.Function__DOT__inputToHiddenProduct));
            if ((0x030fU == (IData)(vlSelfRef.Function__DOT__weightIdx))) {
                __Vdly__Function__DOT__weightIdx = 0U;
                __Vdly__Function__DOT__phase = 2U;
            } else {
                __Vdly__Function__DOT__weightIdx = 
                    (0x000003ffU & ((IData)(1U) + (IData)(vlSelfRef.Function__DOT__weightIdx)));
            }
        } else if (vlSelfRef.start) {
            __Vdly__Function__DOT__phase = 1U;
            __Vdly__Function__DOT__neuronIdx = 0U;
            __Vdly__Function__DOT__weightIdx = 0U;
            __Vdly__Function__DOT__runningSum = 0ULL;
        }
    }
    if (__VdlySet__Function__DOT__inputPixels__v0) {
        vlSelfRef.Function__DOT__inputPixels[__VdlyDim0__Function__DOT__inputPixels__v0] 
            = __VdlyVal__Function__DOT__inputPixels__v0;
    }
    vlSelfRef.Function__DOT__phase = __Vdly__Function__DOT__phase;
    vlSelfRef.Function__DOT__runningSum = __Vdly__Function__DOT__runningSum;
    if (__VdlySet__Function__DOT__hidden__v0) {
        vlSelfRef.Function__DOT__hidden[__VdlyDim0__Function__DOT__hidden__v0] 
            = __VdlyVal__Function__DOT__hidden__v0;
    }
    vlSelfRef.Function__DOT__neuronIdx = __Vdly__Function__DOT__neuronIdx;
    vlSelfRef.Function__DOT__weightIdx = __Vdly__Function__DOT__weightIdx;
    vlSelfRef.Function__DOT__InputToHiddenDot = ((IData)(vlSelfRef.Function__DOT__runningSum) 
                                                 + 
                                                 vlSelfRef.Function__DOT__b1
                                                 [(0x0000007fU 
                                                   & (IData)(vlSelfRef.Function__DOT__neuronIdx))]);
    vlSelfRef.Function__DOT__HiddenToOutputDOT = ((IData)(vlSelfRef.Function__DOT__runningSum) 
                                                  + 
                                                  ((9U 
                                                    >= 
                                                    (0x0000000fU 
                                                     & (IData)(vlSelfRef.Function__DOT__neuronIdx)))
                                                    ? 
                                                   vlSelfRef.Function__DOT__b2
                                                   [
                                                   (0x0000000fU 
                                                    & (IData)(vlSelfRef.Function__DOT__neuronIdx))]
                                                    : 0U));
    Function__DOT__InputToHiddenLayer = (0x0001ffffU 
                                         & (((IData)(0x00000310U) 
                                             * (IData)(vlSelfRef.Function__DOT__neuronIdx)) 
                                            + (IData)(vlSelfRef.Function__DOT__weightIdx)));
    Function__DOT__HiddenToOutput = (0x000007ffU & 
                                     (VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.Function__DOT__neuronIdx), 7U) 
                                      + (IData)(vlSelfRef.Function__DOT__weightIdx)));
    Function__DOT__temp1 = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                                         ((0x000187ffU 
                                                           >= Function__DOT__InputToHiddenLayer)
                                                           ? 
                                                          vlSelfRef.Function__DOT__W1
                                                          [Function__DOT__InputToHiddenLayer]
                                                           : 0U)), 
                                       VL_EXTENDS_QI(64,32, 
                                                     ((0x030fU 
                                                       >= (IData)(vlSelfRef.Function__DOT__weightIdx))
                                                       ? 
                                                      vlSelfRef.Function__DOT__inputPixels
                                                      [vlSelfRef.Function__DOT__weightIdx]
                                                       : 0U)));
    vlSelfRef.Function__DOT__inputToHiddenProduct = (IData)(
                                                            (Function__DOT__temp1 
                                                             >> 0x10U));
    Function__DOT__temp2 = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                                         ((0x04ffU 
                                                           >= (IData)(Function__DOT__HiddenToOutput))
                                                           ? 
                                                          vlSelfRef.Function__DOT__W2
                                                          [Function__DOT__HiddenToOutput]
                                                           : 0U)), 
                                       VL_EXTENDS_QI(64,32, 
                                                     vlSelfRef.Function__DOT__hidden
                                                     [
                                                     (0x0000007fU 
                                                      & (IData)(vlSelfRef.Function__DOT__weightIdx))]));
    vlSelfRef.Function__DOT__HiddenToOutputProduct 
        = (IData)((Function__DOT__temp2 >> 0x10U));
}

void VFunction___024root___eval_nba(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_nba\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VFunction___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VFunction___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VFunction___024root___eval_phase__act(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_phase__act\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VFunction___024root___eval_triggers__act(vlSelf);
    VFunction___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VFunction___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VFunction___024root___eval_phase__nba(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_phase__nba\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VFunction___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VFunction___024root___eval_nba(vlSelf);
        VFunction___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VFunction___024root___eval(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VFunction___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("Function.sv", 2, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VFunction___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("Function.sv", 2, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (VFunction___024root___eval_phase__act(vlSelf));
    } while (VFunction___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void VFunction___024root___eval_debug_assertions(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_debug_assertions\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");
    }
    if (VL_UNLIKELY(((vlSelfRef.pixelAddr & 0xfc00U)))) {
        Verilated::overWidthError("pixelAddr");
    }
    if (VL_UNLIKELY(((vlSelfRef.pixelWr & 0xfeU)))) {
        Verilated::overWidthError("pixelWr");
    }
}
#endif  // VL_DEBUG
