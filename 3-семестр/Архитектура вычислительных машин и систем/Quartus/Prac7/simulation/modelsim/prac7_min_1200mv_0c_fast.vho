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

-- DATE "10/14/2024 03:13:43"

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

ENTITY 	prac7 IS
    PORT (
	a : IN std_logic;
	b : IN std_logic;
	clock : IN std_logic;
	q : OUT std_logic_vector(3 DOWNTO 0)
	);
END prac7;

-- Design Ports Information
-- q[0]	=>  Location: PIN_N4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- q[1]	=>  Location: PIN_M6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- q[2]	=>  Location: PIN_N6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- q[3]	=>  Location: PIN_M4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b	=>  Location: PIN_L5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clock	=>  Location: PIN_J7,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF prac7 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic;
SIGNAL ww_b : std_logic;
SIGNAL ww_clock : std_logic;
SIGNAL ww_q : std_logic_vector(3 DOWNTO 0);
SIGNAL \clock~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \q[0]~output_o\ : std_logic;
SIGNAL \q[1]~output_o\ : std_logic;
SIGNAL \q[2]~output_o\ : std_logic;
SIGNAL \q[3]~output_o\ : std_logic;
SIGNAL \clock~input_o\ : std_logic;
SIGNAL \clock~inputclkctrl_outclk\ : std_logic;
SIGNAL \b~input_o\ : std_logic;
SIGNAL \a~input_o\ : std_logic;
SIGNAL \r5~0_combout\ : std_logic;
SIGNAL \r5~1_combout\ : std_logic;
SIGNAL \newq2~0_combout\ : std_logic;
SIGNAL \newq2~1_combout\ : std_logic;
SIGNAL \dff2~q\ : std_logic;
SIGNAL \newq1~1_combout\ : std_logic;
SIGNAL \newq1~0_combout\ : std_logic;
SIGNAL \newq1~2_combout\ : std_logic;
SIGNAL \dff1~q\ : std_logic;
SIGNAL \newq3~0_combout\ : std_logic;
SIGNAL \dff3~q\ : std_logic;
SIGNAL \newq0~1_combout\ : std_logic;
SIGNAL \newq0~0_combout\ : std_logic;
SIGNAL \newq0~2_combout\ : std_logic;
SIGNAL \dff0~q\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
ww_clock <= clock;
q <= ww_q;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\clock~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clock~input_o\);

-- Location: IOOBUF_X10_Y0_N9
\q[0]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \dff0~q\,
	devoe => ww_devoe,
	o => \q[0]~output_o\);

-- Location: IOOBUF_X12_Y0_N9
\q[1]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \dff1~q\,
	devoe => ww_devoe,
	o => \q[1]~output_o\);

-- Location: IOOBUF_X12_Y0_N2
\q[2]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \dff2~q\,
	devoe => ww_devoe,
	o => \q[2]~output_o\);

-- Location: IOOBUF_X8_Y0_N2
\q[3]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \dff3~q\,
	devoe => ww_devoe,
	o => \q[3]~output_o\);

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

-- Location: IOIBUF_X14_Y0_N8
\b~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b,
	o => \b~input_o\);

-- Location: IOIBUF_X14_Y0_N1
\a~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a,
	o => \a~input_o\);

-- Location: LCCOMB_X13_Y1_N24
\r5~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \r5~0_combout\ = (!\dff3~q\ & \dff2~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \dff3~q\,
	datad => \dff2~q\,
	combout => \r5~0_combout\);

-- Location: LCCOMB_X13_Y1_N4
\r5~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \r5~1_combout\ = (\b~input_o\ & (\dff0~q\ & (\dff1~q\ & \r5~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \dff0~q\,
	datac => \dff1~q\,
	datad => \r5~0_combout\,
	combout => \r5~1_combout\);

-- Location: LCCOMB_X13_Y1_N8
\newq2~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq2~0_combout\ = (\dff3~q\ & (((\dff1~q\ & !\dff2~q\)))) # (!\dff3~q\ & (\dff2~q\ & ((\a~input_o\) # (\dff1~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a~input_o\,
	datab => \dff3~q\,
	datac => \dff1~q\,
	datad => \dff2~q\,
	combout => \newq2~0_combout\);

-- Location: LCCOMB_X13_Y1_N20
\newq2~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq2~1_combout\ = (\r5~1_combout\) # ((\dff0~q\ & (!\dff1~q\)) # (!\dff0~q\ & ((\newq2~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111011111110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \dff1~q\,
	datab => \dff0~q\,
	datac => \r5~1_combout\,
	datad => \newq2~0_combout\,
	combout => \newq2~1_combout\);

