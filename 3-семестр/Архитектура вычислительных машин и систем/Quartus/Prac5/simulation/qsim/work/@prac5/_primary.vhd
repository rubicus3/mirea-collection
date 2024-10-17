library verilog;
use verilog.vl_types.all;
entity Prac5 is
    port(
        y               : out    vl_logic;
        x7              : in     vl_logic;
        x6              : in     vl_logic;
        x5              : in     vl_logic;
        x4              : in     vl_logic;
        x3              : in     vl_logic;
        x2              : in     vl_logic;
        x1              : in     vl_logic;
        x0              : in     vl_logic;
        a               : in     vl_logic_vector(2 downto 0)
    );
end Prac5;
