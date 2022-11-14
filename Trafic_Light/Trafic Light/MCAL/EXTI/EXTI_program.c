/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL				**********************************/
/**********************************		SWC: External Intrupt			**********************************/
/**********************************		Version: 1.00				**********************************/

#include "../../LIB/BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"

void (*EXTI_pfISR0function)(void) = NULL;
void (*EXTI_pfISR1function)(void) = NULL;
void (*EXTI_pfISR2function)(void) = NULL;

void EXTI_voidInitINT0()
{   
	#if EXIT_INT0_MODE == ACTIVE_LOW
    CLR_BIT(MCUCR,MCUCR_ISC00);
    CLR_BIT(MCUCR,MCUCR_ISC01);

    #elif EXTI_INT0_MODE == ACTIVE_CHANGE
    SET_BIT(MCUCR,MCUCR_ISC00);
    CLR_BIT(MCUCR,MCUCR_ISC01);

    #elif EXIT_INT0_MODE == ACTIVE_FALLING
    CLR_BIT(MCUCR,MCUCR_ISC00);
    SET_BIT(MCUCR,MCUCR_ISC01);

    #elif EXIT_INT0_MODE == ACTIVE_RISING
    SET_BIT(MCUCR,MCUCR_ISC00);
    SET_BIT(MCUCR,MCUCR_ISC01);
	
	#else
	#error Wrong sense control mode

    #endif
	
    SET_BIT(GICR,GICR_INT0);
}

void EXTI_voidInitINT1()
{
    #if EXIT_INT1_MODE == ACTIVE_LOW
    CLR_BIT(MCUCR,MCUCR_ISC10);
    CLR_BIT(MCUCR,MCUCR_ISC11);

    #elif EXTI_INT0_MODE == ACTIVE_CHANGE
    SET_BIT(MCUCR,MCUCR_ISC10);
    CLR_BIT(MCUCR,MCUCR_ISC11);

    #elif EXIT_INT1_MODE == ACTIVE_FALLING
    CLR_BIT(MCUCR,MCUCR_ISC10);
    SET_BIT(MCUCR,MCUCR_ISC11);

    #elif EXIT_INT1_MODE == ACTIVE_RISING
    SET_BIT(MCUCR,MCUCR_ISC10);
    SET_BIT(MCUCR,MCUCR_ISC11);
	
	#else
	#error Wrong sense control mode
    
	#endif
    
    SET_BIT(GICR,GICR_INT1);
}

void EXTI_voidInitINT2()
{

    #if EXIT_INT2_MODE == ACTIVE_FALLING
    CLR_BIT(MCUCSR,MCUCSR_ISC2);

    #elif EXIT_INT2_MODE == ACTIVE_RISING
    SET_BIT(MCUCSR,MCUCSR_ISC2);
	
	
    #endif
    
    SET_BIT(GICR,GICR_INT2);
}

u8   EXTI_u8InitINT(u8 Copy_u8IntPin)
{
	u8 Local_u8ErrorStatus = 0;
	switch(Copy_u8IntPin)
	{
		case EXTI_INT0_PIN:
		SET_BIT(GICR,GICR_INT0);
		break;
		case EXTI_INT1_PIN:
		SET_BIT(GICR,GICR_INT1);
		break;
		case EXTI_INT2_PIN:
		SET_BIT(GICR,GICR_INT2);
		break;
		default:
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}

u8   EXTI_u8ChangeSenseControl(u8 Copy_IntPin,u8 Copy_Sense)
{
	u8 Local_u8ErrorStatus = 0;
	if (Copy_IntPin == EXTI_INT0_PIN)
	{
		switch(Copy_Sense)
		{
			case EXTI_SENSE_LOW:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
			case EXTI_SENSE_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
			case  EXTI_SENSE_FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
			case EXTI_SENSE_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
			default:
			Local_u8ErrorStatus = 1;
		}
	}
	else if (Copy_IntPin == EXTI_INT1_PIN)
	{
		switch(Copy_Sense)
		{
		    case EXTI_SENSE_LOW:
		    CLR_BIT(MCUCR,MCUCR_ISC10);
		    CLR_BIT(MCUCR,MCUCR_ISC11);
			break;
			case EXTI_SENSE_CHANGE:
		    SET_BIT(MCUCR,MCUCR_ISC10);
		    CLR_BIT(MCUCR,MCUCR_ISC11);
			break;
		    case EXTI_SENSE_FALLING_EDGE:
		    CLR_BIT(MCUCR,MCUCR_ISC10);
		    SET_BIT(MCUCR,MCUCR_ISC11);
			break;
		    case EXTI_SENSE_RISING_EDGE:
		    SET_BIT(MCUCR,MCUCR_ISC10);
		    SET_BIT(MCUCR,MCUCR_ISC11);
			break;
			default:
			Local_u8ErrorStatus = 1;
		}
	}
	else if (Copy_IntPin == EXTI_INT2_PIN)
	{
		switch(Copy_Sense)
		{
		    case EXTI_SENSE_FALLING_EDGE:
		    CLR_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		    case  EXTI_SENSE_RISING_EDGE:
		    SET_BIT(MCUCR,MCUCSR_ISC2);
			break;
			default:
			Local_u8ErrorStatus = 1;
		}
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}

u8	 EXTI_u8SendISR0function(void (*Copy_pfISRfunction)(void))
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_pfISRfunction != NULL)
	{
		EXTI_pfISR0function = Copy_pfISRfunction;
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}

u8	 EXTI_u8SendISR1function(void (*Copy_pfISRfunction)(void))
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_pfISRfunction != NULL)
	{
		EXTI_pfISR1function = Copy_pfISRfunction;
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}

u8	 EXTI_u8SendISR2function(void (*Copy_pfISRfunction)(void))
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_pfISRfunction != NULL)
	{
		EXTI_pfISR2function = Copy_pfISRfunction;
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (EXTI_pfISR0function!=NULL)
	{
		EXTI_pfISR0function();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (EXTI_pfISR1function!=NULL)
	{
		EXTI_pfISR1function();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (EXTI_pfISR2function!=NULL)
	{
		EXTI_pfISR2function();
	}	
}

