

// Motorized Ball Valve Pins

uint8_t motor1_close = 25;
uint8_t motor1_open = 23;
uint8_t motor_state;
char motor_buffer[5];

void tap1_close() {

  digitalWrite(motor1_close, HIGH);
  digitalWrite(motor1_open, LOW);
  motor_state=0;
}

void tap1_open() {
  digitalWrite(motor1_close, LOW);   /// TAP 1 OPEN
  digitalWrite(motor1_open, HIGH);
  motor_state=1;
}

void ballvalves_init() {

  pinMode(motor1_close, OUTPUT);
  pinMode(motor1_open, OUTPUT);
  tap1_close();
}
