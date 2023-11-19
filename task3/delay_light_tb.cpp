#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vdelay_light.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vdelay_light * top = new Vdelay_light;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("delay_light.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T3:F1");

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  top->en = 1;
  top->N = 36;     //input value V:36 $24
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    // Display toggle neopixel
    vbdBar(top->data_out & 0xFF);
    vbdCycle(simcyc);   

    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->N = vbdValue();
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0); 
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
