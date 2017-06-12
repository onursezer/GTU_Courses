library verilog;
use verilog.vl_types.all;
entity mux_base is
    port(
        f               : out    vl_logic;
        s0              : in     vl_logic;
        s1              : in     vl_logic;
        b0              : in     vl_logic;
        b1              : in     vl_logic;
        b2              : in     vl_logic;
        b3              : in     vl_logic
    );
end mux_base;
