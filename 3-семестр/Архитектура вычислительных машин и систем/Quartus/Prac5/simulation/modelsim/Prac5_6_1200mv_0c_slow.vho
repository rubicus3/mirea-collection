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

-- DATE "10/08/2024 01:52:25"

-- 
-- Device: Altera EP4CGX15BF14C6 Package FBGA169
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIV;
LIBRARY IEEE;
USE CYCLONEIV.CYCLONEIV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Prac5 IS
    PORT (
	y : OUT std_logic;
	x7 : IN std_logic;
	x6 : IN std_logic;
	x5 : IN std_logic;
	x4 : IN std_logic;
	x3 : IN std_logic;
	x2 : IN std_logic;
	x1 : IN std_logic;
	x0 : IN std_logic;
	a : IN std_logic_vector(2 DOWNTO 0)
	);
END Prac5;

-- Design Ports Information
-- y	=>  Location: PIN_A6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x6	=>  Location: PIN_M6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_N11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x5	=>  Location: PIN_N6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_M4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x4	=>  Location: PIN_N8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x7	=>  Location: PIN_L4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x1	=>  Location: PIN_A8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x2	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x0	=>  Location: PIN_K9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x3	=>  Location: PIN_G13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[2]	=>  Location: PIN_H13,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Prac5 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_y : std_logic;
SIGNAL ww_x7 : std_logic;
SIGNAL ww_x6 : std_logic;
SIGNAL ww_x5 : std_logic;
SIGNAL ww_x4 : std_logic;
SIGNAL ww_x3 : std_logic;
SIGNAL ww_x2 : std_logic;
SIGNAL ww_x1 : std_logic;
SIGNAL ww_x0 : std_logic;
SIGNAL ww_a : std_logic_vector(2 DOWNTO 0);
SIGNAL \y~output_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \x3~input_o\ : std_logic;
SIGNAL \x1~input_o\ : std_logic;
SIGNAL \x0~input_o\ : std_logic;
SIGNAL \x2~input_o\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \inst|LPM_MUX_component|auto_generated|_~2_combout\ : std_logic;
SIGNAL \inst|LPM_MUX_component|auto_generated|_~3_combout\ : std_logic;
SIGNAL \x6~input_o\ : std_logic;
SIGNAL \x7~input_o\ : std_logic;
SIGNAL \x5~input_o\ : std_logic;
SIGNAL \x4~input_o\ : std_logic;
SIGNAL \inst|LPM_MUX_component|auto_generated|_~0_combout\ : std_logic;
SIGNAL \inst|LPM_MUX_component|auto_generated|_~1_combout\ : std_logic;
SIGNAL \a[2]~input_o\ : std_logic;
SIGNAL \inst|LPM_MUX_component|auto_generated|_~4_combout\ : std_logic;

BEGIN

y <= ww_y;
ww_x7 <= x7;
ww_x6 <= x6;
ww_x5 <= x5;
ww_x4 <= x4;
ww_x3 <= x3;
ww_x2 <= x2;
ww_x1 <= x1;
ww_x0 <= x0;
ww_a <= a;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X10_Y31_N2
\y~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|LPM_MUX_component|auto_generated|_~4_combout\,
	devoe => ww_devoe,
	o => \y~output_o\);

-- Location: IOIBUF_X8_Y0_N1
\a[0]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: IOIBUF_X33_Y16_N22
\x3~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x3,
	o => \x3~input_o\);

-- Location: IOIBUF_X12_Y31_N8
\x1~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x1,
	o => \x1~input_o\);

-- Location: IOIBUF_X22_Y0_N1
\x0~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x0,
	o => \x0~input_o\);

-- Location: IOIBUF_X14_Y0_N1
\x2~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x2,
	o => \x2~input_o\);

-- Location: IOIBUF_X26_Y0_N1
\a[1]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

