// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// ADS7830
// This code is designed to work with the ADS7830_I2CADC_I2CS I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Analog-Digital-Converters?sku=ADS7830_I2CADC#tabs-0-product_tabset-2

#include <Wire.h>

// ADS7830 I2C address is 0x48(72)
#define Addr 0x48

void setup()
{
  // Initialise I2C communication as Master
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);
  delay(300);
}

void loop()
{
  unsigned int data;

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Differential inputs, channel-0, channel-1 selected
  Wire.write(0x04);
  // Stop I2C transmission
  Wire.endTransmission();
  
  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);
  
  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data = Wire.read();
  }

  // Output data to serial monitor
  Serial.print("Digital value of analog input  : ");
  Serial.println(data);
  delay(300);
}

