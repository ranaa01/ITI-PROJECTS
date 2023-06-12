/*
 * led_private.h
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */

#ifndef HAL_LED_LED_PRIVATE_H_
#define HAL_LED_LED_PRIVATE_H_


typedef enum
{
	ConectionError,
	 on,
	 off
}LedErrState;

typedef enum {
	Source_Connection ,
	Sink_Connection

}Led_ConnectionType;

#endif /* HAL_LED_LED_PRIVATE_H_ */
