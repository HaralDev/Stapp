/*
  Communicate with BME280s with different I2C addresses
  Nathan Seidle @ SparkFun Electronics
  March 23, 2015

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14348 - Qwiic Combo Board
  https://www.sparkfun.com/products/13676 - BME280 Breakout Board

  This example shows how to connect two sensors on the same I2C bus.

  The BME280 has two I2C addresses: 0x77 (jumper open) or 0x76 (jumper closed)

  Hardware connections:
  BME280 -> Arduino
  GND -> GND
  3.3 -> 3.3
  SDA -> A4
  SCL -> A5
*/

#include <Wire.h>

#include "SparkFunBME280.h"

BME280 stappBME; //Uses default I2C address 0x77

void setup()
{
  Serial.begin(9600);

  // We set the mode to normal and measurement standbytime to 50 ms
  stappBME.setMode(MODE_NORMAL);
  stappBME.setStandbyTime(10);

  // We only want data on the pressure, so exclude humidity and temperature.
  stappBME.setTempOverSample(1);
  stappBME.setHumidityOverSample(0);
  stappBME.setPressureOverSample(3);


 
  Wire.begin();  
  stappBME.setI2CAddress(0x76); //The default for the SparkFun Environmental Combo board is 0x77 (jumper open).
  //If you close the jumper it is 0x76
  //The I2C address must be set before .begin() otherwise the cal values will fail to load.

  if(stappBME.beginI2C() == false) Serial.println("Sensor A connect failed");
  
}

void loop()
{

  Serial.print("HumidityA: ");
  Serial.print(stappBME.readFloatHumidity(), 0);
  
  Serial.print(" PressureA: ");
  Serial.print(stappBME.readFloatPressure(), 0);

  Serial.println();

  delay(1000);
}
