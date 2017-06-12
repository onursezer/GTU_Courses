library verilog;
use verilog.vl_types.all;
entity mips_core_testbench is
    port(
        result          : out    vl_logic_vector(31 downto 0);
        input_instruction: in     vl_logic_vector(31 downto 0);
        rs_content      : in     vl_logic_vector(31 downto 0);
        rt_content      : in     vl_logic_vector(31 downto 0)
    );
end mips_core_testbench;
