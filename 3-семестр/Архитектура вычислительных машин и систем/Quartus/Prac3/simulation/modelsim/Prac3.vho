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

-- DATE "10/07/2024 07:37:04"

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

ENTITY 	Prac3 IS
    PORT (
	Y : OUT std_logic;
	x0 : IN std_logic;
	a2 : IN std_logic;
	a1 : IN std_logic;
	a0 : IN std_logic;
	x2 : IN std_logic;
	x1 : IN std_logic;
	x3 : IN std_logic;
	x5 : IN std_logic;
	x4 : IN std_logic;
	x6 : IN std_logic;
	x7 : IN std_logic
	);
END Prac3;

-- Design Ports Information
-- Y	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x3	=>  Location: PIN_N8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x2	=>  Location: PIN_K8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a0	=>  Location: PIN_L5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a2	=>  Location: PIN_A6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x1	=>  Location: PIN_J13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x0	=>  Location: PIN_H10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a1	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x7	=>  Location: PIN_M11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x6	=>  Location: PIN_M9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x5	=>  Location: PIN_G13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x4	=>  Location: PIN_H13,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Prac3 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Y : std_logic;
SIGNAL ww_x0 : std_logic;
SIGNAL ww_a2 : std_logic;
SIGNAL ww_a1 : std_logic;
SIGNAL ww_a0 : std_logic;
SIGNAL ww_x2 : std_logic;
SIGNAL ww_x1 : std_logic;
SIGNAL ww_x3 : std_logic;
SIGNAL ww_x5 : std_logic;
SIGNAL ww_x4 : std_logic;
SIGNAL ww_x6 : std_logic;
SIGNAL ww_x7 : std_logic;
SIGNAL \Y~output_o\ : std_logic;
SIGNAL \a0~input_o\ : std_logic;
SIGNAL \x6~input_o\ : std_logic;
SIGNAL \a2~input_o\ : std_logic;
SIGNAL \x7~input_o\ : std_logic;
SIGNAL \inst11~3_combout\ : std_logic;
SIGNAL \x5~input_o\ : std_logic;
SIGNAL \x4~input_o\ : std_logic;
SIGNAL \inst11~4_combout\ : std_logic;
SIGNAL \a1~input_o\ : std_logic;
SIGNAL \x2~input_o\ : std_logic;
SIGNAL \x3~input_o\ : std_logic;
SIGNAL \inst11~0_combout\ : std_logic;
SIGNAL \x0~input_o\ : std_logic;
SIGNAL \x1~input_o\ : std_logic;
SIGNAL \inst11~1_combout\ : std_logic;
SIGNAL \inst11~2_combout\ : std_logic;
SIGNAL \inst11~5_combout\ : std_logic;

BEGIN

Y <= ww_Y;
ww_x0 <= x0;
ww_a2 <= a2;
ww_a1 <= a1;
ww_a0 <= a0;
ww_x2 <= x2;
ww_x1 <= x1;
ww_x3 <= x3;
ww_x5 <= x5;
ww_x4 <= x4;
ww_x6 <= x6;
ww_x7 <= x7;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X20_Y31_N2
\Y~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11~5_combout\,
	devoe => ww_devoe,
	o => \Y~output_o\);

-- Location: IOIBUF_X14_Y0_N8
\a0~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a0,
	o => \a0~input_o\);

-- Location: IOIBUF_X24_Y0_N1
\x6~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x6,
	o => \x6~input_o\);

-- Location: IOIBUF_X10_Y31_N1
\a2~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a2,
	o => \a2~input_o\);

-- Location: IOIBUF_X29_Y0_N8
\x7~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x7,
	o => \x7~input_o\);

-- Location: LCCOMB_X23_Y20_N6
\inst11~3\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst11~3_combout\ = (\a2~input_o\ & ((\a0~input_o\ & ((\x7~input_o\))) # (!\a0~input_o\ & (\x6~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000001000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a0~input_o\,
	datab => \x6~input_o\,
	datac => \a2~input_o\,
	datad => \x7~input_o\,
	combout => \inst11~3_combout\);

-- Location: IOIBUF_X33_Y16_N22
\x5~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x5,
	o => \x5~input_o\);

-- Location: IOIBUF_X33_Y16_N15
\x4~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x4,
	o => \x4~input_o\);

-- Location: LCCOMB_X23_Y20_N0
\inst11~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst11~4_combout\ = (\a2~input_o\ & ((\a0~input_o\ & (\x5~input_o\)) # (!\a0~input_o\ & ((\x4~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101000010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a0~input_o\,
	datab => \x5~input_o\,
	datac => \a2~input_o\,
	datad => \x4~input_o\,
	combout => \inst11~4_combout\);

-- Location: IOIBUF_X14_Y0_N1
\a1~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a1,
	o => \a1~input_o\);

-- Location: IOIBUF_X22_Y0_N8
\x2~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x2,
	o => \x2~input_o\);

-- Location: IOIBUF_X20_Y0_N8
\x3~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x3,
	o => \x3~input_o\);

-- Location: LCCOMB_X23_Y20_N24
\inst11~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst11~0_combout\ = (!\a2~input_o\ & ((\a0~input_o\ & ((\x3~input_o\))) # (!\a0~input_o\ & (\x2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a0~input_o\,
	datab => \a2~input_o\,
	datac => \x2~input_o\,
	datad => \x3~input_o\,
	combout => \inst11~0_combout\);

-- Location: IOIBUF_X33_Y14_N1
\x0~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x0,
	o => \x0~input_o\);

-- Location: IOIBUF_X33_Y15_N8
\x1~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x1,
	o => \x1~input_o\);

-- Location: LCCOMB_X23_Y20_N2
\inst11~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst11~1_combout\ = (!\a2~input_o\ & ((\a0~input_o\ & ((\x1~input_o\))) # (!\a0~input_o\ & (\x0~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a0~input_o\,
	datab => \x0~input_o\,
	datac => \a2~input_o\,
	datad => \x1~input_o\,
	combout => \inst11~1_combout\);

-- Location: LCCOMB_X23_Y20_N12
\inst11~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst11~2_combout\ = (\a1~input_o\ & (\inst11~0_combout\)) # (!\a1~input_o\ & ((\inst11~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111111000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst11~0_combout\,
	datac => \a1~input_o\,
	datad => \inst11~1_combout\,
	combout => \inst11~2_combout\);

-- Location: LCCOMB_X23_Y20_N18
\inst11~5\ : cycloneiv_lcell_comb
-- Equation(s):
-- \inst11~5_combout\ = (\inst11~2_combout\) # ((\a1~input_o\ & (\inst11~3_combout\)) # (!\a1~input_o\ & ((\inst11~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst11~3_combout\,
	datab => \inst11~4_combout\,
	datac => \a1~input_o\,
	datad => \inst11~2_combout\,
	combout => \inst11~5_combout\);

ww_Y <= \Y~output_o\;
END structure;


