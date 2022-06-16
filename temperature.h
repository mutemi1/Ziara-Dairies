#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire of the temp sensor  is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS A8

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

uint8_t deviceCount = 0;  //Number of temperature sensors connected to the ONE WIRE BUS
uint8_t tempC=0;          //Temperature in celsius

char inlet_temp [4] = "0";
char outlet_temp [4] = "0";

void temp_sensors_init() {

  sensors.begin();  // Initialize the library
  // locate devices on the bus
  Serial.println("Locating devices...");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");

}


void Temp_Sensors_Read_Data() {

  // Send command to all the sensors for temperature conversion
  sensors.requestTemperatures();

  // Display temperature from each sensor
  for (uint8_t i = 0;  i < deviceCount;  i++)
  {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" : ");
    tempC = sensors.getTempCByIndex(i);
    if (i == 0)
    {
      itoa(tempC, inlet_temp, 10);

    } else if (i == 1) {

      itoa(tempC, outlet_temp, 10);

    }
    Serial.print(tempC);
    Serial.print("C  |  ");
  }

  Serial.println("");
  delay(1000);

}
