# OnTheGo(OTG) - Control Panel for Modular Home

## Team
### Illinois Institute of Technology
#### IPRO 497-203 Robotics Independent Projects

1. [Jordan Mynes](http://mynes.me)
2. Joshua Mac-Williams
3. Ludin Castillo
4. James "Tucker" Arnold  

## Tech Specs
* 1x Arduino MKR 1000 (WiFi Enabled)
  * USB-A Cable
* Laptop running Antergos Linux/Windows 10
  * Arduino software
* 1x Micro Servo 9g - SG90
  * Ideally this should be externally powered, we have not set that up yet. We could also use the VIN port on the Arduino, but have yet to explore that route fully.
* LEDs
* NFC tags
* Android phone with:
  * Blynk
  * Tasker
    * [RESTask plugin](https://play.google.com/store/apps/details?id=com.freehaha.restask&hl=en)
  * Trigger

### Setup
* git clone
* Match Arduino MKR 1000 & Breadboard to fritzing diagram
* Arduino IDE Setup:
  * Tools > Boards > Manage Boards
    * Install Arduino SAMD Boards, for our mkr1000
  * Sketch > Include Library > Manage Libraries
    * Search for and install wifi101 library
    * Manually install Blynk library
  * Restart Arduino IDE
* If above steps are all successful, upload arduino/blynk.io
  * If it claims that the Blynk, Servo, or any other library wasn't found, then [compile from source, or run the binary exe if you're on Windows](https://www.arduino.cc/en/Main/Software)

## Script
* Moving servos between 0 and 90 in a binary configuration is surprisingly rough.
  * Slight jitter, works better on 5v despite higher jitter
    * [StackOverflow
suggestions](https://electronics.stackexchange.com/questions/77502/is-there-a-way-to-stop-servos-from-shaking)
    * Worst jitter at 0, rests ok at 10, 90, 170-180

## Resources
1. [Communication over terminal with Arduino/Bluetooth](https://www.tautvidas.com/blog/2015/12/easy-arduino-bluetooth-communication-with-jy-mcu/)
2. [JY-MCU part file for Fritzing](https://github.com/RafaGS/Fritzing/blob/master/Bluetooth%20HC-06.fzpz)
3. [Arduino IDE](https://www.arduino.cc/en/Main/Software)
