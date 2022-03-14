// Copyright 2022 antoniotrkdz (@antoniotrkdz)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* // Defines names for use in layer keycodes and the keymap
enum layer_names {
    _base,
    _fn
}; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
     KEYMAP(
		KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_INS, 
		KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, 
		KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_DEL, 
		KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,  KC_ENT, 
		KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,    KC_SPC, 
		KC_SPC, KC_SPC, KC_LALT, KC_LCTL,          KC_LEFT, KC_DOWN,  KC_RIGHT),

/*     KEYMAP(
		KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, 
		KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_DEL, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT, 
		KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SPC, KC_NO, KC_SPC, 
		KC_SPC, KC_SPC, KC_LALT, KC_LCTL, KC_NO, KC_NO, KC_NO
    ),
    KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______
    ) */
};
