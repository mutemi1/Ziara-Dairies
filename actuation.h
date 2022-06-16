/*
   There is a 4 channel relay in the system
   Relay 1 is used to actuate the pump depending on the status of the float switches as
   described in float.h
   Relay 2,3 and 4 are open-ended. They can be used to actuate any external device.
   The MCU listens to MQTT commands to actuate them

*/
#define ON        1
#define OFF       0

const byte relay2 = 8;
const byte relay3 = 9;
const byte relay4 = 10;

uint8_t relay2_state;
uint8_t relay3_state;
uint8_t relay4_state;
char relay2_buffer[5];
char relay3_buffer[5];
char relay4_buffer[5];

void relay2_on() {
  digitalWrite(relay2, LOW);   /// RELAY 2 ON
  relay2_state=1;
}

void relay2_off() {
  digitalWrite(relay2, HIGH);   /// RELAY 2 OFF
  relay2_state=0;
}
void relay3_on() {
  digitalWrite(relay3, LOW);   /// RELAY 3 ON
  relay3_state=1;
}

void relay3_off() {
  digitalWrite(relay3, HIGH);   /// RELAY 3 OFF
  relay3_state=0;
}
void relay4_on() {
  digitalWrite(relay4, LOW);   /// RELAY 4 ON
  relay4_state=1;
}

void relay4_off() {
  digitalWrite(relay4, HIGH);   /// RELAY 4 OFF
  relay4_state=0;

}
//Based on the MQTT command received, The selected relay can either be on or off
void actuate_relay(int select_relay, bool relay_status) {

  if (select_relay == 2 && relay_status == ON) {
    relay2_on();

  } else if (select_relay == 2 && relay_status == OFF)
  {
    relay2_off();
  }
  else if (select_relay == 3 && relay_status == ON) {
    relay3_on();

  } else if (select_relay == 3 && relay_status == OFF)
  {
    relay3_off();
  }
  else if (select_relay == 4 && relay_status == ON) {
    relay4_on();

  } else if (select_relay == 4 && relay_status == OFF)
  {
    relay4_off();
  }

}

void actuate_init() {

  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  relay2_off();
  relay3_off();
  relay4_off();
}
