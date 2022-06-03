#include "F05_common.h" 
#include "F05_sfr.h" 

#define CLK P0_4
#define DAT P0_5
#define OUT P0_3

#define CLK_1302 P2_0
#define DAT_1302 P1_5
#define RST_1302 P1_4

#define NUM_1 P0_0
#define NUM_2 P1_0
#define NUM_3 P1_1
#define NUM_4 P2_1

#define HG P0_6
#define LIGHT P0_7

#define BTN_1 P1_6
#define BTN_2 P1_7

#define LONG_PRESS_TIME 90 // 超过这个就算长按

unsigned char DIGIT[4];
unsigned char display_num_data[4];
unsigned char display_data[4][8];
unsigned char display_temp[8];
unsigned char NUM_SHAPE[10];
unsigned char SHAPE_TRANSFORM[8];

unsigned char mode = 0;

unsigned char now_time[2] = {11, 59}; // 当前时间。在mode==0，非温度时将now_time复制到display_num_data
unsigned char btn1_press_time, btn2_press_time, btn_both_press_time; // 记录各个按钮长按的累计时间
unsigned char btn_state, add_state; // btn_state是长按/短按哪个键，add_state长按连续加用来记录millis整除之后状态，以便隔一段时间连续加
unsigned char HG_state;
unsigned char max_[2]; // 各个位的最大数值，动态设置
unsigned char hot_num = 0; // 正在修改的是前两位还是后两位，0/1
unsigned char lift = 1; // 长按后是否抬起
unsigned char edit = 0; // 是否处于编辑中
float temp = 250; // 扩大10倍
unsigned char show_temp = 0;
unsigned char brightness = 3;
unsigned char max_brightness = 7;
unsigned long running_time=0;
unsigned char running_count = 0; // 跑了多少轮100轮回


unsigned char jishi = 1; // 1：计时，0，倒计时
unsigned char jishi_running; // 计时运行中
unsigned long start_time; // 计时开始时间
unsigned long last_end_time = 0; // 最后一次停止的时间 tips: 每次显示的时间都是通过last_end_time和start_time和running_time算出来的，算出来的结果保存在total_time
long total_time; // 显示的时间。不能用unsigned因为倒计时可能小于0
unsigned char accurate = 0;
unsigned char auto_dark_en = 1;

// millis 函数使用定时器实现

// 时钟： /4 /65535 /8 /16=8388608Hz???????(8MHz)
void InitTimer0()
{
	/*
	16 位 TMR0 使能后进行累加计数，当计数器 TMR0 值与周期寄存器 TMRn_CY 值相等时，产生 1 次
  计数溢出， TMRn 被自动清零后继续累加计数
	*/
	GIE_EN; // 总中断使能

	TMR0_SYSCLK; // TMR0时钟源选择system clock
	TMR0_CYH = 0x08; // 计数周期2097(.152)，每1毫秒中断1次 误差:5分钟1s
  TMR0_CYL = 0x39;	// 42s0 32 fast 38yyds 14min时候fast
	
	TMR0_DIV8_DIS; 	  //八分频禁止
	TMR0_PST_1;	      //后分频为1

	TMR0_INT_EN; // 溢出后产生一个中断（中断2）
	INT2_EN; // 让中断2起作用

	
	TMR0_EN; // 最后才使能TMR0开始累计
	
}

void Timer0Interrupt() interrupt 7 // TMRn对应的向量编号是2，中断编号是7 datasheetP44
{
  if(TMR0_IF)
	{
		TMR0_IF = 0;
		running_time++;	//每1毫秒加1
	}
}

void short_delay(uint q)
{
	//100ms
	uint i,j;
	for(i=0;i<q;i++)
		for(j=0;j<30;j++)
	    CLR_WDT;
}

// system timing end
// ####################################################################################################################################
// ds1302 start


