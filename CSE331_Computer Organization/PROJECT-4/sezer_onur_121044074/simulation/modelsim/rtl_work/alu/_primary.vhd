library verilog;
use verilog.vl_types.all;
entity alu is
    port(
        opcode          : in     vl_logic_vector(5 downto 0);
        rs_content      : in     vl_logic_vector(31 downto 0);
        rt_content      : in     vl_logic_vector(31 downto 0);
        imme32          : in     vl_logic_vector(31 downto 0);
        shamt           : in     vl_logic_vector(4 downto 0);
        funct           : in     vl_logic_vector(5 downto 0);
        result          : out    vl_logic_vector(31 downto 0)
    );
end alu;
