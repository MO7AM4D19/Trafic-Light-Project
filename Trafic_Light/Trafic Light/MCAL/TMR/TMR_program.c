/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Timer						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "TMR_config.h"
#include "TMR_interface.h"
#include "TMR_private.h"
#include "TMR_register.h"
#include "..\..\LIB\BIT_MATH.h"

void (* TMR0_fpOverflowFunction)(void) = NULL;
void (* TMR0_fpCompareMatchFunction)(void) = NULL;


void TMR0_voidInit()
{
    /* Timer Mode*/
    #if TMR0_MODE == TMR_NORMAL
    CLR_BIT(TCCR0,TCCR0_WGM00);
    CLR_BIT(TCCR0,TCCR0_WGM01);
    #elif TMR0_MODE == TMR_PWM_PHASE_CORRECT
    SET_BIT(TCCR0,TCCR0_WGM00);
    CLR_BIT(TCCR0,TCCR0_WGM01);
    #elif TMR0_MODE == TMR_CTC
    CLR_BIT(TCCR0,TCCR0_WGM00);
    SET_BIT(TCCR0,TCCR0_WGM01);
    #elif TMR0_MODE == TMR_FAST_PWM
    SET_BIT(TCCR0,TCCR0_WGM00);
    SET_BIT(TCCR0,TCCR0_WGM01);
    #endif

    /* Setting Clock*/
    TCCR0 &= 0b11111000;
    TCCR0 |= TMR0_PRESCALER;
    
    /* Setting Compare Match Value*/
    #if TMR0_MODE == TMR_CTC
    OCR0 = TMR0_CTC_VALUE;
    #endif
    
    /* Setting Timer Action*/
    TCCR0 &= 0b11001111;
    #if TMR0_MODE == TMR_CTC
    TCCR0 |= (TMR0_CTC_OUT<<4);
    #elif TMR0_MODE == TMR_FAST_PWM
    TCCR0 |= (TMR0_FAST_PWM_OUT<<4);
    #elif TMR0_MODE == TMR_PWM_PHASE_CORRECT
    TCCR0 |= (TMR0_PHASE_PWM_OUT<<4);
    #endif

    /* Enabling Timer Intrupt*/
    
    #if TMR0_MODE == TMR_NORMAL
    SET_BIT(TIMSK,TIMSK_TOIE0);
    CLR_BIT(TIMSK,TIMSK_OCIE0);
    #elif TMR0_MODE == TMR_CTC
    CLR_BIT(TIMSK,TIMSK_TOIE0);
    SET_BIT(TIMSK,TIMSK_OCIE0);
    #elif TMR0_MODE == TMR_FAST_PWM
    SET_BIT(TIMSK,TIMSK_TOIE0);
    SET_BIT(TIMSK,TIMSK_OCIE0);
    #elif TMR0_MODE == TMR_PWM_PHASE_CORRECT
    CLR_BIT(TIMSK,TIMSK_TOIE0);
    SET_BIT(TIMSK,TIMSK_OCIE0);
    #endif

}

u8 TMR0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),u8 Copy_u8TimerState)
{
    u8 Local_u8ErrorState = OK;
    if(Copy_pvCallBackFunc == NULL)
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    else if(Copy_u8TimerState == TMR_OVERFLOW)
    {
        TMR0_fpOverflowFunction = Copy_pvCallBackFunc;
    }
    else if(Copy_u8TimerState == TMR_COMPARE_MATCH)
    {
        TMR0_fpCompareMatchFunction = Copy_pvCallBackFunc;
    }
    else
    {
        Local_u8ErrorState = WRONG_TIMER_STATE;
    }
    return Local_u8ErrorState;
}

void TMR0_voidSetCompareMatchValue(u8 Copy_u8Value)
{
    OCR0 = Copy_u8Value;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    TMR0_fpCompareMatchFunction();
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    TMR0_fpOverflowFunction();
}
