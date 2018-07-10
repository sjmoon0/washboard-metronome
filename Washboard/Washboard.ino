#include <Servo.h>

Servo scratch; 
Servo tap; 

int scratch_pos = 0;
bool scratch_dir = false;//false=up
int tap_pos = 0;
int speed_coef = 10;
int up_stop = 90;
int up_start = 0;
int down_stop = 90;
int down_start = 180;

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
      for(scratch_pos=up_start;scratch_pos<=up_stop;scratch_pos+=1*speed_coef){
        scratch.write(scratch_pos);
        delay(5);
        if(scratch_pos + 1*speed_coef > up_stop){
          scratch.write(up_stop);
          break;
        }
      }
      if(up_stop==90){
        up_stop = 180;
        up_start = 90;
        scratch_dir = false;
      }else{
        up_stop = 90;
        up_start = 0;
        scratch_dir = true;
      }
    }else{
      for(scratch_pos=down_start;scratch_pos>=down_stop;scratch_pos-=1*speed_coef){
        scratch.write(scratch_pos);
        delay(5);
        if(scratch_pos + 1*speed_coef < down_stop){
          scratch.write(down_stop);
          break;
        }
      }
      if(down_stop==90){
        down_stop = 0;
        down_start = 90;
        scratch_dir = true;
      }else{
        down_stop = 90;
        down_start = 180;
        scratch_dir = false;
      }
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

