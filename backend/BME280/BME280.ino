/*
  Get basic environmental readings from the BME280
  By: Nathan Seidle
  SparkFun Electronics
  Date: March 9th, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14348 - Qwiic Combo Board
  https://www.sparkfun.com/products/13676 - BME280 Breakout Board
  
  This example shows how to read humidity, pressure, and current temperature from the BME280 over I2C.

  Hardware connections:
  BME280 -> Arduino
  GND -> GND
  3.3 -> 3.3
  SDA -> A4
  SCL -> A5
*/

#include <Wire.h>

#include "SparkFunBME280.h"
BME280 stappBME;

void setup()
{
  Serial.begin(9600);
  Serial.println("Reading basic values from BME280");

  Wire.begin();

  // We set the mode to normal and measurement standbytime to 50 ms
  stappBME.setMode(MODE_NORMAL);
  stappBME.setStandbyTime(50);

  // We only want data on the pressure, so exclude humidity and temperature.
  stappBME.setTempOverSample(1);
  stappBME.setHumidityOverSample(0);
  stappBME.setPressureOverSample(3);

  stappBME.setI2CAddress(0x76);
  if (stappBME.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
}

void loop()
{

  Serial.print(" Pressure: ");
  Serial.print(stappBME.readFloatPressure(), 0);

  Serial.print(" Alt: ");
  //Serial.print(stappBME.readFloatAltitudeMeters(), 1);
  Serial.print(stappBME.readFloatAltitudeMeters(), 1);

  Serial.print(" Temp: ");
  //Serial.print(stappBME.readTempC(), 2);
  Serial.print(stappBME.readTempC(), 2);

  Serial.println();

  delay(500);
}
