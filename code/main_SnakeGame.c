/*
 * main_SnakeGame.c
 *
 *  Created on: Sep 18, 2022
 *      Author: Mega Store
 */

/*
 *todo's
 * -big when eat 				 >>DONE
 * -no move in the oppsite direc >>DONE
 * -clean code					 >>DONE
 *
 *
 * -score
 * -loss case
 * -accurate snake speed
 *
 * */

#include "newTypes.h"

#include "DIO_interface.h"
#include "Timer_interface.h"

#include "KPD_interface.h"
#include "LCD_interface.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#define EMPTY 			(255)

#define MAX_SNAKE		(10)
// can't be more than 7
#define LCD_SIZE_X_COLS	(7)
// can't be more than 1
#define LCD_SIZE_Y_ROWS	(1)

#define SNAKE_SPEED_1MS_TICKS (200)

/*
 * Desc:
 *  if overflow error will be happend
 * */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char * pcTaskName) {
	DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, 1);
}

/*
 * Desc:
 *  the availabe directions
 * */
typedef enum {

	SnakeDirection_Right,
	SnakeDirection_Left,
	SnakeDirection_Up,
	SnakeDirection_Down

} SnakeDirection_t;

/*
 * Desc:
 *  Each bit as a point has 3 pars
 * */
typedef struct {
	u8 x;
	u8 y;
	SnakeDirection_t direc;
} Point_t;

/*
 * Desc:
 *  One char in LCD 16*2
 * */
typedef struct {
	u8 arrChar[8];
} LCD_Char_t;

/*
 * Desc:
 *  We fill our snake path in this array
 * then paste it to CGRAM in LCD
 * then in the display RAM
 * */
volatile LCD_Char_t Glob_arrCharLCD[LCD_SIZE_Y_ROWS][LCD_SIZE_X_COLS];

/*
 * Desc:
 *  The point of apple , it will be eaten by snake
 * */
volatile Point_t Glob_pointApple = { .x = EMPTY, .y = EMPTY };

/*
 * Desc:
 *  Snake data (head direction - snake array - snake length)
 * */
volatile SnakeDirection_t Glob_enumSnakeDirection = SnakeDirection_Right;
volatile Point_t Glob_pointArrSnake[MAX_SNAKE];
volatile u8 Glob_u8SnakeLength = 3;

/*
 * Desc:
 *  to be safe when snake move
 * */
volatile xSemaphoreHandle semSnakeArr_1;

/*
 * Desc:
 *  Task to check the direction from keypad
 * */
void voidTaskDirectionBtn(void *pv);

/*
 * Desc:
 *  Task to move snake
 * */
void voidTaskMoveSnake(void *pv);

/*
 * Desc:
 *  Task to update any change into LCD
 * */
void voidTaskUpdateLCD(void *pv);

void voidTaskDirectionBtn(void *pv) {

	static u8 Local_u8BtnValue = 0;

	while (1) {

		KPD_u8GetKeyValueNoWait(&Local_u8BtnValue);

		xSemaphoreTake(semSnakeArr_1, portMAX_DELAY);

		if (Local_u8BtnValue == '6') {

			if (Glob_enumSnakeDirection != SnakeDirection_Left) {
				Glob_enumSnakeDirection = SnakeDirection_Right;
			}

		} else if (Local_u8BtnValue == '4') {

			if (Glob_enumSnakeDirection != SnakeDirection_Right) {
				Glob_enumSnakeDirection = SnakeDirection_Left;
			}

		} else if (Local_u8BtnValue == '2') {
			if (Glob_enumSnakeDirection != SnakeDirection_Down) {
				Glob_enumSnakeDirection = SnakeDirection_Up;
			}

		} else if (Local_u8BtnValue == '5') {
			if (Glob_enumSnakeDirection != SnakeDirection_Up) {
				Glob_enumSnakeDirection = SnakeDirection_Down;
			}

		}

		xSemaphoreGive(semSnakeArr_1);

		if (Local_u8BtnValue != 0) {
			Local_u8BtnValue = 0;
		}

		vTaskDelay(100);

	}

}

