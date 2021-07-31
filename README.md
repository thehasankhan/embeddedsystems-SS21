# embeddedsystems-SS21
This is the git repository for the embedded systems lab typing challenge game

We are using a Display Watterott MI0283QT-2 (mounted on microSD Shield Watterott) for the letter sewuence and to display the result of the player as well. The letters will be displayed on the screen for a period of time which can be changed. They will then disappear and the player would have to remember the letters from memory and type them to win.

The arduino is connected to a USB type-A female connector which will be connected to a standard USB keyboard.

The Display is mouted on the m-SD shield which is mounted on the arduino uno board. The Analog inputs for the display will be disconnected and the USB input will replace the touch display.

![image](https://user-images.githubusercontent.com/40824378/120810953-c992eb00-c54b-11eb-8ae2-56887580077d.png)
- (image source: https://learn.watterott.com/de/shields/msd-shield/)

![image](https://user-images.githubusercontent.com/40824378/120813573-4d4dd700-c54e-11eb-912a-38449002e8d7.png)


###Parts Needed:
- (1x) Arduino Uno
- (2x) Display Watterott MI0283QT-2 [1x extra in case of failover]
- (2x) microSD Shield Watterott [1x extra in case of failover]
~~- (8x) 1.5V AA Batteries~~ Takes power directly from the USB port
- (10x) cut wires for connections
- (2x) USB type-A connectors (female) [1x extra in case of failover]
- (1x) Standard USB keyboard
~~- (5x) 220 Ohms resistors~~ No need for additional resistances
- (1x) Arduino to USB connector cable
~~- (2x) Switch or push button [1x extra in case of failover]~~ Takes power directly from USB port
- (4x) Standard red LED (for connection troubleshooting)
- (1x) Breadboard



### Group Participants:
- Muhammad Hasan Khan
- Ramsha Munir

### Installation instructions
Just download the typing-challenge.ino file and open it in the arduino IDE. It will ask you to create a folder named "typing-challenge" (if using the windows client). Create the folder and this will launch in the IDE. 
Add the needed libraries.
Upload the code to the Arduino Uno board.

### Libraries used:
Libraries used are in the libraries folder. These are:-
- <MI0283QT2.h>
- <PS2Keyboard.h>
- <GraphicsLib>
- <digitalWriteFast>


### Game code explanation:
