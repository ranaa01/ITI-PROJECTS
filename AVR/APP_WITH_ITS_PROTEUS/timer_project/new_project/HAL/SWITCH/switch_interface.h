/*
 * switch_interface.h
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_

#include "switch_private.h"
#include "switch_confg.h"

SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,SwitchState * Result);

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
