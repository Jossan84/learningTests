#include <xc.h>
#include <LCD_NHD_0216BZ_FL_pic16f84a.h>
#include <stdlib.h>

/* PIC 16F84A Configuration with  XC8 Compiler */
#pragma config FOSC=XT, WDTE=OFF, PWRTE=OFF, CP=OFF
#define _XTAL_FREQ	4000000	

void main(void)
{
    /* Init LCD*/
	initLCD();
	clearLCDScreen();
    
    /* Led ON */
    TRISB = 0;
    RB7 = 1;
	
    /* Application */
	do{
		
		unsigned char i;	
		unsigned char num[16];
		gotoXYLCD(1,0);
		writeStringToLCD("Test LCD");
		gotoXYLCD(1,11);
		
		for(i=1; i<17; i++){
					
			itoa(num,i,10);		//Convert number to string
			
			gotoXYLCD(1,10);
			writeStringToLCD(num);
			__delay_ms(500);					
		}		
		clearLCDScreen();  
        
	}while(1);	
}

	