void voidTaskMoveSnake(void *pv) {
	static u8 Local_u8i = 0;
	static Point_t Local_pointSnakeOldTail;

	// Init the Snake points
	{

		// the starting position of Snake
		u8 temp = Glob_u8SnakeLength;

		for (Local_u8i = 0; Local_u8i < Glob_u8SnakeLength; Local_u8i++) {
			Glob_pointArrSnake[Local_u8i].x = temp--;
			Glob_pointArrSnake[Local_u8i].y = 5;
			Glob_pointArrSnake[Local_u8i].direc = Glob_enumSnakeDirection;
		}
	}

	while (1) {

		xSemaphoreTake(semSnakeArr_1, portMAX_DELAY);

		/// Moving

		// store the tail of snake for future growth

		Local_pointSnakeOldTail = Glob_pointArrSnake[(Glob_u8SnakeLength - 1)];

		// update the direction for all point

		for (Local_u8i = (Glob_u8SnakeLength - 1); Local_u8i > 0; Local_u8i--) {
			Glob_pointArrSnake[Local_u8i].direc = Glob_pointArrSnake[Local_u8i
					- 1].direc;
		}

		Glob_pointArrSnake[0].direc = Glob_enumSnakeDirection;

		// update the values of points

		for (Local_u8i = 0; Local_u8i < Glob_u8SnakeLength; Local_u8i++) {
			switch (Glob_pointArrSnake[Local_u8i].direc) {
			case SnakeDirection_Right:
				Glob_pointArrSnake[Local_u8i].x++;
				Glob_pointArrSnake[Local_u8i].x %= (LCD_SIZE_X_COLS * 5);
				break;
			case SnakeDirection_Left:
				Glob_pointArrSnake[Local_u8i].x--;
				if (Glob_pointArrSnake[Local_u8i].x == EMPTY) {
					Glob_pointArrSnake[Local_u8i].x = (LCD_SIZE_X_COLS * 5) - 1;
				}
				break;
			case SnakeDirection_Up:
				Glob_pointArrSnake[Local_u8i].y++;
				Glob_pointArrSnake[Local_u8i].y %= (LCD_SIZE_Y_ROWS * 8);
				break;
			case SnakeDirection_Down:
				Glob_pointArrSnake[Local_u8i].y--;
				if (Glob_pointArrSnake[Local_u8i].y == EMPTY) {
					Glob_pointArrSnake[Local_u8i].y = (LCD_SIZE_Y_ROWS * 8) - 1;
				}
				break;
			}
		}

		/// Eating an apple

		// is there an apple ?
		if ((Glob_pointApple.x == EMPTY) || (Glob_pointApple.y == EMPTY)) {
			// create a new apple

			u8 temp;

			// get a random number

			TMR_voidGetTMR0(&temp);
			Glob_pointApple.x = temp % (LCD_SIZE_X_COLS * 5);

			// get a random number

			TMR_voidGetTMR0(&temp);
			Glob_pointApple.y = temp % (LCD_SIZE_Y_ROWS * 8);

		} else {

			// check if corrent eating

			// head of snake
			if ((Glob_pointArrSnake[0].x == Glob_pointApple.x)
					&& (Glob_pointArrSnake[0].y == Glob_pointApple.y)) {

				// succss

				if (Glob_u8SnakeLength < MAX_SNAKE) {
					Glob_u8SnakeLength++;

					Glob_pointArrSnake[(Glob_u8SnakeLength - 1)] =
							Local_pointSnakeOldTail;

				}

				// to create a new one
				Glob_pointApple.x = EMPTY;
				Glob_pointApple.y = EMPTY;

			}

		}

		xSemaphoreGive(semSnakeArr_1);

		vTaskDelay(SNAKE_SPEED_1MS_TICKS);
	}
}

