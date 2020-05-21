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
void displayNumber(unsigned char units,unsigned char tens,unsigned char hundreds, unsigned char thousands){		
//This function delays 200ms
    TRISD = 0;
    TRISA = 0;
          
    RA3=1;
    PORTD=T7SEG[units];
    __delay_ms(60);
    RA3=0;
  
    RA2=1;
    PORTD=T7SEG[tens];
    __delay_ms(60);
    RA2=0;
    
    RA1=1;
    PORTD=T7SEG[hundreds];
    __delay_ms(60);
    RA1=0;

    RA0=1;
    PORTD=T7SEG[thousands];
    __delay_ms(60);
    RA0=0; 
}

/* displayError */
void displayError(void){		
//This function delays 200ms
    TRISD = 0;
    TRISA = 0;
          
    RA3=1;
    PORTD=0x79;
    __delay_ms(60);
    RA3=0;
  
    RA2=1;
    PORTD=0x79;
    __delay_ms(60);
    RA2=0;
    
    RA1=1;
    PORTD=0x79;
    __delay_ms(60);
    RA1=0;

    RA0=1;
    PORTD=0x79;
    __delay_ms(60);
    RA0=0;
}