/**
 * ReadSHT1xValues
 *
 * Read temperature and humidity values from an SHT1x-series (SHT10,
 * SHT11, SHT15) sensor.
 *
 * Copyright 2009 Jonathan Oxer <jon@oxer.com.au>
 * www.practicalarduino.com
 */

#include <SHT1x.h>

int DataPin=14;
int ClockPin=15;
SHT1x sht1x(DataPin,ClockPin);
float g_fTempC=0;
float g_fHumidity=0;

void setup()
{
   Serial.begin(9600); // Open serial connection to report values to host
   Serial.println("TEMP/HUMISensorReadingStart");
}

void SensorRead(){
  g_fTempC=sht1x.readTemperatureC()-5;
  g_fHumidity=sht1x.readHumidity();
  Serial.print("TEMP");
  Serial.println(g_fTempC);
  Serial.print("HUMI:");
  Serial.println(g_fHumidity);
  
}
void loop()
{

  SensorRead();
  delay(200);
}
