// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdelay_light.h"
#include "Vdelay_light__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdelay_light::Vdelay_light(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdelay_light__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , data_out{vlSymsp->TOP.data_out}
    , N{vlSymsp->TOP.N}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdelay_light::Vdelay_light(const char* _vcname__)
    : Vdelay_light(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdelay_light::~Vdelay_light() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vdelay_light___024root___eval_initial(Vdelay_light___024root* vlSelf);
void Vdelay_light___024root___eval_settle(Vdelay_light___024root* vlSelf);
void Vdelay_light___024root___eval(Vdelay_light___024root* vlSelf);
#ifdef VL_DEBUG
void Vdelay_light___024root___eval_debug_assertions(Vdelay_light___024root* vlSelf);
#endif  // VL_DEBUG
void Vdelay_light___024root___final(Vdelay_light___024root* vlSelf);

static void _eval_initial_loop(Vdelay_light__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vdelay_light___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vdelay_light___024root___eval_settle(&(vlSymsp->TOP));
        Vdelay_light___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vdelay_light::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdelay_light::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdelay_light___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vdelay_light___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vdelay_light::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vdelay_light::final() {
    Vdelay_light___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdelay_light::hierName() const { return vlSymsp->name(); }
const char* Vdelay_light::modelName() const { return "Vdelay_light"; }
unsigned Vdelay_light::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vdelay_light::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdelay_light___024root__trace_init_top(Vdelay_light___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdelay_light___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay_light___024root*>(voidSelf);
    Vdelay_light__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vdelay_light___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vdelay_light___024root__trace_register(Vdelay_light___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdelay_light::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdelay_light___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
