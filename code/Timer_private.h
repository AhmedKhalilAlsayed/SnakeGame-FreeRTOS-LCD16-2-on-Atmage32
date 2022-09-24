/*
 * Timer_private.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Mega Store
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TMR_u8_TMR0_OCR0_REG		*((volatile u8*)0x5c)
#define TMR_u8_TMR0_TCCR0_REG		*((volatile u8*)0x53)
#define TMR_u8_TMR0_TCNT0_REG		*((volatile u8*)0x52)

#if 0

#define TMR_u8_TMR1_TCCR1A_REG		*((volatile u8*)0x4f)
#define TMR_u8_TMR1_TCCR1B_REG		*((volatile u8*)0x4e)

#define TMR_u16_TMR1_TCNT1_REG		*((volatile u16*)0x4c)
#define TMR_u16_TMR1_OCR1A_REG		*((volatile u16*)0x4a)
#define TMR_u16_TMR1_OCR1B_REG		*((volatile u16*)0x48)
#define TMR_u16_TMR1_ICR1_REG		*((volatile u16*)0x46)

//////////////////////////

#define TMR_u8_TIMSK_REG		*((volatile u8*)0x59)
#define TMR_u8_TIFR_REG			*((volatile u8*)0x58)

//MAXVOLT_
#define MAX_MILLI_VOLT_CONTROLLER	5000UL
// resolution
#define TMR_MAXCOUNTER	256
// time of OVF by prescaler
#define MICRO_TIME_OVF_PRESCALER_1		    32UL
#define MICRO_TIME_OVF_PRESCALER_8		    256UL
#define MICRO_TIME_OVF_PRESCALER_64		    2048UL
#define MICRO_TIME_OVF_PRESCALER_256		8192UL
#define MICRO_TIME_OVF_PRESCALER_1024		32768UL

// OFF for any thing
#define OFF		0

/* NORMAL, CTC, FAST_PWM , PHASE_PWM*/
#define NORMAL	1
#define CTC		2
#define FAST_PWM	3
#define PHASE_PWM 4
#define COUNTER 5

//mode of pin PWM
#define INVERTING	6
#define NON_INVERTING	7

#endif

#endif /* TIMER_PRIVATE_H_ */
