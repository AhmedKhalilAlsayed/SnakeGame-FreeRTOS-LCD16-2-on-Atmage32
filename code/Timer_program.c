#include "newTypes.h"

#include "Timer_private.h"
#include "Timer_interface.h"
#include "Timer_config.h"

void TMR_voidInitTMR0(void) {

	// Timer 0 mode
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT6);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT3);
	// prescaler
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
	SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);

}

void TMR_voidGetTMR0(u8* value) {

	*value = TMR_u8_TMR0_TCNT0_REG;

}

#if 0
#define STOP 	0
#define NO_STOP 1

static void (*TMR_pfn[3])(void);
static u8 TMR_Au8Mode[3] = {TMR_MODE_TMR_0, TMR_MODE_TMR_1, TMR_MODE_TMR_2};
static u16 TMR_Au8Prescaler[3] = {TMR_PRESCALER_TMR_0, TMR_PRESCALER_TMR_1,
	TMR_PRESCALER_TMR_2};
static u16 TMR_Au16RepeatOVF[3];
static u16 TMR_u16Counters[3];
static u16 TMR_Au16Preload[3];
static u8 TMR_Au8WaitStops[3];

//

void TMR_voidFastPWMCorrectFreqTMR_1(void) {
	//TMR1 > mode 14, ICR1 is top
	CLR_BIT(TMR_u8_TMR1_TCCR1A_REG, BIT0);
	SET_BIT(TMR_u8_TMR1_TCCR1A_REG, BIT1);

	SET_BIT(TMR_u8_TMR1_TCCR1B_REG, BIT3);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG, BIT4);

	//select non inverting mode for OC1A pin
	CLR_BIT(TMR_u8_TMR1_TCCR1A_REG, BIT6);
	SET_BIT(TMR_u8_TMR1_TCCR1A_REG, BIT7);

	// set top value of TMR1

	TMR_u16_TMR1_ICR1_REG = 20000 - 1;

	// to go to angle 0 , duty = 1ms,
	TMR_u16_TMR1_OCR1A_REG = 2100 - 1;

	// start TMR1 by prescaler = 8
	CLR_BIT(TMR_u8_TMR1_TCCR1B_REG, BIT2);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG, BIT1);
	CLR_BIT(TMR_u8_TMR1_TCCR1B_REG, BIT0);

}

void TMR_voidSetOCR1A(u16 value) {
	TMR_u16_TMR1_OCR1A_REG = value;
}

u16 TMR_u16GetOCR1A() {
	return TMR_u16_TMR1_OCR1A_REG;
}

//
static u8 TMR_TickCalc(u8 TMRX, u32 unitScale, u16 value) {

	if (TMR_Au8Mode[TMRX] != FAST_PWM && TMR_Au8Mode[TMRX] != PHASE_PWM) {

		TMR_Au16RepeatOVF[TMRX] =
		(value * (F_CPU / unitScale / TMR_Au8Prescaler[TMRX]))
		/ TMR_MAXCOUNTER;

		TMR_Au16Preload[TMRX] =
		((value * (F_CPU / unitScale / TMR_Au8Prescaler[TMRX]))
				% TMR_MAXCOUNTER);

		if (TMR_Au16Preload[TMRX] > 0) {

			if (TMR_Au8Mode[TMRX] != CTC)
			TMR_Au16Preload[TMRX] = TMR_MAXCOUNTER - TMR_Au16Preload[TMRX];

			TMR_Au16RepeatOVF[TMRX]++;
		}

		TMR_u16Counters[TMRX] = TMR_Au16RepeatOVF[TMRX];

		return 0;

	} else {

		return ((value * (F_CPU / unitScale / TMR_Au8Prescaler[TMRX]))
				% TMR_MAXCOUNTER);

	}

}

void TMR_voidChangePrescaler_TMR_0(u16 prescaler) {

	TMR_Au8Prescaler[TMR_0] = prescaler;

	switch (TMR_Au8Prescaler[TMR_0]) {

		case PRESCALER_1:
		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);
		break;

		case PRESCALER_8:

		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);
		break;

		case PRESCALER_64:

		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);

		break;

		case PRESCALER_256:

		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);

		break;

		case PRESCALER_1024:

		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);

		break;

		case PRESCALER_EXT_T0PIN_FALLINGEFGE:

		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
		CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);

		break;

		case PRESCALER_EXT_T0PIN_RISINGEFGE:

		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
		SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);

		break;

	}

}

