#include QMK_KEYBOARD_H

/* Inizialise indicator LEDs state functionality */
void keyboard_pre_init_user(void) {
    layer_state_set_user(layer_state);
}

/* Turn on/off num_lock according to state, but returning false takes control
 * over the indicator LEDs */
bool led_update_user(led_t led_state) {
    writePin(NUMLOCK_LED_PIN, led_state.num_lock);
    return false;
}

/* Macros enum */
enum {
    SCAD_TRANS,
    SCAD_ROT
};

/* Tap dance stuff */
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD
};

/* Tap dance enums */
enum {
    NO_HOME,
    NO_END,
    F13_LAYER
};

/* Tap dance functions */
uint8_t cur_dance(qk_tap_dance_state_t *state);

void nohome_finished(qk_tap_dance_state_t *state, void *user_data);
void nohome_reset(qk_tap_dance_state_t *state, void *user_data);
void noend_finished(qk_tap_dance_state_t *state, void *user_data);
void noend_reset(qk_tap_dance_state_t *state, void *user_data);

/* RGB light timeout stuff */
#define RGBLIGHT_TIMEOUT 5    // minutes
static uint16_t idle_timer = 0;
static uint8_t halfmin_counter = 0;
static bool rgb_on = true;

/* Matrix and layers */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base          ,-----------------------------------------.     ,-----------------------------------------------------.
    *                | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 |Print| Ins | Del |
    * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
    * |  8  |  9  |  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspace | Home|
    * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
    * |  6  |  7  |  | Tab   |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    | PgUp|
    * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
    * |  4  |  5  |  | Caps    |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | PgDn|
    * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
    * |  2  |  3  |  | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | End |
    * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
    * |  0  |  1  |  | Ctrl  |  GUI |  Alt |   Space   |Space|     | Space         |  Alt  |     | Ctrl  | Left| Down|Right|
    * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
    */
    [0] = LAYOUT(
//--------------------------------Left Hand-----------------------------------| |--------------------------------Right Hand------------------------------------------------
                KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   KC_PSCR,  KC_INS,  KC_DEL,
SCAD_TRANS,  SCAD_ROT,    KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,           TD(NO_HOME),
KC_6,  KC_7,    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_PGUP,
KC_4,  KC_5,    KC_LCTL,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                 KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENTER,                    KC_PGDN,
KC_2,  KC_3,    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,                     KC_RSFT,  KC_UP,   TD(NO_END),
KC_0,  KC_1,    KC_LCTL,  KC_LGUI, KC_LALT, MT(MOD_LGUI, KC_SPC), TD(F13_LAYER),                       KC_SPC,         KC_RALT, MO(1), KC_RCTL,               KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

    [1] = LAYOUT(
                _______,  _______, _______, _______,_______,_______,_______,              _______,_______, _______,_______, _______,  _______,  _______,  _______, _______,
RESET, _______, _______,  _______, _______, _______,_______,_______,_______,              _______,_______, _______,_______, _______,  _______,  _______,           _______,
RGB_TOG,RGB_MOD,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______, _______,  _______,  _______,           _______,
RGB_SAI,RGB_SAD,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______, _______,  RESET,                     _______,
RGB_HUI,RGB_HUD,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______,                     _______,  _______, _______,
RGB_VAI,RGB_VAD,_______,  _______, _______,         _______,  _______,                    _______,               _______,_______,_______,       _______,  _______,  _______
      ),

    [2] = LAYOUT(
                _______,  _______, _______, _______,_______,_______,_______,              _______,_______, _______,_______, _______,  _______,  _______,  _______, _______,
_______,_______,_______,  _______, _______, _______,_______,_______,_______,              _______,_______, _______,_______, _______,  _______,  _______,           _______,
_______,_______,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______, _______,  _______,  _______,           _______,
_______,_______,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______, _______,  _______,                     _______,
_______,_______,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______,                     _______,  _______, _______,
_______,_______,_______,  _______, _______,         _______,  TD(F13_LAYER),                    _______,               _______,_______,_______,       _______,  _______,  _______
      ),

    [3] = LAYOUT(
                _______,  _______, _______, _______,_______,_______,_______,              _______,_______, _______,_______, _______,  _______,  _______,  _______, _______,
_______,_______,_______,  _______, _______, _______,_______,_______,_______,              _______,_______, _______,_______, _______,  _______,  _______,           _______,
_______,_______,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______, _______,  _______,  _______,           _______,
_______,_______,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______, _______,  _______,                     _______,
_______,_______,_______,  _______, _______, _______,_______,_______,              _______,_______,_______, _______,_______,                     _______,  _______, _______,
_______,_______,_______,  _______, _______,         _______,  TD(F13_LAYER),                    _______,               _______,_______,_______,       _______,  _______,  _______
      ),
};

