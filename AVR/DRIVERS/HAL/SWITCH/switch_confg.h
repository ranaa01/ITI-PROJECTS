/*
 * switch_confg.h
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */

#ifndef HAL_SWITCH_SWITCH_CONFG_H_
#define HAL_SWITCH_SWITCH_CONFG_H_

#include "switch_private.h"
#include "../../MCAL/DIO/DIO_Private.h"

typedef struct
{
	DIO_GroupNumber  SW_Group ;
	DIO_PinNumber    SW_Pin ;
	SwitchConnectionType   ConnectionType ;
}Switch_Info ;

#endif /* HAL_SWITCH_SWITCH_CONFG_H_ */
