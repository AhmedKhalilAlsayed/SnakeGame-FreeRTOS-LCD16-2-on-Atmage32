//Lib
#include "newTypes.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

//MCAL
#include "DIO_interface.h"

//HAL
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_confg.h"

#if LCD_MODE == 8

void LCD_Init(void) {
	_delay_ms(35);

	//function set
	LCD_voidWriteComnd(0b00111000);
	_delay_us(40);
	//display on/off control
	LCD_voidWriteComnd(0b00001101);
	_delay_us(40);
	//display clear
	LCD_voidWriteComnd(0b00000001);
	_delay_ms(2);
	//entry mode
	LCD_voidWriteComnd(0b00000110);
}

void LCD_voidWriteChar(u8 Copy_u8Char) {

	/*
	 * RS = 1
	 * RW = 0
	 * Send Data as a Byte to LCD
	 * Enable
	 * */

	DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

	DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);

	_delay_us(1);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);

}

void LCD_voidWriteComnd(u8 Copy_u8Cmnd) {

	/*
	 * RS = 0
	 * RW = 0
	 * Send Data as a Byte to LCD
	 * Enable
	 * */

	DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

	DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);

	_delay_us(1);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);

}

#elif LCD_MODE == 4
//privates
static void LCD_voidWriteHalfComnd(u8 Copy_u8HalfCmnd) {
	//RS
	DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);
	//RW
	DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	//half data
	DIO_u8SetPinValue(LCD_u8_DATA_PIN7_PORT, LCD_u8_DATA_PIN7,
			Copy_u8HalfCmnd >> 3 & 1);
	DIO_u8SetPinValue(LCD_u8_DATA_PIN6_PORT, LCD_u8_DATA_PIN6,
			Copy_u8HalfCmnd >> 2 & 1);
	DIO_u8SetPinValue(LCD_u8_DATA_PIN5_PORT, LCD_u8_DATA_PIN5,
			Copy_u8HalfCmnd >> 1 & 1);
	DIO_u8SetPinValue(LCD_u8_DATA_PIN4_PORT, LCD_u8_DATA_PIN4,
			Copy_u8HalfCmnd >> 0 & 1);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);

	_delay_us(1);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);

}
static void LCD_voidWriteHalfChar(u8 Copy_u8HalfChar) {
	//RS
	DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);
	//RW
	DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	//half data
	DIO_u8SetPinValue(LCD_u8_DATA_PIN7_PORT, LCD_u8_DATA_PIN7,
			Copy_u8HalfChar >> 3 & 1);
	DIO_u8SetPinValue(LCD_u8_DATA_PIN6_PORT, LCD_u8_DATA_PIN6,
			Copy_u8HalfChar >> 2 & 1);
	DIO_u8SetPinValue(LCD_u8_DATA_PIN5_PORT, LCD_u8_DATA_PIN5,
			Copy_u8HalfChar >> 1 & 1);
	DIO_u8SetPinValue(LCD_u8_DATA_PIN4_PORT, LCD_u8_DATA_PIN4,
			Copy_u8HalfChar >> 0 & 1);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);

	_delay_us(1);

	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);

}
//end privates

void LCD_Init(void) {
	_delay_ms(35);

	//function set
	LCD_voidWriteHalfComnd(0b0010);

	LCD_voidWriteComnd(0b00101000);
	_delay_us(40);
	//display on/off control
	LCD_voidWriteComnd(0b00001101);
	_delay_us(40);
	//display clear
	LCD_voidWriteComnd(0b00000001);
	_delay_ms(2);
	//entry mode
	LCD_voidWriteComnd(0b00000110);

}

void LCD_voidWriteChar(u8 Copy_u8Char) {
	LCD_voidWriteHalfChar(Copy_u8Char >> 4 & 0x0f); //high bits
	LCD_voidWriteHalfChar(Copy_u8Char & 0x0f); //low  bits



}

void LCD_voidWriteComnd(u8 Copy_u8Cmnd) {
	LCD_voidWriteHalfComnd(Copy_u8Cmnd >> 4 & 0x0f); //high bits
	LCD_voidWriteHalfComnd(Copy_u8Cmnd & 0x0f); //low  bits
}


void LCD_voidCursorOFFDataON(){
	LCD_voidWriteComnd(0b00001100);
}

#else

