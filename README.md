# embeddedsystems-SS21
This is the git repository for the embedded systems lab typing challenge game

We are using a Display Watterott MI0283QT-2 (mounted on microSD Shield Watterott) for the letter sewuence and to display the result of the player as well. The letters will be displayed on the screen for a period of time which can be changed. They will then disappear and the player would have to remember the letters from memory and type them to win.

The arduino is connected to a USB type-A female connector which will be connected to a standard USB keyboard.

The Display is mouted on the m-SD shield which is mounted on the arduino uno board. The Analog inputs for the display will be disconnected and the USB input will replace the touch display.

![image](https://user-images.githubusercontent.com/40824378/120810953-c992eb00-c54b-11eb-8ae2-56887580077d.png)
- (image source: https://learn.watterott.com/de/shields/msd-shield/)

![image](https://user-images.githubusercontent.com/40824378/120813573-4d4dd700-c54e-11eb-912a-38449002e8d7.png)


### Parts Needed:
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
Download the "Required-libraries" zip file and extract the libraries.
Add the libraries.
Upload the code to the Arduino Uno board.

### Libraries used:
Libraries used are in the libraries folder. These are:-
- <MI0283QT2.h>
- <PS2Keyboard.h>
- GraphicsLib
- digitalWriteFast


### Game explanation:
There are 6 functions
- void setup()
- void loop()
- void loop2()
- void loop3()
- void startgame1()
- void startgame2()

The following is the general flow of instruction is the game
![image](https://user-images.githubusercontent.com/40824378/127754362-1aef2a9d-9d94-4809-8bc7-b12b6d38bf74.png)

#### Variables:
We define a few variables in the beginning. These are 
- score (int)
- DataPin (int)
- IRQpin (int)
- wordlimit (int)
- letters[26] (String)
- alphanumeric[36] (String)
- randNumber (int)
- current (String)
- input (char)

### Code Explanation:
The player begins the game at the home screen. He or she has three options. He can either start the game by selecting 1, or he can get information by selecting 2 (About information) or 3 (Game instructions).
If he chooses 1, he is taken to another screen where he can select one of the two levels.
Upon selecting a level, his game for that specific level begins. He is shown a string of characters and then they disappear. He has to memorize and enter the characters correctly in the given time. Failure to do so will exit his game and bring him to the home screen
If he enters the letters correctly, he is congratulated and his score is shown. He can then either opt to play the game again and add up to his score, or he can quit to the home screen.
If he has marked some of the letters correctly and then makes a mistake, he is shown a Game Over screen with his current score and taken to the home screen. His score counter is the reset.
If the player opts to finish his game after winning, his score counter is again reset to zero so he can start again from the same level or the more difficult level.
