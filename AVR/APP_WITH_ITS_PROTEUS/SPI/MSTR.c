#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/spi/spi_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
#include <util/delay.h>
//master
void main(void)
{

	        DIO_ErrStateSetPinDirection(DIO_GroupB,Pin5,DIO_Output);
			DIO_ErrStateSetPinDirection(DIO_GroupB,Pin6,DIO_Input);
			DIO_ErrStateSetPinDirection(DIO_GroupB,Pin7,DIO_Output);
			DIO_ErrStateSetPinValue(DIO_GroupB,Pin4,DIO_High);
			DIO_ErrStateSetPinDirection(DIO_GroupB,Pin4,DIO_Input);
			mstr_init();
	while(1)
	{
		send_recieve(1);
		_delay_ms(10);

	}
}




























