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

-- DATE "10/08/2024 01:39:33"

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

ENTITY 	Prac4 IS
    PORT (
	a0 : IN std_logic;
	a1 : IN std_logic;
	a2 : IN std_logic;
	x0 : IN std_logic;
	x1 : IN std_logic;
	x2 : IN std_logic;
	x3 : IN std_logic;
	x4 : IN std_logic;
	x5 : IN std_logic;
	x6 : IN std_logic;
	x7 : IN std_logic;
	y : OUT std_logic
	);
END Prac4;

-- Design Ports Information
-- y	=>  Location: PIN_A6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x5	=>  Location: PIN_M6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a2	=>  Location: PIN_N11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x3	=>  Location: PIN_N6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a1	=>  Location: PIN_M4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x1	=>  Location: PIN_N8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x7	=>  Location: PIN_L4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x2	=>  Location: PIN_A8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x4	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x0	=>  Location: PIN_K9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x6	=>  Location: PIN_G13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a0	=>  Location: PIN_H13,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Prac4 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a0 : std_logic;
SIGNAL ww_a1 : std_logic;
SIGNAL ww_a2 : std_logic;
SIGNAL ww_x0 : std_logic;
SIGNAL ww_x1 : std_logic;
SIGNAL ww_x2 : std_logic;
SIGNAL ww_x3 : std_logic;
SIGNAL ww_x4 : std_logic;
SIGNAL ww_x5 : std_logic;
SIGNAL ww_x6 : std_logic;
SIGNAL ww_x7 : std_logic;
SIGNAL ww_y : std_logic;
SIGNAL \y~output_o\ : std_logic;
SIGNAL \a1~input_o\ : std_logic;
SIGNAL \x6~input_o\ : std_logic;
SIGNAL \x2~input_o\ : std_logic;
SIGNAL \x0~input_o\ : std_logic;
SIGNAL \x4~input_o\ : std_logic;
SIGNAL \a2~input_o\ : std_logic;
SIGNAL \y~2_combout\ : std_logic;
SIGNAL \y~3_combout\ : std_logic;
SIGNAL \x5~input_o\ : std_logic;
SIGNAL \x7~input_o\ : std_logic;
SIGNAL \x3~input_o\ : std_logic;
SIGNAL \x1~input_o\ : std_logic;
SIGNAL \y~0_combout\ : std_logic;
SIGNAL \y~1_combout\ : std_logic;
SIGNAL \a0~input_o\ : std_logic;
SIGNAL \y~4_combout\ : std_logic;

BEGIN

ww_a0 <= a0;
ww_a1 <= a1;
ww_a2 <= a2;
ww_x0 <= x0;
ww_x1 <= x1;
ww_x2 <= x2;
ww_x3 <= x3;
ww_x4 <= x4;
ww_x5 <= x5;
ww_x6 <= x6;
ww_x7 <= x7;
y <= ww_y;
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
	i => \y~4_combout\,
	devoe => ww_devoe,
	o => \y~output_o\);

-- Location: IOIBUF_X8_Y0_N1
\a1~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a1,
	o => \a1~input_o\);

-- Location: IOIBUF_X33_Y16_N22
\x6~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x6,
	o => \x6~input_o\);

-- Location: IOIBUF_X12_Y31_N8
\x2~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x2,
	o => \x2~input_o\);

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
\x4~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x4,
	o => \x4~input_o\);

-- Location: IOIBUF_X26_Y0_N1
\a2~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a2,
	o => \a2~input_o\);

-- Location: LCCOMB_X18_Y2_N12
\y~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \y~2_combout\ = (\a1~input_o\ & (((\a2~input_o\)))) # (!\a1~input_o\ & ((\a2~input_o\ & ((\x4~input_o\))) # (!\a2~input_o\ & (\x0~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101001000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a1~input_o\,
	datab => \x0~input_o\,
	datac => \x4~input_o\,
	datad => \a2~input_o\,
	combout => \y~2_combout\);

-- Location: LCCOMB_X18_Y2_N6
\y~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \y~3_combout\ = (\a1~input_o\ & ((\y~2_combout\ & (\x6~input_o\)) # (!\y~2_combout\ & ((\x2~input_o\))))) # (!\a1~input_o\ & (((\y~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a1~input_o\,
	datab => \x6~input_o\,
	datac => \x2~input_o\,
	datad => \y~2_combout\,
	combout => \y~3_combout\);

-- Location: IOIBUF_X12_Y0_N8
\x5~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x5,
	o => \x5~input_o\);

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
\x3~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x3,
	o => \x3~input_o\);

-- Location: IOIBUF_X20_Y0_N8
\x1~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x1,
	o => \x1~input_o\);

-- Location: LCCOMB_X18_Y2_N8
\y~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \y~0_combout\ = (\a1~input_o\ & ((\x3~input_o\) # ((\a2~input_o\)))) # (!\a1~input_o\ & (((\x1~input_o\ & !\a2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a1~input_o\,
	datab => \x3~input_o\,
	datac => \x1~input_o\,
	datad => \a2~input_o\,
	combout => \y~0_combout\);

-- Location: LCCOMB_X18_Y2_N2
\y~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \y~1_combout\ = (\y~0_combout\ & (((\x7~input_o\) # (!\a2~input_o\)))) # (!\y~0_combout\ & (\x5~input_o\ & ((\a2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100101011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \x5~input_o\,
	datab => \x7~input_o\,
	datac => \y~0_combout\,
	datad => \a2~input_o\,
	combout => \y~1_combout\);

-- Location: IOIBUF_X33_Y16_N15
\a0~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a0,
	o => \a0~input_o\);

-- Location: LCCOMB_X18_Y2_N0
\y~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \y~4_combout\ = (\a0~input_o\ & ((\y~1_combout\))) # (!\a0~input_o\ & (\y~3_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \y~3_combout\,
	datab => \y~1_combout\,
	datad => \a0~input_o\,
	combout => \y~4_combout\);

ww_y <= \y~output_o\;
END structure;


