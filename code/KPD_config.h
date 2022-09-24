#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#include "DIO_interface.h"

//for row pins
#define KPD_U8_R1_PIN 		DIO_u8_PIN3
#define KPD_U8_R1_PIN_PORT 	DIO_u8_PORTC

#define KPD_U8_R2_PIN	 	 DIO_u8_PIN2
#define KPD_U8_R2_PIN_PORT	 DIO_u8_PORTC

#define KPD_U8_R3_PIN 		DIO_u8_PIN1
#define KPD_U8_R3_PIN_PORT 	DIO_u8_PORTC

#define KPD_U8_R4_PIN 		DIO_u8_PIN0
#define KPD_U8_R4_PIN_PORT 	DIO_u8_PORTC

//for cols pins
#define KPD_U8_C1_PIN 		DIO_u8_PIN4
#define KPD_U8_C1_PIN_PORT 	DIO_u8_PORTC

#define KPD_U8_C2_PIN	 	 DIO_u8_PIN5
#define KPD_U8_C2_PIN_PORT	 DIO_u8_PORTC

#define KPD_U8_C3_PIN 		DIO_u8_PIN6
#define KPD_U8_C3_PIN_PORT 	DIO_u8_PORTC

#define KPD_U8_C4_PIN 		DIO_u8_PIN7
#define KPD_U8_C4_PIN_PORT 	DIO_u8_PORTC


#define KPD_KEYS	{			\
		{'1', '2', '3', '+'},	\
		{'4', '5', '6', '-'},	\
		{'7', '8', '9', '*'},	\
		{'0', '/', '%', '='}	\
}

#endif
