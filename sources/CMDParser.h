// Hướng dẫn sử dụng
const String HELP_CMD = "   CMD Syntaxt: type[;param1~9]";


bool  cmd_done; // Bao hieu lenh cua user da duoc xu ly chua
char  cmd[40];    // Lenh cua nguoi su dung, gui qua Serial
char  cmd_type; // Kieu lenh. Xem   MOTOR_CMD_TYPE
byte  cmd_paramc;   // So luong tham so 0 --> 6
char* cmd_params[10]; // Danh sachs cac tham so



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     SETUP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup_cmd() {
   //Hiển thị hướng dẫn sử dụng
   Serial.println(HELP_CMD);
} 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                     PHÂN TÍCH LỆNH
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// @brief phan tich cu phap lenh
// @detail    m;<left power>;<right power>. Eg: m;100;-85    
// @return  = false neu viec phan tich tham so that bai
void CMDParser(char * cmd)
{
  int posLeft; // Danh dau diem dau va diem cuoi cua tham so trong chuoi cmd
  int cmd_len;
  cmd_paramc = 0; //chi so cua tham so 

  //Serial.println(cmd);     //Hien thi lenh goc
  
  posLeft = 0;
  cmd_len = strlen(cmd);
  for (int i = 0; i<cmd_len; i++)
  {
    if (cmd[i] == ';')
    {
      cmd_params[cmd_paramc]=&cmd[posLeft];
      cmd_paramc++;
      cmd[i] = '\0';
      posLeft = i+1;
    }
  }
  cmd_params[cmd_paramc]=&cmd[posLeft]; // tham so cuoi cung
  cmd_paramc++;

  //Hien thi cac tham so sau khi da phan tic
  //for (int i = 0; i<cmd_paramc; i++)
  //{
  // Serial.println(cmd_params[i]);
  // }
}
