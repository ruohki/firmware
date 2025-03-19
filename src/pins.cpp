#include <Arduino.h>
#include <pins.h>
#include <config.h>

void pins_init(void)
{
    #if !WAVESHARE_BOARD || WAVESHARE_BOARD_WITH_PINS
    pinMode(PIN_INTERRUPT, INPUT);
    pinMode(PIN_RESET, INPUT_PULLUP);
    #endif
}

void pins_set_clear_interrupt(void (*f)(void))
{
    #if !WAVESHARE_BOARD || WAVESHARE_BOARD_WITH_PINS
    attachInterrupt(PIN_RESET, f, RISING);
    #endif
}