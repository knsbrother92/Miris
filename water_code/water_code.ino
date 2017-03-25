#include <Wire.h>
#include <SoftwareSerial.h>

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0);
  //Serial.println(sensorValue);
  
  if(sensorValue <= 600 && sensorValue >450){
    //Serial.println(sensorValue);  
    Serial.print('U');
  }
  
  else if(sensorValue <= 450 && sensorValue >150){
    //Serial.println(sensorValue);  
    Serial.print('V');
  }
  
  else if(sensorValue <= 150 && sensorValue >=0){
    //Serial.println(sensorValue); 
    Serial.print('W');
  }
  delay(500);
}

