library verilog;
use verilog.vl_types.all;
entity Prac5_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(2 downto 0);
        x0              : in     vl_logic;
        x1              : in     vl_logic;
        x2              : in     vl_logic;
        x3              : in     vl_logic;
        x4              : in     vl_logic;
        x5              : in     vl_logic;
        x6              : in     vl_logic;
        x7              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end Prac5_vlg_sample_tst;