void TMR_voidWaitEvery_TMR_0(u32 TMR_unitScale, u16 value, void (*fn)(void)) {

	TMR_TickCalc(TMR_0, TMR_unitScale, value);
	TMR_pfn[TMR_0] = fn;
	TMR_Au8WaitStops[TMR_0] = NO_STOP;

	//enable Intrrupt
	//check mode, to enable its intrrupt
	switch (TMR_Au8Mode[TMR_0]) {

		case NORMAL:
		//intrrupt OVF
		CLR_BIT(TMR_u8_TIMSK_REG, BIT1);
		SET_BIT(TMR_u8_TIMSK_REG, BIT0);

		//value of counter REG
		TMR_u8_TMR0_TCNT0_REG = TMR_Au16Preload[TMR_0];

		break;

		case CTC:
		//intrrupt COMPARE
		CLR_BIT(TMR_u8_TIMSK_REG, BIT0);
		SET_BIT(TMR_u8_TIMSK_REG, BIT1);

		//value of compare REG
		TMR_u8_TMR0_OCR0_REG = --TMR_Au16Preload[TMR_0];
		break;

		case FAST_PWM:

		break;

		case PHASE_PWM:

		break;

		case OFF:
		break;

	}

	/*//CTC mode
	 CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT6);
	 SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT3);*/

	//INT
//	SET_BIT(TMR_u8_TIMSK_REG, BIT1);
//
//	TMR_u8_TMR0_OCR0_REG = 99;
	//pfnCTC = fn;
	//fast PWM mode
//	SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT6);
//	SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT3);
//
//	//select
//	SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT5);
//	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT4);
//
//	//init OCR
//	TMR_u8_TMR0_OCR0_REG = 0;
	//phase correct PWM mode
//	SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT6);
//	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT3);
//
//	//select
//	SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT5);
//	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT4);
//
//	//init OCR
//	TMR_u8_TMR0_OCR0_REG = 0;
//
//	//start with prescaler = 8, timerFreq = 1MHz
//	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
//	SET_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
//	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);
}

void TMR_voidWaitStop_TMR_0(u32 TMR_unitScale, u16 value, void (*fn)(void)) {
	TMR_voidWaitEvery_TMR_0(TMR_unitScale, value, fn);
	TMR_Au8WaitStops[TMR_0] = STOP;
}

void TMR__voidStop_TMR_0(void) {

	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT2);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT1);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG, BIT0);

}

void TMR_voidGenerateFASTPWM_RMS_TMR0(u16 milliVolts) {

	u32 microTimeOVF = MICRO_TIME_OVF_PRESCALER_1;

	switch (TMR_Au8Prescaler[TMR_0]) {

		case PRESCALER_1:

		microTimeOVF = MICRO_TIME_OVF_PRESCALER_1;

		break;

		case PRESCALER_8:

		microTimeOVF = MICRO_TIME_OVF_PRESCALER_8;

		break;

		case PRESCALER_64:

		microTimeOVF = MICRO_TIME_OVF_PRESCALER_64;

		break;

		case PRESCALER_256:

		microTimeOVF = MICRO_TIME_OVF_PRESCALER_256;

		break;

		case PRESCALER_1024:

		microTimeOVF = MICRO_TIME_OVF_PRESCALER_1024;

		break;
	}

	u32 tOn = (u32) ((u32) milliVolts * (u32) milliVolts * microTimeOVF)
	/ (MAX_MILLI_VOLT_CONTROLLER * MAX_MILLI_VOLT_CONTROLLER);

	u8 OCR0 = TMR_TickCalc(TMR_0, TMR_UNIT_SCALE_MICROSEC, tOn);

	// set value in OCR0 REG
	if (OCR0 != 0) {
		TMR_u8_TMR0_OCR0_REG = OCR0 - 1;
	} else {
		TMR_u8_TMR0_OCR0_REG = OCR0;
	}

}

// OVF TMR0 ISR
void __vector_11(void) __attribute__((signal));
void __vector_11(void) {

	GIE_voidDisable();

	if (TMR_Au8Mode[TMR_0] != COUNTER) {

		TMR_u16Counters[TMR_0]--;

		if (TMR_u16Counters[TMR_0] == 0) {

			if (TMR_Au8WaitStops[TMR_0] != STOP) {

				TMR_u16Counters[TMR_0] = TMR_Au16RepeatOVF[TMR_0];
				TMR_u8_TMR0_TCNT0_REG = TMR_Au16Preload[TMR_0];

			} else {
				TMR__voidStop_TMR_0();
			}

			//action
			TMR_pfn[TMR_0]();

		}
	} else {

		TMR_Au16RepeatOVF[TMR_0]++;

	}

	GIE_voidEnable();

}

// CTC TMR0 ISR
void __vector_10(void) __attribute__((signal));
void __vector_10(void) {

	TMR_u16Counters[TMR_0]--;

	if (TMR_u16Counters[TMR_0] == 0) {

		TMR_u16Counters[TMR_0] = TMR_Au16RepeatOVF[TMR_0];
		TMR_u8_TMR0_TCNT0_REG = TMR_Au16Preload[TMR_0];

		//action
		TMR_pfn[TMR_0]();

	}
}
#endif
