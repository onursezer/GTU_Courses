library verilog;
use verilog.vl_types.all;
entity main_demos is
    port(
        led             : out    vl_logic_vector(9 downto 0);
        sw              : in     vl_logic_vector(9 downto 0)
    );
end main_demos;
