module lfsr    (
    input   logic       clk,        // clock
    input   logic       rst,        // reset
    input   logic       en,         // enable
    output  logic [7:1] data_out    // pseudo-random output
);

    logic   [7:1]   sreg;           //shift register

    always_ff @( posedge clk, posedge rst ) begin
        if (rst)
            sreg <= 7'b1;
        else if (en)
            sreg <= {sreg[6:1], sreg[7] ^ sreg[3]};
        else
        sreg <= sreg;
    end
    assign data_out = sreg;
endmodule
