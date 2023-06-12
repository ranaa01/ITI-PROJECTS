#include <util/delay.h>
#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/lcd_interface.h"
#include "../HAL/SWITCH/switch_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
#define Pressed       0
#define NOTPressed    1

#define DDRA_ITI        (*(volatile u8*)0x3A)
#define DDRB_ITI		(*(volatile u8*)0x37)

#define PORTA_ITI       (*(volatile u8*)0x3B)
#define PORTB_ITI		(*(volatile u8*)0x38)

#define PINA_ITI		(*(volatile u8*)0x39)
#define PINB_ITI		(*(volatile u8*)0x36)


void main()
{

	//int c[3]= {1,1,1,1};
	//int r[2]= {1,1,1};
	u8 Result;

	//ddr of c
	DIO_ErrStateSetPinDirection(DIO_GroupA  , Pin0,DIO_Input);
	DIO_ErrStateSetPinDirection(DIO_GroupA  , Pin1,DIO_Input);
	DIO_ErrStateSetPinDirection(DIO_GroupA  , Pin2,DIO_Input);
	DIO_ErrStateSetPinDirection(DIO_GroupA  , Pin3,DIO_Input);
	/*Clr_Bit(DDRA_ITI,0);
	Clr_Bit(DDRA_ITI,1);
	Clr_Bit(DDRA_ITI,2);
	Clr_Bit(DDRA_ITI,2);*/
	//ddr of r
	DIO_ErrStateSetPinDirection(DIO_GroupB  , Pin0,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupB  , Pin1,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupB  , Pin2,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupB  , Pin3,DIO_Output);
	/*Set_Bit(DDRB_ITI , 0 ) ;
	Set_Bit(DDRB_ITI , 1 ) ;
	Set_Bit(DDRB_ITI , 2 ) ;
	Set_Bit(DDRB_ITI , 3 ) ;*/
	//c inputs pins = 1
	DIO_ErrStateSetPinValue(DIO_GroupA  ,Pin0 ,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupA  ,Pin1 ,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupA  ,Pin2 ,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupA  ,Pin3 ,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupB  ,Pin0 ,DIO_High);
	DIO_ErrStateSetPinValue(DIO_GroupB  ,Pin1 ,DIO_High);
	DIO_ErrStateSetPinValue(DIO_GroupB  ,Pin2 ,DIO_High);
	DIO_ErrStateSetPinValue(DIO_GroupB  ,Pin3 ,DIO_High);
	/*Set_Bit(PORTA_ITI,0);
	Set_Bit(PORTA_ITI,1);
	Set_Bit(PORTA_ITI,2);
	Set_Bit(PORTA_ITI,3);
	Set_Bit(PORTB_ITI,0);
	Set_Bit(PORTB_ITI,1);
	Set_Bit(PORTB_ITI,2);
	Set_Bit(PORTB_ITI,3);*/
	 lcd_info lcd1= {DIO_GroupB, DIO_GroupB, DIO_GroupB, Pin2, Pin1, Pin0, DIO_Low};
	 lcd_voidinit(&lcd1);
	 //Switch_Info Switch1= {DIO_GroupB, Pin2, 0};
	 int flag=0;
	while(1)
	{

		char c_r[4][4] = {{'A', 'B', 'C', 'D'},
				          {'E', 'F', 'H', 'I'},
						  {'J', 'K', 'L', 'M'},
						  {'X', 'Y', 'Z', 'W'}};

		for (int i=0; i<4; i++)
			{
				DIO_ErrStateSetPinValue(DIO_GroupB  ,i,DIO_Low);
				for (int j=0; j<4; j++)
							{
					DIO_ErrStateReadPinValue(DIO_GroupA  , j, &Result);
					if(Result == 0)
					{
						//DIO_ErrStateSetPinValue(DIO_GroupB  ,i+4,DIO_High);
						 lcd_voidsendchar(c_r[j][i],&lcd1);

						 flag++;
						 break;
					}
							}
				DIO_ErrStateSetPinValue(DIO_GroupB  ,i,DIO_High);
				if(flag>0)
						{
							break;
						}

			}

	}


}


