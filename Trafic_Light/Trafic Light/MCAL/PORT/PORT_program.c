/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: PORT						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "PORT_config.h"
#include "PORT_interface.h"
#include "PORT_private.h"
#include "PORT_register.h"
#include "..\DIO\DIO_interface.h"


void PORT_voidInint()
{
    DDRA = PORTA_DIR;
    DDRB = PORTB_DIR;
    DDRC = PORTC_DIR;
    DDRD = PORTD_DIR;
    DIO_u8SetPortValue(DIO_u8PORTA,PORTA_INIT);
    DIO_u8SetPortValue(DIO_u8PORTB,PORTB_INIT);
    DIO_u8SetPortValue(DIO_u8PORTC,PORTC_INIT);
    DIO_u8SetPortValue(DIO_u8PORTD,PORTD_INIT);
}