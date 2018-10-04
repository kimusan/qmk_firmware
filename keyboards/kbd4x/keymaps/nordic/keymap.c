/* Copyright 2018 sevenseacat
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap_nordic.h"
#define ___ KC_TRNS
#define KC_AA NO_AM
#define KC_AE NO_AE
#define KC_OE NO_OSLH

#define _QUERTY 0
#define _RAISE  1
#define _LOWER  2
#define _FN     3
#define _CODE   4

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KBD4X = SAFE_RANGE,
  RAISE,
  LOWER,
  FN,
  CODE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QUERTY] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,    KC_K,    KC_L,    KC_AE,   KC_OE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENTER,
    KC_LCTL, MO(3), KC_LGUI,   KC_LALT, MO(2),   KC_SPACE,         MO(1),   KC_RALT, KC_AA, MO(4),     KC_RSFT
  ),

  [_RAISE] = LAYOUT_planck_mit(
    KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  NO_PIPE,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,      ___,
    ___,      ___,     ___,     ___,     ___,     ___,        ___,  ___,  ___,  ___,      ___
  ),
  [_FN] = LAYOUT_planck_mit(
    KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, RESET,
    ___,      KC_F11,  KC_F12,  ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,      KC_UP,    ___,
    ___,      ___,     ___,     ___,     ___,     ___,        ___,  ___,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  [_LOWER] = LAYOUT_planck_mit(
    NO_TILD,  KC_EXLM, NO_AT, KC_HASH, NO_DLR, KC_PERC, NO_CIRC, NO_AMPR , NO_MINS, NO_SLSH, KC_0, KC_MINS,
    ___,      ___,     ___, ___, ___, ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___, ___, ___, ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___, ___,     ___,   ___,  ___,  ___,  ___,  ___,  ___
  ),
  [_CODE] = LAYOUT_planck_mit(
    ___,      RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0), RALT(KC_MINS),
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,        ___,  ___,  ___,  ___,  ___
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
