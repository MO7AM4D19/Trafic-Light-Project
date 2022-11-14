/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Timer						**********************************/
/**********************************		Version: 1.00					**********************************/

#ifndef TMR_REGISTER_H
#define TMR_REGISTER_H

/*Timer 0 registers*/
#define OCR0                *((volatile u8*)0x5C)

#define TIMSK               *((volatile u8*)0x59)
#define TIMSK_TOIE0         0
#define TIMSK_OCIE0         1

#define TIFR                *((volatile u8*)0x58)
#define TIFR_TOV0           0
#define TIFR_OCF0           1

#define TCCR0               *((volatile u8*)0x53)
#define TCCR0_CS00          0
#define TCCR0_CS01          1
#define TCCR0_CS02          2
#define TCCR0_WGM01         3
#define TCCR0_COM00         4
#define TCCR0_COM01         5
#define TCCR0_WGM00         6
#define TCCR0_FOC           7

#define TCNT0               *((volatile u8*)0x52)

/*timer 1 registers*/



#endif