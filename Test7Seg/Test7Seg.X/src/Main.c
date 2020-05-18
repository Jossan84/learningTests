#include <xc.h>
#include <stdlib.h>

/* PIC16F887 Configuration with  XC8 Compiler */
#pragma config FOSC=XT, WDTE=OFF, PWRTE=OFF, CP=OFF
#define _XTAL_FREQ	8000000	

void main(void)
{

    
    TRISD = 0;
    

    /* Application */
	do{

	/* Led ON */
	RD7 = 1;
	__delay_ms(500);
		RD7 = 0;
	__delay_ms(500);
       
	}while(1);	
}

	