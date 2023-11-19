// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdelay_light__Syms.h"
#include "Vdelay_light.h"
#include "Vdelay_light___024root.h"

// FUNCTIONS
Vdelay_light__Syms::~Vdelay_light__Syms()
{
}

Vdelay_light__Syms::Vdelay_light__Syms(VerilatedContext* contextp, const char* namep, Vdelay_light* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
