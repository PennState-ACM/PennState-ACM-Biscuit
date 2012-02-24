#include "main.h"

int main(void) {
    bisc_init();

    uint8_t value = 0;
    while(1) {
        if(value % 2 == 0) {
            bisc_led_on(BISC_LED_BOTH, 255, 255);
        }
        else {
            bisc_led_off(BISC_LED_BOTH);
        }

        value++;
    }


/*    // Testing the song functions
    uint8_t song[4];

    song[0] = 35;
    song[1] = 64;
    song[2] = 50;
    song[3] = 32;

    bisc_define_song(0, 2, song);
    bisc_play_song(0);*/

    return 0;
}
