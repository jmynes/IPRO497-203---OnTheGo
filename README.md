# IPRO497-203---OnTheGo
OnTheGo(OTG) - Control Panel for Modular Home

## Team
### Illinois Institute of Technology
#### IPRO 497-203 Robotics Independent Projects

1. [Jordan Mynes](http://mynes.me)
2. Joshua Mac-Williams
3. Ludin Castillo
4. James "Tucker" Arnold  

## Tech Specs
* 1x Arduino Uno
  * USB-A Cable
* Laptop running Antergos Linux/Windows 10
  * Arduino software
  * NodeJS
* 1x JY-MCU Linvor v1.8 Bluetooth Module
  * 4 pins/wires
* 1x Micto Servo 9g - SG90
  * Ideally this should be externally powered, we have not set that 
up yet.

### Tech to test
* LED
  * Single color (Red, Blue, etc)
  * RGB
* More to come...

### Setup
* git clone
* npm install
* Match Arduino Uno & Breadboard to fritzing diagram
* DO NOT use the Arduino IDE from the Arch Linux Repos (Or probably
any repo)
  * It throws an error when trying to upload StandardFirmataPlus 
for
Johnny-Five. For whatever reason, it claims that the Servo.h library
wasn't found. Instead, [Compile from source, or run the binary exe if
you're on Windows](https://www.arduino.cc/en/Main/Software)
* From Arduino IDE:
  * Upload
  * Sketch > Include Library > Manage Libraries
  * Search for and install Firmata by Firmata Developers (2.5.7)
  * Restart Arduino IDE
  * Upload arduino/OTGIPRO497-203-Bluetooth.ino to Arduino Uno
    * Test connection between JY-MCU Linvor 1.8 Bluetooth Module & Android device
      * Text between starting config & done does not reliably show up in any
one location, if at all
      * Bluetooth Terminal app should be able to send to serial monitor @ 9600 BAUD
  * If successful, upload 
arduino/standardFirmataPlus/standardFirmataPlus.ino to Arduino board

* Johnny-Five scripts (only one can be running at a time, don't 
have IDE occupying port)
* Run node node/board-with-port.js
  * Celebrate as your LED now blinks repeatedly!
* Run node node/server-prompt.js
  * Sets position to 90 by default. Issue a command 0-180 to move 
the servo to that position
    * Slight jitter, works better on 5v despite higher jitter
      * [StackOverflow 
suggestions](https://electronics.stackexchange.com/questions/77502/is-there-a-way-to-stop-servos-from-shaking)
    * Worst jitter at 0, rests ok at 10, 90, 170-180 

## Resources
1. [JY-MCU Bluetooth code skeleton for Arduino](https://github.com/rwaldron/johnny-five/wiki/Getting-Started-with-Johnny-Five-and-JY-MCU-Bluetooth-Serial-Port-Module)
2. [Communication over terminal with Arduino/Bluetooth](https://www.tautvidas.com/blog/2015/12/easy-arduino-bluetooth-communication-with-jy-mcu/)
3. [JY-MCU part file for Fritzing](https://github.com/RafaGS/Fritzing/blob/master/Bluetooth%20HC-06.fzpz)
4. [Johnny Five JS Controller for Arduino LED Test](https://github.com/rwaldron/johnny-five/blob/master/docs/board-with-port.md
  * And more code samples from the same repo
5. [StandardFirmata 
Plus](https://github.com/firmata/arduino/blob/master/examples/StandardFirmataPlus/StandardFirmataPlus.ino)
6. [Arduino IDE](https://www.arduino.cc/en/Main/Software)
7. 
[Blynk 
Library 
Download 
& 
Install](http://help.blynk.cc/getting-started-library-auth-token-code-examples/how-to-install-blynk-library-for-arduino)
