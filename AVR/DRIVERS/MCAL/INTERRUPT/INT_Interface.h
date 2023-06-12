#include "INT_Private.h"
#include "INT_Confg.h"


#define int_rising 0
#define int_falling 1
#define int_onchange 2
#define int_low_level 3
#define polling 0
#define interrupt 1

EXTIErrState EXTI_EXTIErrStateInit(EXTI_Info * INT);
FlagState EXTI_FlagStatePollingHandler(EXTI_Info * INT);
void __vector_1(void)__attribute__((signal));
void setcallback(void(*ptr)(void));
