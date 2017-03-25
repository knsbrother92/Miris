#include <Wire.h>
#include <SoftwareSerial.h>

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0);
  //int sensorValue2 = analogRead(A1);
  //Serial.println(sensorValue);

  if(sensorValue <= 600 && sensorValue >450){
    //Serial.println(sensorValue);  
    Serial.print('D');
  }
  
  else if(sensorValue <= 450 && sensorValue >150){
    //Serial.println(sensorValue);  
    Serial.print('E');
  }
  
  else if(sensorValue <= 150 && sensorValue >=0){
    //Serial.println(sensorValue); 
    Serial.print('F');
  }

  delay(500);
}

