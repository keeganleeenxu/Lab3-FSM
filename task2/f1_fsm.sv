module f1_fsm   #(
    parameter WIDTH = 8
)(
    input logic clk, // clock
    input logic rst, // synchronous reset
    input logic en,  // input trigger signal
    output logic [WIDTH-1:0] data_out // output signal
);

    // Defining states
    typedef enum  {s0, s1, s2, s3, s4, s5, s6, s7, s8} states;
    states current_state, next_state;

    //state registers
    always_ff @( posedge clk, posedge rst )
        if (rst)        current_state <= s0;
        else if (en)    current_state <= next_state;

    // next state logic
    always_comb begin
        case(current_state)
        s0:  next_state = s1;
        s1:  next_state = s2;
        s2:  next_state = s3;
        s3:  next_state = s4;
        s4:  next_state = s5;
        s5:  next_state = s6;
        s6:  next_state = s7;
        s7:  next_state = s8;
        s8:  next_state = s0;
        default: next_state = s0;
        endcase
    end

    // output logic
    always_comb begin
        case(current_state)
        s0:         data_out = 8'b0;
        s1:         data_out = 8'b1;
        s2:         data_out = 8'b11;
        s3:         data_out = 8'b111;
        s4:         data_out = 8'b1111;
        s5:         data_out = 8'b11111;
        s6:         data_out = 8'b111111;
        s7:         data_out = 8'b1111111;
        s8:         data_out = 8'b11111111;
        default:    data_out = 8'b0;
        endcase
    end

endmodule
