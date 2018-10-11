/* 
 *        GPS Code for Stapp
 *        
 *        Component used:
 *        GY-GPS6mV2
 *        https://www.tinytronics.nl/shop/nl/communicatie/gps/gy-neo6mv2-gps-module
 *        
 *        Mostly learned from:
 *        https://idyl.io/arduino/how-to/interface-gps-module-arduino/
 *  
 */

// We include the Softwareserial package for UART communication
 #include <SoftwareSerial.h>

// RXpin corresponds to the T-Minus pin connected to TX on the GPS
// TXpin is connected to RX on the GPS
// Defined Baud rate is 9600
 static const int RXpin = 34, TXpin = 3;
 static const uint32_t GPSBaud = 9600;

// Prep the connection
 SoftwareSerial ss(RXpin, TXpin);


void setup() 
{
  // Setup the core with maximum Baud rate (for some reason, look at this later)
  // and the GPS connection with the predefined Baud rate
  Serial.begin(115200);
  ss.begin(GPSBaud);
}

void loop() {
  // Output raw GPS data
  Serial.print(ss.read());

}
