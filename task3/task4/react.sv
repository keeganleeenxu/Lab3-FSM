module react # (
    parameter   N_WIDTH = 5,
                K_WIDTH = 7,
                D_WIDTH = 8
)(
    // interface signals
    input   logic                 clk,        // clock
    input   logic                 rst,        // reset
    input   logic [N_WIDTH-1:0]   N,          // delay for clktick.sv
    input   logic                 trigger,    // trigger for delay.sv
    output  logic [D_WIDTH-1:0]   data_out,   // signal for lights
    output  logic                 cmd_seq,    // high during the sequencing of data_out[7:0] from 8'b1 to 8'b11111111
    output  logic                 cmd_delay  // triggers the start of the delay.sv component

);
    // interconnected wires
    logic   [K_WIDTH-1:0]   K;
    logic                   delay_out;
    logic                   pulse;
    logic                   light_en;

lfsr regi(
    .clk(clk),
    .data_out(K)
);

delay del(
    .clk(clk),
    .rst(rst),
    .trigger(cmd_delay),
    .n(K),
    .time_out(delay_out)
);

clktick ticker(
    .clk(clk),
    .rst(rst),
    .en(cmd_seq),
    .N(N),
    .tick(pulse)
);

mux2 mux(
    .d0(delay_out),
    .d1(pulse),
    .sel(cmd_seq),
    .dout(light_en)
);

f1_fsm f1(
    .clk(clk),
    .rst(rst),
    .en(light_en),
    .trigger(trigger),
    .data_out(data_out),
    .cmd_delay(cmd_delay),
    .cmd_seq(cmd_seq)
);

endmodule
