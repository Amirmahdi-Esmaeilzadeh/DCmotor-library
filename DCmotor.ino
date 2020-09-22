#include "DCmotor.h"
DCmotor motor(1);
void setup(){
  motor.begin(100,120,9600,"rpm");

}
void loop(){
  
}
