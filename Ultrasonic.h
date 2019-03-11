// Hướng dẫn sử dụng
const String HELP_ULTRASONIC = "   ";

//Tham khảo từ http://mualinhkien.vn/san-pham/34/cam-bien-sieu-am-srf04.html
#define ECHOPIN 13
#define TRIGPIN 12


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     SETUP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup_ultrasonic(){
  //Hiển thị hướng dẫn sử dụng
  Serial.println(HELP_ULTRASONIC);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  //pinMode(11, OUTPUT);
  //pinMode(8,OUTPUT);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     LOOP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop_ultrasonic()
{  
  //digitalWrite(11,LOW);                          //chan gnd module
  //digitalWrite(8,HIGH);                          // chan cap vcc module
  //digitalWrite(TRIGPIN, LOW);                    // Set chan Trig xuong muc thap 2uS
  //delayMicroseconds(2);
  //digitalWrite(TRIGPIN, HIGH);                   //Gui mot xung 10uS muc cao vao chan Trig
  //delayMicroseconds(10);
  //digitalWrite(TRIGPIN, LOW);                    // Gui lai muc thap vao chan Trig
  //int distance = pulseIn(ECHOPIN, HIGH);        // Doc thoi gian tra ve
  //distance= distance/58;                        // Tinh toan khoang cach
  //if (distance >= 0)
  //{
  //  Serial.println(distance);                    // Neu du lieu dung thi in ra
  //  delay(100);
  //}
}
