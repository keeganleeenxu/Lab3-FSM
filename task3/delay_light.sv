module delay_light # (
    parameter   WIDTH = 8,
                N_WIDTH = 16
)(
    // interface signals
    input   logic                   clk,
    input   logic                   rst,
    input   logic                   en,
    input   logic   [N_WIDTH-1:0]   N, 
    output  logic   [WIDTH-1:0]     data_out
);

    logic pulse; // interconnection wire

clktick ticker(
    .clk(clk),
    .rst(rst),
    .en(en),
    .N(N),
    .tick(pulse)
);

f1_fsm lights(
    .clk(clk),
    .rst(rst),
    .en(pulse),
    .data_out(data_out)
);

endmodule
