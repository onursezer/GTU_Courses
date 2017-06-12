library verilog;
use verilog.vl_types.all;
entity regMemory is
    port(
        readRegister1   : in     vl_logic_vector(4 downto 0);
        readRegister2   : in     vl_logic_vector(4 downto 0);
        writeRegister   : in     vl_logic_vector(4 downto 0);
        data            : in     vl_logic_vector(31 downto 0);
        ch              : in     vl_logic_vector(1 downto 0);
        rsContent       : out    vl_logic_vector(31 downto 0);
        rtContent       : out    vl_logic_vector(31 downto 0)
    );
end regMemory;
