// @remark   Arduino UNO, Nano, Mini chi cho phep ngat o chan pin 2 (INT 0) va pin 3 (INT 1)
#include "InfraRed_Interrupt.h"
// Hướng dẫn sử dụng
const String HELP_BUTTON = "   Button: button1 o pin2.  Bam nut de chuyen che do REMOTE(bluetooth) --> TRACK (find path) --> TRACK INTERRUPT (find path)-->  BODYGUARD (keep distance)";

const int PIN_BUTTON_1  = 2;
int button1 = 0;
int button1_newval=0;


enum ActionMode{
  remote=0,    // dieu khien bang remote bluetooth
  track=1,      // bam theo duong di
  interrupt_track=2,      // bam theo duong di
  bodyguard=3,  // giu khoang cach voi vat the
  nothing       // đánh dấu điểm kết thúc để xoay vòng
};
ActionMode tank_mode;  // Trang thai hoat dong cua xe

int ReadButton1() {
  return digitalRead(PIN_BUTTON_1);
}

// Interrupt Service Routine
void ISR_button1() {
  // Nếu sắp rời khỏi chế độ dò đường bằng ngắt thì phải cấm ngắt
  if (tank_mode == interrupt_track) 
  {
      disable_infrared_interrupt();
  }
  
  button1_newval = ReadButton1()  ;
  // Chuyển chế độ hoạt động của xe theo kiểu round robin
  tank_mode =  (tank_mode + 1) % nothing;

  Serial.print("Che do hoat dong: ");
  Serial.println(tank_mode);

  // Luon tat dong co
  MotorPower(0,0);

  // Nếu mới chuyển tới chế độ dò đường bằng ngắt thì phải kích hoạt ngắt
  if (tank_mode == interrupt_track) 
  {
      enable_infrared_interrupt();
  }
  
  return;
} 



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     LOOP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop_buttons() {
  //nothing to do because of using interrupt
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     SETUP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup_buttons() {
   //Hiển thị hướng dẫn sử dụng
   Serial.println(HELP_BUTTON);
   //Thiết lập chế độ vào ra của chân Digital
   pinMode(PIN_BUTTON_1, INPUT); 
   //Thiet lap chuong trinh con phuc vu ngat cho su kien cua pin, CHANGE | LOW  | RISING | FALLING 
   attachInterrupt(digitalPinToInterrupt(PIN_BUTTON_1), ISR_button1, RISING);
} 
