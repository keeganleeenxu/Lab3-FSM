// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdelay_light.h for the primary calling header

#ifndef VERILATED_VDELAY_LIGHT___024ROOT_H_
#define VERILATED_VDELAY_LIGHT___024ROOT_H_  // guard

#include "verilated.h"

class Vdelay_light__Syms;

class Vdelay_light___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(data_out,7,0);
    CData/*0:0*/ delay_light__DOT__pulse;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_IN16(N,15,0);
    SData/*15:0*/ delay_light__DOT__ticker__DOT__count;
    IData/*31:0*/ delay_light__DOT__lights__DOT__current_state;
    IData/*31:0*/ delay_light__DOT__lights__DOT__next_state;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vdelay_light__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdelay_light___024root(Vdelay_light__Syms* symsp, const char* name);
    ~Vdelay_light___024root();
    VL_UNCOPYABLE(Vdelay_light___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
