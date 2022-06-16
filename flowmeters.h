const byte inlet_flowmeter = 18;
const byte inlet_2_flowmeter = 2;
const byte outlet_flowmeter = 19;


unsigned long int *p1;
unsigned long int *p2;
unsigned long int *p3;
unsigned long int   counter_A = 0;
unsigned long int   counter_B = 0;
unsigned long int   counter_C = 0;
char inlet_total_liters_buffer[15];
char inlet_2_total_liters_buffer[15];
char outlet_total_liters_buffer[15];



void inlet_flowmeter_ISR() {
  (*p1)++;
  Serial.println("P1++ : " + String(*p1));

}

void inlet_flowmeter_2_ISR() {
  (*p3)++;
  Serial.println("P1++ : " + String(*p1));

}

void outlet_flowmeter_ISR() {
   (*p2)++;
   Serial.println("P2++ : " + String(*p2));

}

void flowmeters_init() {
  pinMode(inlet_flowmeter, INPUT_PULLUP);
  pinMode(inlet_2_flowmeter, INPUT_PULLUP);
  pinMode(outlet_flowmeter, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(inlet_flowmeter), inlet_flowmeter_ISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(inlet_2_flowmeter), inlet_flowmeter_2_ISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(outlet_flowmeter), outlet_flowmeter_ISR, FALLING);
  p1 = &counter_A;
  p2 = &counter_B;
  p3 = &counter_C;

}
