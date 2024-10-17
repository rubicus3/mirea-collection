-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Web Edition"

-- DATE "10/12/2024 04:53:00"

-- 
-- Device: Altera EP4CGX15BF14C6 Package FBGA169
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIV;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIV.CYCLONEIV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Prac6 IS
    PORT (
	q : OUT std_logic_vector(3 DOWNTO 0);
	clock : IN std_logic;
	b : IN std_logic;
	a : IN std_logic
	);
END Prac6;

-- Design Ports Information
-- q[3]	=>  Location: PIN_M4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- q[2]	=>  Location: PIN_N6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- q[1]	=>  Location: PIN_M6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- q[0]	=>  Location: PIN_N4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clock	=>  Location: PIN_J7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a	=>  Location: PIN_L5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Prac6 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_q : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_clock : std_logic;
SIGNAL ww_b : std_logic;
SIGNAL ww_a : std_logic;
SIGNAL \clock~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \q[3]~output_o\ : std_logic;
SIGNAL \q[2]~output_o\ : std_logic;
SIGNAL \q[1]~output_o\ : std_logic;
SIGNAL \q[0]~output_o\ : std_logic;
SIGNAL \clock~input_o\ : std_logic;
SIGNAL \clock~inputclkctrl_outclk\ : std_logic;
SIGNAL \inst18~0_combout\ : std_logic;
SIGNAL \b~input_o\ : std_logic;
SIGNAL \inst~0_combout\ : std_logic;
SIGNAL \inst18~1_combout\ : std_logic;
SIGNAL \a~input_o\ : std_logic;
SIGNAL \inst~3_combout\ : std_logic;
SIGNAL \inst~4_combout\ : std_logic;
SIGNAL \inst~2_combout\ : std_logic;
SIGNAL \inst19~0_combout\ : std_logic;
SIGNAL \inst18~2_combout\ : std_logic;
SIGNAL \inst25~q\ : std_logic;
SIGNAL \inst~5_combout\ : std_logic;
SIGNAL \inst20~0_combout\ : std_logic;
SIGNAL \inst~6_combout\ : std_logic;
SIGNAL \inst20~1_combout\ : std_logic;
SIGNAL \inst20~2_combout\ : std_logic;
SIGNAL \inst29~q\ : std_logic;
SIGNAL \inst19~1_combout\ : std_logic;
SIGNAL \inst~1_combout\ : std_logic;
SIGNAL \inst19~2_combout\ : std_logic;
SIGNAL \inst19~3_combout\ : std_logic;
SIGNAL \inst27~q\ : std_logic;
SIGNAL \inst17~combout\ : std_logic;
SIGNAL \inst23~q\ : std_logic;

BEGIN

q <= ww_q;
ww_clock <= clock;
ww_b <= b;
ww_a <= a;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\clock~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clock~input_o\);

-- Location: IOOBUF_X8_Y0_N2
\q[3]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst23~q\,
	devoe => ww_devoe,
	o => \q[3]~output_o\);

-- Location: IOOBUF_X12_Y0_N2
\q[2]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst25~q\,
	devoe => ww_devoe,
	o => \q[2]~output_o\);

-- Location: IOOBUF_X12_Y0_N9
\q[1]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst27~q\,
	devoe => ww_devoe,
	o => \q[1]~output_o\);

-- Location: IOOBUF_X10_Y0_N9
\q[0]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst29~q\,
	devoe => ww_devoe,
	o => \q[0]~output_o\);

-- Location: IOIBUF_X16_Y0_N15
\clock~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clock,
	o => \clock~input_o\);

-- Location: CLKCTRL_G17
\clock~inputclkctrl\ : cycloneiv_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \clock~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \clock~inputclkctrl_outclk\);

-- Location: LCCOMB_X14_Y1_N22
\inst18~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst18~0_combout\ = (\inst27~q\ & (!\inst25~q\ & !\inst29~q\)) # (!\inst27~q\ & (\inst25~q\ & \inst29~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000000001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datac => \inst25~q\,
	datad => \inst29~q\,
	combout => \inst18~0_combout\);

-- Location: IOIBUF_X14_Y0_N1
\b~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b,
	o => \b~input_o\);

-- Location: LCCOMB_X14_Y1_N2
\inst~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst~0_combout\ = (!\inst23~q\ & (\inst25~q\ & (\inst29~q\ & \inst27~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst23~q\,
	datab => \inst25~q\,
	datac => \inst29~q\,
	datad => \inst27~q\,
	combout => \inst~0_combout\);

-- Location: LCCOMB_X14_Y1_N26
\inst18~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst18~1_combout\ = (\inst~5_combout\) # ((\b~input_o\ & \inst~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b~input_o\,
	datac => \inst~5_combout\,
	datad => \inst~0_combout\,
	combout => \inst18~1_combout\);

-- Location: IOIBUF_X14_Y0_N8
\a~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a,
	o => \a~input_o\);

