#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/spi/spi_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
#include <util/delay.h>
//slave
void main(void)
{

	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin5,DIO_Input);
			DIO_ErrStateSetPinDirection(DIO_GroupB,Pin6,DIO_Output);
			DIO_ErrStateSetPinDirection(DIO_GroupB,Pin7,DIO_Input);
		//	DIO_ErrStateSetPinValue(DIO_GroupB,Pin4,DIO_High);
			DIO_ErrStateSetPinDirection(DIO_GroupB,Pin4,DIO_Input);
			DIO_ErrStateSetPinDirection(DIO_GroupA,Pin7,DIO_Output);
			//DIO_ErrStateSetPinValue(DIO_GroupB,Pin0,DIO_High);
			slave_init();
			u8 data1;
	while(1)
	{
		data1= send_recieve(10);
		_delay_ms(10);
		if(data1==1)
		{
			DIO_ErrStateSetPinValue(DIO_GroupA,Pin7,DIO_High);
		}

	}
}




























