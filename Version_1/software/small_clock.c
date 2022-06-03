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

#define LONG_PRESS_TIME 90 // ����������㳤��

unsigned char DIGIT[4];
unsigned char display_num_data[4];
unsigned char display_data[4][8];
unsigned char display_temp[8];
unsigned char NUM_SHAPE[10];
unsigned char SHAPE_TRANSFORM[8];

unsigned char mode = 0;

unsigned char now_time[2] = {11, 59}; // ��ǰʱ�䡣��mode==0�����¶�ʱ��now_time���Ƶ�display_num_data
unsigned char btn1_press_time, btn2_press_time, btn_both_press_time; // ��¼������ť�������ۼ�ʱ��
unsigned char btn_state, add_state; // btn_state�ǳ���/�̰��ĸ�����add_state����������������¼millis����֮��״̬���Ա��һ��ʱ��������
unsigned char HG_state;
unsigned char max_[2]; // ����λ�������ֵ����̬����
unsigned char hot_num = 0; // �����޸ĵ���ǰ��λ���Ǻ���λ��0/1
unsigned char lift = 1; // �������Ƿ�̧��
unsigned char edit = 0; // �Ƿ��ڱ༭��
float temp = 250; // ����10��
unsigned char show_temp = 0;
unsigned char brightness = 3;
unsigned char max_brightness = 7;
unsigned long running_time=0;
unsigned char running_count = 0; // ���˶�����100�ֻ�


unsigned char jishi = 1; // 1����ʱ��0������ʱ
unsigned char jishi_running; // ��ʱ������
unsigned long start_time; // ��ʱ��ʼʱ��
unsigned long last_end_time = 0; // ���һ��ֹͣ��ʱ�� tips: ÿ����ʾ��ʱ�䶼��ͨ��last_end_time��start_time��running_time������ģ�������Ľ��������total_time
long total_time; // ��ʾ��ʱ�䡣������unsigned��Ϊ����ʱ����С��0
unsigned char accurate = 0;
unsigned char auto_dark_en = 1;

// millis ����ʹ�ö�ʱ��ʵ��

// ʱ�ӣ� /4 /65535 /8 /16=8388608Hz???????(8MHz)
void InitTimer0()
{
	/*
	16 λ TMR0 ʹ�ܺ�����ۼӼ������������� TMR0 ֵ�����ڼĴ��� TMRn_CY ֵ���ʱ������ 1 ��
  ��������� TMRn ���Զ����������ۼӼ���
	*/
	GIE_EN; // ���ж�ʹ��

	TMR0_SYSCLK; // TMR0ʱ��Դѡ��system clock
	TMR0_CYH = 0x08; // ��������2097(.152)��ÿ1�����ж�1�� ���:5����1s
  TMR0_CYL = 0x39;	// 42s0 32 fast 38yyds 14minʱ��fast
	
	TMR0_DIV8_DIS; 	  //�˷�Ƶ��ֹ
	TMR0_PST_1;	      //���ƵΪ1

	TMR0_INT_EN; // ��������һ���жϣ��ж�2��
	INT2_EN; // ���ж�2������

	
	TMR0_EN; // ����ʹ��TMR0��ʼ�ۼ�
	
}

