EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:bluepill_breakouts
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BluePill_STM32F103C U1
U 1 1 5C286B9B
P 5850 3350
F 0 "U1" H 5400 2000 50  0000 C CNN
F 1 "BluePill_STM32F103C" H 5900 4200 50  0000 C CNN
F 2 "BluePill_breakouts:BluePill_STM32F103C" H 5900 1750 50  0001 C CNN
F 3 "www.rogerclark.net" H 5850 1850 50  0001 C CNN
	1    5850 3350
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 J-LEDIR1
U 1 1 5C286C56
P 3850 3850
F 0 "J-LEDIR1" H 3850 4200 50  0000 C CNN
F 1 "CONN_01X06" V 3950 3850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x06_Pitch2.54mm" H 3850 3850 50  0001 C CNN
F 3 "" H 3850 3850 50  0001 C CNN
	1    3850 3850
	1    0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5C286DAA
P 3350 3600
F 0 "R1" V 3430 3600 50  0000 C CNN
F 1 "100" V 3350 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3280 3600 50  0001 C CNN
F 3 "" H 3350 3600 50  0001 C CNN
	1    3350 3600
	0    1    1    0   
$EndComp
Text Label 3000 3600 0    60   ~ 0
LD1
Text Label 7000 3550 0    60   ~ 0
LD1
$Comp
L R R2
U 1 1 5C2874F9
P 3350 3700
F 0 "R2" V 3430 3700 50  0000 C CNN
F 1 "100" V 3350 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3280 3700 50  0001 C CNN
F 3 "" H 3350 3700 50  0001 C CNN
	1    3350 3700
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5C287589
P 3350 3800
F 0 "R3" V 3430 3800 50  0000 C CNN
F 1 "100" V 3350 3800 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3280 3800 50  0001 C CNN
F 3 "" H 3350 3800 50  0001 C CNN
	1    3350 3800
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5C287590
P 3350 3900
F 0 "R4" V 3430 3900 50  0000 C CNN
F 1 "100" V 3350 3900 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3280 3900 50  0001 C CNN
F 3 "" H 3350 3900 50  0001 C CNN
	1    3350 3900
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5C28762C
P 3350 4000
F 0 "R5" V 3430 4000 50  0000 C CNN
F 1 "100" V 3350 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3280 4000 50  0001 C CNN
F 3 "" H 3350 4000 50  0001 C CNN
	1    3350 4000
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5C287633
P 3350 4100
F 0 "R6" V 3430 4100 50  0000 C CNN
F 1 "100" V 3350 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3280 4100 50  0001 C CNN
F 3 "" H 3350 4100 50  0001 C CNN
	1    3350 4100
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR01
U 1 1 5C28779B
P 3400 5200
F 0 "#PWR01" H 3400 5050 50  0001 C CNN
F 1 "+3.3V" H 3400 5340 50  0000 C CNN
F 2 "" H 3400 5200 50  0001 C CNN
F 3 "" H 3400 5200 50  0001 C CNN
	1    3400 5200
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5C287867
P 3400 5550
F 0 "R7" V 3480 5550 50  0000 C CNN
F 1 "220k" V 3400 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3330 5550 50  0001 C CNN
F 3 "" H 3400 5550 50  0001 C CNN
	1    3400 5550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 J-PT1
U 1 1 5C287A09
P 3650 6000
F 0 "J-PT1" H 3650 6350 50  0000 C CNN
F 1 "CONN_01X06" V 3750 6000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x06_Pitch2.54mm" H 3650 6000 50  0001 C CNN
F 3 "" H 3650 6000 50  0001 C CNN
	1    3650 6000
	0    1    1    0   
$EndComp
Text Label 4900 3050 0    60   ~ 0
PT1
$Comp
L R R8
U 1 1 5C288655
P 3500 5550
F 0 "R8" V 3580 5550 50  0000 C CNN
F 1 "220k" V 3500 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3430 5550 50  0001 C CNN
F 3 "" H 3500 5550 50  0001 C CNN
	1    3500 5550
	1    0    0    -1  
