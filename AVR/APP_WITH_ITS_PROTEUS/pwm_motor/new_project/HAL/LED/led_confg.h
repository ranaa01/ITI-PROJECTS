/*
 * led_confg.h
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */

#ifndef HAL_LED_LED_CONFG_H_
#define HAL_LED_LED_CONFG_H_

#include "led_private.h"
#include "../../MCAL/DIO/DIO_Private.h"
typedef struct
{
DIO_GroupNumber        Led_Group;
DIO_PinNumber          Led_Pin;
Led_ConnectionType     ConnectionType;
}Led_info;



#endif /* HAL_LED_LED_CONFG_H_ */
