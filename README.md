
# Arduino Calculator

## Description

This project is a basic calculator built with an Arduino board, a 16x2 LCD display, and a 4x4 keypad. It can perform basic arithmetic operations: addition, subtraction, multiplication, and division.

## Features

- Basic arithmetic operations
- Interactive 16x2 LCD display
- 4x4 keypad for input

## Components

- Arduino Board (e.g., Arduino Uno)
- 16x2 LCD Display
- 4x4 Keypad
- Connecting Wires
- Breadboard (optional)

## Setup

### Hardware

1. Connect the LCD display to the Arduino:
   - RS to pin 12
   - Enable to pin 11
   - D4 to pin 10
   - D5 to pin 9
   - D6 to pin 8
   - D7 to pin 7
   - VSS to GND
   - VDD to 5V
   - V0 to potentiometer for contrast
   - A to 5V (backlight)
   - K to GND (backlight)

2. Connect the keypad to the Arduino:
   - Rows to pins 5, 4, 3, 2
   - Columns to pins A3, A2, A1, A0

### Software

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Open the IDE and create a new sketch.
3. Copy and paste the code into the sketch.
4. Ensure the necessary libraries are included:
   ```cpp
   #include <LiquidCrystal.h>
   #include <Keypad.h>
   ```
5. Upload the sketch to your Arduino board.

## Usage

1. Power on the Arduino. The LCD will display a welcome message.
2. Use the keypad to enter numbers and operations.
3. Press '=' to calculate the result.
4. Press 'C' to clear and start a new calculation.
