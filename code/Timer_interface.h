/*
 * Timer_interface.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Mega Store
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TMR_voidInitTMR0(void);
void TMR_voidGetTMR0(u8* value);

#if 0

#define TMR_u8_TMR0_OVF_INT			TMR0
#define TMR_u8_TMR0_CTC_INT			TMR0

// TMR_X
#define TMR_0	0
#define TMR_1	1
#define TMR_2	2

//prescaler
#define PRESCALER_OFF		            0

#define PRESCALER_1			            1UL
#define PRESCALER_8			            8UL
#define PRESCALER_64		            64UL
#define PRESCALER_256		            256UL
#define PRESCALER_1024 		            1024UL
#define PRESCALER_EXT_T0PIN_FALLINGEFGE 5
#define PRESCALER_EXT_T0PIN_RISINGEFGE  6

//unitScale
#define TMR_UNIT_SCALE_SEC		    1
#define TMR_UNIT_SCALE_mSEC		    1000UL
#define TMR_UNIT_SCALE_MICROSEC		1000000UL
//#define TMR_UNIT_SCALE_nSEC		1000000000UL

void TMR_voidInitConfig(void);

void TMR_voidChangePrescaler_TMR_0(u16 prescaler);

void TMR_voidReadCounter(u8 TMRX, u32* count);

void TMR_voidWaitEvery_TMR_0(u32 TMR_unitScale, u16 value, void (*fn)(void));
void TMR_voidWaitStop_TMR_0(u32 TMR_unitScale, u16 value, void (*fn)(void));
void TMR__voidStop_TMR_0(void);

void TMR_voidGenerateFASTPWM_RMS_TMR0(u16 milliVolts);

//
void TMR_voidFastPWMCorrectFreqTMR_1(void);
void TMR_voidSetOCR1A(u16 value);
u16 TMR_u16GetOCR1A();
//

#endif
#endif /* TIMER_INTERFACE_H_ */
