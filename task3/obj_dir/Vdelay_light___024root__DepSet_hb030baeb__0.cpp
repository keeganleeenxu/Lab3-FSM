// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdelay_light.h for the primary calling header

#include "verilated.h"

#include "Vdelay_light___024root.h"

VL_INLINE_OPT void Vdelay_light___024root___sequent__TOP__0(Vdelay_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay_light___024root___sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__delay_light__DOT__ticker__DOT__count;
    // Body
    __Vdly__delay_light__DOT__ticker__DOT__count = vlSelf->delay_light__DOT__ticker__DOT__count;
    if (vlSelf->rst) {
        vlSelf->delay_light__DOT__lights__DOT__current_state = 0U;
        vlSelf->delay_light__DOT__pulse = 0U;
        __Vdly__delay_light__DOT__ticker__DOT__count 
            = vlSelf->N;
    } else {
        if (vlSelf->delay_light__DOT__pulse) {
            vlSelf->delay_light__DOT__lights__DOT__current_state 
                = vlSelf->delay_light__DOT__lights__DOT__next_state;
        }
        if (vlSelf->en) {
            if ((0U == (IData)(vlSelf->delay_light__DOT__ticker__DOT__count))) {
                vlSelf->delay_light__DOT__pulse = 1U;
                __Vdly__delay_light__DOT__ticker__DOT__count 
                    = vlSelf->N;
            } else {
                __Vdly__delay_light__DOT__ticker__DOT__count 
                    = (0xffffU & ((IData)(vlSelf->delay_light__DOT__ticker__DOT__count) 
                                  - (IData)(1U)));
                vlSelf->delay_light__DOT__pulse = 0U;
            }
        }
    }
    if (((((((((0U == vlSelf->delay_light__DOT__lights__DOT__current_state) 
               | (1U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
              | (2U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
             | (3U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
            | (4U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
           | (5U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
          | (6U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
         | (7U == vlSelf->delay_light__DOT__lights__DOT__current_state))) {
        if ((0U == vlSelf->delay_light__DOT__lights__DOT__current_state)) {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 1U;
            vlSelf->data_out = 0U;
        } else if ((1U == vlSelf->delay_light__DOT__lights__DOT__current_state)) {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 2U;
            vlSelf->data_out = 1U;
        } else if ((2U == vlSelf->delay_light__DOT__lights__DOT__current_state)) {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 3U;
            vlSelf->data_out = 3U;
        } else if ((3U == vlSelf->delay_light__DOT__lights__DOT__current_state)) {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 4U;
            vlSelf->data_out = 7U;
        } else if ((4U == vlSelf->delay_light__DOT__lights__DOT__current_state)) {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 5U;
            vlSelf->data_out = 0xfU;
        } else if ((5U == vlSelf->delay_light__DOT__lights__DOT__current_state)) {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 6U;
            vlSelf->data_out = 0x1fU;
        } else if ((6U == vlSelf->delay_light__DOT__lights__DOT__current_state)) {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 7U;
            vlSelf->data_out = 0x3fU;
        } else {
            vlSelf->delay_light__DOT__lights__DOT__next_state = 8U;
            vlSelf->data_out = 0x7fU;
        }
    } else {
        vlSelf->delay_light__DOT__lights__DOT__next_state = 0U;
        vlSelf->data_out = ((8U == vlSelf->delay_light__DOT__lights__DOT__current_state)
                             ? 0xffU : 0U);
    }
    vlSelf->delay_light__DOT__ticker__DOT__count = __Vdly__delay_light__DOT__ticker__DOT__count;
}

void Vdelay_light___024root___eval(Vdelay_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay_light___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vdelay_light___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vdelay_light___024root___eval_debug_assertions(Vdelay_light___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay_light___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
