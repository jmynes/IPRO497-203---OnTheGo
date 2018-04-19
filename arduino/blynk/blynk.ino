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

/*
   This function has a couple purposes. From Blynk's app, 
   we have a dropdown menu that if switched to V0, turns
   this into a full control panel. However, that isn't very good UX.
  
   We also have a series of NFC tags that interface with this as a 
   master virtual pin. This probably is not the best solution as it 
   makes it difficult to do multiple tasks, particularly with the delay
   fix the servos are presently utilizing. We hope to update this soon.

   Thirdly, from the Blynk app you can control the servo from here for now.
*/
BLYNK_WRITE(V0) {
  int count = 0;
  switch (param.asInt())
  {
    case 1: // Servo Down
      SerialUSB.println("Servo moved to resting position");

       // Band-aid fix to Servo for some reason needing same command twice
       // Even as a bandaid fix, this should really be a function for DRY code.
      while(count < 2) {
        servo.attach(10); // Connect Servo pin 10
        delay(400);          // Wait a bit
        servo.write(90);  // Servo rotates to down position (not fully certain why that's 90 in our case...)
        servo.detach();   // Take a nap, servo. We wouldn't want you to overheat for a model.

        count = count +1;
      }
      break;
    case 2: // Servo Up
      SerialUSB.println("Servo moved to standing position");
      
      // Band-aid fix to Servo for some reason needing same command twice
      while(count < 2) {   
        servo.attach(10); // Repeat above but inverse position
        delay(400);
        servo.write(0);
        servo.detach();

        count = count +1;
      }
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

