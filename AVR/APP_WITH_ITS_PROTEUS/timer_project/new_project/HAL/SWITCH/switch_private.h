/*
 * switch_private.h
 *
 *  Created on: Mar 26, 2023
 *      Author: ranah
 */

#ifndef HAL_SWITCH_SWITCH_PRIVATE_H_
#define HAL_SWITCH_SWITCH_PRIVATE_H_


typedef enum
{
	SwitchStateerror,
	ConnectionTypeError
}SwitchErrState;

typedef enum
{
	PressedPullUp,
	NotPressedPullUp,
	NotPressedPullDown=0,
	PressedPullDown,


}SwitchState;

typedef enum
{
	InternalPullUp,
	ExternalPullUp,
	ExternalPullDown
}SwitchConnectionType;

#endif /* HAL_SWITCH_SWITCH_PRIVATE_H_ */
