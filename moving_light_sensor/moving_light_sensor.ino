#include <Wire.h>
#include <SoftwareSerial.h>
int lights_one = A0;

void setup()
{
  Serial.begin(9600); 
}
void loop()
{
  int lights_one = analogRead(lights_one);

   if(lights_one < 5){
    Serial.print('P');
   }
   delay(500);
}
