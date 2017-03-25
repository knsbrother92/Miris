#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600); 
  Serial.println("Arduino Test");
}

void loop() {
  char temp[100];
  if(Serial.available()){
    byte leng = Serial.readBytes(temp, 1);

    for(int i = 0; i < leng ; i++){
      Serial.print(temp[i]);
      BTSerial.println(temp[i]);
    }
    Serial.println();
  }
}
