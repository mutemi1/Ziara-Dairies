#include "current.h"
#include "pressure.h"
#include "ballvalves.h"
#include "actuation.h"
#include "float.h"

char data[100];


void send_data_online(){
  
  if(send_data==true && mqtt_conn==true)
  {
    send_data=false;
   
    itoa(counter_A, inlet_total_liters_buffer, 10);
    itoa(counter_C, inlet_2_total_liters_buffer, 10);
    itoa(counter_B, outlet_total_liters_buffer, 10);
    *p1 = 0;
    counter_A = 0;
    *p2 = 0;
    counter_B = 0;
    *p3 = 0;
    counter_C = 0;
    
    itoa(Irms1, Irms1_buffer, 10);
    itoa(Irms2, Irms2_buffer, 10);
    itoa(Irms3, Irms3_buffer, 10);
    itoa(Irms4, Irms4_buffer, 10);
    itoa(Irms5, Irms5_buffer, 10);

    itoa(pressureValue, pressure_buffer, 10);
    itoa(motor_state, motor_buffer, 10);
    itoa(pump_state, pump_buffer, 10);
    itoa(relay2_state, relay2_buffer, 10);
    itoa(relay3_state, relay3_buffer, 10);
    itoa(relay4_state, relay4_buffer, 10);
    
    strcpy(data,imei);
    strcat(data,"%");
    strcat(data,inlet_total_liters_buffer);
    strcat(data,"%");
    strcat(data,inlet_2_total_liters_buffer);
    strcat(data,"%");
    strcat(data,outlet_total_liters_buffer);
    strcat(data,"%");
//    strcat(data,inlet_temp);
//    strcat(data,"%");
//    strcat(data,outlet_temp);
//    strcat(data,"%");

    strcat(data,Irms1_buffer);
    strcat(data,"%");
    strcat(data,Irms2_buffer);
    strcat(data,"%");
    strcat(data,Irms3_buffer);
    strcat(data,"%");
    strcat(data,Irms4_buffer);
    strcat(data,"%");
    strcat(data,Irms5_buffer);
    strcat(data,"%");
    strcat(data,pressure_buffer);
    strcat(data,"%");
    strcat(data,motor_buffer);
    strcat(data,"%");
    strcat(data,pump_buffer);
    strcat(data,"%");
    strcat(data,relay2_buffer);
    strcat(data,"%");
    strcat(data,relay3_buffer);
    strcat(data,"%");
    strcat(data,relay4_buffer);
  
    
    Serial.println(data);
   
    mqtt.publish(topicEnergyData , data);
    //Send Data to the MQTT server 
    
  }
  
}
