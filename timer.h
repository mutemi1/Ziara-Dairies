uint8_t count=0;
uint8_t time_to_send=15;
bool send_data=false;

ISR(TIMER4_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)

//Serial.print("TIMER COUNT: ");
Serial.println(count++);

if(count==time_to_send){
  count=0;
  ///This flag is used to send data every x seconds 
  send_data=true;
  }

}


void timer_init(){
  
 TCCR4A = 0;// set entire TCCR1A register to 0
 TCCR4B = 0;// same for TCCR1B
 TCNT4  = 0;//initialize counter value to 0
 // set compare match register for 1hz increments
 OCR4A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
 // turn on CTC mode
 // Set CS12 and CS10 bits for 1024 prescaler
 TCCR4B |= (1 << WGM12)|(1 << CS12) | (1 << CS10);  
 // enable timer compare interrupt
 TIMSK4 |= (1 << OCIE4A);
  }
