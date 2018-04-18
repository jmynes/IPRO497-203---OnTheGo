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

// Debug menu, hoping for a better solution during presentation because dropdowns suck in Blynk
BLYNK_WRITE(V0) {
  switch (param.asInt())
  {
    case 1: // Servo Down
      SerialUSB.println("Servo moved to resting position");
      servo.attach(10); // Connect Servo pin 10
      delay(1000);          // Wait a bit
      servo.write(90);  // Servo rotates to down position (not fully certain why that's 90 in our case...)
      servo.detach();   // Take a nap, servo. We wouldn't want you to overheat for a model.
      break;
    case 2: // Servo Up
      SerialUSB.println("Servo moved to standing position");
      servo.attach(10); // Repeat above but inverse position
      delay(1000);
      servo.write(0);
      servo.detach();
      break;
     case 3: // LED on
      SerialUSB.println("LED on V1: on");
      digitalWrite(7, HIGH); 
      break;
     case 4: // LED off
      SerialUSB.println("LED on V1: off");
      digitalWrite(7, LOW);
      break;
    default:
      SerialUSB.println("Unknown item selected");
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

