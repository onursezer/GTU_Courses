library verilog;
use verilog.vl_types.all;
entity mux_full is
    port(
        fout            : out    vl_logic_vector(3 downto 0);
        selector        : in     vl_logic_vector(1 downto 0);
        adder           : in     vl_logic_vector(3 downto 0);
        subtractor      : in     vl_logic_vector(3 downto 0);
        andop           : in     vl_logic_vector(3 downto 0);
        xorop           : in     vl_logic_vector(3 downto 0)
    );
end mux_full;
