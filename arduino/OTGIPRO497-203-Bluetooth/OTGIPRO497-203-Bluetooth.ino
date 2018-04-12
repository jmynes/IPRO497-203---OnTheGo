#define ROBOT_NAME "OTG"

// If you haven't configured your device before use this
// #define BLUETOOTH_SPEED 9600
// If you are modifying your existing configuration, use this:
#define BLUETOOTH_SPEED 57600

#include <SoftwareSerial.h>

// Swap RX/TX connections on bluetooth chip
//   Old Fritzing diagram:
//   Pin 10 --> Bluetooth TX
//   Pin 11 --> Bluetooth RX

//   Current build
//   Pin 2 --> Bluetooth TX
//   Pin 4 --> Bluetooth RX
SoftwareSerial bluetoothSerial(4, 2); // RX, TX


/*
  The posible baudrates are:
    AT+BAUD1-------1200
    AT+BAUD2-------2400
    AT+BAUD3-------4800
    AT+BAUD4-------9600 - Default for hc-06
    AT+BAUD5------19200
    AT+BAUD6------38400
    AT+BAUD7------57600 - Johnny-five speed
    AT+BAUD8-----115200
    AT+BAUD9-----230400
    AT+BAUDA-----460800
    AT+BAUDB-----921600
    AT+BAUDC----1382400
*/


void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Starting config");
  bluetoothSerial.begin(BLUETOOTH_SPEED);
  delay(1000);

  // Should respond with OK
  bluetoothSerial.print("AT");
  waitForResponse();

  // Should respond with its version
  bluetoothSerial.print("AT+VERSION");
  waitForResponse();

  // Set pin to 1337
  // Obviously this is not very secure, but this is testing!
  bluetoothSerial.print("AT+PIN1337");
  waitForResponse();

  // Set the name to ROBOT_NAME
  bluetoothSerial.print("AT+NAME");
  bluetoothSerial.print(ROBOT_NAME);
  waitForResponse();

  // Set baudrate to 57600
  bluetoothSerial.print("AT+BAUD7");
  waitForResponse();

  Serial.println("Done!");
}

void waitForResponse() {
    delay(1000);
    while (bluetoothSerial.available()) {
      Serial.write(bluetoothSerial.read());
    }
    Serial.write("\n");
}

void loop() {
  if (bluetoothSerial.available()) {
    Serial.write(bluetoothSerial.read());
  }
  if (Serial.available()) {
    bluetoothSerial.write(Serial.read());
  } 

  //
}
