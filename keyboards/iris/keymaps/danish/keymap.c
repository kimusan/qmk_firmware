#include "iris.h"
#include "keymap_nordic.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _EMPTY 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET

#define KC_AA NO_AM
#define KC_AE NO_AE
#define KC_OE NO_OSLH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                     ,-------+-------+-------+-------+-------+-------.
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                      KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                      KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  , KC_AA ,
  //|-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                      KC_H   , KC_J  , KC_K  , KC_L  , KC_AE , KC_OE ,
  //|-------+-------+-------+-------+-------+-------+---------  ,---------|-------+-------+-------+-------+-------+-------|
     KC_LCTL , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_HOME,     KC_END , KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,RSFT_T(KC_ENT),
  //`-------+-------+-------+-----+-+-------+-------+-------/     \-------+-------+-------+-------+-------+-------+-------'
                             ALT_T(KC_LGUI),KC_LOWR,KC_SPC ,       KC_ENT ,KC_RASE,KC_RALT
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_LOWER] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     NO_TILD,KC_EXLM,NO_AT  ,KC_HASH,NO_DLR ,KC_PERC,                     NO_CIRC,NO_AMPR,NO_MINS,NO_SLSH,NO_LPRN,NO_PLUS,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     LALT(KC_TAB),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                     KC_TRNS,KC_TRNS,KC_UP,NO_PIPE,NO_PIPE,NO_QUOT,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     KC_TRNS,TERM_ON,TERM_OFF,KC_TRNS,KC_TRNS,NO_BSLS,                     KC_TRNS,KC_LEFT,KC_DOWN  ,KC_RGHT,KC_TRNS, NO_APOS,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     BL_STEP,RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,KC_PGUP,     KC_PGDN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,NO_LESS,KC_RSFT,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                   KC_LGUI,KC_TRNS,KC_TRNS,         KC_TRNS,KC_TRNS,KC_TRNS
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_RAISE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     KC_TRNS ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                     KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     NO_GRV ,KC_F11 ,KC_F12  ,KC_9   ,NO_MINS,NO_MINS,                     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,NO_PIPE,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     KC_TRNS,KC_4   ,KC_5   ,KC_6   ,NO_PLUS,NO_SLSH,                     KC_HOME,KC_PGDN,KC_PGUP,KC_END ,KC_TRNS,NO_APOS,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     KC_NUBS,KC_1   ,KC_2   ,KC_3   ,KC_0   ,NO_EQL ,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                   KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS,KC_TRNS,KC_TRNS
  //                              `-------+-------+-------'        `-------+-------+-------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
  }
  return true;
}
