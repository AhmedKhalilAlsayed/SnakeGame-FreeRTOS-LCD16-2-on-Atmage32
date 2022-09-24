/*******************************************/
/*		Name : Ahmed Khalil
 Date : 11-9-2021
 SWC : DIO
 Version : 1.0
 */


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


//RS
#define LCD_u8_RS_PORT 			DIO_u8_PORTA
#define LCD_u8_RS_PIN			DIO_u8_PIN1

//RW
#define LCD_u8_RW_PORT 			DIO_u8_PORTA
#define LCD_u8_RW_PIN			DIO_u8_PIN2

//EN
#define LCD_u8_EN_PORT 			DIO_u8_PORTA
#define LCD_u8_EN_PIN			DIO_u8_PIN3

//Mode
/* options =>
 * 8-bit mode = 8,
 * 4-bit mode = 4
 * */
#define LCD_MODE 4
/**/

//data as port in  => 8-bit mode
#if LCD_MODE == 8

#define LCD_u8_DATA_PORT        DIO_u8_PORTC


#elif LCD_MODE == 4

//data in 4 pins
#define LCD_u8_DATA_PIN4_PORT   DIO_u8_PORTA
#define LCD_u8_DATA_PIN4		DIO_u8_PIN4

#define LCD_u8_DATA_PIN5_PORT   DIO_u8_PORTA
#define LCD_u8_DATA_PIN5		DIO_u8_PIN5

#define LCD_u8_DATA_PIN6_PORT   DIO_u8_PORTA
#define LCD_u8_DATA_PIN6		DIO_u8_PIN6

#define LCD_u8_DATA_PIN7_PORT   DIO_u8_PORTA
#define LCD_u8_DATA_PIN7		DIO_u8_PIN7

#else

#error "You entered invalid LCD_MODE in <LCD_confg.h>"


#endif

#endif
