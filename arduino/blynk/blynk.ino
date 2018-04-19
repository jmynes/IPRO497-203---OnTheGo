/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how to use the Menu Widget.

  App project setup:
    Menu widget attached to V1 (put 3 items in it)
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT SerialUSB


#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleWiFiShield101.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e03b7e93390b467b97a498e1312fa148";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "krustyt";
char pass[] = "krabpizza";

Servo servo;
int ledCount = 4;

// Takes a pin
void servoCMD (int pin) {
  int count = 0;
  Serial.print(pin);

  servo.attach(pin);
  int toggle = servo.read();
  servo.detach();

  if (toggle == 0) {  // Servo Down
  SerialUSB.println("Servo moved to resting position");

  // Band-aid fix to Servo for some reason needing same command twice
  // Even as a bandaid fix, this should really be a function for DRY code.
    while(count < 2) {
      servo.attach(pin); // Connect Servo pin 10
      delay(400);          // Wait a bit
      servo.write(90);  // Servo rotates to down position (not fully certain why that's 90 in our case...)
      servo.detach();   // Take a nap, servo. We wouldn't want you to overheat for a model.

      count = count +1;
    }
  }
  else {  // Servo Up
    SerialUSB.println("Servo moved to standing position");

    // Band-aid fix to Servo for some reason needing same command twice
    while(count < 2) {   
      servo.attach(10); // Repeat above but inverse position
      delay(400);
      servo.write(0);
      servo.detach();

      count = count +1;
    }
  }
}

/*
 * Takes a pin, & Universal On/Off (2 or 3) Override for LED control
 * V99 is used for universal LED commands
 * 
 * The int toggle starts at the state (0 or 1) of the called pin.
 * If the pin is on, the command turns the pin off, and vice versa.
 */
void ledCMD(int pin, int universalOverride)
{
  int toggle = digitalRead(pin);
  int count = 0;

  /* 
   * We used the Analog pins for our LEDs mostly because of wiring space. 
   * Because of this, it's difficult to iterate over the Analog pins, so here's a
   * array of A1-A4. I would like to find a different solution to this so I can just
   * utilize the global variable ledCount.
   */
  static const uint8_t analog_pins[] = {A1,A2,A3,A4};

  if (universalOverride == 2) {
    while (count < ledCount) {
      digitalWrite(analog_pins[count], HIGH);
      count = count +1;
    }
  }
  else if (universalOverride == 3) {
    while (count < ledCount) {
      digitalWrite(analog_pins[count], LOW);
      count = count +1;
    }
  }
  else {
    if (toggle == 0) {
      Serial.println(" LED: On");
      digitalWrite(pin, HIGH);
    }
    else {
      Serial.println(" LED: Off");
      digitalWrite(pin, LOW);
    }
  }
}

/*
   This function has a couple purposes. From Blynk's app, 
   we have a dropdown menu that if switched to V0, turns
   this into a full Servo control panel. However, that isn't very good UX.
  
   We also have a series of NFC tags that interface with this as a 
   master virtual pin for our Servos. This probably is not the best solution as it 
   makes it difficult to do multiple tasks, particularly with the delay
   fix the servos are presently utilizing. We hope to update this soon.
*/
BLYNK_WRITE(V0) {  // Servos
  int count = 0;
  switch (param.asInt())
  {
    case 1: // Servo Pin 10 (#1)
      servoCMD(10);
      break;
    default:
       SerialUSB.println("Unknown item selected");
    break;
  }
}

/*
   This function has a couple purposes. From Blynk's app, 
   we have a dropdown menu that if switched to V1, turns
   this into a full LED control panel. However, that isn't very good UX.
  
   We also have a series of NFC tags that interface with this as a 
   master virtual pin for our LEDs. There might be a better way to do
   this, but it is sufficient for our purpose.
*/
BLYNK_WRITE(V1) {
  switch (param.asInt())
  {
    case 1:
      //SerialUSB.println("Red LED: on");
      ledCMD(A1, 0);
    break;
    case 2:
      //SerialUSB.println("Yellow LED: on");
      ledCMD(A2, 0); 
    break;
    case 3:
      //SerialUSB.println("White LED: on");
      ledCMD(A3, 0);
    break;
    case 4:
      //SerialUSB.println("Blue LED: on");
      ledCMD(A4, 0); 
    break;
    case 5: // Universal LED On
      ledCMD(V99, 2);
    break;
    case 6: // Universal LED Off
      ledCMD(V99, 3);
    break;
    default:
      SerialUSB.println("Unknown item selected");
    break;
  }
}

void setup()
{
  // Debug console
  SerialUSB.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  //servo.attach(10);
  pinMode(7, OUTPUT);
}

void loop()
{
  Blynk.run();
}

