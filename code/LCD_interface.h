/*******************************************/
/*		Name : Ahmed Khalil
 Date : 11-9-2021
 SWC : DIO
 Version : 1.0
 */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE1 0
#define LCD_u8_LINE2 1

enum LCD_enumDirections {
	LEFT, RIGHT, UP, DOWN, NONE
} option;

void LCD_Init(void);
void LCD_voidWriteChar(u8 Copy_u8Char);
void LCD_voidWriteComnd(u8 Copy_u8Cmnd);
void LCD_voidWriteString(u8* str);
u8 LCD_u8GoToXY(u8 Copy_u8LineNumber, u8 Copy_u8CharLocation);
void LCD_voidCreateChar(u8 indexInCGRAM, u8* smallPattern);
void LCD_voidCursorOFFDataON();


#if 0
void LCD_voidClear(void);

void LCD_voidWriteNumber(u32 number);

void LCD_voidWriteFloatNumber(f32 number);

void LCD_voidShiftString(u8* str, enum LCD_enumDirections enumOption);

void LCD_voidShiftDisplay(enum LCD_enumDirections enumDirection);
#endif

#endif
