// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdelay_light__Syms.h"


void Vdelay_light___024root__trace_chg_sub_0(Vdelay_light___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdelay_light___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay_light___024root__trace_chg_top_0\n"); );
    // Init
    Vdelay_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay_light___024root*>(voidSelf);
    Vdelay_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdelay_light___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdelay_light___024root__trace_chg_sub_0(Vdelay_light___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay_light___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->delay_light__DOT__pulse));
        bufp->chgIData(oldp+1,(vlSelf->delay_light__DOT__lights__DOT__current_state),32);
        bufp->chgIData(oldp+2,((((((((((0U == vlSelf->delay_light__DOT__lights__DOT__current_state) 
                                       | (1U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
                                      | (2U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
                                     | (3U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
                                    | (4U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
                                   | (5U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
                                  | (6U == vlSelf->delay_light__DOT__lights__DOT__current_state)) 
                                 | (7U == vlSelf->delay_light__DOT__lights__DOT__current_state))
                                 ? ((0U == vlSelf->delay_light__DOT__lights__DOT__current_state)
                                     ? 1U : ((1U == vlSelf->delay_light__DOT__lights__DOT__current_state)
                                              ? 2U : 
                                             ((2U == vlSelf->delay_light__DOT__lights__DOT__current_state)
                                               ? 3U
                                               : ((3U 
                                                   == vlSelf->delay_light__DOT__lights__DOT__current_state)
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    == vlSelf->delay_light__DOT__lights__DOT__current_state)
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == vlSelf->delay_light__DOT__lights__DOT__current_state)
                                                     ? 6U
                                                     : 
                                                    ((6U 
                                                      == vlSelf->delay_light__DOT__lights__DOT__current_state)
                                                      ? 7U
                                                      : 8U)))))))
                                 : 0U)),32);
        bufp->chgSData(oldp+3,(vlSelf->delay_light__DOT__ticker__DOT__count),16);
    }
    bufp->chgBit(oldp+4,(vlSelf->clk));
    bufp->chgBit(oldp+5,(vlSelf->rst));
    bufp->chgBit(oldp+6,(vlSelf->en));
    bufp->chgSData(oldp+7,(vlSelf->N),16);
    bufp->chgCData(oldp+8,(vlSelf->data_out),8);
}

void Vdelay_light___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay_light___024root__trace_cleanup\n"); );
    // Init
    Vdelay_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay_light___024root*>(voidSelf);
    Vdelay_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