/* ds1302 datasheet:
    所有地址开头都是1
    地址最后一位0写1读

                   | 地址             |RAM内容意义
                   |                  |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
    秒             |写0x80 - 读0x81   |  CH |      秒十位     |        秒个位         |
    分             |写0x82 - 读0x83   |  0  |      分十位     |        分个位         |
    时             |写0x84 - 读0x85   |12/24|  0  |   时十位  |        时个位         |
    日             |写0x86 - 读0x87   |     0     |   日十位  |        日个位         |
    月             |写0x88 - 读0x89   |        0        |   月十位  |      月个位     |
    星期           |写0x8A - 读0x8B   |             0               |       星期      |
    年             |写0x8C - 读0x8D   |         年十位        |         年个位        |
    控制           |写0x8E - 读0x8F   |写保护|                0                       |
    充电           |写0x90 - 读0x91   | TCS  | TCS | TCS | TCS| DS  | DS  | DS  | DS  |
    批量写入RTC    |写0xCE - 读0xCF   | 连续好多个8位...                              |
    用户RAM0       |写0xD0 - 读0xD1   | 用户自定义要写入的内容                        |
    ...
    用户RAM31      |写0xFC - 读0xFD   |  用户自定义要写入的内容                       |
    批量写入RAM    |写0xFE - 读0xFF   |  连续好多个8位...                             |

    CH: 0运行 1停止
		12/24 0是24,1是12

    写入先把data设置好，再把CLK拉高，上升沿写入
    读取先拉低，拉低之后1302输出马上变化，arduino读取。下降沿读取
    而且读取时，先写入，写入CLK拉低之后马上就可以读取。

*/

void shift_out(unsigned int data_)
{
	int i;
	P15_IN_DIS; // DAT
	P15_OUT_EN;
  for (i = 0; i < 8; i++)
  {
    // 1302先传入的是低位的
    DAT_1302 = data_ >> i & 1;
    //上升沿写数据
    CLK_1302 = 1;
		
    CLK_1302 = 0;
		
  }
}

unsigned int shift_in()
{
	int i;
  unsigned int data_ = 0;
	P15_OUT_DIS; // DAT
	P15_IN_EN;
  //注意这里只有7次循环.第七次结束就可以读.后面clock的拉高再拉低没有用
  for (i = 0; i < 7; i++)
  {
    //下降沿读数据 在shift_out函数拉低之后马上读
		if (DAT_1302==1)
			data_ |= 1 << i;
    CLK_1302 = 1;
		
    CLK_1302 = 0;
		
  }
	if (DAT_1302==1)
		data_ |= 1 << 7;
  return data_;
}

void write_1302(unsigned int address, unsigned int data_)
{
	P15_IN_DIS; // DAT
	P15_OUT_EN;
  DAT_1302 = 0;
	
  RST_1302 = 0;
	
  RST_1302 = 1;
	
  shift_out(address);
  shift_out(data_);
  RST_1302 = 0;
	
}

unsigned int read_1302(unsigned int address)
{
  unsigned int data_;

  DAT_1302 = 0;
  RST_1302 = 0;
  RST_1302 = 1;
  shift_out(address);
  data_ = shift_in();
  RST_1302 = 0;
  return data_;
}


// ds1302 end
// ####################################################################################################################################
// // ds1302 ctrl start

void update_now_time()
{
  unsigned int time_data;

  // 这一堆东西一定要括起来，不然会加到15就清零
  time_data = read_1302(0x85); // hour
	//                   提取前4位        7是mask(0111)
  now_time[0] = (time_data >> 4 & 7) * 10 + (time_data & 15);

  time_data = read_1302(0x83); // min
  //                   提取前4位        7是mask(0111)
  now_time[1] = (time_data >> 4 & 7) * 10 + (time_data & 15);
}

void set_now_time()
{
  write_1302(0x84, (now_time[0] / 10 << 4) + now_time[0] % 10); // hour
  write_1302(0x82, (now_time[1] / 10 << 4) + now_time[1] % 10); // min
}

