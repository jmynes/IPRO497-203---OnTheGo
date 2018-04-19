# OnTheGo(OTG) - Control Panel for Modular Home

## Team
### Illinois Institute of Technology
#### IPRO 497-203 Robotics Independent Projects

1. [Jordan Mynes](http://mynes.me)
2. Joshua Mac-Williams
3. Ludin Castillo
4. James "Tucker" Arnold  

## Diagrams and Screenshots
![Fritzing Diagram](https://raw.githubusercontent.com/jmynes/IPRO497-203---OnTheGo/master/pics-and-screenshots/fritzingDiagram.png)
![Mobile Screenshot](https://raw.githubusercontent.com/jmynes/IPRO497-203---OnTheGo/master/pics-and-screenshots/mobileConnected.png)

## Tech Specs
* 1x Arduino MKR 1000 (WiFi Enabled)
  * USB-A Cable
* Laptop running Antergos Linux/Windows 10
  * Arduino software
* 1x Micro Servo 9g - SG90
  * Ideally this should be externally powered, we have not set that up yet. We could also use the VIN port on the Arduino, but have yet to explore that route fully.
* LEDs
* [Rewriteable NFC tags](https://www.amazon.com/dp/B00XYVU24G/ref=sspa_dk_detail_6?pd_rd_i=B076B86LWF&pd_rd_wg=joLMI&pd_rd_r=9JGYQP20VXAVRSN1WYPX&pd_rd_w=HmI7w&th=1)
* Android phone with:
  * [Trigger - Task Launcher](https://play.google.com/store/apps/details?id=com.jwsoft.nfcactionlauncher&hl=en)
  * [Tasker](https://play.google.com/store/apps/details?id=net.dinglisch.android.taskerm)
    * [RESTask
    plugin](https://play.google.com/store/apps/details?id=com.freehaha.restask&hl=en)
  * [Blynk](https://play.google.com/store/apps/details?id=cc.blynk)

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

### Communication
* Android phone (in our case, a Gen 1 Google Pixel XL running Android 8.1)
  * Installed the following apps from the Tech Specs section of this README
* [This tutorial will show how to trigger a tasker function](https://community.blynk.cc/t/tutorial-blynk-and-tasker/5063)
  * It's basically a simple API request with a value sent to a digital or
  virtual pin, interpreted by Blynk (over HTTP, sadly), and the rest is as
  README follows.

#### Our Stack
1. If NFC tag is tapped on our display
  * Trigger runs a related Tasker task
    * HTTP auth'd RESTful call to Blynk's server, a pin and a parameter
  * Blynk's server forwards the task to our Arduino over the Internet
    * Arduino MKR 1000 receives task over WiFi (in our case, using the same Pixel XL's hotspot to get around school network authentication)
  * Arduino tells LED/Servo(s) to do task
2. Instead, we can also use a graphical control panel with the Blynk app
  * Click the digital control labeled for a specific LED/Servo(s)

## Problems
* Moving servos between 0 and 90 in a binary configuration is surprisingly rough.
  * Slight jitter, works better on 5v despite higher jitter
    * [StackOverflow
suggestions](https://electronics.stackexchange.com/questions/77502/is-there-a-way-to-stop-servos-from-shaking)
    * Worst jitter at 0, rests ok at 10, 90, 170-180
* We wasted **a lot** of time trying to make this work with Bluetooth. In the interest of that time spent, the abandoned Bluetooth branch is preserved for archival purposes.

## Resources
1. [Communication over terminal with Arduino/Bluetooth](https://www.tautvidas.com/blog/2015/12/easy-arduino-bluetooth-communication-with-jy-mcu/)
2. [Arduino MKR 1000 Fritzing Part](http://forum.fritzing.org/uploads/default/original/2X/4/4b1a613c74f767e53dbd82fd8be1ea16f0981033.fzpz)
  * Or read [this thread](http://forum.fritzing.org/t/mkr1000-fritzing-part/1408/11), we used the version from the final post
3. [Arduino IDE](https://www.arduino.cc/en/Main/Software)
4. [Blynk initial setup code](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LED/LED_Blink/LED_Blink.ino)
5. [Blynk integration with Tasker](https://community.blynk.cc/t/tutorial-blynk-and-tasker/5063)
