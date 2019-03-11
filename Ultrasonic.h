// Hướng dẫn sử dụng
const String HELP_ULTRASONIC = "   ";

//Tham khảo từ http://mualinhkien.vn/san-pham/34/cam-bien-sieu-am-srf04.html
#define ECHOPIN 13
#define TRIGPIN 12

int UltrasonicSensorValue; //Giá trị thô lấy từ module siêu âm

// @brief  Lây khoảng cách tới vật thể từ cảm biến siêu âm
// @remark   nên đợi một chút, tầm 100ms trước khi gọi hàm lần nữa
int get_distance(){
  digitalWrite(TRIGPIN, LOW);                    // Set chan Trig xuong muc thap 2uS: ~~__
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                   //Gui mot xung 10uS muc cao vao chan Trig ~~__----------
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                    // Gui lai muc thap vao chan Trig         ~~__----------____
  int distance = pulseIn(ECHOPIN, HIGH);        // Đếm thời gian (đơn vị us) cho tới khi chân ECHOPIN có sườn lên
  distance= distance/58;                        // Qui đổi thời gian ra khoảng cách
  return distance;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     SETUP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup_ultrasonic(){
  //Hiển thị hướng dẫn sử dụng
  Serial.println(HELP_ULTRASONIC);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     LOOP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop_ultrasonic()
{  
    UltrasonicSensorValue = get_distance();
    Serial.println(UltrasonicSensorValue);                    // Hiển thị giá trị đo
}
