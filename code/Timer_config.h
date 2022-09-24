/*
 * Timer_config.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Mega Store
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


#if 0

#define F_CPU	8000000UL
/* PRESCALER_OFF
 PRESCALER_1
 PRESCALER_8
 PRESCALER_64
 PRESCALER_256
 PRESCALER_1024
 PRESCALER_EXT_T0PIN_FALLINGEFGE
 PRESCALER_EXT_T0PIN_RISINGEFGE  */
#define TMR_PRESCALER_TMR_0		PRESCALER_8
#define TMR_PRESCALER_TMR_1		PRESCALER_OFF
#define TMR_PRESCALER_TMR_2		PRESCALER_OFF


/*/* COUNTER, NORMAL, CTC, FAST_PWM , PHASE_PWM>>is not complete */

#define TMR_MODE_TMR_0	 NORMAL
#define TMR_MODE_TMR_1	 OFF
#define TMR_MODE_TMR_2	 OFF


/* //mode of pin PWM
 * OFF
 INVERTING
 NON_INVERTING	 */
#define TMR_PWM_PIN_MODE_TMR_0	NON_INVERTING
#define TMR_PWM_PIN_MODE_TMR_1	OFF
#define TMR_PWM_PIN_MODE_TMR_2	OFF

#endif

#endif /* TIMER_CONFIG_H_ */
