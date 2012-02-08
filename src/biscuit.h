#ifndef __BISCUIT_
#define __BISCUIT_

#include "biscuit_core.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>

/*
 * Power related macros
 *
 * Power High bit is 0x80 on PORTD
 * Power Sense bit is 0x20 on PINB
 */
#define BISC_PWR_HIGH               0x80
#define BISC_PWR_SENSE              0x20
#define BISC_PWR_TOGGLE_HIGH()      (PORTD |= BISC_PWR_HIGH)
#define BISC_PWR_TOGGLE_LOW()       (PORTD &= ~BISC_PWR_HIGH)
#define BISC_PWR_IS_ON              (PINB & BISC_PWR_SENSE)

/*
 * Prepares the Create to execute programs
 */
void bisc_prepare();

/*
 * Powers on the Create
 */
void bisc_power_on()

/*
 * Sets the operating mode of Create to passive
 */
void bisc_mode_passive();

/*
 * Sets the operating mode of Create to safe
 */
void bisc_mode_safe();

/*
 * Sets the operating mode of Create to full
 */
void bisc_mode_full();

/*
 * description
 * 
 * led: 
 * color: integer 0-255 from green to red
 * intensity: integer 0-255 from 0% to 100%
 */
void bisc_led_on(uint8_t led, uint8_t color, uint8_t intensity);

/*
 * description
 * 
 * led: 
 */
void bisc_led_off(uint8_t led);

#endif