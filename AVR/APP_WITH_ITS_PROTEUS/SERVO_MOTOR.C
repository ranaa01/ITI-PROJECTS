#include <util/delay.h>
#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/INTERRUPT/INT_Interface.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../HAL/LED/led_interface.h"
#include "../HAL/SWITCH/switch_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
#define Pressed       0
#define NOTPressed    1
#define PORTD_ITI    (*(volatile u8*)0x32)
//Led_info Led1 = {DIO_GroupB,Pin2, Source_Connection};
timer_info t1={ctc, pre_1};
u8 Main_u8ServoAngle = 0u;
void A()
{
	static u16 Counter = 0;
	Counter++;
	if(Counter== Main_u8ServoAngle){
		Clr_Bit(PORTD_ITI,Pin2);
	}
	if(Counter ==800u)
	{
			Set_Bit(PORTD_ITI,Pin2);
			Counter = 0;
	}
}
void main()
{

	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin2,DIO_Output);
//	DIO_ErrStateSetPinValue(DIO_GroupD,Pin2,DIO_High);
	set_timer(&t1);
	TIMERS_SetCallBack(A);
	while(1)
		{
			Main_u8ServoAngle = 20u;
			_delay_ms(1000);
			Main_u8ServoAngle = 60u;
			_delay_ms(1000);
			Main_u8ServoAngle = 100u;
			_delay_ms(1000);
		}
}
