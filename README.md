# Microcontroller-Design-Project-

This project is part of the IA 2209 - Microcontroller Laboratory course. 
It involves creating a microcontroller-based temperature monitoring system with various features including temperature display, alarm, and range indication using LEDs.

## Features

- **Temperature Display**: Displays the current temperature on a 7-segment display with the ability to switch between Celsius and Fahrenheit.
- **Temperature Alarm**: An alarm system that triggers when the temperature exceeds 40°C.
- **Temperature Range Indication**: LEDs indicate different temperature ranges with varying brightness.
- **Mode Switching**: Toggle between displaying temperature (Celsius and Fahrenheit) and temperature range.
<img src ="hardware simulation/1719309044267.jpg">

## Components
- ATmega328P Microcontroller
- MAX7219CNG Display driver
- 4-Digit 7-segment displays
- LEDs
- Push buttons
- Resistors, capacitors, and other supporting components
## Simulation on Proteus
https://github.com/user-attachments/assets/188e2a22-0e74-4096-baf8-a73c14bb029d

## Hardware Testing
https://github.com/user-attachments/assets/ba68c1e6-b078-402f-8ae6-b2f3dc63eebe

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
<img src="hardware simulation/a.png">
<img src="hardware simulation/b.png">
<img src="hardware simulation/c.png">
<img src="hardware simulation/v.png">
