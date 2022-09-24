/*******************************************/
/*		Name : Ahmed Khalil
 Date : 11-9-2021
 SWC : DIO
 Version : 1.0
 */

//Library
#include "newTypes.h"

//MCAL
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_Init(void) {

	//directions
	DIO_U8_DDRA_REG = PRIVATE_CONC(DIO_DDRA_7, DIO_DDRA_6, DIO_DDRA_5,
			DIO_DDRA_4, DIO_DDRA_3, DIO_DDRA_2, DIO_DDRA_1, DIO_DDRA_0);

	DIO_U8_DDRB_REG = PRIVATE_CONC(DIO_DDRB_7, DIO_DDRB_6, DIO_DDRB_5,
			DIO_DDRB_4, DIO_DDRB_3, DIO_DDRB_2, DIO_DDRB_1, DIO_DDRB_0);

	DIO_U8_DDRC_REG = PRIVATE_CONC(DIO_DDRC_7, DIO_DDRC_6, DIO_DDRC_5,
			DIO_DDRC_4, DIO_DDRC_3, DIO_DDRC_2, DIO_DDRC_1, DIO_DDRC_0);

	DIO_U8_DDRD_REG = PRIVATE_CONC(DIO_DDRD_7, DIO_DDRD_6, DIO_DDRD_5,
			DIO_DDRD_4, DIO_DDRD_3, DIO_DDRD_2, DIO_DDRD_1, DIO_DDRD_0);

	//values
	DIO_U8_PORTA_REG = PRIVATE_CONC(DIO_PORTA_7, DIO_PORTA_6, DIO_PORTA_5,
			DIO_PORTA_4, DIO_PORTA_3, DIO_PORTA_2, DIO_PORTA_1, DIO_PORTA_0);

	DIO_U8_PORTB_REG = PRIVATE_CONC(DIO_PORTB_7, DIO_PORTB_6, DIO_PORTB_5,
			DIO_PORTB_4, DIO_PORTB_3, DIO_PORTB_2, DIO_PORTB_1, DIO_PORTB_0);

	DIO_U8_PORTC_REG = PRIVATE_CONC(DIO_PORTC_7, DIO_PORTC_6, DIO_PORTC_5,
			DIO_PORTC_4, DIO_PORTC_3, DIO_PORTC_2, DIO_PORTC_1, DIO_PORTC_0);

	DIO_U8_PORTD_REG = PRIVATE_CONC(DIO_PORTD_7, DIO_PORTD_6, DIO_PORTD_5,
			DIO_PORTD_4, DIO_PORTD_3, DIO_PORTD_2, DIO_PORTD_1, DIO_PORTD_0);

}
u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue) {
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7
			&& (Copy_u8PinValue == DIO_u8_LOW || Copy_u8PinValue == DIO_u8_HIGH)) {

		switch (Copy_u8PortId) {

		case DIO_u8_PORTA:

			if (Copy_u8PinValue) {
				SET_BIT(DIO_U8_PORTA_REG, Copy_u8PinId);
			} else {
				CLR_BIT(DIO_U8_PORTA_REG, Copy_u8PinId);
			}

			break;

		case DIO_u8_PORTB:

			if (Copy_u8PinValue) {
				SET_BIT(DIO_U8_PORTB_REG, Copy_u8PinId);
			} else {
				CLR_BIT(DIO_U8_PORTB_REG, Copy_u8PinId);
			}

			break;

		case DIO_u8_PORTC:

			if (Copy_u8PinValue) {
				SET_BIT(DIO_U8_PORTC_REG, Copy_u8PinId);
			} else {
				CLR_BIT(DIO_U8_PORTC_REG, Copy_u8PinId);
			}

			break;

		case DIO_u8_PORTD:

			if (Copy_u8PinValue) {
				SET_BIT(DIO_U8_PORTD_REG, Copy_u8PinId);
			} else {
				CLR_BIT(DIO_U8_PORTD_REG, Copy_u8PinId);
			}

			break;

		}

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_Pu8ReturnValue) {
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7
			&& Copy_Pu8ReturnValue != NULL) {

		switch (Copy_u8PortId) {

		case DIO_u8_PORTA:

			*Copy_Pu8ReturnValue = GET_BIT(DIO_U8_PINA_REG, Copy_u8PinId);

			break;

		case DIO_u8_PORTB:

			*Copy_Pu8ReturnValue = GET_BIT(DIO_U8_PINB_REG, Copy_u8PinId);

			break;

		case DIO_u8_PORTC:

			*Copy_Pu8ReturnValue = GET_BIT(DIO_U8_PINC_REG, Copy_u8PinId);

			break;

		case DIO_u8_PORTD:

			*Copy_Pu8ReturnValue = GET_BIT(DIO_U8_PIND_REG, Copy_u8PinId);

			break;

		}

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

#if 0
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinDirection) {

	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7) {

		switch (Copy_u8PortId) {

			case DIO_u8_PORTA:

			Local_u8ErrorState = Private_u8AccessPinDirection(
					(volatile u8*) PORTA_REG, Copy_u8PinId,
					Copy_u8PinDirection);

			break;

			case DIO_u8_PORTB:

			Local_u8ErrorState = Private_u8AccessPinDirection(
					(volatile u8*) PORTB_REG, Copy_u8PinId,
					Copy_u8PinDirection);

			break;

			case DIO_u8_PORTC:

			Local_u8ErrorState = Private_u8AccessPinDirection(
					(volatile u8*) PORTC_REG, Copy_u8PinId,
					Copy_u8PinDirection);

			break;

			case DIO_u8_PORTD:

			Local_u8ErrorState = Private_u8AccessPinDirection(
					(volatile u8*) PORTD_REG, Copy_u8PinId,
					Copy_u8PinDirection);

			break;

		}

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;

}

