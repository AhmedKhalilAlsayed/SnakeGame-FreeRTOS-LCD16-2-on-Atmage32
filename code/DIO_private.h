/*******************************************/
/*		Name : Ahmed Khalil
 Date : 11-9-2021
 SWC : DIO
 Version : 1.0
 */

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

// registers for DIO
// PORTA REG
#define PORTA_REG							0x3B
#define DIO_U8_PORTA_REG	*((volatile u8*)0x3B)
#define DIO_U8_DDRA_REG		*((volatile u8*)0x3A)
#define DIO_U8_PINA_REG		*((volatile u8*)0x39)

// PORTB REG                   volatile 
#define PORTB_REG							0x38
#define DIO_U8_PORTB_REG	*((volatile u8*)0x38)
#define DIO_U8_DDRB_REG		*((volatile u8*)0x37)
#define DIO_U8_PINB_REG		*((volatile u8*)0x36)

// PORTC REG                   volatile 
#define PORTC_REG							0x35
#define DIO_U8_PORTC_REG	*((volatile u8*)0x35)
#define DIO_U8_DDRC_REG		*((volatile u8*)0x34)
#define DIO_U8_PINC_REG		*((volatile u8*)0x33)

// PORTD REG                   volatile 
#define PORTD_REG							0x32
#define DIO_U8_PORTD_REG	*((volatile u8*)0x32)
#define DIO_U8_DDRD_REG		*((volatile u8*)0x31)
#define DIO_U8_PIND_REG		*((volatile u8*)0x30)

/**/
//direction
#define INPUT_INIT		 0
#define OUTPUT_INIT 	 1

//output value
#define OUTPUT_HIGH 	1
#define OUTPUT_LOW  	0

//switches
#define INPUT_FLOATING	0
#define INPUT_PULLUP	1

//
#define PRIVATE_CONC(B7, B6, B5, B4, B3, B2, B1, B0)  PRIVATE_CONC_HELP(B7, B6, B5, B4, B3, B2, B1, B0)
#define PRIVATE_CONC_HELP(B7, B6, B5, B4, B3, B2, B1, B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0
/**/


u8 Private_u8AccessPinDirection(  volatile u8* Copy_P_u8PORTX_REG, u8 Copy_u8PinId, u8 Copy_u8PinDirection ) {
 	u8 Local_u8ErrorState = STD_TYPES_OK;

	switch (Copy_u8PinDirection) {
	case DIO_u8_OUTPUT:
		SET_BIT(*(Copy_P_u8PORTX_REG-1), Copy_u8PinId);//DDRX
		break;

	case DIO_u8_INPUT_FLOATING:
		CLR_BIT(*(Copy_P_u8PORTX_REG-1), Copy_u8PinId);//DDRX
		break;

	case DIO_u8_INPUT_PULLUP:
		CLR_BIT(*(Copy_P_u8PORTX_REG-1), Copy_u8PinId);//DDRX
		SET_BIT(*(Copy_P_u8PORTX_REG  ), Copy_u8PinId);//PORTX

		break;

	default:
		Local_u8ErrorState = STD_TYPES_NOK;

	}

	return Local_u8ErrorState;
}

u8 Private_u8AccessPortDirection( volatile u8* Copy_P_u8PORTX_REG, u8 Copy_u8PortDirection ) {
 	u8 Local_u8ErrorState = STD_TYPES_OK;

	switch (Copy_u8PortDirection) {
	case DIO_u8_OUTPUT:
		*(Copy_P_u8PORTX_REG-1) = 0xff;//DDRX
		break;

	case DIO_u8_INPUT_FLOATING:
		*(Copy_P_u8PORTX_REG-1) = 0x00;//DDRX
		break;

	case DIO_u8_INPUT_PULLUP:
		*(Copy_P_u8PORTX_REG-1) = 0x00;//DDRX
		*(Copy_P_u8PORTX_REG  ) = 0xff;//PORTX

		break;

	default:
		Local_u8ErrorState = STD_TYPES_NOK;

	}

	return Local_u8ErrorState;
}

#endif
