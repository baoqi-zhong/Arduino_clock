/*
  这个是针对4个独立数码管的程序

  time:2021.7.20-2021.7.23

*/
// 数码管每一段拉低有效
// 每一位拉低有效
// 第一位在左边

// define 没有等号 没有;

// DS1302 settings
#define CLK 10
#define DAT 11
#define CE 12

// pin settings
#define BTN_1 0
#define BTN_2 1
#define LIGHT 14
#define TEMP 15
#define BUZZER 13

#define LONG_PRESS_TIME 120 // 超过这个就算长按

#define BUZZER_ENABLE true
#define AUTO_DARK true // 黑暗时自动调节时间使能
#define DETECT_BRIGHTNESS 90 // 黑暗判断阈值

unsigned char DIGIT[4] = {19, 18, 17, 16}; // pin
unsigned char SEGMENT[8] = {2, 3, 9, 7, 6, 4, 5, 8}; // pin
unsigned char TRANSFORM[8] = {3, 4, 5, 0, 1, 2, 6, 8}; // 为了适应第三位颠倒
//                             0   1  2   3   4    5    6    7  8    9 empty C
unsigned char NUM_SHAPE[12] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 0, 57};

unsigned char mode = 0; // 0:正常时钟/温度  1:计时/倒计时  2:闹钟调节
unsigned char display_data[4][8]; // 数码管7段1点是否点亮  这里可以改成bool
unsigned char display_num_data[4]; // 要显示四个数字/字符
unsigned char now_time[2] = {12, 00}; // 当前时间。在mode==0，非温度时将now_time复制到display_num_data
unsigned char alarm_data[3]; // [时, 分, EN]
unsigned char btn1_press_time, btn2_press_time, btn_both_press_time; // 记录各个按钮长按的累计时间
unsigned char btn_state, add_state; // btn_state是长按/短按哪个键，add_state长按连续加用来记录millis整除之后状态，以便隔一段时间连续加
unsigned char max_[2]; // 各个位的最大数值，动态设置
unsigned char hot_num = 0; // 正在修改的是前两位还是后两位，0/1
unsigned char lift = 1; // 长按后是否抬起
bool edit = false; // 是否处于编辑中
bool buzzer_on = false;
bool alarmed = false; // 防止在同一分钟内重复响
float temp = 250; // 扩大10倍
bool show_temp = false;
unsigned char update_count = 10;

bool jishi = true; // true：计时，false，倒计时
bool jishi_running; // 计时运行中
unsigned long start_time; // 计时开始时间
unsigned long last_end_time = 0; // 最后一次停止的时间 tips: 每次显示的时间都是通过last_end_time和start_time和millis()算出来的，算出来的结果保存在total_time
long total_time; // 显示的时间。不能用unsigned因为倒计时可能小于0
bool accurate = false;

// 数码管每一段拉低有效
// 每一位拉低有效
// 第一位在左边
// << >> 运算符要加括号！！！这两个的运算级别很低！

// 1302-START  ********************************************************************************

/* ds1302 data sheet:
    所有地址开头都是1
    地址最后一位0写1读

                   | 地址             |RAM内容意义
                   |                 |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
    秒             |写0x80 - 读0x81   | CH  |      秒十位      |         秒个位         |
    分             |写0x82 - 读0x83   |  0  |      分十位      |         分个位         |
    时             |写0x84 - 读0x85   |12/24|  0  |10A/P|       小时(0-24/1-12)        |
    日             |写0x86 - 读0x87   |     0     |   日十位   |         日个位         |
    月             |写0x88 - 读0x89   |        0        |   月十位   |      月个位      |
    星期            |写0x8A - 读0x8B   |             0               |       星期      |
    年             |写0x8C - 读0x8D   |         年十位         |         年个位         |
    控制            |写0x8E - 读0x8F   |写保护|                0                        |
    充电            |写0x90 - 读0x91   | TCS | TCS | TCS | TCS | DS  | DS  | DS  | DS  |
    批量写入RTC     |写0xCE - 读0xCF   | 连续好多个8位...                                |
    用户RAM0        |写0xD0 - 读0xD1   | 用户自定义要写入的内容                           |
    ...
    用户RAM31       |写0xFC - 读0xFD   |  用户自定义要写入的内容                           |
    批量写入RAM     |写0xFE - 读0xFF   |  连续好多个8位...                                |

    CH: 0运行 1停止

    写入先把data设置好，再把CLK拉高，上升沿写入
    读取先拉低，拉低之后1302输出马上变化，arduino读取。下降沿读取
    而且读取时，先写入，写入CLK拉低之后马上就可以读取。

*/

