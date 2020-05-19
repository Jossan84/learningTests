#include <xc.h>
#include <stdlib.h>

/* PIC16F887 Configuration with  XC8 Compiler */
#pragma config FOSC=XT, WDTE=OFF, PWRTE=OFF, CP=OFF
#define _XTAL_FREQ	8000000	



const unsigned char T7SEG[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6d,0x7C,0x07,0x7F,0x6F};
unsigned char unidades=0,decenas=0,centenas=0;


void display(int num){		//This function delays 200ms

    TRISD = 0;
    TRISA = 0;
    
    unsigned char units=0,tens=0,hundreds=0,thousands=0;
      
    RA3=1;
    PORTD=T7SEG[units];
    __delay_ms(50);
    RA3=0;
  
    RA2=1;
    PORTD=T7SEG[tens];
    __delay_ms(50);
    RA2=0;
    
    RA1=1;
    PORTD=T7SEG[hundreds];
    __delay_ms(50);
    RA1=0;

    RA0=1;
    PORTD=T7SEG[thousands];
    __delay_ms(50);
    RA0=0;
    
}


void main(void)
{   
    TRISD = 0;
    TRISA = 0;
       
    int num = 0;
    /* Application */
	do{

        /* Led ON */
        RD7 = 1;

        /* Display number */
        display(num);
        
	}while(1);	
}

	