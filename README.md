# Intro

> Hi

I built a Simple Snake Game with FreeRTOS with < AVR atmega32 > and i like to share it .

# Components
* AVR atmega32
* LCD 16*2
* Keypad 4*4
* 1 LED for check if any overflow error

## Config LED
* V+ = A0
* V- = GND

## Config LCD
* VSS = GND
* VDD = 5v
* V0 = GND
* RS = A1
* RW = A2
* EN = A3
* D0 = floating
* D1 = floating
* D2 = floating
* D3 = floating
* D4 = A4
* D5 = A5
* D6 = A6
* D7 = A7
* LED+ = 5v
* LED- = GND

## Config Keypad
* R1 = C3
* R2 = C2
* R3 = C1
* R1 = C0
* C1 = C4
* C2 = C5
* C3 = C6
* C4 = C7