void shift_out(unsigned int data)
{
  pinMode(DAT, OUTPUT);
  for (int i = 0; i < 8; i++)
  {
    // 1302先传入的是低位的
    digitalWrite(DAT, data >> i & 1);
    //上升沿写数据
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }
}

unsigned int shift_in()
{
  unsigned int data = 0;
  //注意这里只有7次循环.第七次结束就可以读.后面clock的拉高再拉低没有用
  for (int i = 0; i < 7; i++)
  {
    //下降沿读数据 在shift_out函数拉低之后马上读
    data |= digitalRead(DAT) << i;
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }
  data |= digitalRead(DAT) << 7;
  return data;
}

void write_1302(unsigned int address, unsigned int data)
{
  pinMode(DAT, OUTPUT);
  digitalWrite(DAT, LOW);
  digitalWrite(CE, LOW);
  digitalWrite(CE, HIGH);
  shift_out(address);
  shift_out(data);
  digitalWrite(CE, LOW);
}

unsigned int read_1302(unsigned int address)
{
  unsigned int data;

  pinMode(DAT, OUTPUT);
  digitalWrite(DAT, LOW);
  digitalWrite(CE, LOW);
  digitalWrite(CE, HIGH);
  shift_out(address);
  pinMode(DAT, INPUT);
  data = shift_in();
  digitalWrite(CE, LOW);
  return data;
}

// 1302-OVER  *********************************************************************************


// CLOCK-TIME-START   *************************************************************************
void update_now_time()
{
  unsigned int time_data;

  // 这一堆东西一定要括起来，不然会加到15就清零
  time_data = read_1302(0x85); // hour
  //                            31是mask(11111)
  now_time[0] = time_data & 31;

  time_data = read_1302(0x83); // min
  //                   提取前4位        7是mask(0111)
  now_time[1] = (time_data >> 4 & 7) * 10 + (time_data & 15);
}

void set_now_time()
{
  write_1302(0x84, now_time[0]); // hour
  write_1302(0x82, (now_time[1] / 10 << 4) + now_time[1] % 10); // min
}

void update_alarm_time()
{
  /*
    alarm RAM 规范：

                       |       地址       |                     内容                      |
                       |                 |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
    alarm0 时   RAM0   |写0xD0 - 读0xD1   | EN  |      时十位      |         时个位         |
    alarm0 分   RAM1   |写0xD2 - 读0xD3   |  0  |      分十位      |         分个位         |

    EN:0-off 1-on
  */
  unsigned int alarm_time_data;

  alarm_time_data = read_1302(0xD1); // hour
  alarm_data[2] = alarm_time_data >> 7;

  // 这一堆东西一定要括起来，不然会加到15就清零
  //                   提取前4位        7是mask(0111)
  alarm_data[0] = (alarm_time_data >> 4 & 7) * 10 + (alarm_time_data & 15);

  alarm_time_data = read_1302(0xD3); // min
  //                   提取前4位        7是mask(0111)
  alarm_data[1] = (alarm_time_data >> 4 & 7) * 10 + (alarm_time_data & 15);
}