$EndComp
Text Label 3000 3700 0    60   ~ 0
LD2
Text Label 3000 3800 0    60   ~ 0
LD3
Text Label 3000 3900 0    60   ~ 0
LD4
Text Label 3000 4000 0    60   ~ 0
LD5
Text Label 3000 4100 0    60   ~ 0
LD6
Text Label 7000 3450 0    60   ~ 0
LD2
Text Label 7000 3350 0    60   ~ 0
LD3
Text Label 7000 3250 0    60   ~ 0
LD4
Text Label 7000 3150 0    60   ~ 0
LD5
Text Label 7000 3050 0    60   ~ 0
LD6
$Comp
L R R9
U 1 1 5C28A160
P 3600 5550
F 0 "R9" V 3680 5550 50  0000 C CNN
F 1 "220k" V 3600 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3530 5550 50  0001 C CNN
F 3 "" H 3600 5550 50  0001 C CNN
	1    3600 5550
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 5C28A166
P 3700 5550
F 0 "R10" V 3780 5550 50  0000 C CNN
F 1 "220k" V 3700 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3630 5550 50  0001 C CNN
F 3 "" H 3700 5550 50  0001 C CNN
	1    3700 5550
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5C28A241
P 3800 5550
F 0 "R11" V 3880 5550 50  0000 C CNN
F 1 "220k" V 3800 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3730 5550 50  0001 C CNN
F 3 "" H 3800 5550 50  0001 C CNN
	1    3800 5550
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 5C28A247
P 3900 5550
F 0 "R12" V 3980 5550 50  0000 C CNN
F 1 "220k" V 3900 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3830 5550 50  0001 C CNN
F 3 "" H 3900 5550 50  0001 C CNN
	1    3900 5550
	1    0    0    -1  
$EndComp
Text Label 3150 5700 0    60   ~ 0
PT1
Text Label 3150 5750 0    60   ~ 0
PT2
Text Label 3150 5800 0    60   ~ 0
PT3
Wire Wire Line
	3650 3600 3500 3600
Wire Wire Line
	3200 3600 3000 3600
Wire Wire Line
	6750 3550 7000 3550
Wire Wire Line
	3200 3800 3000 3800
Wire Wire Line
	3200 4000 3000 4000
Wire Wire Line
	3400 5200 3400 5400
Wire Wire Line
	5000 3050 4900 3050
Wire Wire Line
	3500 5700 3500 5800
Wire Wire Line
	3500 5400 3500 5300
Wire Wire Line
	3400 5300 3900 5300
Connection ~ 3400 5300
Wire Wire Line
	3400 5700 3400 5800
Wire Wire Line
	3500 3700 3650 3700
Wire Wire Line
	3500 3800 3650 3800
Wire Wire Line
	3500 3900 3650 3900
Wire Wire Line
	3500 4000 3650 4000
Wire Wire Line
	3500 4100 3650 4100
Wire Wire Line
	3000 3700 3200 3700
Wire Wire Line
	3000 3900 3200 3900
Wire Wire Line
	3000 4100 3200 4100
Wire Wire Line
	7000 3450 6750 3450
Wire Wire Line
	7000 3350 6750 3350
Wire Wire Line
	7000 3250 6750 3250
Wire Wire Line
	7000 3150 6750 3150
Wire Wire Line
	7000 3050 6750 3050
Wire Wire Line
	3700 5700 3700 5800
Wire Wire Line
	3700 5300 3700 5400
Wire Wire Line
	3600 5700 3600 5800
Wire Wire Line
	3900 5700 3900 5800
Wire Wire Line
	3900 5300 3900 5400
Wire Wire Line
	3800 5700 3800 5800
Wire Wire Line
	3600 5300 3600 5400
Connection ~ 3500 5300
Connection ~ 3600 5300
Wire Wire Line
	3800 5300 3800 5400
Connection ~ 3700 5300
Connection ~ 3800 5300
Wire Wire Line
	3150 5700 3400 5700
Connection ~ 3500 5750
Wire Wire Line
	3600 5800 3150 5800
Wire Wire Line
	3150 5750 3500 5750
Wire Wire Line
	4050 5700 3900 5700
Text Label 4050 5700 0    60   ~ 0
PT6
Wire Wire Line
	4050 5750 3800 5750
