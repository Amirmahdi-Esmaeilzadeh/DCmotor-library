#ifndef tl
#define tl

#if(ARDUINO>=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
class DCmotor {
  public:
    DCmotor(bool sure);
    void begin(int R,int L,long rate,String speed_mode);
    void pin(int RE,int R1,int R2,int LE,int L1,int L2);
    void forward(long speed);
    void right(long speed);
    void left(long speed);
    void backward(long speed);
  private:
    bool msg;
    int r;
    int l;
    String speed_unit;
    int speed_default;
    int right_enable,right_in1,right_in2,left_enable,left_in1,left_in2;
    int ekhtelaf;
    int speeds;
};
#endif