void set_alarm_data()
{
  write_1302(0xD0, (alarm_data[2] << 7) + (alarm_data[0] / 10 << 4) + alarm_data[0] % 10); // hour
  write_1302(0xD2, (alarm_data[1] / 10 << 4) + alarm_data[1] % 10); // min
}
// CLOCK-TIME-OVER   **************************************************************************


// CTRL-START   *******************************************************************************
void alarm()
{
  update_alarm_time();
  if (now_time[0] == alarm_data[0] and now_time[1] == alarm_data[1])
  {
    if (alarm_data[2] == 1  and not alarmed) // true == true ?
    {
      buzzer_on = true;
      alarmed = true;
    }
  }
  else
    alarmed = false;
}


void check_zero()
{
  if (display_num_data[0] == 0)
  {
    display_num_data[0] = 10;
  }
}

void blink_(int hot_num)
{
  if (millis() / 150 % 2 == 0)
  {
    if (hot_num == 0)
    {
      display_num_data[0] = 10;
      display_num_data[1] = 10;
    }
    else
    {
      display_num_data[2] = 10;
      display_num_data[3] = 10;
    }
  }
}

void update_display_num_data()
{
  // mode == 3摇摇棒的情况不写 写在update_display_data里面
  // 为了方便顺便把blink中间双点也改了

  // 先把所有的点清了
  display_data[0][7] = 0;
  display_data[1][7] = 0;
  display_data[2][7] = 0;
  display_data[3][7] = 0;

  if (mode == 0) //时间
  {
    if (show_temp)
    {
      // 显示温度
      if (update_count == 1)
      {
        float R = 22528 / float(analogRead(TEMP)) - 22 ;
        temp = -R * R * R * 0.114  + R * R * 5.33  - 99.907 * R + 828.34; // 扩大10倍
      }

      display_num_data[0] = int(temp) / 100 % 10;
      display_num_data[1] = int(temp) / 10 % 10;
      display_num_data[2] = int(temp) % 10;
      display_num_data[3] = 11; // C
      display_data[1][7] = 1;
    }
    else
    {
      // 正常显示主时间
      display_num_data[0] = now_time[0] / 10;
      display_num_data[1] = now_time[0] % 10;
      display_num_data[2] = now_time[1] / 10;
      display_num_data[3] = now_time[1] % 10;

      check_zero();
      blink_middle();
    }
  }
  else if (mode == 1) // 计时
  {
    if (jishi_running)
    {
      if (jishi)
        total_time = last_end_time + millis() - start_time;
      else
      {
        // 倒计时
        total_time = last_end_time + start_time - millis();
        if (total_time < 0)
        {
          buzzer_on = true;
          last_end_time = 0;
          jishi_running = false; // 停止计时
          jishi = true; // 改成正计时模式
          start_time = millis(); // 后面要立马响铃。所以要计算结束时间
        }
      }
      if (accurate)
      {
        // 更高精度
        display_num_data[0] = total_time / 10000 % 6;
        display_num_data[1] = total_time / 1000 % 10;
        display_num_data[2] = total_time / 100 % 10;
        display_num_data[3] = total_time / 10 % 10;
      }
      else
      {
        // 粗略
        display_num_data[0] = total_time / 600000 % 6;
        display_num_data[1] = total_time / 60000 % 10;
        display_num_data[2] = total_time / 10000 % 6;
        display_num_data[3] = total_time / 1000 % 10;
      }
    }
    else // 没有running
    {
      if (accurate)
      {
        // 更高精度
        display_num_data[0] = last_end_time / 10000 % 6;
        display_num_data[1] = last_end_time / 1000 % 10;
        display_num_data[2] = last_end_time / 100 % 10;
        display_num_data[3] = last_end_time / 10 % 10;
      }
      else
      {
        // 粗略
        display_num_data[0] = last_end_time / 600000 % 6;
        display_num_data[1] = last_end_time / 60000 % 10;
        display_num_data[2] = last_end_time / 10000 % 6;
        display_num_data[3] = last_end_time / 1000 % 10;
      }
    }

    if (not jishi) // 倒计时 右下角的点
      display_data[3][7] = millis() / 100 % 2;

    if (accurate)
      // 更高精度
      display_data[1][7] = 1;
    else
    {
      // 粗略
      if (jishi_running)
        blink_middle();
      else
      {
        display_data[1][7] = 1;
        display_data[2][7] = 1;
      }
    }
  }
  else if (mode == 2) // 闹钟
  {
    display_num_data[0] = alarm_data[0] / 10;
    display_num_data[1] = alarm_data[0] % 10;
    display_num_data[2] = alarm_data[1] / 10;
    display_num_data[3] = alarm_data[1] % 10;

    check_zero();
    display_data[1][7] = 1;
    display_data[2][7] = 1;
    display_data[3][7] = alarm_data[2]; // 是否打开闹钟
  }
  if (edit)
    blink_(hot_num);

}

