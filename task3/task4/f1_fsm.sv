module f1_fsm   #(
    parameter WIDTH = 8
)(
    input   logic                clk,       // clock
    input   logic                rst,       // synchronous reset
    input   logic                en,        // input trigger signal
    input   logic                trigger,   // input to start the sequence
    output  logic [WIDTH-1:0]    data_out,  // output signal
    output  logic                cmd_seq,   // high during the sequencing of data_out[7:0] from 8'b1 to 8'b11111111
    output  logic                cmd_delay // triggers the start of the delay.sv component
);

    // Defining states
    typedef enum  {s0, s1, s2, s3, s4, s5, s6, s7, s8} states;
    states current_state, next_state;

    // trigger logic
    logic triggered;

    always_ff @(posedge trigger) begin
        triggered <= 1'b1;
    end
    
    //state registers
    always_ff @( posedge clk, posedge rst ) begin
        if (rst)        current_state <= s0;
        else if (en & triggered)    current_state <= next_state;
    end

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
        s1: begin   data_out = 8'b1;        cmd_seq = 1'b1;                     end
        s2: begin   data_out = 8'b11;       cmd_seq = 1'b1;                     end
        s3: begin   data_out = 8'b111;      cmd_seq = 1'b1;                     end
        s4: begin   data_out = 8'b1111;     cmd_seq = 1'b1;                     end
        s5: begin   data_out = 8'b11111;    cmd_seq = 1'b1;                     end
        s6: begin   data_out = 8'b111111;   cmd_seq = 1'b1;                     end
        s7: begin   data_out = 8'b1111111;  cmd_seq = 1'b1;                     end
        s8: begin   data_out = 8'b11111111; cmd_seq = 1'b1; cmd_delay = 1'b1;   end
        default:    data_out = 8'b0;
        endcase
    end

endmodule
