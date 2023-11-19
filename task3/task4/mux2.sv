module mux2 (
    input   logic   d0, d1,
    input   logic   sel,
    output  logic   dout
);

assign dout = sel ? d0 : d1;
endmodule
