#include <util/delay.h>
#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/led_interface.h"
#include "../HAL/SWITCH/switch_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
#define Pressed       0
#define NOTPressed    1

void main()
{

	u8 Result;
	Switch_Info Switch1= {DIO_GroupB, Pin1, ExternalPullUp};
	Led_info Led1 = {DIO_GroupB,Pin2, Source_Connection};
	 //SW_SwitchErrStateGetState(&Switch1, &Result);
	while(1)
	{
		 SW_SwitchErrStateGetState(&Switch1, &Result);

		if(Result== Pressed)
		{
			Led_LedErrStateTurnOn(&Led1);
		}
		else if (Result== NOTPressed)
		{
			Led_LedErrStateTurnOff(&Led1);
		}
	}
}


