#include "variables.h"
#include "timer.h"
#include "temperature.h"
#include "flowmeters.h"
#include "mqtt.h"
#include "send_data.h"


void mqtt_start() {
  // mqtt init
  mqtt_init();
  mqtt.setServer(broker, 1883);
  mqtt.setCallback(mqttCallback);

  Serial2.println("AT+GSN\r\n");
  delay(500);
  char ch;
  int i;
  i = 0;
  while (Serial2.available()) {
    ch = Serial2.read();
    if (ch == '\r' || ch == '\n' || ch == 'O' || ch == 'K');
    else {
      imei[i] = ch;
      i++;
    }
  }
  Serial.write("IMEI: ");
  Serial.println(imei);
  
}

void setup(void)
{  
//   Serial.begin(9600);
   Serial.begin(115200);
   temp_sensors_init();
   flowmeters_init();
   //ballvalves_init();
   timer_init();
   float_init();
   actuate_init();
   current_init();
   mqtt_start();
}

void loop(void)
{
   Temp_Sensors_Read_Data();
   float_check();
   pump_actuation();
   pressure_read();
   current_read();
   send_data_online();
   mqtt_check();


}
