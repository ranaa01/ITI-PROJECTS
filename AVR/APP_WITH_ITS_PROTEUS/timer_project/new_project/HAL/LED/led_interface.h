/*
 * led_interface.h
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "led_private.h"
#include "led_confg.h"

LedErrState	Led_LedErrStateTurnOn(Led_info *Led);
LedErrState	Led_LedErrStateTurnOff(Led_info *Led);


#endif /* HAL_LED_LED_INTERFACE_H_ */
