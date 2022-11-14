/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: PORT						**********************************/
/**********************************		Version: 1.00					**********************************/
#include "..\..\LIB\STD_TYPES.h"

#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H
#define DDRA                *((volatile u8*) 0x3A)
#define DDRB                *((volatile u8*) 0x37)
#define DDRC                *((volatile u8*) 0x34)
#define DDRD                *((volatile u8*) 0x31)
#endif