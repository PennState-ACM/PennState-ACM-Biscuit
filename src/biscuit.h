/*
 * Starts the Open Interface and sets the mode to BISC_MODE_SAFE
 */
void bisc_init();

/*
 * Sets the operating mode of Create
 *
 * mode: BISC_MODE_PASSIVE, BISC_MODE_SAFE, or BISC_MODE_FULL
 */
void bisc_setMode(uint8_t mode);

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
