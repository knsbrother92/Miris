#include <AddicoreRFID.h>
#include <SPI.h>
 
#define    uchar    unsigned char
#define    uint    unsigned int
 
//4 bytes tag serial number, the first 5 bytes for the checksum byte
uchar serNumA[5];
 
uchar fifobytes;
uchar fifoValue;
 
AddicoreRFID myRFID; // create AddicoreRFID object to control the RFID module
const int chipSelectPin = 10;
const int NRSTPD = 5;
 
//Maximum length of the array
#define MAX_LEN 16
 
void setup() {                
  Serial.begin(9600);                        // 시리얼 모니터 출력 설정
 
  // start the SPI library:
  SPI.begin();
  
  pinMode(chipSelectPin,OUTPUT);              // Set digital pin 10 as OUTPUT to connect it to the RFID /ENABLE pin 
  digitalWrite(chipSelectPin, LOW);         // Activate the RFID reader
  pinMode(NRSTPD,OUTPUT);                     // Set digital pin 10 , Not Reset and Power-down
  digitalWrite(NRSTPD, HIGH);
 
  myRFID.AddicoreRFID_Init();  
}
 
void loop()
{
  uchar i, tmp, checksum1;
  uchar status;
  uchar str[MAX_LEN];
  uchar RC_size;
  uchar blockAddr;    //Selection operation block address 0 to 63
  String mynum = "";
  str[1] = 0x4400;
        
  //RFID 태그의 타입을 리턴
  status = myRFID.AddicoreRFID_Request(PICC_REQIDL, str);
    
  //RFID 충돌방지, RFID 태그의 ID값(시리얼넘버) 등 저장된 값을 리턴함. 4Byte
  status = myRFID.AddicoreRFID_Anticoll(str);
  if (status == MI_OK){ // MIFARE 카드일때만 작동
      checksum1 = str[0] ^ str[1] ^ str[2] ^ str[3];
      if(str[0] == 14){                   // 245 == a 전송
        Serial.print("a");          
      }
      else if(str[0] == 30) {             // 134 == b 전송
        Serial.print("b");
      }
      else if(str[0] == 46) {             // 134 == c 전송
        Serial.print("c");
      }
      else if(str[0] == 90) {             // 134 == d 전송
        Serial.print("d");
      }
      else if(str[0] == 170) {             // 134 == e 전송
        Serial.print("e");
      }
      else if(str[0] == 202) {             // 134 == f 전송
        Serial.print("f");
      }
      else if(str[0] == 10) {             // 134 == g 전송
        Serial.print("g");
      }
      else if(str[0] == 218) {             // 134 == h 전송
        Serial.print("h");
      }
        delay(1000);
  }
  myRFID.AddicoreRFID_Halt();           //Command tag into hibernation              
}