-- Location: LCCOMB_X18_Y2_N12
\inst|LPM_MUX_component|auto_generated|_~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst|LPM_MUX_component|auto_generated|_~2_combout\ = (\a[0]~input_o\ & (((\a[1]~input_o\)))) # (!\a[0]~input_o\ & ((\a[1]~input_o\ & ((\x2~input_o\))) # (!\a[1]~input_o\ & (\x0~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101001000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[0]~input_o\,
	datab => \x0~input_o\,
	datac => \x2~input_o\,
	datad => \a[1]~input_o\,
	combout => \inst|LPM_MUX_component|auto_generated|_~2_combout\);

-- Location: LCCOMB_X18_Y2_N6
\inst|LPM_MUX_component|auto_generated|_~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst|LPM_MUX_component|auto_generated|_~3_combout\ = (\a[0]~input_o\ & ((\inst|LPM_MUX_component|auto_generated|_~2_combout\ & (\x3~input_o\)) # (!\inst|LPM_MUX_component|auto_generated|_~2_combout\ & ((\x1~input_o\))))) # (!\a[0]~input_o\ & 
-- (((\inst|LPM_MUX_component|auto_generated|_~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[0]~input_o\,
	datab => \x3~input_o\,
	datac => \x1~input_o\,
	datad => \inst|LPM_MUX_component|auto_generated|_~2_combout\,
	combout => \inst|LPM_MUX_component|auto_generated|_~3_combout\);

-- Location: IOIBUF_X12_Y0_N8
\x6~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x6,
	o => \x6~input_o\);

-- Location: IOIBUF_X8_Y0_N8
\x7~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x7,
	o => \x7~input_o\);

-- Location: IOIBUF_X12_Y0_N1
\x5~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x5,
	o => \x5~input_o\);

-- Location: IOIBUF_X20_Y0_N8
\x4~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x4,
	o => \x4~input_o\);

-- Location: LCCOMB_X18_Y2_N8
\inst|LPM_MUX_component|auto_generated|_~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst|LPM_MUX_component|auto_generated|_~0_combout\ = (\a[0]~input_o\ & ((\x5~input_o\) # ((\a[1]~input_o\)))) # (!\a[0]~input_o\ & (((\x4~input_o\ & !\a[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[0]~input_o\,
	datab => \x5~input_o\,
	datac => \x4~input_o\,
	datad => \a[1]~input_o\,
	combout => \inst|LPM_MUX_component|auto_generated|_~0_combout\);

-- Location: LCCOMB_X18_Y2_N2
\inst|LPM_MUX_component|auto_generated|_~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst|LPM_MUX_component|auto_generated|_~1_combout\ = (\inst|LPM_MUX_component|auto_generated|_~0_combout\ & (((\x7~input_o\) # (!\a[1]~input_o\)))) # (!\inst|LPM_MUX_component|auto_generated|_~0_combout\ & (\x6~input_o\ & ((\a[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100101011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \x6~input_o\,
	datab => \x7~input_o\,
	datac => \inst|LPM_MUX_component|auto_generated|_~0_combout\,
	datad => \a[1]~input_o\,
	combout => \inst|LPM_MUX_component|auto_generated|_~1_combout\);

-- Location: IOIBUF_X33_Y16_N15
\a[2]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(2),
	o => \a[2]~input_o\);

-- Location: LCCOMB_X18_Y2_N0
\inst|LPM_MUX_component|auto_generated|_~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst|LPM_MUX_component|auto_generated|_~4_combout\ = (\a[2]~input_o\ & ((\inst|LPM_MUX_component|auto_generated|_~1_combout\))) # (!\a[2]~input_o\ & (\inst|LPM_MUX_component|auto_generated|_~3_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|LPM_MUX_component|auto_generated|_~3_combout\,
	datab => \inst|LPM_MUX_component|auto_generated|_~1_combout\,
	datad => \a[2]~input_o\,
	combout => \inst|LPM_MUX_component|auto_generated|_~4_combout\);

ww_y <= \y~output_o\;
END structure;


