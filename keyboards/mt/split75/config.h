// Copyright 2022 Artjoms Rizihs (@artjomsR)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 14

#define LED_NUM_LOCK_PIN D0
#define LED_CAPS_LOCK_PIN D1
#define LED_SCROLL_LOCK_PIN D6

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
#define I2C_START_RETRY_COUNT 1
