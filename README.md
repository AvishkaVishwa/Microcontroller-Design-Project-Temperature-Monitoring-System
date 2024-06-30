# Microcontroller-Design-Project-

This project is part of the IA 2209 - Microcontroller Laboratory course. 
It involves creating a microcontroller-based temperature monitoring system with various features including temperature display, alarm, and range indication using LEDs.

## Features

- **Temperature Display**: Displays the current temperature on a 7-segment display with the ability to switch between Celsius and Fahrenheit.
- **Temperature Alarm**: An alarm system that triggers when the temperature exceeds 40°C.
- **Temperature Range Indication**: LEDs indicate different temperature ranges with varying brightness.
- **Mode Switching**: Toggle between displaying temperature (Celsius and Fahrenheit) and temperature range.

## Components

- ATmega328P Microcontroller
- MAX7219CNG Display driver
- 4-Digit 7-segment displays
- LEDs
- Push buttons
- Resistors, capacitors, and other supporting components

## Usage

1. **Compile and Upload Code**: Compile the provided C/C++ code and upload it to the ATmega328P microcontroller.
2. **Hardware Setup**: Connect the hardware components as per the circuit diagram provided in `hardware/circuit_diagram.png`.
3. **Operating the System**:
   - Use the increment and decrement buttons to adjust the temperature.
   - The current temperature is displayed on the 7-segment display.
   - The alarm LED blinks if the temperature exceeds 40°C and can be acknowledged with the acknowledgment button.
   - LEDs indicate the current temperature range.
<img src="hardware simulation/1717617684600.jpg">   
<img src="hardware simulation/1717617684541.jpg">
<img src="hardware simulation/schematic.png">
<img src="hardware simulation/1.png">
<img src="hardware simulation/2.png">
<img src="hardware simulation/3.png">
<img src="hardware simulation/4.png">