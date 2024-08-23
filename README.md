# Dreamscape Diorama: Real-Time Environmental Interactions

Welcome to the Dreamscape Diorama project! This project demonstrates how to create a real-time interactive diorama that uses environmental data to influence a virtual scene, combining Unity 3D and Pepper's Ghost illusion to create an immersive experience. This README provides step-by-step instructions on how to replicate this project.

## Table of Contents

1. [Overview](#overview)
2. [Project Setup](#project-setup)
3. [Hardware Requirements](#hardware-requirements)
4. [Software Requirements](#software-requirements)
5. [Step-by-Step Instructions](#step-by-step-instructions)
6. [Usage](#usage)
7. [Troubleshooting](#troubleshooting)
8. [Acknowledgements](#acknowledgements)

## Overview

The Dreamscape Diorama integrates real-time environmental data, such as noise levels and wind speed, to animate a diorama using Unity 3D and a Pepper's Ghost illusion setup. This project aims to provide an engaging and educational experience by visualizing environmental changes within a miniature world.

## Project Setup

To replicate this project, follow the steps below to set up both the hardware and software components. The project uses Unity 3D for creating the virtual environment and animations, and Arduino with MQTT for sensor data collection.

## Hardware Requirements

- **Tablet**: Samsung SE5 (Android-based) or any tablet that supports Unity 3D.
- **Pepper’s Ghost Setup**: Transparent surface, projector screen, or tablet for projection.
- **Sensors**: Microphone sensor for noise detection, wind speed sensor.
- **Microcontroller**: Arduino with WiFi capability (e.g., Arduino UNO with ESP8266).
- **Miscellaneous**: Connecting cables, power supplies, support frame for Pepper’s Ghost setup.

## Software Requirements

- **Unity 3D**: Version 2021 or later, with Android build support.
- **MQTT Server**: Any MQTT broker (e.g., Mosquitto) for data handling.
- **Arduino IDE**: For programming the microcontroller.
- **MQTT Libraries**: Install MQTT libraries for Unity and Arduino.

## Step-by-Step Instructions

### 1. Setting Up the Hardware

1. **Build the Pepper’s Ghost Setup**: Position a transparent surface at a 45-degree angle to the tablet or projector screen.
2. **Install Sensors**: Connect the microphone and wind speed sensors to the Arduino. Ensure the sensors are properly calibrated and tested.
3. **Connect to Arduino**: Upload the Arduino script provided in the `scripts/arduino/` directory to the Arduino using the Arduino IDE. Ensure WiFi settings are configured for MQTT communication.

### 2. Setting Up the Software

1. **Unity Project**: Clone the repository and open the Unity project located in the `UnityProject/` directory.
2. **Install MQTT Plugins**: Import the MQTT library into the Unity project. Configure the MQTT Manager and Controller scripts to match your MQTT broker settings.
3. **Scene Setup**: Open the Unity scene file and configure the environment with the appropriate assets. Assign the `mqttControllerSheep` and `mqttWindspeed` scripts to relevant GameObjects.
4. **Animation and Interaction**: Adjust the animation settings to correspond with sensor data inputs. Ensure colliders and rigid bodies are correctly set up for interaction.

### 3. Running the Project

1. **Build and Deploy**: Use Unity’s build settings to deploy the project to the Android tablet. Connect the tablet to the Pepper’s Ghost setup.
2. **Start MQTT Server**: Run your MQTT broker and ensure it is configured to handle incoming data from the Arduino.
3. **Test and Calibrate**: Once deployed, test the diorama by creating different noise levels and wind speeds. Adjust sensor sensitivity and animation parameters as necessary.

## Usage

- **Interactive Mode**: The diorama responds to real-time environmental data. Adjust noise levels and observe how the sheep models react. Vary wind speed to see changes in animation speed for environmental objects like trees and fog.
- **Educational Mode**: Use the diorama to demonstrate the impact of environmental changes visually.

## Troubleshooting

- **No Animation Response**: Check the MQTT connection and ensure the tablet is properly receiving data.
- **Pepper's Ghost Illusion Not Clear**: Adjust the angle and distance of the screen and transparent surface for better projection.
  ![image](https://github.com/user-attachments/assets/845a61ca-a711-4fe4-bd86-c66b15c894a2)

- **Sensors Not Responding**: Verify sensor connections and calibration. Check the Arduino script for correct sensor handling.

## Acknowledgements

The grammar and language refinement, as well as modifications to the Unity scripts, were partially assisted by ChatGPT-4, an AI language model developed by OpenAI. This tool was instrumental in enhancing the clarity of the writing structure and improving the accuracy of code implementation.
