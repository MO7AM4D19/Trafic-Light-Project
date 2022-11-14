/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Timer						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "TMR_interface.h"

#ifndef TMR_CONFIG_H
#define TMR_CONFIG_H

#define TMR0_MODE           TMR_NORMAL
#define TMR0_PRESCALER      TMR_PRESCALER_1024  
#define TMR0_CTC_VALUE      250
#define TMR0_CTC_OUT        TMR_CTC_OC0_OFF
#define TMR0_FAST_PWM_OUT   TMR_FAST_PWM_NON_INVERT
#define TMR0_PHASE_PWM_OUT  TMR_PHASE_PWM_SCS
#define TMR0_INTRUPT        TMR_INTRUPT_ENABLE


#endif