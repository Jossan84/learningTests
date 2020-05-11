#include <xc.h> 
#include "<LCD_pic16f84a.h>"

#define _XTAL_FREQ	4000000      	// 4 MHz

/* toggleEpinOfLCD */
void toggleEpinOfLCD(void)
{
	LCD_E = 1;						
	__delay_us(E_Delay);			
	LCD_E = 0;						
	__delay_us(E_Delay);				
}

/* initLCD */
void initLCD(void)
{ 
	LCD_E  		 		 = 0;		// E  = 0
	LCD_RS  	 		 = 0;		// RS = 0
	LCD_Data_Bus_D0		 = 0;		// Bit 0 of the data bus = 0
	LCD_Data_Bus_D1		 = 0;		// Bit 1 of the data bus = 0
	LCD_Data_Bus_D2		 = 0;		// Bit 2 of the data bus = 0
	LCD_Data_Bus_D3		 = 0;		// Bit 3 of the data bus = 0
	LCD_Data_Bus_D4		 = 0;		// Bit 4 of the data bus = 0
	LCD_Data_Bus_D5		 = 0;		// Bit 5 of the data bus = 0
	LCD_Data_Bus_D6		 = 0;		// Bit 6 of the data bus = 0
	LCD_Data_Bus_D7		 = 0;		// Bit 7 of the data bus = 0
	LCD_E_Dir    		 = 0;		// Control of terminal E set --> output
	LCD_RS_Dir    	 	 = 0;		// Control of terminal RS set --> output
	LCD_Data_Bus_Dir_D0  = 0;		// Control of terminal 0 of the data bus set --> output
	LCD_Data_Bus_Dir_D1  = 0;		// Control of terminal 1 of the data bus set --> output
	LCD_Data_Bus_Dir_D2  = 0;		// Control of terminal 2 of the data bus set --> output
	LCD_Data_Bus_Dir_D3  = 0;		// Control of terminal 3 of the data bus set --> output
	LCD_Data_Bus_Dir_D4  = 0;		// Control of terminal 4 of the data bus set --> output
	LCD_Data_Bus_Dir_D5  = 0;		// Control of terminal 5 of the data bus set --> output
	LCD_Data_Bus_Dir_D6  = 0;		// Control of terminal 6 of the data bus set --> output
	LCD_Data_Bus_Dir_D7  = 0;		// Control of terminal 7 of the data bus set --> output

   /************ Star reboot of  LCD module (from LCD datasheet) *************/
   __delay_ms(60);					// Settlement time of the module
   
 	writeCommandToLCD(0x38);		// Data bus of 8 bits
									// Activate the two lines
									// Character de 5x8
	writeCommandToLCD(0x0c);		// LCD activated
									// Cursor non visible
									// Cursor without blicking
	writeCommandToLCD(0x01);		// Clean screen
	writeCommandToLCD(0x06);		// Cursor position is increased after write
                                    // each character
									// The contend of the screen is not shifted
}

/* writeCommandToLCD */
void writeCommandToLCD(unsigned char Command)  
{
	LCD_RS = 0;						
	
	DATA = Command;					
	toggleEpinOfLCD();				
}

/* writeCharToLCD */
void writeCharToLCD(char LCDChar)  
{
	LCD_RS = 1;						

	DATA = LCDChar;					
	toggleEpinOfLCD();				
}

/* writeStringToLCD */
void writeStringToLCD(char *LCDstr)
{
	unsigned char i = 0;
		
	while (LCDstr[i] != '\0')					
	{
		writeCharToLCD(LCDstr[i]);		
		i++;						
	}	
}

/* clearLCDScreen */
void clearLCDScreen(void)
{
	writeCommandToLCD(0x01);    
	__delay_ms(2); 
}

/* gotoXYLCD */
void gotoXYLCD(unsigned char row,unsigned char col)
{
	if (col > 16)
		col = 0;
	if (row == 2)
		writeCommandToLCD(0xC0 + col);
	else
		writeCommandToLCD(0x80 + col);
}	

