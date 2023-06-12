/*
 * led_program.c
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */


#include "led_interface.h"

#include "../../Comman/definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"

LedErrState	Led_LedErrStateTurnOn(Led_info *Led)
{
	 DIO_ErrStateSetPinDirection(Led->Led_Group, Led->Led_Pin, DIO_Output);
			switch(Led->ConnectionType)
			{
			/* if Led_ConnectionType is SOURCE the (HIGH) pin will be connected to the led  */
			case 0: DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_High); break;
			/* if Led_ConnectionType is SINK the (LOW) pin will be connected to the led  */
			case 1: DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_Low); break;
			default:
						return ConectionError;
			}
}
LedErrState	Led_LedErrStateTurnOff(Led_info *Led)
{
	//I am not sure how to implement this in efficient way
	 DIO_ErrStateSetPinDirection(Led->Led_Group, Led->Led_Pin, DIO_Output);
				switch(Led->ConnectionType)
				{
				/* if Led_ConnectionType is SOURCE the (HIGH) pin will be connected to the led  */
				case 0: DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_Low); break;
				/* if Led_ConnectionType is SINK the (LOW) pin will be connected to the led  */
				case 1: DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_High); break;
				default:
							return ConectionError;

				}
}


