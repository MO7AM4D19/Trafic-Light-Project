/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Timer						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "..\..\LIB\STD_TYPES.h"

#ifndef TMR_INTERFACE_H
#define TMR_INTERFACE_H

#define TMR_NORMAL                          0
#define TMR_PWM_PHASE_CORRECT               1
#define TMR_CTC                             3
#define TMR_FAST_PWM                        4

#define TMR_COUNTER                         0
#define TMR_PRESCALER_OFF                   1
#define TMR_PRESCALER_8                     2
#define TMR_PRESCALER_64                    3
#define TMR_PRESCALER_256                   4
#define TMR_PRESCALER_1024                  5
#define TMR_PRESCALER_T0_FE                 6
#define TMR_PRESCALER_T0_RE                 7

#define TMR_CTC_OC0_OFF                     0
#define TMR_CTC_OC0_TOGGLE                  1
#define TMR_CTC_OC0_CLR                     2
#define TMR_CTC_OC0_SET                     3

#define TMR_FAST_PWM_OC0_OFF                0
#define TMR_FAST_PWM_NON_INVERT             2
#define TMR_FAST_PWM_INVERT                 3

#define TMR_PHASE_PWM_OC0_OFF               0
#define TMR_PHASE_PWM_SCS                   2
#define TMR_PHASE_PWM_CSC                   3

#define TMR_COMPARE_MATCH                   0
#define TMR_OVERFLOW                        1

#define TMR_INTRUPT_DISABLE                 0
#define TMR_INTRUPT_ENABLE                  1


void TMR0_voidInit();
u8   TMR0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),u8 Copy_u8TimerState);
void TMR0_voidSetCompareMatchValue(u8 Copy_u8Value);

#endif