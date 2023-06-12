/*
 * switch_program.c
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */


#include "switch_interface.h"

#include "../../Comman/definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"

SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,SwitchState * Result)
{
	u8 Result1;
	/*
	 * if pullup:
	 * DDR=0 (INPUT)
	 * SWITCH PIN= 1 (HIGH)
	 * so it will only work when the SWITCH PIN gets 0 instead of 1 (pressed)
	 */
	if (Switch->ConnectionType == InternalPullUp )
	    {

	    	//DDR=0
	    	DIO_ErrStateSetPinDirection(Switch->SW_Group ,Switch->SW_Pin, DIO_Input);
	    	//SWITCH PIN= 1 (HIGH)
	    	DIO_ErrStateSetPinValue(Switch->SW_Group ,Switch->SW_Pin, DIO_High);
	    	DIO_ErrStateReadPinValue(Switch->SW_Group ,Switch->SW_Pin,&Result1);
	    	*Result = Result1;

	    }
	else if (Switch->ConnectionType == ExternalPullUp)
	    {
	    	DIO_ErrStateReadPinValue(Switch->SW_Group ,Switch->SW_Pin,&Result1);
	    	*Result = Result1;

	    }
	else if (Switch->ConnectionType == ExternalPullDown )
		{
			//DDR=0
		//	DIO_ErrStateSetPinDirection(Switch->SW_Group ,Switch->SW_Pin, DIO_Input);
			//SWITCH PIN= 0 (LOW)
		//	DIO_ErrStateSetPinValue(Switch->SW_Group ,Switch->SW_Pin, DIO_Low);
			DIO_ErrStateReadPinValue(Switch->SW_Group ,Switch->SW_Pin,&Result1);
			if( Result1==1)
				*Result=0;
			else if(Result1==0)
				*Result=1;

		}
	else
	    {
	    	return ConnectionTypeError;
	    }
}