Connection ~ 3800 5750
Text Label 4050 5750 0    60   ~ 0
PT5
Wire Wire Line
	3700 5800 4050 5800
Text Label 4050 5800 0    60   ~ 0
PT4
Wire Wire Line
	4900 3150 5000 3150
Wire Wire Line
	4900 3250 5000 3250
Wire Wire Line
	4900 3350 5000 3350
Wire Wire Line
	4900 3450 5000 3450
Wire Wire Line
	4900 3550 5000 3550
Text Label 4900 3150 0    60   ~ 0
PT2
Text Label 4900 3250 0    60   ~ 0
PT3
Text Label 4900 3350 0    60   ~ 0
PT4
Text Label 4900 3450 0    60   ~ 0
PT5
Text Label 4900 3550 0    60   ~ 0
PT6
$Comp
L CONN_01X04 J-COMM1
U 1 1 5C28BF1E
P 8800 3250
F 0 "J-COMM1" H 8800 3500 50  0000 C CNN
F 1 "CONN_01X04" V 8900 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x04_Pitch2.54mm" H 8800 3250 50  0001 C CNN
F 3 "" H 8800 3250 50  0001 C CNN
	1    8800 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 3300 8500 3300
Wire Wire Line
	8600 3400 8500 3400
Text Label 8500 3300 0    60   ~ 0
RX
Text Label 8500 3400 0    60   ~ 0
TX
$Comp
L +3.3V #PWR02
U 1 1 5C28CFA9
P 8500 3100
F 0 "#PWR02" H 8500 2950 50  0001 C CNN
F 1 "+3.3V" H 8500 3240 50  0000 C CNN
F 2 "" H 8500 3100 50  0001 C CNN
F 3 "" H 8500 3100 50  0001 C CNN
	1    8500 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 3100 8500 3100
$Comp
L GND #PWR03
U 1 1 5C28D023
P 8350 3200
F 0 "#PWR03" H 8350 2950 50  0001 C CNN
F 1 "GND" H 8350 3050 50  0000 C CNN
F 2 "" H 8350 3200 50  0001 C CNN
F 3 "" H 8350 3200 50  0001 C CNN
	1    8350 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 3200 8350 3200
$Comp
L CONN_01X02 J-GND1
U 1 1 5C28DF41
P 4950 5150
F 0 "J-GND1" H 4950 5300 50  0000 C CNN
F 1 "CONN_01X02" V 5050 5150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x02_Pitch2.54mm" H 4950 5150 50  0001 C CNN
F 3 "" H 4950 5150 50  0001 C CNN
	1    4950 5150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5C28DFF2
P 4650 5200
F 0 "#PWR04" H 4650 4950 50  0001 C CNN
F 1 "GND" H 4650 5050 50  0000 C CNN
F 2 "" H 4650 5200 50  0001 C CNN
F 3 "" H 4650 5200 50  0001 C CNN
	1    4650 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 5100 4750 5200
Wire Wire Line
	4750 5150 4650 5150
Wire Wire Line
	4650 5150 4650 5200
Connection ~ 4750 5150
$Comp
L GND #PWR05
U 1 1 5C28E88A
P 7050 2750
F 0 "#PWR05" H 7050 2500 50  0001 C CNN
F 1 "GND" H 7050 2600 50  0000 C CNN
F 2 "" H 7050 2750 50  0001 C CNN
F 3 "" H 7050 2750 50  0001 C CNN
	1    7050 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2750 7050 2750
$Comp
L +3.3V #PWR06
U 1 1 5C28E90D
P 7050 2650
F 0 "#PWR06" H 7050 2500 50  0001 C CNN
F 1 "+3.3V" H 7050 2790 50  0000 C CNN
F 2 "" H 7050 2650 50  0001 C CNN
F 3 "" H 7050 2650 50  0001 C CNN
	1    7050 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2650 6750 2650
Wire Wire Line
	6750 3950 6950 3950
Wire Wire Line
	6750 4050 6950 4050
Text Label 6950 4050 0    60   ~ 0
TX
Text Label 6950 3950 0    60   ~ 0
RX
$EndSCHEMATC
