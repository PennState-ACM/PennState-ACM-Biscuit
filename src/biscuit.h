#ifndef __BISCUIT_
#define __BISCUIT_

#include "biscuit_core.h"

/*
 * Starts the Open Interface and sets the mode to BISC_MODE_SAFE
 */
void bisc_init();

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
void bisc_ledOn(uint8_t led, uint8_t color, uint8_t intensity);

/*
 * description
 * 
 * led: 
 */
void bisc_ledOff(uint8_t led);

#endif