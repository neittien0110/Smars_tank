#ifndef HBRIDGE_MOTOR
#define HBRIDGE_MOTOR


const String  HELP_HBRIDGE = "   H-bridge Mini cmd: m;<left power>;<right power>. Eg: m;100;-85   ";

const int MOTOR_11  = 4;
const int MOTOR_12  = 5;
const int MOTOR_21  = 6;
const int MOTOR_22  = 7;
const char MOTOR_CMD_TYPE  = 'm';  // Kí tự nhận dạng lệnh serial là dành cho động cơ. Kí tự đầu tiên là m 

//  Thiết lập sức mạnh của động cơ DC 1 chiều 
// @param in  left_percent    -100~0~+100 công suất
// @param in  right_percent   -100~0~+100 công suất
void MotorPower(int left_percent, int right_percent) {
      int lp;
      int rp;
      lp = map(abs(left_percent), 0, 100, 0, 255);
      rp = map(abs(right_percent), 0, 100, 0, 255);   
      if (left_percent > 0) {
        analogWrite(MOTOR_11,lp);
        analogWrite(MOTOR_12,0);
      } else   {
        analogWrite(MOTOR_11,0);
        analogWrite(MOTOR_12,lp);
      }

      if (right_percent > 0) {
        analogWrite(MOTOR_21,0);
        analogWrite(MOTOR_22,rp);
      } else   {
        analogWrite(MOTOR_21,rp);
        analogWrite(MOTOR_22,0);
      }
}   

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     SETUP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup_hbridge() {
    //Hiển thị hướng dẫn sử dụng
   Serial.println(HELP_HBRIDGE);
  
   pinMode(MOTOR_11, OUTPUT);
   pinMode(MOTOR_12, OUTPUT);
   pinMode(MOTOR_21, OUTPUT);
   pinMode(MOTOR_22, OUTPUT);

    //Thiết lập tốc độ 0 cho chắc ăn
    MotorPower(0,0);
}   

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     LOOP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool loop_hbridge(char * leftpower, char * rightpower) {
  MotorPower(atoi(leftpower),atoi(rightpower));
}                                  


#endif
