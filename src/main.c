#include "main.h"

int main(void) {
    bisc_prepare();

    bisc_led_on(BISC_LED_POWER, 255, 255);

    // Testing the song functions
    uint8_t song[4];

    song[0] = 35;
    song[1] = 64;
    song[2] = 50;
    song[3] = 32;

    bisc_define_song(0, 2, song);
    bisc_play_song(0);

    return 0;
}
