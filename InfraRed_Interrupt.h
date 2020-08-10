#ifndef INFRARED_INTERRUPT
#define INFRARED_INTERRUPT


// @remark   Arduino UNO, Nano, Mini chi cho phep ngat o chan pin 2 (INT 0) va pin 3 (INT 1)

const String  HELP_INFRARED_INTERRUPT = "   Infrared: thu nhan ngat tu pin D0, su kien lech trai, lech phai";

const int PIN_INFRARED_DIGITAL  = 3;   // Pin 3 supports interrupt


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     INTERRUPT
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Interrupt Service Routine turn right
void ISR_deviation() {
  byte D0;
  D0 = digitalRead(PIN_INFRARED_DIGITAL);
  Serial.println(D0);   
  // thiết lập hoạt động đáp ứng của động cơ
  if (D0 == 1) 
  {
    MotorPower(0,-100);
  } else {
    MotorPower(-100,0);
  }
} 


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     SETUP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// @brief Kích hoạt ngắt
void enable_infrared_interrupt() 
{
    Serial.println("Enable interrupt");   
   //Thiet lap chuong trinh con phuc vu ngat cho su kien cua pin, CHANGE | LOW  | RISING | FALLING 
   attachInterrupt(digitalPinToInterrupt(PIN_INFRARED_DIGITAL), ISR_deviation, CHANGE);
}

/// @brief  Cấm ngắt
void disable_infrared_interrupt()  
{
  Serial.println("Disable interrupt"); 
  detachInterrupt(digitalPinToInterrupt(PIN_INFRARED_DIGITAL));
}

void setup_infrared_interrupt() {

   //Hiển thị hướng dẫn sử dụng
   Serial.println(HELP_INFRARED_INTERRUPT);
   //Thiết lập chế độ vào ra của chân Digital
   pinMode(PIN_INFRARED_DIGITAL, INPUT); 
} 
#endif
