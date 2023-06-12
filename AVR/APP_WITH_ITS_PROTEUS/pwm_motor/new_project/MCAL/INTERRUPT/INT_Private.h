/*
 * INT_Private.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ranah
 */

#ifndef MCAL_INTERRUPT_INT_PRIVATE_H_
#define MCAL_INTERRUPT_INT_PRIVATE_H_


typedef enum
{
	EXTI_INT0, //PD2
	EXTI_INT1, //PD3
	EXTI_INT2  //PB2
}EXTI_Type ;

typedef enum
{
	EXTI_Low,
	EXTI_AnyChange,
	EXTI_Falling,
	EXTI_Rising,
}EXTI_SensControl ;

typedef enum
{
	EXTI_Polling ,
	EXTI_Interrupt
}EXTI_EventHandler;

typedef enum
{
	EXTI_TypeErr ,
	EXTI_IntSensErr,
	EXTI_HandlerErr,

}EXTIErrState;

typedef enum
{
	EXTI_ISC00 ,
	EXTI_ISC01,
	EXTI_ISC10 ,
	EXTI_ISC11


}EXTI_MCUCRPin;


typedef enum
{
	EXTI_ISC2=6 ,
}EXTI_MCUCSRPin;

typedef enum
{
	EXTIInterrupt_INT2=5,
	EXTIInterrupt_INT0,
	EXTIInterrupt_INT1

}EXTI_GICRPin;

typedef enum
{
	EXTI_INTF2=5,
	EXTI_INTF0,
	EXTI_INTF1

}EXTI_GIFRPin;

typedef enum
{
    Flag_On ,
	Flag_Err
}FlagState;


typedef struct
{
	EXTI_Type Type ;
	EXTI_SensControl Int_Sens;
	EXTI_EventHandler Handler ;

}EXTI_Info;


#endif /* MCAL_INTERRUPT_INT_PRIVATE_H_ */
