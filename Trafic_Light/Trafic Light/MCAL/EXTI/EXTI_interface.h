/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: External Intrupt			**********************************/
/**********************************		Version: 1.00					**********************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_INT0_PIN						0
#define EXTI_INT1_PIN						1
#define EXTI_INT2_PIN						2

#define EXTI_SENSE_LOW						0
#define EXTI_SENSE_CHANGE					1
#define EXTI_SENSE_FALLING_EDGE				2
#define EXTI_SENSE_RISING_EDGE				3



void EXTI_voidInitINT0();
void EXTI_voidInitINT1();
void EXTI_voidInitINT2();
u8   EXTI_u8InitINT(u8 Copy_u8IntPin);
u8   EXTI_u8ChangeSenseControl(u8 Copy_IntPin,u8 Copy_Sense);
u8	 EXTI_u8SendISR0function(void (*Copy_pfISRfunction)(void));
u8	 EXTI_u8SendISR1function(void (*Copy_pfISRfunction)(void));
u8	 EXTI_u8SendISR2function(void (*Copy_pfISRfunction)(void));


#endif