#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/RTOS/RTOS_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"

#define PORTA_ITI    (*(volatile u8*)0x3B)

void led1()
{
	Tog_Bit(PORTA_ITI,Pin2);

}
void led2(void)
{

	Tog_Bit(PORTA_ITI,Pin1);

}
void led3(void)
{

	Tog_Bit(PORTA_ITI,Pin0);

}

void main(void)
{
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin1,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin2,DIO_Output);
	RTOS_voidcreatetask(0,1000,&led1);
	RTOS_voidcreatetask(1,2000,&led2);
	RTOS_voidcreatetask(2,3000,&led3);
	RTOS_voidstart();
	while(1)
	{

	}
}