u8 DIO_u8TogPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId) {
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7) {

		switch (Copy_u8PortId) {

			case DIO_u8_PORTA:
			TOGGLE_BIT(DIO_U8_PORTA_REG, Copy_u8PinId);

			break;

			case DIO_u8_PORTB:
			TOGGLE_BIT(DIO_U8_PORTB_REG, Copy_u8PinId);

			break;

			case DIO_u8_PORTC:
			TOGGLE_BIT(DIO_U8_PORTC_REG, Copy_u8PinId);

			break;

			case DIO_u8_PORTD:
			TOGGLE_BIT(DIO_U8_PORTD_REG, Copy_u8PinId);

			break;

		}

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection) {
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD) {

		switch (Copy_u8PortId) {

			case DIO_u8_PORTA:

			Local_u8ErrorState = Private_u8AccessPortDirection(
					(volatile u8*) PORTA_REG, Copy_u8PortDirection);

			break;

			case DIO_u8_PORTB:

			Local_u8ErrorState = Private_u8AccessPortDirection(
					(volatile u8*) PORTB_REG, Copy_u8PortDirection);

			break;

			case DIO_u8_PORTC:

			Local_u8ErrorState = Private_u8AccessPortDirection(
					(volatile u8*) PORTC_REG, Copy_u8PortDirection);

			break;

			case DIO_u8_PORTD:

			Local_u8ErrorState = Private_u8AccessPortDirection(
					(volatile u8*) PORTD_REG, Copy_u8PortDirection);

			break;

		}

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue) {
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD) {

		switch (Copy_u8PortId) {

			case DIO_u8_PORTA:

			DIO_U8_PORTA_REG = Copy_u8PortValue;

			break;

			case DIO_u8_PORTB:

			DIO_U8_PORTB_REG = Copy_u8PortValue;

			break;

			case DIO_u8_PORTC:

			DIO_U8_PORTC_REG = Copy_u8PortValue;

			break;

			case DIO_u8_PORTD:

			DIO_U8_PORTD_REG = Copy_u8PortValue;

			break;

		}

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8* Copy_Pu8ReturnValue) {
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_Pu8ReturnValue != NULL) {

		switch (Copy_u8PortId) {

			case DIO_u8_PORTA:

			*Copy_Pu8ReturnValue = DIO_U8_PINA_REG;

			break;

			case DIO_u8_PORTB:

			*Copy_Pu8ReturnValue = DIO_U8_PINB_REG;

			break;

			case DIO_u8_PORTC:

			*Copy_Pu8ReturnValue = DIO_U8_PINC_REG;

			break;

			case DIO_u8_PORTD:

			*Copy_Pu8ReturnValue = DIO_U8_PIND_REG;

			break;

		}

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
#endif
