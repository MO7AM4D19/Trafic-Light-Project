
#include "MCAL\DIO\DIO_interface.h"
#include "MCAL\PORT\PORT_interface.h"
#include "MCAL\GIE\GIE_interface.h"
#include "MCAL\TMR\TMR_interface.h"
#define F_CPU 8000000
#include "util\delay.h"
void TimerIntrupt();

typedef enum modes{NormalMode,PedestrainMod} Modes;
Modes SystemMode = NormalMode;
u32 TimerCounter = 0;
u8 color = 0;

void main()
{
	PORT_voidInint();
	GIE_voidEnabaleGeneralIntrupt();
	TMR0_u8SetCallBack(TimerIntrupt,TMR_OVERFLOW);
    while (1) 
    {
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		TMR0_voidInit();
		if(TimerCounter == 19073 && color == 0)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
			TimerCounter =0;
			color++;
			TMR0_voidInit();
		}
		else if(TimerCounter == 19073 && color == 1)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
			TimerCounter =0;
			color++;
			TMR0_voidInit();
		}
		else if(TimerCounter == 19073 && color == 2)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
			TimerCounter =0;
			color = 0;
			TMR0_voidInit();
		}		
    }
}

void TimerIntrupt()
{
	TimerCounter++;
}

void PedMode()
{
	
}

