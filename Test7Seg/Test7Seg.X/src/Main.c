#include <xc.h>
#include <stdlib.h>
#include <7Segments.h>

/* PIC16F887 Configuration with  XC8 Compiler */
#pragma config FOSC=XT, WDTE=OFF, PWRTE=OFF, CP=OFF
#define _XTAL_FREQ	8000000	

void main(void)
{   
    TRISD = 0;
    TRISA = 0;
       
    unsigned int num = 550;
    unsigned char digits[4] = {0,0,0,};
        
            
    /* Application */
	do{

        /* Led ON */
        RD7 = 1;

        /* Display number */
        if (extractDigits(num, digits))
            displayNumber(digits[0], digits[1], digits[2], digits[3]);
        else
            displayError();
        
        
	}while(1);	
}

	