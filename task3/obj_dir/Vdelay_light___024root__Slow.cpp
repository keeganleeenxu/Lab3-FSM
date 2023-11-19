// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdelay_light.h for the primary calling header

#include "verilated.h"

#include "Vdelay_light__Syms.h"
#include "Vdelay_light___024root.h"

void Vdelay_light___024root___ctor_var_reset(Vdelay_light___024root* vlSelf);

Vdelay_light___024root::Vdelay_light___024root(Vdelay_light__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdelay_light___024root___ctor_var_reset(this);
}

void Vdelay_light___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vdelay_light___024root::~Vdelay_light___024root() {
}
