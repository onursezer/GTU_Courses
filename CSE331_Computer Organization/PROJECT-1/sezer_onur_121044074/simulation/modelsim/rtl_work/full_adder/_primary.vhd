library verilog;
use verilog.vl_types.all;
entity full_adder is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        c               : in     vl_logic;
        sum             : out    vl_logic;
        carry           : out    vl_logic
    );
end full_adder;