void blink_middle()
{
  display_data[1][7] = millis() / 500 % 2;
  display_data[2][7] = millis() / 500 % 2;
}

void update_display_data()
{
  // 修改几个点的放在update_display_num_data一并处理了
  for (int digit = 0; digit < 4; digit++)
  {
    if (digit != 2)
    {
      for (int segment = 0; segment < 7; segment++)
      {
        display_data[digit][segment] = (NUM_SHAPE[display_num_data[digit]] >> segment) % 2;
      }
    }
    else
    {
      for (int segment = 0; segment < 7; segment++)
      {
        display_data[digit][TRANSFORM[segment]] = (NUM_SHAPE[display_num_data[digit]] >> segment) % 2;
      }
    }
  }
}

void display_()
{
  for (int digit = 0; digit < 4; digit++)
  {
    for (int segment = 0; segment < 8; segment++)
    {
      digitalWrite(SEGMENT[segment], 1 - display_data[digit][segment]);
    }
    digitalWrite(DIGIT[digit], LOW);
    if (not AUTO_DARK or analogRead(LIGHT) > DETECT_BRIGHTNESS)
      delay(1);
    else
      delayMicroseconds(3);
    digitalWrite(DIGIT[digit], HIGH);
    if (AUTO_DARK and analogRead(LIGHT) <= DETECT_BRIGHTNESS)
      delay(1);
  }

  if (buzzer_on and BUZZER_ENABLE and (millis() - start_time) / 400 % 2 == 0 and (millis() - start_time) / 100 % 2 == 0)
    digitalWrite(BUZZER, HIGH);
  else
    digitalWrite(BUZZER, LOW);
}
// CTRL-OVER   ********************************************************************************

// BTN-START   ********************************************************************************
void btn()
{
  // 读取并设置btn_state状态
  // btn_state 0-无 1-btn1短 2-btn1长 3-btn2短 4-btn2长 5-同时短 6-同时长
  // 按下才是LOW！！！松开是HIGH！！
  if (btn1_press_time > LONG_PRESS_TIME)
  {
    // btn1 长按
    btn_state = 2;
    btn1_press_time = 0;
    lift = 0;
  }
  if (btn2_press_time > LONG_PRESS_TIME)
  {
    // btn2 长按
    btn_state = 4;
    btn2_press_time = 0;
    lift = 0;
  }
  if (btn_both_press_time > LONG_PRESS_TIME)
  {
    // btn 同时长按
    btn_state = 6;
    btn_both_press_time = 0;
    lift = 0;
  }

  if (btn1_press_time > 1 and digitalRead(BTN_1) == HIGH and digitalRead(BTN_2) == HIGH)
  {
    //btn1 短按
    btn_state = 1;
  }
  if (btn2_press_time > 1 and digitalRead(BTN_1) == HIGH and digitalRead(BTN_2) == HIGH)
  {
    //btn2 短按
    btn_state = 3;
  }
  if (btn_both_press_time > 1 and digitalRead(BTN_1) == HIGH and digitalRead(BTN_2) == HIGH)
  {
    //btn 同时短按
    btn_state = 5;
  }

  if (digitalRead(BTN_1) == LOW and lift == 1 and digitalRead(BTN_2) == HIGH)
  {
    btn1_press_time += 1;
  }
  else
  {
    btn1_press_time = 0;
  }
  if (digitalRead(BTN_2) == LOW and lift == 1 and digitalRead(BTN_1) == HIGH)
  {
    btn2_press_time += 1;
  }
  else
  {
    btn2_press_time = 0;
  }
  if (digitalRead(BTN_1) == LOW and lift == 1 and digitalRead(BTN_2) == LOW)
  {
    btn_both_press_time += 1;
  }

  if (digitalRead(BTN_1) == HIGH and digitalRead(BTN_2) == HIGH)
  {
    lift = 1;
    btn_both_press_time = 0;
  }

}