// ds1302 ctrl end
// ####################################################################################################################################
// clock ctrl start

void check_zero()
{
  if (display_num_data[0] == 0)
  {
    display_num_data[0] = 10;
  }
}

void blink_middle()
{
	if(HG_state==0)
  display_data[1][2] = running_time / 500 % 2;
	else
		display_data[2][2] = running_time / 500 % 2;
}

void blink_(int hot_num)
{
  if (running_time / 150 % 2 == 0)
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
	// 先把所有的点清了
  display_data[0][2] = 0;
  display_data[1][2] = 0;
  display_data[2][2] = 0;
  display_data[3][2] = 0;
	

	if (mode == 0) //时间
  {

		// 正常显示主时间
		display_num_data[0]  = now_time[0] / 10;
		display_num_data[1] = now_time[0] % 10;
		display_num_data[2] = now_time[1] / 10;
		display_num_data[3] = now_time[1] % 10;

		check_zero();
		blink_middle();
		
	}
	
	else if (mode == 1) // 计时
  {
    if (jishi_running)
    {
      if (jishi)
        total_time = last_end_time + running_time - start_time;
      else
      {
        // 倒计时
        total_time = last_end_time + start_time - running_time;
        if (total_time < 0)
        {
          last_end_time = 0;
          jishi_running = 0; // 停止计时
          jishi = 1; // 改成正计时模式
          start_time = running_time;
        }
      }
      if (accurate == 1)
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
      if (accurate == 1)
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

    if (! jishi) // 倒计时 右下角的点
			if(HG_state==0)
				display_data[3][2] = running_time / 100 % 2;
			else
				display_data[0][2] = running_time / 100 % 2;
      

    if (accurate == 1)
		{
      // 更高精度
		  if (jishi_running)
			{
				// 高精度下，运行过程中常亮
        if(HG_state==0)
					display_data[1][2] = 1;
				else
					display_data[2][2] = 1;
			}
      else
      {
				// 高精度下，停止时中间两个电快速闪动
				if(HG_state==0)
					display_data[1][2] = running_time / 100 % 2;
				else
					display_data[2][2] = running_time / 100 % 2;
      }
		}
    else
    {
      // 粗略
      if (jishi_running)
        blink_middle();
      else
      {
        if(HG_state==0)
					display_data[1][2] = 1;
				else
					display_data[2][2] = 1;
      }
    }
  }
  if (edit)
    blink_(hot_num);

}


void update_display_data()
{
	int digit;
	int segment;
  // 修改几个点的放在update_display_num_data一并处理了
  for (digit = 0; digit < 4; digit++)
		for (segment = 0; segment < 8; segment++)
			if(segment!=2)
        display_data[digit][segment] = (NUM_SHAPE[display_num_data[digit]] >> segment) % 2;
}

void shift()
{
	int i;
  //读入temp
  OUT = 0;
  for (i = 0; i < 8; i++)
  {
    CLK = 0;
    DAT = display_temp[i];
    CLK =  1;
  }
  OUT = 1;
}

void display()
{
	int copy;
	if(HG_state==0)
	{
		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[0][copy];
		}
		shift();
		NUM_1 =  1;
		short_delay(brightness);
		NUM_1  =  0;
		short_delay(10-brightness);

		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[1][copy];
		}
		shift();
		NUM_2  =  1;
		short_delay(brightness);
		NUM_2  =  0;
		short_delay(10-brightness);
		
		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[2][copy];
		}
		shift();
		NUM_3  =  1;
		short_delay(brightness);
		NUM_3  =  0;
		short_delay(10-brightness);
		
		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[3][copy];
		}
		shift();
		NUM_4  =  1;
		short_delay(brightness);
		NUM_4  =  0;
		short_delay(10-brightness);
	}
	else
	{
		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[3][SHAPE_TRANSFORM[copy]];
		}
		shift();
		NUM_1 =  1;
		short_delay(brightness);
		NUM_1  =  0;
		short_delay(10-brightness);

		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[2][SHAPE_TRANSFORM[copy]];
		}
		shift();
		NUM_2  =  1;
		short_delay(brightness);
		NUM_2  =  0;
		short_delay(10-brightness);
		
		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[1][SHAPE_TRANSFORM[copy]];
		}
		shift();
		NUM_3  =  1;
		short_delay(brightness);
		NUM_3  =  0;
		short_delay(10-brightness);
		
		for (copy = 0; copy < 8; copy++)
		{
			display_temp[copy] = display_data[0][SHAPE_TRANSFORM[copy]];
		}
		shift();
		NUM_4  =  1;
		short_delay(brightness);
		NUM_4  =  0;
		short_delay(10-brightness);

	}
}

