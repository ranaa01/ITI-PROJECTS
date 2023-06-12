/*
 * TIMER_Program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: ranah
 */

#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
#include "../../Comman/STD_types.h"
#include "../DIO/DIO_Interface.h"
#include "TIMER_Interface.h"
#include "TIMER_Reg.h"
#include<stdio.h>

void (*ptr_f)(void) = NULL;
void set_timer(timer_info *t)
{
	if (t->t_type== normal)
	{
		Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin3);
		Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin6);
		Set_Bit(TIMSK,Pin0);
		Set_Bit(EXTI_SREG,Pin7);
		Set_Bit(Timer_Counter_Interrupt_Flag_Register_TIFR,Pin0);
	}
	else if(t->t_type== ctc)
	{
		Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin3);
		Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin6);
		Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin5);
		Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin4);
		Set_Bit(TIMSK,Pin1);
		Set_Bit(EXTI_SREG,Pin7);
		Output_Compare_Register_OCR0 = 249;

	}
	switch(t->pre_type){
	case pre_8:    Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
                   Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
                   Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
                   break;
	case pre_64:   Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
	               Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
	               Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
	               break;
	case pre_256:  Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
	               Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
	               Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
		           break;
	case pre_1024: Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
		           Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
		           Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
		           break;
	}
}
/*static void get_ocr()
{

}
static void get_num_of_overflow(u16 o_f)
{


}*/
void Set_PWM(PWM_info *P)
{
	 if(P->PWM_type== PWM_PHASE_CORRECT)
			{

				Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin3);
				Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin6);
				Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin5);
				Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin4);
				Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
				Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
				Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
				Set_Bit(EXTI_SREG,Pin7);
				/*SEt compare match unit register*/
				Output_Compare_Register_OCR0 = 0;
			//	Timer_Counter_Register_TCNT0 = 0;
				//Set_Bit(Timer_Counter_Interrupt_Flag_Register_TIFR,Pin1);
				if(P->PWM_inv_type== PWM_inverting_mode)
			       {
					Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin5);
					Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin4);
		           	}
	     	    else if(P->PWM_inv_type== PWM_nin_inverting_mode)
						{
	     	    	Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin5);
	     	    	Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin4);
						}

			}
		else if(P->PWM_type== PWM_FAST)
				{
                Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin3);
	        	Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin6);

	        	/*SEt compare match unit register*/
	        //	Output_Compare_Register_OCR0 = 125;
	        	//Timer_Counter_Register_TCNT0 = 0;
	        	//Set_Bit(Timer_Counter_Interrupt_Flag_Register_TIFR,Pin1);
	        	if(P->PWM_inv_type== PWM_nin_inverting_mode)
	               {
	        		Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin5);
	        		Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin4);
                   	}
 	            else if(P->PWM_inv_type== PWM_inverting_mode)
	        			{
 	            	Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin5);
 	            	Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin4);
	        			}
				}
	 switch(P->pre_type){
	 	case pre_8:    Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
	                    Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
	                    Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
	                    break;
	 	case pre_64:   Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
	 	               Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
	 	               Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
	 	               break;
	 	case pre_256:  Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
	 	               Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
	 	               Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
	 		           break;
	 	case pre_1024: Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin0);
	 		           Clr_Bit(Timer_Counter_Control_Register_TCCR0,Pin1);
	 		           Set_Bit(Timer_Counter_Control_Register_TCCR0,Pin2);
	 		           break;
	 	}
}
void  TIMERS_Setpwm(u8 copy_cmpare)
{
	Output_Compare_Register_OCR0= copy_cmpare;
}
void  TIMERS_SetCallBack(void(*Copy_pf)(void))
{
		ptr_f =Copy_pf;

}
void __vector_10(void)
{
	if(ptr_f != NULL)
		{
	ptr_f();
		}
}
void __vector_11(void)
{
	if(ptr_f != NULL)
		{
	ptr_f();
		}
}


