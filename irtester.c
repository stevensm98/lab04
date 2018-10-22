#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"
int main(int argc, char *argv[])
{
  
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  while(1) {
    printf("Waiting for reset\n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/frx213", "Alarm", "Update", "It's OFF");
    while(digitalRead(0) == 1);
    {
      printf("Waiting for event\n");
      digitalWrite(1, HIGH);
      digitalWrite(2,LOW);
      ifttt("http://red.eecs.yorku.ca:8080/triggrt/event/with/key/frx213", "Alarm", "Update", "It's ON");
    }
    while(digitalRead(0) == 0);
    {
      printf("Alarm\n");
      digitalWrite(2,HIGH);
      digitalWrite(1,LOW);
    }
  }
  /*NOTREACHED*/
  return 0 ;
}
