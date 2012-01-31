bisc_core_led(int led, int color, int intensity) {
    // Power LED = 0x08
    // Advance LED = 0x02
    // Both power and advance = 0x0A
    // #define these values?

    // Color: integer 0-255 from green to red
    // Intensity: integer 0-255 from 0% to 100%
    byteTx(139);
    byteTx(led);
    byteTx(color);
    byteTx(intensity);
}