/* Define how much to increment our counter each matrix scan */
uint8_t counter_increment;

/* Let's get the layer_state and set the increment accordingly */
layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(NUMLOCK_LED_PIN);
    switch (get_highest_layer(state)) {
      case 2:
          counter_increment = 1;
          break;
      case 3:
          counter_increment = 2;
          break;
    }
    return state;
}

/* This gets executed on every keypress.
 * It resets the timer or turns the RGB light on */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
            rgb_on = rgblight_is_enabled();
            if (rgb_on) {
                idle_timer = timer_read();
                halfmin_counter = 0;
            } else {
              rgblight_enable_noeeprom();
            }
        #endif
    }

    switch (keycode) {
    case SCAD_TRANS:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("translate([ 0 , 0 , 0 ])");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case SCAD_ROT:
        if (record->event.pressed) {
            SEND_STRING("rotate([ 0 , 0 , 0 ])");
        }
        break;
    }

    return true;
}

void matrix_scan_user(void) {
/* Turn on/off the indicator LED (num lock) according to the active layer;
 * frequency depends on the increment. */
    if (IS_LAYER_OFF(0)) {
        writePinLow(NUMLOCK_LED_PIN);

        static uint8_t counter;
        counter = counter + counter_increment;
        if (counter > 127) {
            writePinHigh(NUMLOCK_LED_PIN);
        }
    }

/* RGB Light timer stuff */
    if (idle_timer == 0) idle_timer = timer_read(); // idle_timer needs to be set one time

    #ifdef RGBLIGHT_ENABLE
        if ( rgb_on && timer_elapsed(idle_timer) > 30000) {
            halfmin_counter++;
            idle_timer = timer_read();
        }

        if ( rgb_on && halfmin_counter >= RGBLIGHT_TIMEOUT * 2) {
            rgblight_disable_noeeprom();
            rgb_on = false;
            halfmin_counter = 0;
        }
    #endif
}

/* Various functions of the encoder */
void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(0)) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    } else if (IS_LAYER_ON(2)) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (IS_LAYER_ON(3)) {
        if (clockwise) {
          tap_code16(S(C(KC_TAB)));
        } else {
          tap_code16(C(KC_TAB));
        }
    }
}

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 */

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else return 0; /* returning 0 makes the key to work only on single tap and on hold, no repeat.
    a higher number than count defined above (2) makes it work on double and more taps.*/
}

// Create an instances of 'tap' for our tap dances.
static tap nohome_tap_state;
static tap noend_tap_state;
static tap f13layer_tap_state;

/* Full descriptive way of defining tap dances */
void nohome_finished(qk_tap_dance_state_t *state, void *user_data) {
    nohome_tap_state.state = cur_dance(state);
    switch (nohome_tap_state.state) {
        case SINGLE_TAP: break;
        case SINGLE_HOLD: register_code(KC_HOME); break;
    }
}

void nohome_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (nohome_tap_state.state) {
        case SINGLE_TAP: break;
        case SINGLE_HOLD: unregister_code(KC_HOME); break;
    }
    nohome_tap_state.state = 0;
}

/* Alternative way of defining tap dances having simple states config */
void noend_finished(qk_tap_dance_state_t *state, void *user_data) {
    noend_tap_state.state = cur_dance(state);
    if (noend_tap_state.state == SINGLE_HOLD) { // no switch
        register_code(KC_END);
    }
}

void noend_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (noend_tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_END);
    }
    nohome_tap_state.state = 0;
}

void f13layer_finished(qk_tap_dance_state_t *state, void *user_data) {
    f13layer_tap_state.state = cur_dance(state);
    switch (f13layer_tap_state.state) {
        case SINGLE_TAP:
            if (layer_state_is(0)) {
              layer_move(2);
            } else if (layer_state_is(2)) {
              layer_move(3);
            } else if (layer_state_is(3)) {
              layer_move(0);
            }
            break;
        case SINGLE_HOLD: tap_code(KC_F13); break;
    }
}

void f13layer_reset(qk_tap_dance_state_t *state, void *user_data) {
/* Since 'tap_code()' was used there is no need to unregister_code */
    /* switch (noend_tap_state.state) { 
         case SINGLE_TAP: break;
         case SINGLE_HOLD: unregister_code(KC_F13); break;
     } */
    nohome_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [NO_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nohome_finished, nohome_reset),
    [NO_END] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, noend_finished, noend_reset),
    [F13_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f13layer_finished, f13layer_reset)
};
