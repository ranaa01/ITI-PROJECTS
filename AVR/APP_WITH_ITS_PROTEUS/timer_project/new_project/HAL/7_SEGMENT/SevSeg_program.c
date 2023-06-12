/*
 * SevSeg_program.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */
#include "../../Comman/definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SevSeg_Interface.h"
#include <util/delay.h>

SevErrState SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1){
	DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group ,0xff);
//	DIO_ErrStateSetPinDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState);
		if (SevenSegment1->SevSeg_Type1 ==   Cathod)
		{

			/*Cathod -> Led On if write One*/
			switch (Copy_Number)
			{
					case 0:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x3F);break;
					case 1:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x06);break;
					case 2:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x5B);break;
					case 3:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x4F);break;
					case 4:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x66);break;
					case 5:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x6D);break;
					case 6:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x7D);break;
					case 7:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x07);break;
					case 8:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x7F);break;
					case 9:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x6F);break;
					default: return WrongPort;

			}
			return NoError;
		}
		else if (SevenSegment1->SevSeg_Type1 == Anode)
				{

					/*Cathod -> Led On if write One*/
					switch (Copy_Number)
					{
							case 0:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xC0);break;
							case 1:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xF9);break;
							case 2:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xA4);break;
							case 3:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xB0);break;
							case 4:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x99);break;
							case 5:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x92);break;
							case 6:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x82);break;
							case 7:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xF8);break;
							case 8:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x00);break;
							case 9:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x90);break;
							default: return WrongPort;
					}

					return NoError;
				}
		else {
			return WrongType;
		     }

}

SevErrState SevSeg_SevErrStateDisplayRange(SevSeg_info *SevenSegment1 , u8 Copy_start , u8 Copy_End )
{
	DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group ,0xff);
	if (SevenSegment1->SevSeg_Type1 ==   Cathod)
			{
		for (int i =Copy_start; i<=Copy_End; i++ )
		{
				switch (i)
				{
						case 0:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x3F);break;
						case 1:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x06);break;
						case 2:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x5B);break;
						case 3:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x4F);break;
						case 4:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x66);break;
						case 5:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x6D);break;
						case 6:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x7D);break;
						case 7:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x07);break;
						case 8:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x7F);break;
						case 9:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x6F);break;
						default: return WrongPort;

				}
				_delay_ms(500);

		}
		return NoError;
			}
			else if (SevenSegment1->SevSeg_Type1 == Anode)
					{
				for (int i =Copy_start; i<=Copy_End; i++ )
					{
							switch (i)
							{
								case 0:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xC0);break;
								case 1:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xF9);break;
								case 2:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xA4);break;
								case 3:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xB0);break;
								case 4:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x99);break;
								case 5:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x92);break;
								case 6:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x82);break;
								case 7:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0xF8);break;
								case 8:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x00);break;
								case 9:DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group ,0x90);break;
								default: return WrongPort;
						}
							_delay_ms(500);

							}
				return NoError;

					}
			else {
				return WrongType;
			     }
}
//SevErrState SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1);
