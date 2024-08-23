# Dreamscape Diorama: Real-Time Environmental Interactions

Welcome to the Dreamscape Diorama project! This project demonstrates how to create a real-time interactive diorama that uses environmental data to influence a virtual scene, combining Unity 3D and Pepper's Ghost illusion to create an immersive experience. This README provides step-by-step instructions on how to replicate this project.

![ee8beffe181d4947589bfbc6c4839c3](https://github.com/user-attachments/assets/e2feec03-0103-46b5-9976-178515e62833)


## Introduction
The Dreamscape Diorama project seeks to bridge the gap between environmental awareness and public engagement through the innovative use of digital technology. By integrating real-time environmental data, such as noise levels and wind speed, with visual storytelling techniques, this project creates a miniature world that responds dynamically to its surroundings. Utilizing Unity 3D and the Pepper's Ghost illusion, the diorama offers an immersive experience where digital elements seamlessly interact with physical space. The primary goal of the project is to captivate and educate audiences about the impacts of environmental changes, making complex data more relatable and engaging through visual representation.

***Project Inspiration**:
![29b10a9654d06cf5f70c308eb30aa5f](https://github.com/user-attachments/assets/14ad4461-1b00-4dd6-9814-dcba53728564)

### The inspiration for the Dreamscape Diorama comes from the serene and picturesque landscapes of Grindelwald, Switzerland. Known for its peaceful integration of natural beauty and human elements, Grindelwald provides a perfect backdrop for exploring the relationship between people and their environment. This project aims to evoke similar feelings of tranquility and reflection, encouraging viewers to consider their impact on the natural world. By combining elements of fantasy with cutting-edge technology, the diorama not only showcases the beauty of these landscapes but also highlights the importance of environmental awareness and stewardship.

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

**Project Principle**
![Pepper's ghost](https://github.com/user-attachments/assets/0981c581-7fcc-465d-a519-4be92a3e0f1d)

![579d8027449eb49a2be21d5f1fe6a63](https://github.com/user-attachments/assets/85ecb804-9546-4c57-822b-1c1f771edf33)



## Hardware Requirements

- **Tablet**: Samsung SE5 (Android-based) or any tablet that supports Unity 3D.
- **Pepper’s Ghost Setup**: Transparent surface, projector screen, or tablet for projection.
- **Sensors**: Microphone sensor for noise detection, wind speed sensor
- **Microcontroller**: Arduino with WiFi capability (e.g., Arduino UNO with ESP8266).
- **Miscellaneous**: Connecting cables, power supplies, support frame for Pepper’s Ghost setup.

![Microphone_worked ](https://github.com/user-attachments/assets/f670625e-8f0f-40ee-89b0-243945d33bf3)

## Software Requirements

- **Unity 3D**: Version 2021 or later, with Android build support.
- **MQTT Server**: Any MQTT broker (e.g., Mosquitto) for data handling.
- **Arduino IDE**: For programming the microcontroller.
- **MQTT Libraries**: Install MQTT libraries for Unity and Arduino.
- **Download or build Models**:  Depending on the screen size you decide to use.

![Screenshot 2024-08-06 134959](https://github.com/user-attachments/assets/3a94df84-c2ee-48f1-b1da-d3bf0a631473)
Grindelwald's hill Representation: ![Screenshot 2024-08-06 134959](https://github.com/user-attachments/assets/c93e5df2-043b-44c5-9df5-85a8f74cdf2a)

## Step-by-Step Instructions

### 1. Setting Up the Hardware

1. **Build the Pepper’s Ghost Setup**: Position a transparent surface at a 45-degree angle to the tablet or projector screen.

   ![579d8027449eb49a2be21d5f1fe6a63](https://github.com/user-attachments/assets/9a4052a5-6745-4301-8ac7-eea4349b00a0)

2. **Install Sensors**: Connect the microphone and wind speed sensors to the Arduino. Ensure the sensors are properly calibrated and tested.
   
3. **Connect to Arduino**: Upload the Arduino script provided in the `scripts/arduino/` directory to the Arduino using the Arduino IDE. Ensure WiFi settings are configured for MQTT communication.

### 2. Setting Up the Software

1. **Unity Project**: Clone the repository and open the Unity project located in the `UnityProject/` directory.
2. **Install MQTT Plugins**: Import the MQTT library into the Unity project. Configure the MQTT Manager and Controller scripts to match your MQTT broker settings.
3. **Scene Setup**: Open the Unity scene file and configure the environment with the appropriate assets. Assign the `mqttControllerSheep` and `mqttWindspeed` scripts to relevant GameObjects.
4. **Animation and Interaction**: Adjust the animation settings to correspond with sensor data inputs. Ensure colliders and rigid bodies are correctly set up for interaction.
5. **Code Editor** Such as Visual Studio Code or Android Studio
   ![mqtt controller with animator](https://github.com/user-attachments/assets/56d446a7-7e9c-47e8-9304-d17ee1ef4b8c)


### 3. Running the Project

1. **Build and Deploy**: Use Unity’s build settings to deploy the project to the Android tablet. Connect the tablet to the Pepper’s Ghost setup.
2. **Start MQTT Server**: Run your MQTT broker and ensure it is configured to handle incoming data from the Arduino.
3. **Test and Calibrate**: Once deployed, test the diorama by creating different noise levels and wind speeds. Adjust sensor sensitivity and animation parameters as necessary.
   ![bugs occured having sheeps walk together](https://github.com/user-attachments/assets/56b1e452-de95-4f03-9eeb-537af99d2bb1)


![noise mqtt reads](https://github.com/user-attachments/assets/ca4b0ca9-9f21-4a1f-99f5-4458fe869abb)

## Usage

- **Interactive Mode**: The diorama responds to real-time environmental data. Adjust noise levels and observe how the sheep models react. Vary wind speed to see changes in animation speed for environmental objects like trees and fog.
- **Educational Mode**: Use the diorama to demonstrate the impact of environmental changes visually.

## Troubleshooting

- **No Animation Response**: Check the MQTT connection and ensure the tablet is properly receiving data.
- **Pepper's Ghost Illusion Not Clear**: Adjust the angle and distance of the screen and transparent surface for better projection.
  ![image](https://github.com/user-attachments/assets/845a61ca-a711-4fe4-bd86-c66b15c894a2)

- **Sensors Not Responding**: Verify sensor connections and calibration. Check the Arduino script for correct sensor handling.

## Design Progress and Development**:
![cfba3fa03ea0b06dbc802cc9525ecfd](https://github.com/user-attachments/assets/0f58074e-a4cb-4892-a096-f69950395453)

![5541cdb02f3b44c7ec09f3e547b873a](https://github.com/user-attachments/assets/0ad9dcfb-191f-4b79-8dcb-275d2dc5551f)

![9089ad118fe060a24fe77242912a18f](https://github.com/user-attachments/assets/541cc48e-4280-47cd-a525-d6e0736fca21)


![332dca165835e967ee2c40a63e745e9](https://github.com/user-attachments/assets/3355759d-c22c-4a58-8e7f-6b900315fc7c)


![8664eb9bcb3b2702cd1177790cec0b0](https://github.com/user-attachments/assets/0300aba2-2aa1-43e0-a03e-6d09b3c744a9)

![7dcbb4b6bc19a4fb43959181fc05c72](https://github.com/user-attachments/assets/db89c5fd-7676-44a5-80f7-bdebd4e7be11)

### Limitations

While the *Dreamscape Diorama* project successfully demonstrates the potential of integrating real-time environmental data with visual storytelling, several limitations need to be acknowledged. 

1. **Sensor Sensitivity and Data Accuracy**: The accuracy of the real-time environmental data is highly dependent on the quality and placement of sensors. Inconsistent sensor readings due to external factors, such as changes in temperature or interference, can affect the diorama’s responsiveness and the authenticity of the visual experience.

2. **Pepper's Ghost Illusion Constraints**: The effectiveness of the Pepper's Ghost illusion is limited by the physical setup, including the angle and placement of the transparent surface. Any misalignment can lead to a less convincing illusion, reducing the overall impact of the installation. Additionally, the illusion’s effectiveness is compromised in environments with excessive ambient light or reflective surfaces.

3. **Hardware Limitations**: The use of a tablet, specifically the Samsung SE5, introduces potential risks related to overheating and battery life when used for extended periods. While developer mode helps maintain operation, it is not an ideal long-term solution for public exhibitions.

4. **Scalability**: The current setup is designed for small-scale, controlled environments. Scaling up to larger spaces or more complex scenarios may require additional sensors, more powerful hardware, and advanced software integration, which could increase complexity and cost.

### Future Directions

To further enhance the *Dreamscape Diorama* and address these limitations, several improvements could be made:

1. **Advanced Sensors**: Incorporating more advanced sensors to monitor additional environmental variables, such as air quality, humidity, or temperature, could provide a richer interactive experience. These enhancements would make the diorama more lifelike and capable of demonstrating a wider range of environmental impacts.

2. **Improved Integration**: Future iterations could explore the use of 3D mapping and projection techniques to blur the boundaries between the digital and physical worlds even further. This would enhance the immersive experience and minimize the visibility of the display edges.

3. **Physical Model Enhancements**: Introducing mechanical components to the physical model that interact with the digital scene could create a more dynamic and engaging installation. This might include elements that move in response to data, further blurring the line between the virtual and physical.

4. **Hardware Optimization**: Transitioning from tablet-based displays to more robust, dedicated hardware such as OLED screens could improve stability, reduce the risk of hardware failure, and offer better integration with software components. 

5. **Expanded Thematic Content**: Adding culturally relevant elements that align with the theme of the diorama could deepen audience engagement. For example, incorporating narrative elements that tell specific historical or cultural stories would provide a richer context and enhance the emotional connection with the audience.

By addressing these limitations and exploring new directions, the *Dreamscape Diorama* can evolve into a more robust tool for environmental education and public engagement, providing meaningful insights into the relationship between humans and their environment.

## References
Spectral Illusions: The Pepper’s Ghost Effect and How It Works. (2022). Art of Play. Available at: https://www.artofplay.com/blogs/stories/spectral-illusions-the-peppers-ghost-effect-and-how-it-works (Accessed: 23 August 2024).

Choudhary, R., Lee, H., Sundar, S. S., and Bailey, B. P. (2017) 'Understanding the Role of Interaction in Multimodal Displays: A Case Study of the Pepper’s Ghost Illusion', Proceedings of the 19th ACM International Conference on Multimodal Interaction, ICMI '17, pp. 249-253. Available at: https://dl.acm.org/doi/abs/10.1145/3126594.3126602 (Accessed: 23 August 2024).

Kainos Software Ltd (n.d.) Peppers Ghost Pyramid. GitHub. Available at: https://github.com/KainosSoftwareLtd/PeppersGhostPyramid?tab=readme-ov-file (Accessed: 23 August 2024).

Various documents and files downloaded for research and reference were used in the development of this project. These included technical specifications, software documentation, and scholarly articles, which provided essential information on integrating real-time data with visual effects and using Pepper’s Ghost illusion in interactive displays.

## Acknowledgements

The grammar and language refinement, as well as modifications to the Unity scripts, were partially assisted by ChatGPT-4, an AI language model developed by OpenAI. This tool was instrumental in enhancing the clarity of the writing structure and improving the accuracy of code implementation.
