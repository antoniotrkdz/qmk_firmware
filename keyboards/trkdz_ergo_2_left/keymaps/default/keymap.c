#include "trkdz_ergo_2_left.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
    *   ,-----------------------------------------.     ,-----------------------------------------------------.
    *   | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 |Print| Ins | Del |
    *   |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
    *   |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspace | Home|
    *   |-----------------------------------------'     ,-----------------------------------------------+-----|
    *   | Tab       |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  \  | PgUp|
    *   |-----------------------------------------.     `-----------------------------------------------+-----|
    *   | Ctrl      |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |   Enter   | PgDn|
    *   |-----------------------------------------.     `-----------------------------------------------+-----|
    *   | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | End |
    *   |-----------------------------------------'     ,-----------------------------------------+-----+-----|
    *   | Ctrl      | GUI | Alt |  Space | Space  |     | Space         |  Alt  |   | Ctrl  | Left| Down|Right|
    *   `-----------------------------------------'     `-----------------------------------------------------'
    */
//--------------------------------Left Hand-----------------------------------| |--------------------------------Right Hand------------------------------------------------
	KEYMAP(
		KC_ESC, 	KC_F1, 		KC_F2, 		KC_F3, 	KC_F4, 	KC_F5, 
		KC_GRV, 	KC_1, 		KC_2, 		KC_3, 	KC_4, 	KC_5, 
		KC_TAB, 	KC_Q, 		KC_W, 		KC_E, 	KC_R, 	KC_T, 
		KC_LCTL,	KC_A, 		KC_S, 		KC_D, 	KC_F, 	KC_G, 
		KC_LSFT, 	KC_Z, 		KC_X, 		KC_C, 	KC_V, 	KC_B, 
		KC_LCTL, 	KC_LGUI,	KC_LALT,	KC_SPC, KC_SPC),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

/* const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
} */

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}