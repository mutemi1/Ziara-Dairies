const int analogInPin = A10;  // Analog Pressue Pin 
int sensorValue = 0;        // value read from the pot
int pressureValue = 0; 
char pressure_buffer[6];

void pressure_read(){
  
  sensorValue = analogRead(analogInPin);
  pressureValue = map(sensorValue, 0, 1023, 0, 255);
 
  
  }
