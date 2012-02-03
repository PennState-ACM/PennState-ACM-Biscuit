#include "biscuit.h"



void bisc_init() {
    bisc_start();
    bisc_setMode(BISC_MODE_SAFE);
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

void bisc_ledOn(uint8_t led, uint8_t color, uint8_t intensity) {
    bisc_led(led, color, intensity);
}


void bisc_ledOff(uint8_t led) {
    // Power LED = 0x08
    // Advance LED = 0x02
    // Both power and advance = 0x0A
    // #define these values?

    bisc_led(led, 0, 0);
}