-- Location: LCCOMB_X14_Y1_N0
\inst~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst~3_combout\ = (!\inst27~q\ & (\inst25~q\ & (\inst29~q\ & !\inst23~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst25~q\,
	datac => \inst29~q\,
	datad => \inst23~q\,
	combout => \inst~3_combout\);

-- Location: LCCOMB_X14_Y1_N14
\inst~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst~4_combout\ = (\inst27~q\ & (\inst25~q\ & (!\inst29~q\ & !\inst23~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst25~q\,
	datac => \inst29~q\,
	datad => \inst23~q\,
	combout => \inst~4_combout\);

-- Location: LCCOMB_X14_Y1_N10
\inst~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst~2_combout\ = (!\inst27~q\ & (\inst25~q\ & (!\inst29~q\ & !\inst23~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst25~q\,
	datac => \inst29~q\,
	datad => \inst23~q\,
	combout => \inst~2_combout\);

-- Location: LCCOMB_X14_Y1_N12
\inst19~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst19~0_combout\ = (!\inst~3_combout\ & (!\inst~4_combout\ & ((!\inst~2_combout\) # (!\a~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a~input_o\,
	datab => \inst~3_combout\,
	datac => \inst~4_combout\,
	datad => \inst~2_combout\,
	combout => \inst19~0_combout\);

-- Location: LCCOMB_X14_Y1_N28
\inst18~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst18~2_combout\ = (\inst18~1_combout\) # (((\inst18~0_combout\ & \inst23~q\)) # (!\inst19~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111100011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst18~0_combout\,
	datab => \inst23~q\,
	datac => \inst18~1_combout\,
	datad => \inst19~0_combout\,
	combout => \inst18~2_combout\);

-- Location: FF_X14_Y1_N29
inst25 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \inst18~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst25~q\);

-- Location: LCCOMB_X14_Y1_N20
\inst~5\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst~5_combout\ = (!\inst27~q\ & (!\inst25~q\ & (\inst29~q\ & \inst23~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst25~q\,
	datac => \inst29~q\,
	datad => \inst23~q\,
	combout => \inst~5_combout\);

-- Location: LCCOMB_X13_Y1_N26
\inst20~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst20~0_combout\ = (\inst27~q\ & ((\inst25~q\) # ((\inst23~q\ & \inst29~q\)))) # (!\inst27~q\ & ((\inst23~q\ $ (!\inst29~q\)) # (!\inst25~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110101111010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst23~q\,
	datac => \inst29~q\,
	datad => \inst25~q\,
	combout => \inst20~0_combout\);

-- Location: LCCOMB_X14_Y1_N30
\inst~6\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst~6_combout\ = (\inst27~q\ & (!\inst25~q\ & (\inst29~q\ & \inst23~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst25~q\,
	datac => \inst29~q\,
	datad => \inst23~q\,
	combout => \inst~6_combout\);

-- Location: LCCOMB_X14_Y1_N18
\inst20~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst20~1_combout\ = (\b~input_o\ & ((\inst~6_combout\) # ((!\a~input_o\ & \inst~2_combout\)))) # (!\b~input_o\ & (!\a~input_o\ & ((\inst~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011001110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \a~input_o\,
	datac => \inst~6_combout\,
	datad => \inst~2_combout\,
	combout => \inst20~1_combout\);

-- Location: LCCOMB_X14_Y1_N8
\inst20~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst20~2_combout\ = (\inst~5_combout\) # ((\inst~4_combout\) # ((\inst20~1_combout\) # (!\inst20~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111101111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst~5_combout\,
	datab => \inst~4_combout\,
	datac => \inst20~0_combout\,
	datad => \inst20~1_combout\,
	combout => \inst20~2_combout\);

-- Location: FF_X14_Y1_N9
inst29 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \inst20~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst29~q\);

-- Location: LCCOMB_X14_Y1_N16
\inst19~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst19~1_combout\ = (\inst29~q\) # ((!\inst25~q\ & \inst27~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst29~q\,
	datac => \inst25~q\,
	datad => \inst27~q\,
	combout => \inst19~1_combout\);

-- Location: LCCOMB_X14_Y1_N24
\inst~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst~1_combout\ = (\inst27~q\ & (\inst25~q\ & (\inst29~q\ & \inst23~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst25~q\,
	datac => \inst29~q\,
	datad => \inst23~q\,
	combout => \inst~1_combout\);

-- Location: LCCOMB_X14_Y1_N4
\inst19~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst19~2_combout\ = (\inst~1_combout\) # ((\b~input_o\ & ((\inst~6_combout\) # (\inst~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111011101100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \inst~1_combout\,
	datac => \inst~6_combout\,
	datad => \inst~0_combout\,
	combout => \inst19~2_combout\);

-- Location: LCCOMB_X14_Y1_N6
\inst19~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst19~3_combout\ = (\inst19~2_combout\) # (((\inst23~q\ & !\inst19~1_combout\)) # (!\inst19~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst23~q\,
	datab => \inst19~1_combout\,
	datac => \inst19~2_combout\,
	datad => \inst19~0_combout\,
	combout => \inst19~3_combout\);

-- Location: FF_X14_Y1_N7
inst27 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \inst19~3_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst27~q\);

-- Location: LCCOMB_X13_Y1_N28
inst17 : cycloneiv_lcell_comb
-- Equation(s):
-- \inst17~combout\ = (\inst29~q\ & ((\inst27~q\ & ((\inst25~q\) # (!\inst23~q\))) # (!\inst27~q\ & (!\inst23~q\ & \inst25~q\)))) # (!\inst29~q\ & (\inst25~q\ $ (((\inst27~q\) # (!\inst23~q\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001110000101011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst27~q\,
	datab => \inst29~q\,
	datac => \inst23~q\,
	datad => \inst25~q\,
	combout => \inst17~combout\);

-- Location: FF_X13_Y1_N29
inst23 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \inst17~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst23~q\);

ww_q(3) <= \q[3]~output_o\;

ww_q(2) <= \q[2]~output_o\;

ww_q(1) <= \q[1]~output_o\;

ww_q(0) <= \q[0]~output_o\;
END structure;


