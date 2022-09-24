/*******************************************/
/*		Name : Ahmed Khalil
 Date : 11-9-2021
 SWC : DIO
 Version : 1.0
 */

#ifndef DIO_CONFIG_H
#define  DIO_CONFIG_H

/*
 * option:
 *
 *
 * */
//config pins direction
#define DIO_DDRA_0			OUTPUT_INIT
#define DIO_DDRA_1          OUTPUT_INIT
#define DIO_DDRA_2          OUTPUT_INIT
#define DIO_DDRA_3          OUTPUT_INIT
#define DIO_DDRA_4          OUTPUT_INIT
#define DIO_DDRA_5          OUTPUT_INIT
#define DIO_DDRA_6          OUTPUT_INIT
#define DIO_DDRA_7          OUTPUT_INIT

#define DIO_DDRB_0          INPUT_INIT
#define DIO_DDRB_1          INPUT_INIT
#define DIO_DDRB_2          INPUT_INIT
#define DIO_DDRB_3          INPUT_INIT
#define DIO_DDRB_4          INPUT_INIT
#define DIO_DDRB_5          INPUT_INIT
#define DIO_DDRB_6          INPUT_INIT
#define DIO_DDRB_7          INPUT_INIT

#define DIO_DDRC_0          OUTPUT_INIT
#define DIO_DDRC_1          OUTPUT_INIT
#define DIO_DDRC_2          OUTPUT_INIT
#define DIO_DDRC_3          OUTPUT_INIT
#define DIO_DDRC_4          INPUT_INIT
#define DIO_DDRC_5          INPUT_INIT
#define DIO_DDRC_6          INPUT_INIT
#define DIO_DDRC_7          INPUT_INIT

#define DIO_DDRD_0          OUTPUT_INIT
#define DIO_DDRD_1          OUTPUT_INIT
#define DIO_DDRD_2          INPUT_INIT
#define DIO_DDRD_3          OUTPUT_INIT
#define DIO_DDRD_4          OUTPUT_INIT
#define DIO_DDRD_5          OUTPUT_INIT
#define DIO_DDRD_6          OUTPUT_INIT
#define DIO_DDRD_7          OUTPUT_INIT

/*
 * option:
 * OUTPUT_HIGH
 * OUTPUT_LOW
 * INPUT_FLOATING
 * INPUT_PULLUP
 *
 * */
//config pins init values
#define DIO_PORTA_0		 	 OUTPUT_LOW
#define DIO_PORTA_1          OUTPUT_LOW
#define DIO_PORTA_2          OUTPUT_LOW
#define DIO_PORTA_3          OUTPUT_LOW
#define DIO_PORTA_4          OUTPUT_LOW
#define DIO_PORTA_5          OUTPUT_LOW
#define DIO_PORTA_6          OUTPUT_LOW
#define DIO_PORTA_7          OUTPUT_LOW

#define DIO_PORTB_0          INPUT_PULLUP
#define DIO_PORTB_1          INPUT_PULLUP
#define DIO_PORTB_2          INPUT_PULLUP
#define DIO_PORTB_3          OUTPUT_LOW
#define DIO_PORTB_4          INPUT_PULLUP
#define DIO_PORTB_5          INPUT_PULLUP
#define DIO_PORTB_6          INPUT_PULLUP
#define DIO_PORTB_7          INPUT_PULLUP

#define DIO_PORTC_0          OUTPUT_HIGH
#define DIO_PORTC_1          OUTPUT_HIGH
#define DIO_PORTC_2          OUTPUT_HIGH
#define DIO_PORTC_3          OUTPUT_HIGH
#define DIO_PORTC_4          INPUT_PULLUP
#define DIO_PORTC_5          INPUT_PULLUP
#define DIO_PORTC_6          INPUT_PULLUP
#define DIO_PORTC_7          INPUT_PULLUP

#define DIO_PORTD_0          OUTPUT_LOW
#define DIO_PORTD_1          OUTPUT_LOW
#define DIO_PORTD_2          INPUT_PULLUP
#define DIO_PORTD_3          OUTPUT_LOW
#define DIO_PORTD_4          OUTPUT_LOW
#define DIO_PORTD_5          OUTPUT_LOW
#define DIO_PORTD_6          OUTPUT_LOW
#define DIO_PORTD_7          OUTPUT_LOW

#endif