void btn_process()
{
  // 读取btn_state状态，并处理
  // 处理完置0
  // 上面的是btn1
  if (btn_state != 0 and buzzer_on == 1)
  {
    buzzer_on = false;
    btn_state = 0;
  }
  if (btn_state == 1 and not edit) //btn1 短
  {
    mode = (mode + 1) % 3;
    show_temp = false;
    btn_state = 0;
  }
  if (btn_state == 2) //btn1 长
  {
    if (mode == 0 or (mode == 1 and jishi == false and jishi_running == false) or mode == 2)
    {
      if (edit)
      {
        edit = false;
        write_1302(0x8E, 0x80);
      }
      else
      {
        edit = true;
        write_1302(0x8E, 0x00);
      }
      btn_state = 0;
    }
  }

  if (mode == 0) // 时间
  {
    // 以后温度等也可以合并到时间
    // 所以下面的if edit不可以合并
    max_[0] = 24;
    max_[1] = 60;

    if (edit)
    {
      if (btn_state == 1) //btn1 短
      {
        hot_num = 1 - hot_num;
        btn_state = 0;
      }
      if (btn_state == 3) //btn2 短
      {
        now_time[hot_num] = (now_time[hot_num] + 1) % max_[hot_num];
        set_now_time();
        btn_state = 0;
      }
      if (btn_state == 4 and add_state != millis() / 120 % 2) //btn2 长
      {
        add_state = millis() / 120 % 2;
        now_time[hot_num] = (now_time[hot_num] + 1) % max_[hot_num];
        set_now_time();
        if (digitalRead(BTN_2) == HIGH)
          btn_state = 0;
      }
    }
    else if (btn_state == 3)
    {
      if (show_temp)
        show_temp = false;
      else
        show_temp = true;
      btn_state = 0;
    }
  }
  if (mode == 1) // 计时or倒计时
  {
    if (btn_state == 6) // btn_both 长
    {
      if (accurate ) // 修改精度
      {
        accurate = false;
        max_[0] = 24;
        max_[1] = 60;
      }
      else
      {
        accurate = true;
        max_[0] = 60;
        max_[1] = 100;
      }
      btn_state = 0;
    }

    if (jishi) // 计时
    {
      if (btn_state == 3) // btn2 短
      {
        if (jishi_running)
        {
          last_end_time = last_end_time + millis() - start_time;
          jishi_running = false;
        }
        else
        {
          start_time = millis();
          jishi_running = true;
        }
        btn_state = 0;
      }
      if (btn_state == 4) // btn2 长
      {
        if (not jishi_running)
        {
          last_end_time = 0;
        }
        btn_state = 0;
      }
      if (btn_state == 2) // btn1 长
      {
        jishi = false; // 更改至倒计时
        jishi_running = false;
        last_end_time = 0;
        btn_state = 0;
        edit = true;
      }
    }
    else // 倒计时
    {
      if (btn_state == 1) //btn1 短
      {
        hot_num = 1 - hot_num;
        btn_state = 0;
      }
      if (btn_state == 3) //btn2 短
      {
        if (jishi_running)
        {
          jishi_running = false;
          last_end_time = last_end_time + start_time - millis();
        }
        else
        {
          if (edit)
          {
            start_time = 0;
            if (accurate)
            {
              if (hot_num == 0)
                last_end_time += 600;
              else
                last_end_time += 10;
            }
            else
            {
              if (hot_num == 0)
                last_end_time += 60000;
              else
                last_end_time += 1000;
            }
          }
          else if (last_end_time == 0) // 在倒计时时间=0的时候按开始
          {
            start_time = 0;
            jishi = true; // 更改至正计时
          }
          else
          {
            start_time = millis();
            jishi_running = true;
          }
        }
        btn_state = 0;
      }
      if (btn_state == 4) //btn2 长
      {
        if (start_time == 0 and not jishi_running) // 不是停止之后
        {
          if (add_state != millis() / 120 % 2)
          {
            add_state = millis() / 120 % 2;
            if (accurate)
            {
              if (hot_num == 0)
                last_end_time += 600;
              else
                last_end_time += 10;
            }
            else
            {
              if (hot_num == 0)
                last_end_time += 60000;
              else
                last_end_time += 1000;
            }
            if (digitalRead(BTN_2) == HIGH)
              btn_state = 0;
          }
        }
        else // 运行一段时间了
        {
          last_end_time = 0;
        }
      }
    }
  }
  if (mode == 2) // 闹钟
  {
    max_[0] = 24;
    max_[1] = 60;

    if (edit)
    {
      if (btn_state == 1) //btn1 短
      {
        hot_num = 1 - hot_num;
        btn_state = 0;
      }
      if (btn_state == 3) //btn2 短
      {
        alarm_data[hot_num] = (alarm_data[hot_num] + 1) % max_[hot_num];
        set_alarm_data();
        btn_state = 0;
      }
      if (btn_state == 4 and add_state != millis() / 120 % 2) //btn2 长
      {
        add_state = millis() / 120 % 2;
        alarm_data[hot_num] = (alarm_data[hot_num] + 1) % max_[hot_num];
        set_alarm_data();
        if (digitalRead(BTN_2) == HIGH)
          btn_state = 0;
      }
    }
    else if (btn_state == 3) // btn2短
    {
      alarm_data[2] = 1 - alarm_data[2];
      write_1302(0x8E, 0x00); // 写保护off
      set_alarm_data();
      write_1302(0x8E, 0x80); // 写保护on
      btn_state = 0;
    }
  }
}
// BTN-OVER   *********************************************************************************



void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++)
  {
    pinMode(DIGIT[i], OUTPUT);
    digitalWrite(DIGIT[i], HIGH);
  }
  for (int i = 0; i < 8; i++)
  {
    pinMode(SEGMENT[i], OUTPUT);
    digitalWrite(SEGMENT[i], HIGH);
  }

  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);

  pinMode(TEMP, INPUT);
  pinMode(LIGHT, INPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(CLK, OUTPUT);
  pinMode(DAT, OUTPUT);
  pinMode(CE, OUTPUT);
  
  alarmed = true; // 防止上电就响
  if ((read_1302(0x81) >> 7) & 1 == 1)
  {
    write_1302(0x8E, 0x00); // 写保护off
    write_1302(0x80, read_1302(0x81) & 0x7F); // 晶振起震 // bug:每次设置秒之后，毫秒会清零。所以在1s内不断reset的话，时间会卡住不动
  }
  write_1302(0x8E, 0x80); // 写保护on

}

void loop() {
  // put your main code here, to run repeatedly:
  btn();
  btn_process();

  if (update_count == 10)
  {
    update_now_time();
    alarm();
    update_count = 0;
  }
  update_count++;

  update_display_num_data();
  update_display_data();
  display_();
}

