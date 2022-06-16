
const byte float_low = 2;
const byte float_high = 3;
const byte pump = 6;
uint8_t pump_state;
char pump_buffer[5];

bool float_low_ready = false;
bool float_high_ready = false;
uint8_t button_ready = 0;

void float_check() {

  if (digitalRead(float_low) == 1 ) {
    while (digitalRead(float_low) == 1 ) {
      button_ready++;
      // Serial.println(button_ready);
      if (button_ready > 5 && button_ready < 10) {
        button_ready = 0;
        float_low_ready = true;
     //   Serial.println("float_low_ready!!!!!");
        break;
      }
    }
  } else {

    float_low_ready = false;
  }

  if (digitalRead(float_high) == 1 ) {
    while (digitalRead(float_high) == 1 ) {
      button_ready++;
      //Serial.println(button_ready);
      if (button_ready > 5 && button_ready < 10) {
        button_ready = 0;
        float_high_ready = true;
      //  Serial.println("float_high_ready!!!!!");
        break;
      }
    }
  } else {
    float_high_ready = false;

  }

}

void pump_on() {
  digitalWrite(pump, LOW);   /// TAP 1 OPEN
  pump_state=1;
}

void pump_off() {
  digitalWrite(pump, HIGH);   /// TAP 1 OPEN
  pump_state=0;

}
void pump_actuation() {

  if (float_low_ready == true && float_high_ready == true) {
    pump_on();
    Serial.println("pump_on");


  } else if (float_low_ready == false && float_high_ready == true) {
    pump_on();
    Serial.println("pump_on");


  } else if (float_low_ready == false && float_high_ready == false)
  {
    pump_off();
    Serial.println("pump_off");
  }

}
void float_init() {
  pinMode(float_low, INPUT_PULLUP);
  pinMode(float_high, INPUT_PULLUP);
  pinMode(pump, OUTPUT);
  pump_off();
}
