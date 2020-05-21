#include <xc.h>
#include <stdlib.h>
#include <7Segments.h>

/* PIC16F887 Configuration with  XC8 Compiler */
/* Uses external oscilator */
#pragma config FOSC=XT, WDTE=OFF, PWRTE=OFF, CP=OFF, MCLRE = ON, BOREN = OFF, LVP = OFF, IESO=ON, FCMEN=ON
#define _XTAL_FREQ	8000000	

void main(void)
{   
    TRISD = 0;
    TRISA = 0;
    TRISB = 0;
       
    unsigned int num = 4861;
    unsigned char digits[4] = {0,0,0,0};
        
            
    /* Application */
	do{

        /* Display number */
        if (extractDigits(num, digits))
            displayNumber(digits[0], digits[1], digits[2], digits[3]);
        else
            displayError();
        
        
        
        
	}while(1);	
}

	