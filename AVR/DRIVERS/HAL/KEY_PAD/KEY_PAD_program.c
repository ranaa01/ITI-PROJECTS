/*
 * KEY_PAD.c
 *
 *  Created on: Oct 24, 2022
 *      Author: abdullah
 */


#include"KEY_PAD_Pcfg.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include<util\delay.h>
#include"../../Comman/STD_types.h"
#include"../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
#include"KEY_PAD_interface.h"
#include"KEY_PAD_private.h"

u8 KEY_PAD_array[8] = KEY_PAD_ARRAY;

void KEY_pad_voidinit(void)
{
	u8 LOC_u8_iterator;
	for( LOC_u8_iterator=0;LOC_u8_iterator<KEY_PAD_ROWSIZE;LOC_u8_iterator++)
		{
			DIO_ErrStateSetPinDirection(DIO_GroupC,KEY_PAD_array[LOC_u8_iterator],DIO_Input);
			DIO_ErrStateSetPinValue (DIO_GroupC,KEY_PAD_array[LOC_u8_iterator], DIO_High);
		}
		for(u8 LOC_u8_iterator=4;LOC_u8_iterator<(KEY_PAD_COLSIZE+KEY_PAD_ROWSIZE);LOC_u8_iterator++)
		{
			DIO_ErrStateSetPinDirection(DIO_GroupC,KEY_PAD_array[LOC_u8_iterator],DIO_Output);
		    DIO_ErrStateSetPinValue (DIO_GroupC,KEY_PAD_array[LOC_u8_iterator],DIO_High);
		}

}
void Key_Pad_u8GetButtonPressed(u8 *r) // returns the ascii code of the button pressed in the keypad values array
{
	u8 LOC_u8coliterator=0;
	u8 LOC_u8rowiterator=0;
	u8 LOC_u8switchpressed=0;
	u8 LOC_u8flag=0;
	u8 Result;
	for(LOC_u8coliterator=KEY_PAD_ROWSIZE;LOC_u8coliterator<(KEY_PAD_ROWSIZE+KEY_PAD_COLSIZE)&&LOC_u8flag==0;LOC_u8coliterator++)
	{
		   DIO_ErrStateSetPinValue(DIO_GroupC, KEY_PAD_array[LOC_u8coliterator] ,DIO_Low);
		for(LOC_u8rowiterator=0;LOC_u8rowiterator<KEY_PAD_ROWSIZE&&LOC_u8flag==0;LOC_u8rowiterator++)
		{
			 DIO_ErrStateReadPinValue(DIO_GroupC,KEY_PAD_array[LOC_u8rowiterator] , &Result);
	//		LOC_u8SW_state= DIO_ErrStateReadPinValue(DIO_GroupA,KEY_PAD_array[LOC_u8rowiterator]);
		if(Result==DIO_Low)//becasuse of internal pullup
		{
			_delay_ms(15);//check for bouncing effect
			 DIO_ErrStateReadPinValue(DIO_GroupC,KEY_PAD_array[LOC_u8rowiterator], &Result);

			if(Result==DIO_Low)
			{
				LOC_u8switchpressed=KEY_PAD_values[LOC_u8rowiterator][LOC_u8coliterator-KEY_PAD_COLSIZE];//3SHAN msh bad2 mn 0
				while(Result==DIO_Low) //this prevents to multiple effect for long  press at the same time ;
				{
					 DIO_ErrStateReadPinValue(DIO_GroupC,KEY_PAD_array[LOC_u8rowiterator], &Result);
				}
                LOC_u8flag=1;
			}
		}
		}
		DIO_ErrStateSetPinValue(DIO_GroupC,KEY_PAD_array[LOC_u8coliterator],DIO_High);
		//at the end for each col set it at 5V
	}
*r = LOC_u8switchpressed;


}



















