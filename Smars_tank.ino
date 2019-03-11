//  Xe SMARS với thành phần
//    + Arduino Uno hoặc Nano
//    + Shield Mở Rộng Arduino Nano (Module Arduino Socket Full Nano) tương thích cả Uno và Nano, https://chotroihn.vn/shield-mo-rong-arduino-nano-tai-linh-kien-dien-tu-3m
//    + 2 động cơ Động Cơ Giảm Tốc JA12-N20 3-12VDC,    https://chotroihn.vn/dong-co-giam-toc-ja12-n20-3-12vdc
//    + Mạch cầu H mini để điều khiển 2 động cơ giảm tốc, https://chotroihn.vn/search?query=mach+cau+mini
//    + Tăng áp 2-24v --> 5-28V 2A ,   https://chotroihn.vn/module-boost-dc-dc-2-24vdc-2a-mt3608-k1a9-4-4-1g, 
//      hoặc sử dụng module xịn hơn,   https://chotroihn.vn/module-boost-dc-dc-xl6009-5-40v-4a-k1a9-5-10g

#include <SoftwareSerial.h>
#include "HBridge_Motor.h"
#include "CMDParser.h"
#include "Buttons.h"
#include "InfraRed.h"
#include "InfraRed_Interrupt.h"
#include "Ultrasonic.h"


const int HC06_TX_PIN = 10;
const int HC06_RX_PIN = 11;

SoftwareSerial hc06(HC06_RX_PIN,HC06_TX_PIN);

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  //Thiết lập bộ phân tích cú pháp lệnh qua serial (bluetooth)
  setup_cmd();

  //trang thai hoat dong ban dau
  tank_mode = remote;
  
  hc06.println("Smars (remixed by TienND)");
  //Thiet lap cho giao tiep bluetooth
  hc06.begin(9600);
  //Thiet lap cho dong co 1 chieu giam toc
  setup_hbridge();
  //Thiết lập cảm biến hồng ngoại
  setup_infrared();
  setup_infrared_interrupt();

  //Thiết lập cho cảm biến siêu âm
  setup_ultrasonic();
  
  //Thiet lap cho nut bam cam ung
  setup_buttons();

  if (ReadButton1() > 0)
  {
     //Tự kiểm tra;
     Seft_Test();
  }
  
}

void Seft_Test()
{
    Serial.println("Tu kiem tra hoat dong cua motor");
    MotorPower(100,100);
    delay(3000);
    MotorPower(-100,-10);
    delay(3000);    
    MotorPower(-10,-100);
    delay(3000);    
    MotorPower(-100,-100);
    delay(3000);    
    MotorPower(0,-0);

    for (int i = 0; i <3000;i++)
    {
      Serial.println(ReadInfraRed());
    }
}
 


void loop() {

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //        CÁC XỬ LÝ KHI CÓ LỆNH TỪ BAN PHIM
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //  Khong xu ly kieu polling, ma xu ly dang interrupt

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //        LẤY SỐ LIỆU TỪ CÁC CẢM BIẾN
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  loop_infrared(); //áp dụng cho mode dò đường
  loop_buttons();  //do nothing
  loop_ultrasonic();  //áp dụng cho mode bodyguard
  

  switch (tank_mode) {
      case remote:
      // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      //        CÁC XỬ LÝ KHI CÓ LỆNH TỪ SERIAL
      // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      if (hc06.available()) {
        hc06.readBytesUntil('\n',cmd,40);
        //Serial.write("Thưc hien lenh "); 
        //Serial.println(cmd);
        // Phan tich cu phap lenh
        CMDParser(cmd);
        switch (cmd_params[0][0])
        {
          case 'l': //---------------------LED--(nen dat truoc Engine de tranh bi delay)--------
                    break;
          case 'm'://---------------------ENGINE----------------------------------------------
                    loop_hbridge(cmd_params[1],cmd_params[2]);
                    break;
        }
        FINISH_CMD: return;
      }
      break;
      case track:
      // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      //         CÁC XỬ LÝ KHI DÒ ĐƯỜNG BẰNG CẢM BIẾN HỒNG NGOẠI CHIẾU XUỐNG ĐẤT
      // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
        if (InfraredSensorValue> 100) 
        {;
            MotorPower(100,50);
        } else {
            MotorPower(50,100);
        }
        break;
      case bodyguard:
      // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      //         CÁC XỬ LÝ KHI BÁM THEO VẬT CHỦ BẰNG SIÊU ÂM
      // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
        break;      
  }
}
