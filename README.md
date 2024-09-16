# Robonetra: Robotic Walking Stick for the Visually Impaired

This project is a robotic walking stick designed to assist visually impaired individuals. The device is equipped with ultrasonic sensors to detect obstacles and a sound system to alert the user through pre-recorded warning sounds stored on an SD card.

## Components

- **Arduino Uno**: As Microcontroller
- **Ultrasonic Sensors (3)**: Object detection sensors placed on the left, center, and right sides
- **DFPlayer Mini**: Sound player module
- **Breadboard**: For connecting wires without soldering
- **Speaker**: For audio output
- **SD Card**: To store warning sounds
- **Jumper cable (F to M and M to M)**: To connect all the components
- **Battery**: For power source
- **Battery Connector**: For connecting the battery into arduino

## Features

- **Obstacle Detection**: Uses three ultrasonic sensors to detect obstacles in the left, center, and right directions.
- **Audio Alerts**: Plays pre-recorded warning sounds stored on an SD card using the DFPlayer Mini module.
- **Portable Power**: Powered by a battery for easy mobility.

## Setup

1. **Arduino Uno**: Connect the Arduino Uno to your computer and upload the provided code.
2. **Ultrasonic Sensors**: Connect the ultrasonic sensors to the Arduino as follows:
   - Center Sensor: Trigger Pin to D2, Echo Pin to D3
   - Left Sensor: Trigger Pin to D4, Echo Pin to D5
   - Right Sensor: Trigger Pin to D6, Echo Pin to D7
3. **DFPlayer Mini**: Connect the DFPlayer Mini to the Arduino:
   - TX Pin to D8
   - RX Pin to D9
4. **Speaker**: Connect the speaker to the DFPlayer Mini.
5. **Breadboard**: Use the breadboard to make necessary connections without soldering.
6. **Power Supply**: Connect the battery to the Arduino.
7. **SD Card**: Load the warning sound files onto the SD card and insert it into the DFPlayer Mini.

**See circuit.jpeg file for more details**

## Code

Upload the provided Arduino code to the Arduino Uno. The code will control the ultrasonic sensors and play the corresponding warning sounds when an obstacle is detected. The priority conditions to be checked first are:

1. Front and left
2. Front and right
3. Left and right
4. Front
5. Left
6. Right

Default distance:

1. Front = 110cm / 3,6 ft
2. Left = 90cm / 2,95 ft
3. Right = 90cm / 2,95 ft

Feel free to customize your own distance 😁

**(NOTE: You need to install DFPlayerMini_Fast library first to use the code)**

## Usage

Turn on the device by connecting the battery. The ultrasonic sensors will continuously monitor for obstacles and trigger the corresponding audio warning through the speaker when an obstacle is detected in any direction.

## Project Files

- **`robonetra.ino`**: The source code file.
- **`warninng sounds`**: Folder containing the warning sound files to be loaded onto the SD card (recommended to change with your own file).
- **`circuit.jpeg`**: Image of details robotic circuit

## Contact

For any questions or feedback, please contact rafiferanda11@gmail.com or @rafi_feranda at instagram.
