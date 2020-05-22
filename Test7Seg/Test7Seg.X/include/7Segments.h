/**
 * @file 7Segments.h
 * @brief Abstraction for the Seven segments display
 *
 * This header file provides an abstraction of reading and
 * writing the pins that command the 7 Segments display installed in
 * the board MikroElektronika EasyPICv7.
 *
 * Note: Uncomment and comment to choose the common cathode or anode
 * 
 * @author Jos√© Manuel
 * @date April 21 2020
 *
 */
#ifndef __7_SEGMENTS_H__
#define __7_SEGMENTS_H__

/* LOOK UP TABLE FOR DECODE THE SEVEN SEGMENTS DISPLAY */
/* T7SEG will be replaced in future */
const unsigned char T7SEG[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6d,0x7C,0x07,0x7F,0x6F};

#define dot RD7
#define N 4  // Number of 7 segments displays

const unsigned char DECODE_COMMON_ANODE[75]= {
/*  0     1     2     3     4     5     6     7     8     9     :     ;     */
    0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B, 0x00, 0x00, 
/*  <     =     >     ?     @     A     B     C     D     E     F     G     */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x00, 0x4E, 0x00, 0x4F, 0x47, 0x5E, 
/*  H     I     J     K     L     M     N     O     P     Q     R     S     */
    0x37, 0x06, 0x3C, 0x00, 0x0E, 0x00, 0x00, 0x7E, 0x67, 0x00, 0x00, 0x5B, 
/*  T     U     V     W     X     Y     Z     [     \     ]     ^     _     */
    0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/*  `     a     b     c     d     e     f     g     h     i     j     k     */
    0x00, 0x7D, 0x1F, 0x0D, 0x3D, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 
/*  l     m     n     o     p     q     r     s     t     u     v     w     */
    0x00, 0x00, 0x15, 0x1D, 0x00, 0x73, 0x05, 0x00, 0x0F, 0x1C, 0x00, 0x00, 
/*  x     y     z     */
    0x00, 0x3B, 0x00
};

const unsigned char DECODE_COMMON_CATHODE[75]= {
/*  0     1     2     3     4     5     6     7     8     9     :     ;     */
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00, 0x00, 
/*  <     =     >     ?     @     A     B     C     D     E     F     G     */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x00, 0x39, 0x00, 0x79, 0x71, 0x3D, 
/*  H     I     J     K     L     M     N     O     P     Q     R     S     */
    0x76, 0x30, 0x1E, 0x00, 0x38, 0x00, 0x00, 0x3F, 0x73, 0x00, 0x00, 0x6D, 
/*  T     U     V     W     X     Y     Z     [     \     ]     ^     _     */
    0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/*  `     a     b     c     d     e     f     g     h     i     j     k     */
    0x00, 0x5F, 0x7C, 0x58, 0x5E, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 
/*  l     m     n     o     p     q     r     s     t     u     v     w     */
    0x00, 0x00, 0x54, 0x5C, 0x00, 0x67, 0x50, 0x00, 0x78, 0x1C, 0x00, 0x00, 
/*  x     y     z     */
    0x00, 0x6E, 0x00
};

/**
 * @brief Decode for a 7 segments display
 *
 * This function decode a ASCII character to display in a 
 * seven segments display.
 *
 * Invalid letters are mapped to all segments off (0x00)
 
 * @param chr - Character to decode into 7 Segments display
 * 
 * @return Character decoded
 */
unsigned char decode7Seg(unsigned char chr);

/**
 * @brief Display string
 *
 * This function display a string in a N seven segments display.
 * 
 * @param *string - Text to display
 * @param size - Size of the string
 * 
 * @return void
 */
void displayString(unsigned char *string, unsigned char size);

/**
 * @brief Extract the digits of a number
 *
 * This function extract the digits of a unsigned integer, this must 
 * be between 0 and 9999, if¥s not the functio return 0.
 * If the input is correct return 1 and the value decode into a 
 * display array
 *
 * @param num - Number
 * @param digits - Array with the digits, 0 position correspond to units. 
 * 
 * @return error code
 */
unsigned char extractDigits(unsigned int num, unsigned char *digits);


#endif /* __7_SEGMENTS_H__ */