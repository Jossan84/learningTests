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
    TRISD = 0;
    TRISA = 0;
    /*  
    unsigned char i;
    
    for (i=0; i<size; i++){ 
    // TO DO DEBUGG PROBLEM WITH PORTA    
        PORTA = i+1;
        PORTD = decode7Seg(string[i+size-1]);  
        __delay_ms(2);
        PORTA = 0;
    }
    */
    
    RA0=1;
    PORTD = decode7Seg(string[3]);        
    __delay_ms(2);
    RA0=0;
  
    RA1=1;
    PORTD = decode7Seg(string[2]);  
    __delay_ms(2);
    RA1=0;
    
    RA2=1;
    PORTD = decode7Seg(string[1]);  
    __delay_ms(2);
    RA2=0;

    RA3=1;
    PORTD = decode7Seg(string[0]);  
    __delay_ms(2);
    RA3=0; 
    
}
