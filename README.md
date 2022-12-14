# Autonomous-Plant-Watering-System

In this project, the soil watering process is programmed to occur in an event wherein the soil bearing the plant is nearly completely void of moisture. Correspondingly, my methodology toward undertaking the challenge of automated plant watering involved 8 crucial components. These components functioned interconnectedly to bring about the complete functionality of the system and comprised of A capacitive soil moisture sensing module, 2 DC water pump modules, 1 with an interconnected potentiometer module, an 8 (four Reds and four Greens) LED display module connected with a shift register, a water sensing module, a PIR sensing module with a corresponding LED notification system, a temperature sensing module and an LCD display module. The resultant functionality created the automatic plant watering system and is described as follows. On sensing an abnormal soil moisture level, the device will cause the water to be pumped from a buffer tank via the first DC motor, followed by the tank’s replenishing, upon the water contained in it, going below a specific low point. Moreover, the temperature being constantly sensed is displayed along with the watering status and soil moisture levels, along with the presence of an obstacle, blocking the source of natural light. An option to manually override the watering system is also provided to the operator via a push button.

## Build View of the Constructed System

Following is a photograph of the complete physical circuit build, depicting the connections between all the modules involved.

![WhatsApp Image 2022-08-09 at 8 58 32 AM](https://user-images.githubusercontent.com/111105406/184284946-4c5b1228-4e6a-4f9d-accb-5391b3c10f23.jpeg)

## Planned Model of the Constructed System

Here is a pictorial depiction of the manner in which the circuitry must be set up, in order to get it to operate as intended.

<img width="671" alt="finalprojsketch" src="https://user-images.githubusercontent.com/111105406/184285684-bd8f0a17-0699-40a5-9620-f5a6bb64eb96.png">

# Build Instructions

## Block Diagram - Inputs & Outputs

Following is a block diagram indicative of the various modules integrated into the circuitry and the manner in which the flow of information takes place. With the help of this the operator can comprehend the connection of the components.

<img width="614" alt="bdfnl" src="https://user-images.githubusercontent.com/111105406/184285815-6a056f92-52e3-4f10-b9ca-7b3398aa7d59.png">

## Circuit View

In order to further understand the circuit assembly, here's a circuit view sketched in TinkerCAD, that details the connections of all the vital components in a neat and comprehensive manner. Following this circuit design, one could build the same circuitry, and even enhance the same, for better results. Note, the basic circuitry must be built in accordance with the design as shown below. Upon successfully building and coding the basic design, the designer may then feel free to modify the circuit as per their preferences. 

Now, the entire circuitry is assembled on a breadboard with the use of jumper wires to establish the various connections as seen in the diagrams below. using a breadboard is always advisable, especially if the components you are working with are volatile, or in the event that you might want to develop yet another prototype before deploying the final circuit build.

On a precautionary note, the LCD 16 X 2 I2C display must be handled with utmost care, especially the I2C integrated board, since these tend to severely malfunction on incurring the slightest of damages.

![d11](https://user-images.githubusercontent.com/111105406/184286683-7591d19e-a226-4d63-9394-edc2a6301298.png)

<img width="424" alt="ds1" src="https://user-images.githubusercontent.com/111105406/184288563-ff87433b-e326-4292-aeb8-ec15d8da5280.png">

<img width="425" alt="ds2" src="https://user-images.githubusercontent.com/111105406/184288573-83e4e929-c74b-43ad-969d-cf221525ee90.png">

# Repository Contents

Here is a map of all the top-level contents listed in the repository:

1. /Images - Here is where the image files for this readme are.
2. /src - Here is where you can see all the coding stuff (.ino).
3. /README.md - Here is the file you're reading now! 

# Requirements and Materials

Libraries required for the project are
1. <Adafruit_LiquidCrystal.h> LIBRARY : (https://github.com/adafruit/Adafruit_LiquidCrystal).
This library is functional in enableing the interfacing of the I2C board on the 16 X 2 LCD display.

The materials required for this project are as follows.:

  • 1 Arduino Uno R3
  
  • 2 DC Motor pumps
  
  • 9 10k ohms resistors
  
  • 2 550 ohms resistors
  
  • 1 Push button
  
  • 1 Temperature Sensor LM35 
  
  • 1 Shift Register 74HC595
  
  • 1 250 k ohms potentiometer
  
  • 1 16 X 2 LCD Display
  
  • 4 Green LEDs
  
  • 5 Red LEDs
  
  • 2 NPN BJT transistors
  
  • 1 PIR sensor
  
  • 1 Water level sensor
  
  • 1 Capacitive Soil Sensor
  
  • 1 Piezo
  
  • 2 Diodes
  
  • Jumper wires

# Installing Arduino Software

1. You can download the IDE from here : (https://www.arduino.cc/en/main/software).

2. After you install the IDE click here to learn more about it : (https://www.arduino.cc/en/Guide/HomePage).

# Usage

1. Connect the various components of the system, in the manner as pictorially represented in the sketch above. Note,have 2 water resources, a smaller buffer container wherein you should insert the soil watering motor pump (connected with the green wire) and the water sensor as well. Another larger container or an external tank is to be used as the secondary water source, wherein you should place the tank refilling motorpump (connected with the purple wire). The potted plant is to be placed in close vicinity of the setup box, with the soil moisture sensor and the soil watering pipe fitted in the soil.

2. Connect the automated plant watering system to an AC power outlet and verify if the integrated 16 X 2 LCD display has commenced showing the temperature values and the soil moisture values subsequently.

3. Now, at first, if the soil moisture sensor is not inserted into the soil, or if the soil surrounding it is dry, the same should reflect on the LCD screen. Check if the LCD display is showing a value lesser than the programmed dryness value, 270, as the current Moisture level. In such a scenario, verify if the soil watering motor pump has started pumping water.

4. Check the buffer tank water levels and verify if these levels correspond with the LED display array’s lights. If the tank is empty, check to see whether the tank refilling pump has started pumping water from the secondary water resource.

5. Now, check to see whether the Soil water pump varies its speed upon turning the potentiometer both clock wise and anticlockwise. Furthermore, Upon the soil water pump completing its automated watering cycle, listen for a melody from the integrated speaker.

6. Check if the manual overriding option is functioning by clicking the blue push button. Upon clicking it, the pump should pump water for 5 seconds and then stop. Here, however, no melody would be played, as, you are manually overriding the system.

7. Check to see if the motion sensor, is functioning as intended, by placing it near the supposed light source, from which the plant would carry out its photosynthesis routine. Place an object in front of the PIR sensor and verify if the red LED starts glowing, indicating the presence of an obstacle.

# Contributors
### Clayton Dsouza 
- I completed this project by myself. I am the sole contributor to the construction and the working of this project. Contact me at @ claytonboss80@gmail.com

# Credits
### Trevor Michael Tomesh (Course Instructor)
- Advice and technical guidance with regards to critical decisions in the construction of the project.
