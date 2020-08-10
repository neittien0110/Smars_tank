#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
WMRGBLed rgbLED(0,4);
///Đèn hồng ngoại nhận tín hiệu từ điều khiển
WMBoardIR boardIr(13);
/// Tạo hanlder điều khiển động cơ trái với 2 pin 8(hướng quay), và 6(công suất PWM)
WMDCMotor motor1(8);
/// Tạo hanlder điều khiển động cơ phải với 2 pin 7(hướng quay), và 5(công suất PWM)
WMDCMotor motor2(7);



void setup(){
    randomSeed(A0);
    rgbLED.setColor(8,8);
    rgbLED.show();
    boardIr.begin();
    
}

void loop(){
  ///Nếu nhấn phím số 2 thì xe đi tiến với tốc độ 50/100
    if(boardIr.keyPressed(24)){
        motor1.reverseRun(50);
        motor2.reverseRun(50);
      }
  ///Nếu nhấn phím số 8 thì xe đi lùi với tốc độ 50/100    
    else if(boardIr.keyPressed(74)){
            motor1.reverseRun(-50);
            motor2.reverseRun(-50);
      }
  ///Nếu nhấn phím số 4 thì xe rẽ trái    
    else if(boardIr.keyPressed(16)){
                motor1.reverseRun(40);
                motor2.reverseRun(70);
            }
  ///Nếu nhấn phím số 6 thì xe rẽ trái          
    else if(boardIr.keyPressed(90)){
                motor1.reverseRun(70);
                motor2.reverseRun(40);
            }
  ///Nếu nhấn phím số 5 thì xe dừng          
    else if(boardIr.keyPressed(56)){
                motor1.reverseRun(0);
                motor2.reverseRun(0);
            }
   
    boardIr.startDecode();
    
    
}
