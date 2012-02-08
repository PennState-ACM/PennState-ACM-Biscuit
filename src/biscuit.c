#include "biscuit.h"

void bisc_prepare() {
    bisc_led_off(BISC_LED_BOTH);

    //TODO: when we handle interrupt stuff, it will go here

    bisc_power_on();
    bisc_start();
    bisc_mode_safe();
}

void bisc_power_on() {
    //check if the power is already on
    if(!BISC_PWR_IS_ON) {
        //loop until the power is on
        while(!BISC_PWR_IS_ON) {
            //a power tranisition happens when the powr toggles low to high
            //delays are included to let the create notice the change
            BISC_PWR_TOGGLE_LOW();
            delayMs(100);
            BISC_PWR_TOGGLE_HIGH();
            delayMs(100);
        }
        //toggle power back to low
        BISC_PWR_TOGGLE_LOW();

        //delay for create bootloader
        delayMs(2000);
    }
}

void bisc_mode_passive() {
    bisc_setMode(BISC_MODE_PASSIVE);
}

void bisc_mode_safe() {
    bisc_setMode(BISC_MODE_SAFE);
}

void bisc_mode_full() {
    bisc_setMode(BISC_MODE_FULL);
}

void bisc_led_on(uint8_t led, uint8_t color, uint8_t intensity) {
    bisc_led(led, color, intensity);
}


void bisc_led_off(uint8_t led) {
    // Power LED = 0x08
    // Advance LED = 0x02
    // Both power and advance = 0x0A
    // #define these values?

    bisc_led(led, 0, 0);
}
