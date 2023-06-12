#include <util/delay.h>
#include<stdio.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/7_SEGMENT/SevSeg_Interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
void main()
{
	 SevSeg_info SevenSegment11= {Anode, DIO_GroupC};
	 SevSeg_info SevenSegment12= {Cathod, DIO_GroupD};
	 while (1)
	 {
	SevSeg_SevErrStateSetNumber(3 , &SevenSegment12);
	SevSeg_SevErrStateDisplayRange(&SevenSegment11 ,5 , 8 );
	SevSeg_SevErrStateSetNumber(3 , &SevenSegment11);
	SevSeg_SevErrStateDisplayRange(&SevenSegment12 ,5 , 8 );
	 }
}


