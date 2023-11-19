module lfsr    (
    input   logic       clk,        // clock
    output  logic [7:1] data_out    // pseudo-random output
);

    logic   [7:1]   sreg;           //shift register

    always_ff @( posedge clk ) begin
        sreg <= {sreg[6:1], sreg[7] ^ sreg[3]};
    end
    assign data_out = sreg;
endmodule
