#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 7 on the Arduino
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup()
{
  sensors.begin();  // Start up the library
  Serial.begin(9600);
}

void loop()
{
  sensors.requestTemperatures(); 
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println("*C");
  
  delay(500);
}
