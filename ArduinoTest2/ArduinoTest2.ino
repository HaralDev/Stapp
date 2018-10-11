
//     Code to run on ATMEGA2560 to gps, pressure and accelerometer
//     data to SD card
//     
//     SD card code: 
//     - http://www.vishnumaiea.in/projects/hardware/interfacing-catalex-micro-sd-card-module
//     - https://github.com/vishnumaiea/Arduino-Snippets/blob/master/SD-Card/SD_Init.ino
//
//     GPS code:
//     - https://idyl.io/arduino/how-to/interface-gps-module-arduino/

// Importing SPI and SD

#include <SPI.h>
#include <SD.h> //include the SD library
#include <Wire.h>

byte inByte;
bool sdInitSuccess = false; //card init status

void setup() {

  // SD card setup:
  Serial.begin(9600);
  while (!Serial) {
    ; //wait for the serial port to connect.
  }


  // other setup stuff
}


void loop() {
  // put your main code here, to run repeatedly:

}
