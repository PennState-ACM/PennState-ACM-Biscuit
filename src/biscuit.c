bisc_ledOn(int led, int color, int intensity) {
    bisc_core_led(led, color, intensity);
}


bisc_ledOff(int led) {
    // Power LED = 0x08
    // Advance LED = 0x02
    // Both power and advance = 0x0A
    // #define these values?

    bisc_core_led(led, 0, 0);
}
