

#pragma once

// Backlight configuration
#define BACKLIGHT_LEVELS 8

#define LED_MATRIX_ROWS MATRIX_ROWS
#define LED_MATRIX_ROW_CHANNELS 3
#define LED_MATRIX_ROWS_HW (LED_MATRIX_ROWS * LED_MATRIX_ROW_CHANNELS)
#define LED_MATRIX_ROW_PINS { C0, C1, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, B6, B7, B8, B9, B10, B11 }

#define LED_MATRIX_COLS MATRIX_COLS
#define LED_MATRIX_COL_PINS MATRIX_COL_PINS

// 106 tasti + 6 LED laterali (3 destra + 3 sinistra), vedi config_led.c
#define DRIVER_LED_TOTAL (112)

// I LED 106-111 (i 6 laterali) hanno i piedini G/B invertiti sul PCB rispetto ai
// LED normali dei tasti: queste macro dicono al driver (drivers/led/sn32/
// rgb_matrix_sn32f24xb.c) di scambiare i due canali solo per questo intervallo di
// indici, direttamente in uscita verso il PWM.
#define RGB_MATRIX_SWAP_GB_LED_MIN 106
#define RGB_MATRIX_SWAP_GB_LED_MAX 111