-- Location: FF_X13_Y1_N21
dff2 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \newq2~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \dff2~q\);

-- Location: LCCOMB_X13_Y1_N30
\newq1~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq1~1_combout\ = (\dff1~q\ & ((\dff2~q\) # ((\b~input_o\ & \dff0~q\)))) # (!\dff1~q\ & (((!\dff0~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000011001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \dff2~q\,
	datac => \dff1~q\,
	datad => \dff0~q\,
	combout => \newq1~1_combout\);

-- Location: LCCOMB_X13_Y1_N18
\newq1~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq1~0_combout\ = (\r5~0_combout\ & ((\dff1~q\ & (!\dff0~q\)) # (!\dff1~q\ & ((\dff0~q\) # (\a~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111011000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \dff1~q\,
	datab => \dff0~q\,
	datac => \a~input_o\,
	datad => \r5~0_combout\,
	combout => \newq1~0_combout\);

-- Location: LCCOMB_X13_Y1_N26
\newq1~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq1~2_combout\ = (\r5~1_combout\) # ((\newq1~0_combout\) # ((\newq1~1_combout\ & \dff3~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \newq1~1_combout\,
	datab => \dff3~q\,
	datac => \r5~1_combout\,
	datad => \newq1~0_combout\,
	combout => \newq1~2_combout\);

-- Location: FF_X13_Y1_N27
dff1 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \newq1~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \dff1~q\);

-- Location: LCCOMB_X13_Y1_N14
\newq3~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq3~0_combout\ = (\dff2~q\ & (\dff0~q\ $ (((!\dff1~q\ & \dff3~q\))))) # (!\dff2~q\ & (((\dff1~q\ & !\dff0~q\)) # (!\dff3~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000111101100011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \dff1~q\,
	datab => \dff2~q\,
	datac => \dff3~q\,
	datad => \dff0~q\,
	combout => \newq3~0_combout\);

-- Location: FF_X13_Y1_N15
dff3 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \newq3~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \dff3~q\);

-- Location: LCCOMB_X13_Y1_N22
\newq0~1\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq0~1_combout\ = (\dff3~q\ & ((\dff2~q\ & ((\dff1~q\) # (\dff0~q\))) # (!\dff2~q\ & (\dff1~q\ $ (!\dff0~q\))))) # (!\dff3~q\ & (\dff0~q\ & (\dff2~q\ $ (!\dff1~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100110000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \dff3~q\,
	datab => \dff2~q\,
	datac => \dff1~q\,
	datad => \dff0~q\,
	combout => \newq0~1_combout\);

-- Location: LCCOMB_X13_Y1_N16
\newq0~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq0~0_combout\ = (\dff3~q\ & (!\dff2~q\ & (\dff1~q\ & \dff0~q\))) # (!\dff3~q\ & (\dff2~q\ & (!\dff1~q\ & !\dff0~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \dff3~q\,
	datab => \dff2~q\,
	datac => \dff1~q\,
	datad => \dff0~q\,
	combout => \newq0~0_combout\);

-- Location: LCCOMB_X13_Y1_N28
\newq0~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \newq0~2_combout\ = (\newq0~1_combout\ & (\b~input_o\ & ((\newq0~0_combout\)))) # (!\newq0~1_combout\ & (((!\newq0~0_combout\) # (!\a~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010001100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \a~input_o\,
	datac => \newq0~1_combout\,
	datad => \newq0~0_combout\,
	combout => \newq0~2_combout\);

-- Location: FF_X13_Y1_N29
dff0 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \newq0~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \dff0~q\);

ww_q(0) <= \q[0]~output_o\;

ww_q(1) <= \q[1]~output_o\;

ww_q(2) <= \q[2]~output_o\;

ww_q(3) <= \q[3]~output_o\;
END structure;


