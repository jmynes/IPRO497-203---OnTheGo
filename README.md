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
* Arduino Uno
  * USB-A Cable
* Laptop running Antergos Linux/Windows 10
  * Arduino software
  * NodeJS
* JY-MCU Linvor v1.8 Bluetooth Module
  * 4 pins/wires

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
  * It throws an error when trying to upload StandardFirmata for
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
  * If successful, upload arduino/standardFirmata/standardFirmata.ino to board
* Run node node/board-with-port.js
* Celebrate as your LED now blinks repeatedly!

## Resources
1. [JY-MCU Bluetooth code skeleton for Arduino](https://github.com/rwaldron/johnny-five/wiki/Getting-Started-with-Johnny-Five-and-JY-MCU-Bluetooth-Serial-Port-Module)
2. [Communication over terminal with Arduino/Bluetooth](https://www.tautvidas.com/blog/2015/12/easy-arduino-bluetooth-communication-with-jy-mcu/)
3. [JY-MCU part file for Fritzing](https://github.com/RafaGS/Fritzing/blob/master/Bluetooth%20HC-06.fzpz)
4. [Johnny Five JS Controller for Arduino LED Test](https://github.com/rwaldron/johnny-five/blob/master/docs/board-with-port.md
