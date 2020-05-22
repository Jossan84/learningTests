#include <xc.h> 
#include <7Segments.h>

#define _XTAL_FREQ	8000000	

/* decode7Seg */
unsigned char decode7Seg(unsigned char chr)
{ /* assuming implementation uses ASCII */
    if (chr > (unsigned char)'z')
        return 0x00;
    return DECODE_COMMON_CATHODE[chr - '0'];
    /* or  DECODE_COMMON_ANODE */
}

/* extractDigits */
unsigned char extractDigits(unsigned int num, unsigned char *digits){  
    
    if(num < 10000 && num >= 0){
        
        unsigned char i = 0;        
        while(num > 0){
            digits[i] = (unsigned char)(num%10);
            num = num/10;
            i++;
        } 
        return 1;
    }else{    
        return 0;
    }
};

/* displayNumber */
void displayString(unsigned char *string, unsigned char size){    
//This function delays 8ms
    ANSEL = 0;
    TRISD = 0;
    TRISA = 0;
    PORTA = 0x01;
      
    unsigned char i;
    
    for (i=0; i<size; i++){      
        PORTD = decode7Seg(string[(size-1) - i]);
        __delay_ms(2);
        //PORTD = 0x00; //Prevent to put data in the incorrect display.
        PORTA <<= 1;
    }
}