void voidTaskUpdateLCD(void *pv) {
	static u8 Local_u8row = 0;
	static u8 Local_u8col = 0;

	while (1) {

		for (Local_u8row = 0; Local_u8row < LCD_SIZE_Y_ROWS; Local_u8row++) {
			for (Local_u8col = 0; Local_u8col < LCD_SIZE_X_COLS;
					Local_u8col++) {

				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[0] = 0;
				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[1] = 0;
				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[2] = 0;
				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[3] = 0;
				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[4] = 0;
				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[5] = 0;
				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[6] = 0;
				Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar[7] = 0;
			}
		}

		/// Modify the Glob_arrCharLCD[][]

		xSemaphoreTake(semSnakeArr_1, portMAX_DELAY);

		for (Local_u8row = 0; Local_u8row < Glob_u8SnakeLength; Local_u8row++) {

			// equation from (x ,y ) to get the char position

			SET_BIT(
					(Glob_arrCharLCD[(Glob_pointArrSnake[Local_u8row].y / 8)][(Glob_pointArrSnake[Local_u8row].x
							/ 5)].arrChar[7
							- (Glob_pointArrSnake[Local_u8row].y % 8)]),
					(4 - (Glob_pointArrSnake[Local_u8row].x % 5)));
//
		}

		/// check apple for display

		if ((Glob_pointApple.x != EMPTY) && (Glob_pointApple.y != EMPTY)) {
			SET_BIT(
					(Glob_arrCharLCD[(Glob_pointApple.y / 8)][(Glob_pointApple.x
							/ 5)].arrChar[7 - (Glob_pointApple.y % 8)]),
					(4 - (Glob_pointApple.x % 5)));
		}

		xSemaphoreGive(semSnakeArr_1);

		/// start update LCD (writing)

		for (Local_u8row = 0; Local_u8row < LCD_SIZE_Y_ROWS; Local_u8row++) {
			for (Local_u8col = 0; Local_u8col < LCD_SIZE_X_COLS;
					Local_u8col++) {

				LCD_voidCreateChar(Local_u8col,
						Glob_arrCharLCD[Local_u8row][Local_u8col].arrChar);
				LCD_u8GoToXY(Local_u8row, (Local_u8col + 5)); // 5>> represents the shift on LCD
				LCD_voidWriteChar(Local_u8col);
			}
		}

		vTaskDelay(SNAKE_SPEED_1MS_TICKS);
	}
}

//void voidTaskLCDTest(void *pv) {
//	while (1) {
//		LCD_voidWriteString("Ahmed ");
//
//		vTaskDelay(SNAKE_SPEED_1MS_TICKS);
//	}
//}

int main() {

	DIO_Init();
	TMR_voidInitTMR0();
	LCD_Init();
	LCD_voidCursorOFFDataON();

	{
		/// Draw The Game Border

		u8 u8arrBlackChar[8] = { 0b11111, 0b10101, 0b10001, 0b10101, 0b11011,
				0b10101, 0b10001, 0b11111 };

		LCD_voidCreateChar(7, u8arrBlackChar);

		for (u8 i = 0; i < 5; i++) {
			LCD_u8GoToXY(0, i);
			LCD_voidWriteChar(7);
		}

		for (u8 i = 11; i < 16; i++) {
			LCD_u8GoToXY(0, i);
			LCD_voidWriteChar(7);
		}

		for (u8 i = 0; i < 16; i++) {
			LCD_u8GoToXY(1, i);
			LCD_voidWriteChar(7);
		}

	}

	semSnakeArr_1 = xSemaphoreCreateCounting(1, 1);

	if ((xTaskCreate(voidTaskDirectionBtn, NULL, 90, NULL, 0, NULL) == pdPASS)
			&& (xTaskCreate(voidTaskMoveSnake, NULL, 110, NULL, 0, NULL)
					== pdPASS)
			&& (xTaskCreate(voidTaskUpdateLCD, NULL, 450, NULL, 0, NULL)
					== pdPASS)) {

		// Start

		vTaskStartScheduler();

	} else {
		// no space found
		LCD_voidWriteString(" NULL ");
	}

	while (1) {

	}

	return 0;
}
