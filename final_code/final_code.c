// just that the Arduino IDE doesnt compile these files.
#ifdef RaspberryPi 
 
//include system librarys
#include <stdio.h> //for printf
#include <stdint.h> //uint8_t definitions
#include <stdlib.h> //for exit(int);
#include <string.h> //for errno
#include <errno.h> //error output
 
//wiring Pi
#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <wiringPi.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TCP_PORT 22
#define BUFFER_SIZE 1024
#define SUCCESS 1
#define SHELL_INVOKE_ERROR 127
#define ERROR -1
#define NO_SHELL 0

char device[]= "/dev/ttyACM0";

int fd;
unsigned long baud = 9600;
unsigned long time=0;

/* touch sensor */
int touchSensor = 5;
 
/* Function */
int main(int argc, char ** argv);
void loop(void);
void setup(void);
 
void setup(){
  pinMode(touchSensor, INPUT);

  printf("%s \n", "Raspberry Startup!");
  fflush(stdout);
 
  //get filedescriptor
  if ((fd = serialOpen (device, baud)) < 0){
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    exit(1); //error
  }
 
  //setup GPIO in wiringPi mode
  if (wiringPiSetup () == -1){
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    exit(1); //error
  } 
}
 
void loop(void){
   
  char*buf = malloc((size_t)(BUFFER_SIZE));
  int touchValue = digitalRead(touchSensor);
  
  // Pong every 3 seconds
  if(millis()-time>=3000){
    serialPuts (fd, "Pong!\n");
    serialPutchar (fd, 65);
    time=millis();
  }
 
  // read signal
  if(serialDataAvail (fd)){
    char newChar = serialGetchar (fd);
    printf("%c", newChar);
    /*
    if (newChar >= 'a' && newChar <= 'z') {
        system("sudo pip install freeze");
        system("sudo pip install azure-storage");
        sprintf(buf, "python ./mirisRFID.py %c", newChar);
        system(buf);
    }
    */
    fflush(stdout); 
  }
//printf("%d\n",touchValue);
  delay(100);
  if(touchValue == HIGH){
    system("raspistill -t 1000 -o cam.jpg");
    system("raspistill -o /home/pi/image.jpg");
    system("sudo pip install freeze");
    system("sudo pip install azure-storage");
    sprintf(buf,"python ./main.py %s","image.jpg");
    system(buf);
  }
  //return SUCCESS;
}
 
// main function for normal c++ programs on Raspberry
int main(int argc, char ** argv){

  int sysValue = system("sudo apt-get install -y python-devel");
  if(sysValue == SHELL_INVOKE_ERROR){
    printf("Shell Invoke Error");
    return SHELL_INVOKE_ERROR;
  }
  else if(sysValue == ERROR){
    printf("Error");
    return ERROR;
  }
  else if(sysValue == NO_SHELL){
    printf("Not Shell");
    return NO_SHELL;
  }
  setup();
  while(1) loop();
  return 0;
}
 
#endif //#ifdef RaspberryPi
