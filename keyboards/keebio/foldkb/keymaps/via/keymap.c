/* Copyright 2021 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "encoder.h"
#include QMK_KEYBOARD_H

extern rgblight_config_t rgblight_config;

enum custom_keycodes {
  T_MUTE = SAFE_RANGE
};

// LAYOUTS = _BASE _PD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [1] = LAYOUT(
    KC_ESC,  KC_GRV,  KC_1,           KC_2,    KC_3,    KC_4,    KC_5,    KC_6,               KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC,
    KC_HOME,          KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_END,           LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_PGUP,          KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, TG(1),
    KC_PGDN,          KC_LCTL,        KC_LGUI, KC_LALT, MO(1),   KC_SPC,  LGUI_T(KC_SPC),     KC_SPC,  MO(1),  KC_RALT, KC_RGUI, KC_MENU, KC_RCTL
  ),
  [2] = LAYOUT(
    KC_MUTE, QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12, _______, KC_DEL,
    T_MUTE,             _______, RGB_HUD, RGB_HUI, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_MOD,            _______, RGB_SAD, RGB_SAI, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,         _______,
    KC_VOLU,            _______, RGB_VAD, RGB_VAI, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    KC_VOLD,            _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  ),
  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  )
};

// int RGB_current_mode = rgblight_config.mode;

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _PD:
//             rgblight_setrgb(RGB_RED);
//             break;
//         default: // for any other layers, or the default layer
//             rgblight_mode(RGB_current_mode);
//             break;
//     }
//   return state;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//       case T_MUTE:
//           if (record->event.pressed) {
//             SEND_STRING(SS_LSFT(SS_LCTL(("m")));
//             // SEND_STRING ("g");
//           } 
//           break;
//       }
//   return true;
// }
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [3] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
};
#endif
