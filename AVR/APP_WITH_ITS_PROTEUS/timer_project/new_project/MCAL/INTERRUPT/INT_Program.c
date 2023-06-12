/*
 * INT_Program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: ranah
 */


#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
#include "../../Comman/STD_types.h"
#include "../DIO/DIO_Interface.h"
#include "INT_Reg.h"
#include "INT_Interface.h"
#include<stdio.h>

void (*ptr_fn)(void) = NULL;
EXTIErrState EXTI_EXTIErrStateInit(EXTI_Info * INT)
{
	if (INT->Type == EXTI_INT0)
	{
		/*Select the Direction as InputPD2*/
		DIO_ErrStateSetPinDirection(DIO_GroupD,Pin2,DIO_Input);
		/*Turn On the Pull Up */
		DIO_ErrStateSetPinValue(DIO_GroupD,Pin2,DIO_High);
		switch(INT->Int_Sens)
		{
		case EXTI_Low :
			Clr_Bit(EXTI_MCUCR,EXTI_ISC00);
			Clr_Bit(EXTI_MCUCR,EXTI_ISC01);
			break ;
		case EXTI_AnyChange:
			Set_Bit(EXTI_MCUCR,EXTI_ISC00);
			Clr_Bit(EXTI_MCUCR,EXTI_ISC01);
			break;
		case EXTI_Falling:
			Clr_Bit(EXTI_MCUCR,EXTI_ISC00);
			Set_Bit(EXTI_MCUCR,EXTI_ISC01);
			break;
		case EXTI_Rising :
			Set_Bit(EXTI_MCUCR,EXTI_ISC00);
			Set_Bit(EXTI_MCUCR,EXTI_ISC01);
			break;
		default : return EXTI_IntSensErr ;
		}
		if (INT->Handler == EXTI_Polling)
		{
			Clr_Bit(EXTI_GICR,EXTIInterrupt_INT0);
		}
		else if(INT->Handler == EXTI_Interrupt)
		{
			Set_Bit(EXTI_GICR,EXTIInterrupt_INT0);//SIE
			Set_Bit(EXTI_SREG,Pin7);//GLOBAL
		}
		else
		{
			return EXTI_HandlerErr;
		}

	}
	else if (INT->Type == EXTI_INT1)
	{
		/*Select the Direction as InputPD3*/
		DIO_ErrStateSetPinDirection(DIO_GroupD,Pin3,DIO_Input);
		/*Turn On the Pull Up */
		DIO_ErrStateSetPinValue(DIO_GroupD,Pin3,DIO_High);
		switch(INT->Int_Sens)
		{
		case EXTI_Low :
			Clr_Bit(EXTI_MCUCR,EXTI_ISC10);
			Clr_Bit(EXTI_MCUCR,EXTI_ISC11);
			break ;
		case EXTI_AnyChange:
			Set_Bit(EXTI_MCUCR,EXTI_ISC10);
			Clr_Bit(EXTI_MCUCR,EXTI_ISC11);
			break;
		case EXTI_Falling:
			Clr_Bit(EXTI_MCUCR,EXTI_ISC10);
			Set_Bit(EXTI_MCUCR,EXTI_ISC11);
			break;
		case EXTI_Rising :
			Set_Bit(EXTI_MCUCR,EXTI_ISC10);
			Set_Bit(EXTI_MCUCR,EXTI_ISC11);
			break;
		default : return EXTI_IntSensErr ;
		}
		if (INT->Handler == EXTI_Polling)
		{
			Clr_Bit(EXTI_GICR,EXTIInterrupt_INT1);
		}
		else if(INT->Handler == EXTI_Interrupt)
		{
			Set_Bit(EXTI_GICR,EXTIInterrupt_INT1);
			Set_Bit(EXTI_SREG,Pin7);
		}
		else
		{
			return EXTI_HandlerErr;
		}
	}
	else if (INT->Type == EXTI_INT2)
	{
		/*Select the Direction as Input PB2*/

		DIO_ErrStateSetPinDirection(DIO_GroupB,Pin2,DIO_Input);
		/*Turn On the Pull Up */
		DIO_ErrStateSetPinValue(DIO_GroupB,Pin2,DIO_High);

		switch(INT->Int_Sens)
		{
		case EXTI_Falling:
				Clr_Bit(EXTI_MCUCSR ,EXTI_ISC2 );
				break ;
		case EXTI_Rising :
				Set_Bit(EXTI_MCUCSR ,EXTI_ISC2 );
				break ;
		default : return EXTI_IntSensErr ;
		}
		if (INT->Handler == EXTI_Polling)
		{
			Clr_Bit(EXTI_GICR,EXTIInterrupt_INT2);
		}
		else if(INT->Handler == EXTI_Interrupt)
		{
			Set_Bit(EXTI_GICR,EXTIInterrupt_INT2);
			Set_Bit(EXTI_SREG,Pin7);
		}
		else
		{
			return EXTI_HandlerErr;
		}
	}
	else
	{
		return EXTI_TypeErr ;
	}


}


FlagState EXTI_FlagStatePollingHandler(EXTI_Info * INT)
{
	if (INT->Type == EXTI_INT0)
	{
		while(Get_Bit(EXTI_GIFR,EXTI_INTF0)==0);
		return Flag_On ;
	}
	else if (INT->Type == EXTI_INT1)
	{
		while(Get_Bit(EXTI_GIFR,EXTI_INTF1)==0);
			return Flag_On ;
	}
	else if (INT->Type == EXTI_INT2)
	{
		while(Get_Bit(EXTI_GIFR,EXTI_INTF2)==0);
			return Flag_On ;
	}
	else
	{
		return Flag_Err ;
	}

}
void __vector_1(void)
{
	if(ptr_fn!=NULL)
    ptr_fn();
}
void setcallback(void(*ptr)(void))
{
	ptr_fn = ptr;
}

