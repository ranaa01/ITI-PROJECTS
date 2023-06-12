#include <util/delay.h>
#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/INTERRUPT/INT_Interface.h"
#include "../HAL/LED/led_interface.h"
#include "../HAL/SWITCH/switch_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
#define Pressed       0
#define NOTPressed    1

void A()
{
	u8 Result;
	Switch_Info Switch1= {DIO_GroupD, Pin2, ExternalPullUp};
	Led_info Led1 = {DIO_GroupB,Pin2, Source_Connection};
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

int main() {
	EXTI_Info INT1 = {EXTI_INT0,EXTI_Rising,EXTI_Interrupt};
    EXTI_EXTIErrStateInit(&INT1);
    Led_info Led2 = {DIO_GroupB,Pin3, Source_Connection};
    u8 R;
    while(1)
    {
    	  R= Get_Bit(0x5A,Pin6);
    	 if(R == 1)
    	    {
    		void (*ptr)() = &A;
    		setcallback(ptr);
    		__vector_1();
    	    }
    }
}
