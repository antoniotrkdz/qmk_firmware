#pragma once

#define VENDOR_ID       0x594D
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    YMDK
#define PRODUCT         Split75
#define DESCRIPTION     VE.A Clone

/* matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 14

#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLIGHT_SPLIT

#define BACKLIGHT_PIN D4

/* Rotary encoder */
#define TAP_CODE_DELAY 10

#define ENCODERS_PAD_A { D1 }
#define ENCODERS_PAD_B { D6 }

#define ENCODER_RESOLUTION 1

/* #define ENCODER_DIRECTION_FLIP */

/* Tap dance */
#define TAPPING_TERM 200
