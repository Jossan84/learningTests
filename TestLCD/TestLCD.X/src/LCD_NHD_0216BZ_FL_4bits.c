#include <xc.h> 
#include <LCD_NHD_0216BZ_FL_pic16f84a.h>

#define _XTAL_FREQ	4000000      	// 4 MHz

/* toggleEpinOfLCD */
void toggleEpinOfLCD(void)
{
	LCD_E = 1;						
    __delay_us(E_Delay);
	LCD_E = 0;						
}

/* initLCD */
void initLCD(void)
{ 
	LCD_E  		 		 = 0;		// E  = 0
	LCD_RS  	 		 = 0;		// RS = 0
	LCD_Data_Bus_D4		 = 0;		// Bit 4 of the data bus = 0
	LCD_Data_Bus_D5		 = 0;		// Bit 5 of the data bus = 0
	LCD_Data_Bus_D6		 = 0;		// Bit 6 of the data bus = 0
	LCD_Data_Bus_D7		 = 0;		// Bit 7 of the data bus = 0
	LCD_E_Dir    		 = 0;		// Control of terminal E set --> output
	LCD_RS_Dir    	 	 = 0;		// Control of terminal RS set --> output
	LCD_Data_Bus_Dir_D4  = 0;		// Control of terminal 4 of the data bus set --> output
	LCD_Data_Bus_Dir_D5  = 0;		// Control of terminal 5 of the data bus set --> output
	LCD_Data_Bus_Dir_D6  = 0;		// Control of terminal 6 of the data bus set --> output
	LCD_Data_Bus_Dir_D7  = 0;		// Control of terminal 7 of the data bus set --> output

  /************ Star reboot of  LCD module (from LCD datasheet) *************/
   __delay_ms(100);                  // Settlement time of the module
   
	DATA &= 0xF0;					// Data = 0
	DATA |= 0x03;					// Data = 3
    __delay_ms(6);					// 6 ms
	
    toggleEpinOfLCD();				// Pulse om terminal E
    __delay_us(200);				// 200 us
    toggleEpinOfLCD();				// Pulse om terminal E
    __delay_us(200);				// 200 us
    toggleEpinOfLCD();				// Pulse om terminal E
    __delay_us(200);				// 200 us   
      
	DATA &= 0xF0;					// Data = 0
	DATA |= 0x02;					// Data = 2
	toggleEpinOfLCD();				// Pulse om terminal E
	
	__delay_ms(2);					// 2 ms
	
  /*********** End of the reboot and start configuration ****************/
  
	writeCommandToLCD(0x28);		// Function set: 4-bit/2-line
	writeCommandToLCD(0x0c);		// Set cursor			
	writeCommandToLCD(0x01);		// Display ON; Blicking cursor off
	writeCommandToLCD(0x06);		// Entry mode set
}

/* writeCommandToLCD */
void writeCommandToLCD(unsigned char command)  
{
	LCD_RS = 0;                                   // Command
		
	DATA &= 0xF0;                                 // Data = 0
	DATA |= ((unsigned char)((command>>4)&0x0F)); // Send to the port 4 MSB of the data
	toggleEpinOfLCD();                            // Pulse on terminal E

    DATA &= 0xF0;                            // Data = 0
	DATA |= ((unsigned char)(command&0x0F)); // Send to the port 4 LSB of the data
	toggleEpinOfLCD();				         // Pulse on terminal E

}

/* writeCharToLCD */
void writeCharToLCD(char LCDChar)  
{
	LCD_RS = 1;						// Data
	
	DATA &= 0xF0;                                 // Data = 0
	DATA |= ((unsigned char)((LCDChar>>4)&0x0F)); // Send to the port 4 MSB of the data
	toggleEpinOfLCD();                            // Pulse on terminal E

	DATA &= 0xF0;                            // Data = 0
	DATA |= ((unsigned char)(LCDChar&0x0F)); // Send to the port 4 LSB of the data
	toggleEpinOfLCD();                       // Pulse on terminal E

}

/* writeStringToLCD */
void writeStringToLCD(char *LCDstr)
{
	unsigned char i = 0;
		
	while (LCDstr[i] != '\0')			// Check the end of the string	
	{
		writeCharToLCD(LCDstr[i]);		// Send the character
		i++;							// Point to the next character
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
		writeCommandToLCD((unsigned char)(0xC0 + col));
	else 
		writeCommandToLCD((unsigned char)(0x80 + col));
}	


