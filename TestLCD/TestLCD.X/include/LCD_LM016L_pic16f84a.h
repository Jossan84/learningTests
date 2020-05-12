/**
 * @file LCD_LM016L_pic16f84a.h
 * @brief Abstraction of pins to command the LCD display
 *
 * This header file provides an abstraction of reading and
 * writing the pins that command the LCD display
 *
 * @author José Manuel
 * @date April 5 2020
 *
 */
#ifndef __LCD_LM016L_PIC16F84A_H__
#define __LCD_LM016L_PIC16F84A_H__

/* Define the control terminals */
#define LCD_E    			RB5			// Control for terminal E of the LCD
#define LCD_RS  			RB4   		// Control for terminal RS of the LCD
#define	DATA				PORTB		// Port for data bus
#define LCD_Data_Bus_D4		RB0			// Bit 4 of the data bus
#define LCD_Data_Bus_D5		RB1			// Bit 5 of the data bus
#define LCD_Data_Bus_D6		RB2			// Bit 6 of the data bus
#define LCD_Data_Bus_D7		RB3			// Bit 7 of the data bus

/* Define the configuration registers used to control the LCD */
#define LCD_E_Dir      		  TRISB5	// E
#define LCD_RS_Dir     		  TRISB4	// RS
#define LCD_Data_Bus_Dir_D4   TRISB0	// D4
#define LCD_Data_Bus_Dir_D5   TRISB1	// D5
#define LCD_Data_Bus_Dir_D6   TRISB2	// D6
#define LCD_Data_Bus_Dir_D7   TRISB3	// D7


/* Auxiliar constants */
#define E_Delay       500       

/**
 * @brief Set pulse on terminal E
 *
 * This function set a pulse of 500us on terminal E of the LCD, this store
 * the bus data on the module.
 *
 * @param void
 * 
 * @return void
 */
void toggleEpinOfLCD(void);

/**
 * @brief Set the init conditions to LCD module
 *
 * This function set the initial conditions for the LCD module
 *
 * @param void
 * 
 * @return void
 */
void initLCD(void);

/**
 * @brief Send command to LCD
 *
 * This function send a command to LCD module
 *
 * @param Command - Order to LCD
 * 
 * @return void
 */
void writeCommandToLCD(unsigned char);

/**
 * @brief Send char data to LCD
 *
 * This function send a data (char) to the LCD module
 *
 * @param LCDChar - Char to show on the LCD
 * 
 * @return void
 */
void writeCharToLCD(char);

/**
 * @brief Send string data to LCD
 *
 * This function send a data (string) to the LCD module
 *
 * @param LCDstr - String to show on the LCD
 * 
 * @return void
 */
void writeStringToLCD(char *);

/**
 * @brief Clean LCD screen
 *
 * This function clear the LCD screen and set the cursos in (0,0) position
 *
 * @param void
 * 
 * @return void
 */
void clearLCDScreen(void);

/**
 * @brief Put the LCD cursor in a column and row
 *
 * This function put the LCD cursor in a column and row. If the values are not
 * correct, the cursor is se by default on col = 0 and row = 1.
 *
 * @param row - Row where put the cursor
 * @param col - Column where put the cursor
 * 
 * @return void
 */
void gotoXYLCD(unsigned char, unsigned char);

#endif /* __LCD_LM016L_PIC16F84A_H__ */