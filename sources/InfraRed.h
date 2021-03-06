// @remark   Arduino UNO, Nano, Mini chi cho phep ngat o chan pin 2 (INT 0) va pin 3 (INT 1)

const String  HELP_INFRARED = "   Infrared: gia tri doc tu pin A0, dai gia tri 0~1023";
const int PIN_INFRA_D0  = 3;

const int INFRARED_ANALOG_PIN  = A0;
int InfraredSensorValue; //Giá trị thô lấy từ cảm biến, phạm vi 0~1023

int ReadInfraRed() {
  return analogRead(INFRARED_ANALOG_PIN);
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     SETUP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup_infrared() {
    //Hiển thị hướng dẫn sử dụng
   Serial.println(HELP_INFRARED);
} 


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     LOOP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop_infrared() {
  // Lấy giá trị từ cảm biến
  InfraredSensorValue = ReadInfraRed();
  //debug
  Serial.println(InfraredSensorValue);
  return;
} 