// ####################################################################################################################################
// BTN start

void btn()
{
  // 读取并设置btn_state状态
  // btn_state 0-无 1-btn1短 2-btn1长 3-btn2短 4-btn2长 5-同时短 6-同时长
  // 按下才是1！！！松开是0！！
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

  if (btn1_press_time > 1 && BTN_1 == 0 && BTN_2 == 0)
  {
    //btn1 短按
    btn_state = 1;
  }
  if (btn2_press_time > 1 && BTN_1 == 0 && BTN_2 == 0)
  {
    //btn2 短按
    btn_state = 3;
  }
  if (btn_both_press_time > 1 && BTN_1 == 0 && BTN_2 == 0)
  {
    //btn 同时短按
    btn_state = 5;
  }

  if (BTN_1 == 1 && lift == 1 && BTN_2 == 0)
  {
    btn1_press_time += 1;
  }
  else
  {
    btn1_press_time = 0;
  }
  if (BTN_2 == 1 && lift == 1 && BTN_1 == 0)
  {
    btn2_press_time += 1;
  }
  else
  {
    btn2_press_time = 0;
  }
  if (BTN_1 == 1 && lift == 1 && BTN_2 == 1)
  {
    btn_both_press_time += 1;
  }

  if (BTN_1 == 0 && BTN_2 == 0)
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
  if (btn_state == 1 && ! edit) //btn1 短
  {
    mode = (mode + 1) % 2;
    show_temp = 0;
    btn_state = 0;
  }
  if (btn_state == 2) //btn1 长
  {
    if (mode == 0 || (mode == 1 && jishi == 0 && jishi_running == 0) || mode == 2)
    {
      if (edit)
      {
        edit = 0;
        write_1302(0x8E, 0x80);
      }
      else
      {
        edit = 1;
        write_1302(0x8E, 0x00);
      }
      btn_state = 0;
    }
  }

  if (mode == 0) // 时间
  {
    max_[0] = 24;
    max_[1] = 60;
		if(edit==1)
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
			if (btn_state == 4 && add_state != running_time / 120 % 2) //btn2 长
			{
				add_state = running_time / 120 % 2;
				now_time[hot_num] = (now_time[hot_num] + 1) % max_[hot_num];
				set_now_time();
				if (BTN_2 == 0)
					btn_state = 0;
			}
		}
		
		if (btn_state == 5) // btn_both短 调整最大亮度
		{
			max_brightness = (max_brightness+1)%8; // 后面显示的时候还要+2 这样范围就是2-9
			btn_state = 0;
		}
		if (btn_state == 6) // btn_both长 修改自动黑暗
		{
		  auto_dark_en = 1-auto_dark_en;
			btn_state = 0;
		}
		
  }
  if (mode == 1) // 计时or倒计时
  {
    if (btn_state == 6) // btn_both 长
    {
      if (accurate == 1) // 修改精度
      {
        accurate = 0;
        max_[0] = 24;
        max_[1] = 60;
      }
      else
      {
        accurate = 1;
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
          last_end_time = last_end_time + running_time - start_time;
          jishi_running = 0;
        }
        else
        {
          start_time = running_time;
          jishi_running = 1;
        }
        btn_state = 0;
      }
      if (btn_state == 4) // btn2 长
      {
        if (! jishi_running)
        {
          last_end_time = 0;
        }
        btn_state = 0;
      }
      if (btn_state == 2) // btn1 长
      {
        jishi = 0; // 更改至倒计时
        jishi_running = 0;
        last_end_time = 0;
        btn_state = 0;
        edit = 1;
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
          jishi_running = 0;
          last_end_time = last_end_time + start_time - running_time;
        }
        else
        {
          if (edit)
          {
            start_time = 0;
            if (accurate == 1)
            {
              if (hot_num == 0)
                last_end_time += 1000;
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
            jishi = 1; // 更改至正计时
          }
          else
          {
            start_time = running_time;
            jishi_running = 1;
          }
        }
        btn_state = 0;
      }
      if (btn_state == 4) //btn2 长
      {
        if (start_time == 0 && ! jishi_running) // 不是停止之后
        {
          if (add_state != running_time / 120 % 2)
          {
            add_state = running_time / 120 % 2;
            if (accurate == 1)
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
            if (BTN_2 == 0)
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
}


void main()
{
  // 时钟主频8MHz
	WDT_LRC_8192MS;
	SYSCK_DIV4; // 时钟分频 2MHz
	InitTimer0(); // 实现running_time
	
	P04_OUT_EN; // CLK
	P05_OUT_EN; // DAT
	P03_OUT_EN; // RST
	
	P20_OUT_EN; // CLK_1302
	P15_OUT_EN; // DAT_1302
	P14_OUT_EN; // RST_1302
	
	P00_OUT_EN; // NUM_1
	P10_OUT_EN; // NUM_2
	P11_OUT_EN; // NUM_3
	P21_OUT_EN; // NUM_4
	
	P06_IN_EN; // HG
	P07_IN_EN; // LIGHT
	
	P16_IN_EN; // BTN_1
	P17_IN_EN; // BTN_2
	
	DIGIT[0] = NUM_1;
	DIGIT[1] = NUM_2;
	DIGIT[2] = NUM_3;
	DIGIT[3] = NUM_4;
	

	NUM_SHAPE[0] = 0xFA;
	NUM_SHAPE[1] = 0x22;
	NUM_SHAPE[2] = 0xB9;
	NUM_SHAPE[3] = 0xAB;
	NUM_SHAPE[4] = 0x63;
	NUM_SHAPE[5] = 0xCB;
	NUM_SHAPE[6] = 0xDB;
	NUM_SHAPE[7] = 0xA2;
	NUM_SHAPE[8] = 0xFB;
	NUM_SHAPE[9] = 0xEB;
	NUM_SHAPE[10] = 0x00; // EMPTY
	
	SHAPE_TRANSFORM[0] = 0;
	SHAPE_TRANSFORM[1] = 6;
	SHAPE_TRANSFORM[2] = 2;
	SHAPE_TRANSFORM[3] = 7;
	SHAPE_TRANSFORM[4] = 5;
	SHAPE_TRANSFORM[5] = 4;
	SHAPE_TRANSFORM[6] = 1;
	SHAPE_TRANSFORM[7] = 3;

	
  if ((read_1302(0x81) >> 7) & 1 == 1)
  {
    write_1302(0x8E, 0x00); // 写保护off
    write_1302(0x80, read_1302(0x81) & 0x7F); // 晶振起震 // bug:每次设置秒之后，毫秒会清零。所以在1s内不断reset的话，时间会卡住不动
  }
	write_1302(0x8E, 0x80); // 写保护on
	
	
	while(1)
	{
		btn();
		btn_process();
		
		if (running_count==0)
		{
			update_now_time();
			HG_state = HG;
			if(auto_dark_en==1 && LIGHT==0)
				brightness = 1;
			else
				brightness=max_brightness+2;
		}
		update_display_num_data();
		update_display_data();
		display();
		running_count = (running_count+1)%20;
	}
}
