/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: External Intrupt			**********************************/
/**********************************		Version: 1.00					**********************************/
#include    "EXTI_private.h"

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H
 
/* for INT0 AND INT1 chose between : ACTIVE_LOW,ACTIVE_CHANGE,ACTIVE_RISING,ACTIVE_FALLING*/
/* for INT2 chose between :ACTIVE_RISING,ACTIVE_FALLING                                   */



#define EXTI_INT0_MODE      ACTIVE_LOW
#define EXTI_INT1_MODE      ACTIVE_LOW
#define EXTI_INT2_MODE      ACTIVE_RISING


#endif 