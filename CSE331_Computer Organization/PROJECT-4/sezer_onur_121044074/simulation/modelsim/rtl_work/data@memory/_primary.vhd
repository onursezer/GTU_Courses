library verilog;
use verilog.vl_types.all;
entity dataMemory is
    generic(
        size            : integer := 11
    );
    port(
        aluOut          : in     vl_logic_vector(31 downto 0);
        ch              : in     vl_logic_vector(1 downto 0);
        rtContent       : in     vl_logic_vector(31 downto 0);
        dataOut         : out    vl_logic_vector(31 downto 0)
    );
    attribute mti_svvh_generic_type : integer;
    attribute mti_svvh_generic_type of size : constant is 1;
end dataMemory;
