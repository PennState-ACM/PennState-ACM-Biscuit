#include "biscuit_core.h"



void bisc_core_led(uint8_t led, uint8_t color, uint8_t intensity) {
    byteTx(BISC_CMD_LED);
    byteTx(led);
    byteTx(color);
    byteTx(intensity);
}


void bisc_core_sendIR(uint8_t value) {
    byteTx(BISC_CMD_SEND_IR);
    byteTx(value);
}
