#include "biscuit.h"



bisc_powerOn() {
    bisc_core_start();
    bisc_core_setMode(BISC_MODE_SAFE);
}


bisc_ledOn(uint8_t led, uint8_t color, uint8_t intensity) {
    bisc_core_led(led, color, intensity);
}


bisc_ledOff(uint8_t led) {
    // Power LED = 0x08
    // Advance LED = 0x02
    // Both power and advance = 0x0A
    // #define these values?

    bisc_core_led(led, 0, 0);
}
