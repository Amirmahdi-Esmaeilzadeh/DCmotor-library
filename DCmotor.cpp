#include "DCmotor.h"

DCmotor::DCmotor(bool sure){
  msg=sure;
}
void DCmotor::begin(int R,int L,long rate,String speed_mode){
  r=R;
  l=L;
  Serial.begin(rate);
  ekhtelaf=l-r;
  if(msg==true){
  Serial.println("DCmotor library is for DC motor easy control with L298N driver");
  Serial.println("made by amirmahdi esmailzadeh");
  Serial.print("boad rate: ");
  Serial.println(rate);
  Serial.print(r);
  Serial.print(" right motor speed is equal to ");
  Serial.print(l);
  Serial.println(" left motor \nspeed in your motors");
  Serial.print("input speed unit is ");
  Serial.print(speed_mode); 
  if(speed_mode=="rpm"){
    Serial.println(" (round per minute)"); 
  }else if(speed_mode=="rps"){
    Serial.println(" (round per second)"); 
  }else{
    Serial.println(" (warning: invalid unit!!)");
    
  }
  speed_unit=speed_mode;
}}
void DCmotor::pin(int RE,int R1,int R2,int LE,int L1,int L2){
  right_enable=RE;
  right_in1=R1;
  right_in2=R2;
  left_enable=LE;
  left_in1=L1;
  left_in2=L2;
  if(msg==true){
    Serial.println("motor pin set:");
    Serial.println(" left motor:");
    Serial.print("  enable: ");
    Serial.println(LE);
    Serial.print("  in1: ");
    Serial.println(L1);  
    Serial.print("  in2 ");
    Serial.println(L2);     
    Serial.println(" right motor:");
    Serial.print("  enable: ");
    Serial.println(RE);
    Serial.print("  in1: ");
    Serial.println(R1);  
    Serial.print("  in2 ");
    Serial.println(R2);        
  }
  pinMode(right_enable,OUTPUT);
  pinMode(right_in1,OUTPUT);
  pinMode(right_in2,OUTPUT);
  pinMode(left_enable,OUTPUT);
  pinMode(left_in1,OUTPUT);
  pinMode(left_in2,OUTPUT);  
}
void DCmotor::forward(long speed){
    if(speed_unit=="rpm"){
      speed_default=speed/2;
      speeds=speed*60;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,1);
      digitalWrite(right_in2,0);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }
      
    }if(speed_unit=="rps"){
      speeds=speed;
      speed=speeds/60;
      speed_default=speed/2;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,1);
      digitalWrite(right_in2,0);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }}
     Serial.print("going forward with ");
     Serial.print(speed);
     Serial.print(" rpm , "); 
     Serial.print(speeds);
     Serial.print(" rps and ");
     Serial.print(speed_default);
     Serial.println(" l298n default speed");
    
}
void DCmotor::right(long speed){
    if(speed_unit=="rpm"){
      speed_default=speed/2;
      speeds=speed*60;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,0 );
      digitalWrite(right_in2,0);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }
      
    }if(speed_unit=="rps"){
      speeds=speed;
      speed=speeds/60;
      speed_default=speed/2;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,0);
      digitalWrite(right_in2,0);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,1);
      digitalWrite(left_in2,0);
      }}
     Serial.print("turning right with ");
     Serial.print(speed);
     Serial.print(" rpm , "); 
     Serial.print(speeds);
     Serial.print(" rps and ");
     Serial.print(speed_default);
     Serial.println(" l298n default speed");
    
}
void DCmotor::left(long speed){
    if(speed_unit=="rpm"){
      speed_default=speed/2;
      speeds=speed*60;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,1);
      digitalWrite(right_in2,0);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,0);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,0);
      }
      
    }if(speed_unit=="rps"){
      speeds=speed;
      speed=speeds/60;
      speed_default=speed/2;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,1);
      digitalWrite(right_in2,0);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,0);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,0);
      }}
     Serial.print("turning left with ");
     Serial.print(speed);
     Serial.print(" rpm , "); 
     Serial.print(speeds);
     Serial.print(" rps and ");
     Serial.print(speed_default);
     Serial.println(" l298n default speed");
    
}
void DCmotor::backward(long speed){
    if(speed_unit=="rpm"){
      speed_default=speed/2;
      speeds=speed*60;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,0);
      digitalWrite(right_in2,1);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,1);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,1);
      }
      
    }if(speed_unit=="rps"){
      speeds=speed;
      speed=speeds/60;
      speed_default=speed/2;
      analogWrite(right_enable,speed_default);
      digitalWrite(right_in1,0);
      digitalWrite(right_in2,1);
      if(ekhtelaf>=0){
        analogWrite(left_enable,speed_default+ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,1);
      }else{
        analogWrite(left_enable,speed_default-ekhtelaf);
      digitalWrite(left_in1,0);
      digitalWrite(left_in2,1);
      }}
     Serial.print("going backward with ");
     Serial.print(speed);
     Serial.print(" rpm , "); 
     Serial.print(speeds);
     Serial.print(" rps and ");
     Serial.print(speed_default);
     Serial.println(" l298n default speed");
    
}
