#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/lcd_interface.h"
#include "../HAL/KEY_PAD/KEY_PAD_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../Comman/definition.h"
#include "../Comman/Bit_Math.h"
PWM_info pwm1={PWM_FAST,PWM_inverting_mode,pre_8};
lcd_info lcd1={DIO_GroupB,DIO_GroupB,DIO_GroupB, Pin2,Pin1,Pin0, DIO_GroupA};
int main()
{
	u8 speed=0;
	u8 r;
	lcd_voidinit(&lcd1);
	KEY_pad_voidinit();
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin3,DIO_Output);
	Set_PWM(&pwm1);
	while(1)
	{
		Key_Pad_u8GetButtonPressed(&r);
		if(r)
		{
		if (r!= '=')
		{
			lcd_voidsendchar(r,&lcd1);
			speed= (speed*10) +r;
				}
		}
		 if (r== '.')
		{
			speed= 0;
			lcd_voidclear( &lcd1);
		}

		TIMERS_Setpwm(speed);
	}
}




























