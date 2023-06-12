#include <util/delay.h>
#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/lcd_interface.h"
#include "../HAL/SWITCH/switch_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
#define Pressed       0
#define NOTPressed    1


void main()
{

	//int c[3]= {1,1,1,1};
	//int r[2]= {1,1,1};
	u8 Result;
	u8 Result1;
	/*Clr_Bit(DDRA_ITI,0);
	Clr_Bit(DDRA_ITI,1);
	Clr_Bit(DDRA_ITI,2);
	Clr_Bit(DDRA_ITI,2);*/
	//ddr of r
	DIO_ErrStateSetPinDirection(DIO_GroupC  , Pin0,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupC  , Pin1,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD  , Pin0,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupD  , Pin2,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA , Pin0,DIO_Output);
		DIO_ErrStateSetPinDirection(DIO_GroupA  , Pin1,DIO_Output);
		DIO_ErrStateSetPinDirection(DIO_GroupA  , Pin2,DIO_Output);
		DIO_ErrStateSetPinDirection(DIO_GroupA  , Pin3,DIO_Output);
	DIO_ErrStateSetPinValue(DIO_GroupC  ,Pin0 ,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupC  ,Pin1 ,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupA  ,Pin0 ,DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA  ,Pin1 ,DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA  ,Pin2,DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA ,Pin3 ,DIO_High);

while(1)
{

		DIO_ErrStateSetPinValue(DIO_GroupD  ,Pin0 ,DIO_Low);
		DIO_ErrStateReadPinValue(DIO_GroupD  , Pin0, &Result);


		DIO_ErrStateSetPinValue(DIO_GroupD  ,Pin2 ,DIO_High);
		DIO_ErrStateReadPinValue(DIO_GroupD  , Pin2, &Result1);

		if( Result1 == 1)
		{
			DIO_ErrStateSetPinValue(DIO_GroupC  ,Pin0 ,DIO_High);
		}
		else if (Result == 1)
		{
			DIO_ErrStateSetPinValue(DIO_GroupC  ,Pin1 ,DIO_High);
			DIO_ErrStateSetPinValue(DIO_GroupC  ,Pin0 ,DIO_High);
		}

}


}


