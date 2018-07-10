#include <Servo.h>

Servo scratch; 
Servo tap; 

int scratch_pos = 0;
bool scratch_dir = false;
int tap_pos = 0;
int speed_coef = 10;

void setup() {
  scratch.attach(9);
  tap.attach(7);
  scratch.write(0);
  tap.write(140);
  //Serial.begin(9600);
}

void loop() {
  speed_coef = (1024 - analogRead(0))/100;
  //Serial.print(speed_coef);
  //scratch
  if(speed_coef == 0){
    
  }
  else{
    if(!scratch_dir){
      for(scratch_pos=0;scratch_pos<=180;scratch_pos+=1*speed_coef){
        scratch.write(scratch_pos);
        delay(5);
      }
      scratch_dir=true;
    }else{
      for(scratch_pos=180;scratch_pos>=0;scratch_pos-=1*speed_coef){
        scratch.write(scratch_pos);
        delay(5);
      }
      scratch_dir=false;
    }
    delay(10);
    
    //tap
    for(tap_pos=140;tap_pos>=50;tap_pos-=2*speed_coef){
      tap.write(tap_pos);
      delay(10);
    }
    for(tap_pos=50;tap_pos<=140;tap_pos+=2*speed_coef){
      tap.write(tap_pos);
      delay(10);
    }
  }
}

