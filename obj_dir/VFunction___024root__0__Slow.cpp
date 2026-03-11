// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFunction.h for the primary calling header

#include "VFunction__pch.h"

VL_ATTR_COLD void VFunction___024root___eval_static(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_static\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VFunction___024root___eval_initial(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_initial\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 100352, 0, "W1.mem"s,  &(vlSelfRef.Function__DOT__W1)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 128, 0, "b1.mem"s,  &(vlSelfRef.Function__DOT__b1)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 1280, 0, "W2.mem"s,  &(vlSelfRef.Function__DOT__W2)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 10, 0, "b2.mem"s,  &(vlSelfRef.Function__DOT__b2)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void VFunction___024root___eval_initial__TOP(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_initial__TOP\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 100352, 0, "W1.mem"s,  &(vlSelfRef.Function__DOT__W1)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 128, 0, "b1.mem"s,  &(vlSelfRef.Function__DOT__b1)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 1280, 0, "W2.mem"s,  &(vlSelfRef.Function__DOT__W2)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 10, 0, "b2.mem"s,  &(vlSelfRef.Function__DOT__b2)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void VFunction___024root___eval_final(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_final\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VFunction___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VFunction___024root___eval_phase__stl(VFunction___024root* vlSelf);

VL_ATTR_COLD void VFunction___024root___eval_settle(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_settle\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VFunction___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("Function.sv", 2, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (VFunction___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void VFunction___024root___eval_triggers__stl(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_triggers__stl\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VFunction___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool VFunction___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VFunction___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VFunction___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VFunction___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void VFunction___024root___stl_sequent__TOP__0(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___stl_sequent__TOP__0\n"); );
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
    // Body
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

VL_ATTR_COLD void VFunction___024root___eval_stl(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_stl\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*63:0*/ __Vinline__stl_sequent__TOP__0_Function__DOT__temp1;
    __Vinline__stl_sequent__TOP__0_Function__DOT__temp1 = 0;
    QData/*63:0*/ __Vinline__stl_sequent__TOP__0_Function__DOT__temp2;
    __Vinline__stl_sequent__TOP__0_Function__DOT__temp2 = 0;
    IData/*16:0*/ __Vinline__stl_sequent__TOP__0_Function__DOT__InputToHiddenLayer;
    __Vinline__stl_sequent__TOP__0_Function__DOT__InputToHiddenLayer = 0;
    SData/*10:0*/ __Vinline__stl_sequent__TOP__0_Function__DOT__HiddenToOutput;
    __Vinline__stl_sequent__TOP__0_Function__DOT__HiddenToOutput = 0;
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        vlSelfRef.Function__DOT__InputToHiddenDot = 
            ((IData)(vlSelfRef.Function__DOT__runningSum) 
             + vlSelfRef.Function__DOT__b1[(0x0000007fU 
                                            & (IData)(vlSelfRef.Function__DOT__neuronIdx))]);
        vlSelfRef.Function__DOT__HiddenToOutputDOT 
            = ((IData)(vlSelfRef.Function__DOT__runningSum) 
               + ((9U >= (0x0000000fU & (IData)(vlSelfRef.Function__DOT__neuronIdx)))
                   ? vlSelfRef.Function__DOT__b2[(0x0000000fU 
                                                  & (IData)(vlSelfRef.Function__DOT__neuronIdx))]
                   : 0U));
        __Vinline__stl_sequent__TOP__0_Function__DOT__InputToHiddenLayer 
            = (0x0001ffffU & (((IData)(0x00000310U) 
                               * (IData)(vlSelfRef.Function__DOT__neuronIdx)) 
                              + (IData)(vlSelfRef.Function__DOT__weightIdx)));
        __Vinline__stl_sequent__TOP__0_Function__DOT__HiddenToOutput 
            = (0x000007ffU & (VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.Function__DOT__neuronIdx), 7U) 
                              + (IData)(vlSelfRef.Function__DOT__weightIdx)));
        __Vinline__stl_sequent__TOP__0_Function__DOT__temp1 
            = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                            ((0x000187ffU 
                                              >= __Vinline__stl_sequent__TOP__0_Function__DOT__InputToHiddenLayer)
                                              ? vlSelfRef.Function__DOT__W1
                                             [__Vinline__stl_sequent__TOP__0_Function__DOT__InputToHiddenLayer]
                                              : 0U)), 
                          VL_EXTENDS_QI(64,32, ((0x030fU 
                                                 >= (IData)(vlSelfRef.Function__DOT__weightIdx))
                                                 ? 
                                                vlSelfRef.Function__DOT__inputPixels
                                                [vlSelfRef.Function__DOT__weightIdx]
                                                 : 0U)));
        vlSelfRef.Function__DOT__inputToHiddenProduct 
            = (IData)((__Vinline__stl_sequent__TOP__0_Function__DOT__temp1 
                       >> 0x10U));
        __Vinline__stl_sequent__TOP__0_Function__DOT__temp2 
            = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                            ((0x04ffU 
                                              >= __Vinline__stl_sequent__TOP__0_Function__DOT__HiddenToOutput)
                                              ? vlSelfRef.Function__DOT__W2
                                             [__Vinline__stl_sequent__TOP__0_Function__DOT__HiddenToOutput]
                                              : 0U)), 
                          VL_EXTENDS_QI(64,32, vlSelfRef.Function__DOT__hidden
                                        [(0x0000007fU 
                                          & (IData)(vlSelfRef.Function__DOT__weightIdx))]));
        vlSelfRef.Function__DOT__HiddenToOutputProduct 
            = (IData)((__Vinline__stl_sequent__TOP__0_Function__DOT__temp2 
                       >> 0x10U));
    }
}

VL_ATTR_COLD bool VFunction___024root___eval_phase__stl(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___eval_phase__stl\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VFunction___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = VFunction___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VFunction___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VFunction___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VFunction___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VFunction___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VFunction___024root___ctor_var_reset(VFunction___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFunction___024root___ctor_var_reset\n"); );
    VFunction__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->pixelAddr = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 2919238307018627515ull);
    vlSelf->pixelData = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7905350927627622786ull);
    vlSelf->pixelWr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13242907264545141831ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->prediction = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8174343725260504883ull);
    vlSelf->Function__DOT____Vlvbound_hc9e37fe2__0 = 0;
    vlSelf->Function__DOT__phase = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18022890987962229498ull);
    for (int __Vi0 = 0; __Vi0 < 100352; ++__Vi0) {
        vlSelf->Function__DOT__W1[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14327118666762719408ull);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->Function__DOT__b1[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5444007203075351855ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1280; ++__Vi0) {
        vlSelf->Function__DOT__W2[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3387682399941933897ull);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->Function__DOT__b2[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16855450326050657677ull);
    }
    for (int __Vi0 = 0; __Vi0 < 784; ++__Vi0) {
        vlSelf->Function__DOT__inputPixels[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15006122408195240519ull);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->Function__DOT__hidden[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6477119394174559736ull);
    }
    vlSelf->Function__DOT__neuronIdx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14666681835942063631ull);
    vlSelf->Function__DOT__weightIdx = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9623899115113724293ull);
    vlSelf->Function__DOT__runningSum = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15909939071069009098ull);
    vlSelf->Function__DOT__maxLogit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 178422152556256061ull);
    vlSelf->Function__DOT__predictedClass = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11613702699983020566ull);
    vlSelf->Function__DOT__inputToHiddenProduct = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10566918639469866284ull);
    vlSelf->Function__DOT__HiddenToOutputProduct = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14383607452287395983ull);
    vlSelf->Function__DOT__InputToHiddenDot = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9736736271232811829ull);
    vlSelf->Function__DOT__HiddenToOutputDOT = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 471586076421327771ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
