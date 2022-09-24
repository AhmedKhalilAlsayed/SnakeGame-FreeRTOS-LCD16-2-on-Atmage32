#include "newTypes.h"
#include <avr/delay.h>

/*MCAL*/
#include "DIO_interface.h"
/*HAL*/
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

static const u8 KPD_Au8Keys[4][4] = KPD_KEYS;

static const u8 KPD_Au8RowsPins[4] = {
KPD_U8_R1_PIN,
KPD_U8_R2_PIN,
KPD_U8_R3_PIN,
KPD_U8_R4_PIN };

static const u8 KPD_Au8RowsPorts[4] = {
KPD_U8_R1_PIN_PORT,
KPD_U8_R2_PIN_PORT,
KPD_U8_R3_PIN_PORT,
KPD_U8_R4_PIN_PORT };

static const u8 KPD_Au8ColsPins[4] = {
KPD_U8_C1_PIN,
KPD_U8_C2_PIN,
KPD_U8_C3_PIN,
KPD_U8_C4_PIN };

static const u8 KPD_Au8ColsPorts[4] = {
KPD_U8_C1_PIN_PORT,
KPD_U8_C2_PIN_PORT,
KPD_U8_C3_PIN_PORT,
KPD_U8_C4_PIN_PORT };

u8 KPD_u8GetKeyValueNoWait(u8* Copy_Pu8ReturnResult) {
	u8 local_u8ErrorState;
	u8 local_u8PinValue = 1;

	if (Copy_Pu8ReturnResult != NULL) {

		//*Copy_Pu8ReturnResult = 0xff;
		local_u8ErrorState = STD_TYPES_NOK;

		for (u8 row = 0; row < 4; row++) {

			//activate only one row
			DIO_u8SetPinValue(KPD_Au8RowsPorts[row], KPD_Au8RowsPins[row],
			DIO_u8_LOW);

			//check each column
			for (u8 col = 0; col < 4; col++) {
				//get pin value
				DIO_u8GetPinValue(KPD_Au8ColsPorts[col], KPD_Au8ColsPins[col],
						&local_u8PinValue);

				if (local_u8PinValue == DIO_u8_LOW) {
					//debouncing
					_delay_ms(20);

					do {
						DIO_u8GetPinValue(KPD_Au8ColsPorts[col],
								KPD_Au8ColsPins[col], &local_u8PinValue);
					} while (local_u8PinValue == DIO_u8_LOW);

					*Copy_Pu8ReturnResult = KPD_Au8Keys[row][col];
					local_u8ErrorState = STD_TYPES_OK; //to make sure we will recive a valid value

					//debouncing
					_delay_ms(20);

					break;
				}
			}
			//deactivate last row
			DIO_u8SetPinValue(KPD_Au8RowsPorts[row], KPD_Au8RowsPins[row],
			DIO_u8_HIGH);

			// break if pressed
			if (local_u8PinValue == 0) {
				break;
			}

		}

	} else {
		local_u8ErrorState = STD_TYPES_NOK;
	}

	return local_u8ErrorState;
}

#if 0
u8 KPD_u8GetKeyValueWait(void) {
	u8 result;
	while (1) {
		if (KPD_u8GetKeyValueNoLoop(&result) == STD_TYPES_OK) {
			break;
		}
	}
	return result;
}
#endif
