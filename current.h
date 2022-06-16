#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
EnergyMonitor emon2;                   // Create an instance
EnergyMonitor emon3;                   // Create an instance
EnergyMonitor emon4;                   // Create an instance
EnergyMonitor emon5;                   // Create an instance

int Irms1=0;
int Irms2=0;
int Irms3=0;
int Irms4=0;
int Irms5=0;

char Irms1_buffer[6];
char Irms2_buffer[6];
char Irms3_buffer[6];
char Irms4_buffer[6];
char Irms5_buffer[6];

void current_init() {
   
  emon1.current(1, 60.6);       //Input pin(A1), Calibration constant 
  emon2.current(2, 60.6);       //Input pin(A1), Calibration constant 
  emon3.current(3, 60.6);       //Input pin(A1), Calibration constant 
  emon4.current(4, 60.6);       //Input pin(A1), Calibration constant 
  emon5.current(5, 60.6);       //Input pin(A1), Calibration constant 

  /* Calibration constant 
   *  15 ohhms - 133.3.
   *  18 ohms - 111.1
   *  22 ohms - 90.9
   *  120 ohms - 16.67
   *  33 ohms - 60.6
   */
} 


void current_read() {
   //106 instances of current are read by the Emon library, capture data for 14 cycles = 1484
   
  double Irms1_temp = emon1.calcIrms(1484);  // Calculate Irms only 
  double Irms2_temp = emon2.calcIrms(1484);  // Calculate Irms only 
  double Irms3_temp = emon3.calcIrms(1484);  // Calculate Irms only 
  double Irms4_temp = emon4.calcIrms(1484);  // Calculate Irms only 
  double Irms5_temp = emon5.calcIrms(1484);  // Calculate Irms only 
  
  Irms1=(int)Irms1_temp;
  Irms2=(int)Irms2_temp;
  Irms3=(int)Irms3_temp;
  Irms4=(int)Irms4_temp;
  Irms5=(int)Irms5_temp;
 // Serial.print(Irms * 230.0);       // Apparent power
 // Serial.print(" ");
//  Serial.print("Irms1: ");          // Irms
//  Serial.println(Irms1);          // Irms
//  Serial.print("Irms2: ");          // Irms
//  Serial.println(Irms2);          // Irms
//  Serial.print("Irms3: ");          // Irms
//  Serial.println(Irms3);          // Irms
//  Serial.print("Irms4: ");          // Irms
//  Serial.println(Irms4);          // Irms
//  Serial.print("Irms5: ");          // Irms
//  Serial.println(Irms5);          // Irms

 

}