void Timer0Interrupt() interrupt 7 // TMRn��Ӧ�����������2���жϱ����7 datasheetP44
{
  if(TMR0_IF)
	{
		TMR0_IF = 0;
		running_time++;	//ÿ1�����1
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
    ���е�ַ��ͷ����1
    ��ַ���һλ0д1��

                   | ��ַ             |RAM��������
                   |                  |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
    ��             |д0x80 - ��0x81   |  CH |      ��ʮλ     |        ���λ         |
    ��             |д0x82 - ��0x83   |  0  |      ��ʮλ     |        �ָ�λ         |
    ʱ             |д0x84 - ��0x85   |12/24|  0  |   ʱʮλ  |        ʱ��λ         |
    ��             |д0x86 - ��0x87   |     0     |   ��ʮλ  |        �ո�λ         |
    ��             |д0x88 - ��0x89   |        0        |   ��ʮλ  |      �¸�λ     |
    ����           |д0x8A - ��0x8B   |             0               |       ����      |
    ��             |д0x8C - ��0x8D   |         ��ʮλ        |         ���λ        |
    ����           |д0x8E - ��0x8F   |д����|                0                       |
    ���           |д0x90 - ��0x91   | TCS  | TCS | TCS | TCS| DS  | DS  | DS  | DS  |
    ����д��RTC    |д0xCE - ��0xCF   | �����ö��8λ...                              |
    �û�RAM0       |д0xD0 - ��0xD1   | �û��Զ���Ҫд�������                        |
    ...
    �û�RAM31      |д0xFC - ��0xFD   |  �û��Զ���Ҫд�������                       |
    ����д��RAM    |д0xFE - ��0xFF   |  �����ö��8λ...                             |

    CH: 0���� 1ֹͣ
		12/24 0��24,1��12

    д���Ȱ�data���úã��ٰ�CLK���ߣ�������д��
    ��ȡ�����ͣ�����֮��1302������ϱ仯��arduino��ȡ���½��ض�ȡ
    ���Ҷ�ȡʱ����д�룬д��CLK����֮�����ϾͿ��Զ�ȡ��

*/

void shift_out(unsigned int data_)
{
	int i;
	P15_IN_DIS; // DAT
	P15_OUT_EN;
  for (i = 0; i < 8; i++)
  {
    // 1302�ȴ�����ǵ�λ��
    DAT_1302 = data_ >> i & 1;
    //������д����
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
  //ע������ֻ��7��ѭ��.���ߴν����Ϳ��Զ�.����clock������������û����
  for (i = 0; i < 7; i++)
  {
    //�½��ض����� ��shift_out��������֮�����϶�
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

  // ��һ�Ѷ���һ��Ҫ����������Ȼ��ӵ�15������
  time_data = read_1302(0x85); // hour
	//                   ��ȡǰ4λ        7��mask(0111)
  now_time[0] = (time_data >> 4 & 7) * 10 + (time_data & 15);

  time_data = read_1302(0x83); // min
  //                   ��ȡǰ4λ        7��mask(0111)
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
	// �Ȱ����еĵ�����
  display_data[0][2] = 0;
  display_data[1][2] = 0;
  display_data[2][2] = 0;
  display_data[3][2] = 0;
	

	if (mode == 0) //ʱ��
  {

		// ������ʾ��ʱ��
		display_num_data[0]  = now_time[0] / 10;
		display_num_data[1] = now_time[0] % 10;
		display_num_data[2] = now_time[1] / 10;
		display_num_data[3] = now_time[1] % 10;

		check_zero();
		blink_middle();
		
	}
	
	else if (mode == 1) // ��ʱ
  {
    if (jishi_running)
    {
      if (jishi)
        total_time = last_end_time + running_time - start_time;
      else
      {
        // ����ʱ
        total_time = last_end_time + start_time - running_time;
        if (total_time < 0)
        {
          last_end_time = 0;
          jishi_running = 0; // ֹͣ��ʱ
          jishi = 1; // �ĳ�����ʱģʽ
          start_time = running_time;
        }
      }
      if (accurate == 1)
      {
        // ���߾���
        display_num_data[0] = total_time / 10000 % 6;
        display_num_data[1] = total_time / 1000 % 10;
        display_num_data[2] = total_time / 100 % 10;
        display_num_data[3] = total_time / 10 % 10;
      }
      else
      {
        // ����
        display_num_data[0] = total_time / 600000 % 6;
        display_num_data[1] = total_time / 60000 % 10;
        display_num_data[2] = total_time / 10000 % 6;
        display_num_data[3] = total_time / 1000 % 10;
      }
    }
    else // û��running
    {
      if (accurate == 1)
      {
        // ���߾���
        display_num_data[0] = last_end_time / 10000 % 6;
        display_num_data[1] = last_end_time / 1000 % 10;
        display_num_data[2] = last_end_time / 100 % 10;
        display_num_data[3] = last_end_time / 10 % 10;
      }
      else
      {
        // ����
        display_num_data[0] = last_end_time / 600000 % 6;
        display_num_data[1] = last_end_time / 60000 % 10;
        display_num_data[2] = last_end_time / 10000 % 6;
        display_num_data[3] = last_end_time / 1000 % 10;
      }
    }

    if (! jishi) // ����ʱ ���½ǵĵ�
			if(HG_state==0)
				display_data[3][2] = running_time / 100 % 2;
			else
				display_data[0][2] = running_time / 100 % 2;
      

    if (accurate == 1)
		{
      // ���߾���
		  if (jishi_running)
			{
				// �߾����£����й����г���
        if(HG_state==0)
					display_data[1][2] = 1;
				else
					display_data[2][2] = 1;
			}
      else
      {
				// �߾����£�ֹͣʱ�м��������������
				if(HG_state==0)
					display_data[1][2] = running_time / 100 % 2;
				else
					display_data[2][2] = running_time / 100 % 2;
      }
		}
    else
    {
      // ����
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
  // �޸ļ�����ķ���update_display_num_dataһ��������
  for (digit = 0; digit < 4; digit++)
		for (segment = 0; segment < 8; segment++)
			if(segment!=2)
        display_data[digit][segment] = (NUM_SHAPE[display_num_data[digit]] >> segment) % 2;
}

void shift()
{
	int i;
  //����temp
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
  // ��ȡ������btn_state״̬
  // btn_state 0-�� 1-btn1�� 2-btn1�� 3-btn2�� 4-btn2�� 5-ͬʱ�� 6-ͬʱ��
  // ���²���1�������ɿ���0����
  if (btn1_press_time > LONG_PRESS_TIME)
  {
    // btn1 ����
    btn_state = 2;
    btn1_press_time = 0;
    lift = 0;
  }
  if (btn2_press_time > LONG_PRESS_TIME)
  {
    // btn2 ����
    btn_state = 4;
    btn2_press_time = 0;
    lift = 0;
  }
  if (btn_both_press_time > LONG_PRESS_TIME)
  {
    // btn ͬʱ����
    btn_state = 6;
    btn_both_press_time = 0;
    lift = 0;
  }

  if (btn1_press_time > 1 && BTN_1 == 0 && BTN_2 == 0)
  {
    //btn1 �̰�
    btn_state = 1;
  }
  if (btn2_press_time > 1 && BTN_1 == 0 && BTN_2 == 0)
  {
    //btn2 �̰�
    btn_state = 3;
  }
  if (btn_both_press_time > 1 && BTN_1 == 0 && BTN_2 == 0)
  {
    //btn ͬʱ�̰�
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
  // ��ȡbtn_state״̬��������
  // ��������0
  // �������btn1
  if (btn_state == 1 && ! edit) //btn1 ��
  {
    mode = (mode + 1) % 2;
    show_temp = 0;
    btn_state = 0;
  }
  if (btn_state == 2) //btn1 ��
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

  if (mode == 0) // ʱ��
  {
    max_[0] = 24;
    max_[1] = 60;
		if(edit==1)
		{
			if (btn_state == 1) //btn1 ��
			{
				hot_num = 1 - hot_num;
				btn_state = 0;
			}
			if (btn_state == 3) //btn2 ��
			{
				now_time[hot_num] = (now_time[hot_num] + 1) % max_[hot_num];
				set_now_time();
				btn_state = 0;
			}
			if (btn_state == 4 && add_state != running_time / 120 % 2) //btn2 ��
			{
				add_state = running_time / 120 % 2;
				now_time[hot_num] = (now_time[hot_num] + 1) % max_[hot_num];
				set_now_time();
				if (BTN_2 == 0)
					btn_state = 0;
			}
		}
		
		if (btn_state == 5) // btn_both�� �����������
		{
			max_brightness = (max_brightness+1)%8; // ������ʾ��ʱ��Ҫ+2 ������Χ����2-9
			btn_state = 0;
		}
		if (btn_state == 6) // btn_both�� �޸��Զ��ڰ�
		{
		  auto_dark_en = 1-auto_dark_en;
			btn_state = 0;
		}
		
  }
  if (mode == 1) // ��ʱor����ʱ
  {
    if (btn_state == 6) // btn_both ��
    {
      if (accurate == 1) // �޸ľ���
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

    if (jishi) // ��ʱ
    {
      if (btn_state == 3) // btn2 ��
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
      if (btn_state == 4) // btn2 ��
      {
        if (! jishi_running)
        {
          last_end_time = 0;
        }
        btn_state = 0;
      }
      if (btn_state == 2) // btn1 ��
      {
        jishi = 0; // ����������ʱ
        jishi_running = 0;
        last_end_time = 0;
        btn_state = 0;
        edit = 1;
      }
    }
    else // ����ʱ
    {
      if (btn_state == 1) //btn1 ��
      {
        hot_num = 1 - hot_num;
        btn_state = 0;
      }
      if (btn_state == 3) //btn2 ��
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
          else if (last_end_time == 0) // �ڵ���ʱʱ��=0��ʱ�򰴿�ʼ
          {
            start_time = 0;
            jishi = 1; // ����������ʱ
          }
          else
          {
            start_time = running_time;
            jishi_running = 1;
          }
        }
        btn_state = 0;
      }
      if (btn_state == 4) //btn2 ��
      {
        if (start_time == 0 && ! jishi_running) // ����ֹ֮ͣ��
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
        else // ����һ��ʱ����
        {
          last_end_time = 0;
        }
      }
    }
  }
}


void main()
{
  // ʱ����Ƶ8MHz
	WDT_LRC_8192MS;
	SYSCK_DIV4; // ʱ�ӷ�Ƶ 2MHz
	InitTimer0(); // ʵ��running_time
	
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
    write_1302(0x8E, 0x00); // д����off
    write_1302(0x80, read_1302(0x81) & 0x7F); // �������� // bug:ÿ��������֮�󣬺�������㡣������1s�ڲ���reset�Ļ���ʱ��Ῠס����
  }
	write_1302(0x8E, 0x80); // д����on
	
	
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
