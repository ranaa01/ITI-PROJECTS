#include <util/delay.h>
#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/INTERRUPT/INT_Interface.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../HAL/LCD/lcd_interface.h"
#include "../HAL/KEY_PAD/KEY_PAD_interface.h"
#include "../HAL/SWITCH/switch_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"

timer_info t1={normal, pre_8};
lcd_info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB, Pin2,Pin1,Pin0, DIO_GroupA};
lcd_info lcd2={DIO_GroupB,DIO_GroupB,DIO_GroupB, Pin3,Pin4,Pin5, DIO_GroupD};

u8 flag1=1;
u8 flag2=0;
u8 sw=0;
u8 time1[9]= {'0','7',':','1','2',':','3','4', '\0'};
u8 time[9]= {'0','0',':','0','0',':','0','0', '\0'};
void A()
{
	static u16 Counter = 0;
	Counter++;

	if(Counter== 3906){
		if(flag1 ==1 )
		{
			time_lcd();
		}
		else if (flag2 ==1)
		{
			s_w_lcd();
			time_lcd();
		}
			Counter = 0;
	}
}

void s_w_lcd()
{
	if( sw==1)
	{
	for (int i=0; i<8;i++ )
	{
			if (i != 5 && i != 2)
			{
				time[i]= '0';
			}
	}
	sw =0;
	}
				lcd_voidclear( &lcd2);
				lcd_voidclear( &lcd1);
				lcd_voidsendstring(time,&lcd2);
				string_lcd(time);
}
void time_lcd()
{
	if (flag2 ==1)
	{
				string_lcd(time1);
	}
	else
	{
		lcd_voidclear( &lcd1);
		lcd_voidclear( &lcd2);
		lcd_voidsendstring(time1,&lcd1);
		string_lcd(time1);
	}
}
void string_lcd(u8 *time)
{
	u8 flag =0;
	if (time[7]!= '9')
	{
		time[7]= time[7]+1;
	}
	else if  (time[7]== '9')
	{
		time[7]= '0';
		flag = 1;
	}
	if (flag==1)
	{
			time[6]= time[6]+1;
			flag=0;
	}
	if(time[6]== '6' && time[7]== '0')
	{
		time[4]= time[4] +1;
		time[7]= '0';
		time[6]= '0';
	}
	if(time[4]== '9')
	{
		time[4] = 0;
		time[3] = time[3] +1;
	}
	if (time[3]== '6' && time[4]== '0')
	{
		time[1]= time[1]+1;
	}
	if(time[1]== '9')
			{
				time[1] = 0;
				time[0] = time[0] +1;
			}
}
void main()
{
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin2,DIO_Output);
	DIO_ErrStateSetPinValue(DIO_GroupD,Pin2,DIO_High);
	set_timer(&t1);
	lcd_voidinit(&lcd1);
	lcd_voidinit(&lcd2);
	KEY_pad_voidinit();
    u8 r;
    u8 swap;
while(1)
{
	TIMERS_SetCallBack(A);
	Key_Pad_u8GetButtonPressed(&r);
	if (r)
	{
		swap = flag1;
		flag1 = flag2;
		flag2= swap;
		sw =1;
	}
}
}