#error "You entered invalid LCD_MODE in <LCD_confg.h>"

#endif





void LCD_voidCreateChar(u8 indexInCGRAM, u8* smallPattern) {

	if (smallPattern != NULL && indexInCGRAM < 8) {

		//set address counter : CGRAM
		LCD_voidWriteComnd(0x40 + (8 * indexInCGRAM));
		//draw a pattern
		LCD_voidWriteChar(smallPattern[0]);
		LCD_voidWriteChar(smallPattern[1]);
		LCD_voidWriteChar(smallPattern[2]);
		LCD_voidWriteChar(smallPattern[3]);
		LCD_voidWriteChar(smallPattern[4]);
		LCD_voidWriteChar(smallPattern[5]);
		LCD_voidWriteChar(smallPattern[6]);
		LCD_voidWriteChar(smallPattern[7]);

	}


//	_delay_ms(1);


	//set address counter : DDRAM
	LCD_u8GoToXY(LCD_u8_LINE1, 0);

}

u8 LCD_u8GoToXY(u8 Copy_u8LineNumber, u8 Copy_u8CharLocation) {
	u8 local_u8ErrorState = STD_TYPES_OK;

	switch (Copy_u8LineNumber) {
	case LCD_u8_LINE1:
		LCD_voidWriteComnd(0x80 + Copy_u8CharLocation);
		break;

	case LCD_u8_LINE2:
		LCD_voidWriteComnd(0xC0 + Copy_u8CharLocation);
		break;

	default:
		local_u8ErrorState = STD_TYPES_NOK;
	}


	_delay_us(40);

	return local_u8ErrorState;
}

void LCD_voidWriteString(u8* str) {

	if (str != NULL) {

		while (*str != '\0') {
			LCD_voidWriteChar(*str);
			str++;
		}

	}
}



#if 0

void LCD_voidClear(void) {
	//display clear
	LCD_voidWriteComnd(0b00000001);
	_delay_ms(2);
}

void LCD_voidWriteNumber(u32 number) {

	/* way 1: 15b
	 * number 4b
	 * temp   1b
	 * arr    4294967295>10b

	 * way 2: 10b!
	 * number 4b
	 * temp 1b
	 * helper 4b
	 * zeros 1b
	 *

	 * way3 : 9b
	 * number 4b
	 * helper 4b
	 * temp   1b
	 *
	 *
	 */

	if (number != 0) {

		u32 helper = 1000000000;

		while (helper != 0) {

			if (number >= helper) {

				u8 temp = (number / helper) % 10;
				LCD_voidWriteChar(ASCI_ZERO + temp);

			}
			helper /= 10;
		}

	} else {
		LCD_voidWriteChar(ASCI_ZERO);
	}

}

void LCD_voidShiftString(u8* str, enum LCD_enumDirections enumDirection) {

	switch (enumDirection) {
		case LEFT:

		private_u8ShiftSpace--;
		private_u8ShiftSpace %= 255;

		break;

		case RIGHT:

		private_u8ShiftSpace++;
		private_u8ShiftSpace %= 80;

		break;

		case UP:

		if (private_u8ShiftSpace >= 40) {
			private_u8ShiftSpace -= 40;
		}

		break;

		case DOWN:

		if (private_u8ShiftSpace <= 40) {
			private_u8ShiftSpace += 40;
		}
		break;

		case NONE:
		//	empty
		break;

	}

	LCD_voidClear();

	for (u8 i = 0; i < private_u8ShiftSpace; i++)
	LCD_voidWriteChar(' ');

	LCD_voidWriteString(str);
}

void LCD_voidShiftDisplay(enum LCD_enumDirections enumDirection) {
	switch (enumDirection) {
		case LEFT:
		LCD_voidWriteComnd(0b00011000);
		break;

		case RIGHT:
		LCD_voidWriteComnd(0b00011100);
		break;

		default:
		//empty
		break;
	}
}

void LCD_voidWriteFloatNumber(f32 number) {

	if ((u32) number != number) {

		LCD_voidWriteNumber((u32) number);
		LCD_voidWriteChar('.');

		// how many digits after decimel point
		for (u8 i = 10; i <= 100; i *= 10) {
			LCD_voidWriteNumber((u32) (number * i) % 10);
		}

	} else {
		LCD_voidWriteNumber((u32) number);
	}

}
#endif
