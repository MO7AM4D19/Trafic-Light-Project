/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: General intrupt			**********************************/
/**********************************		Version: 1.00					**********************************/
#include "GIE_interface.h"
#include "GIE_config.h"
#include "GIE_private.h"
#include "GIE_register.h"
#include "..\..\LIB\BIT_MATH.h"

void GIE_voidEnabaleGeneralIntrupt()
{
    SET_BIT(SREG,SREG_I);
}
void GIE_voidDisabaleGeneralIntrupt()
{
    CLR_BIT(SREG,SREG_I);
}
