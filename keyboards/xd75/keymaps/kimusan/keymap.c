#include "xd75.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_nordic.h"
#include "action_util.h"
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN0 1
#define _FN1 2
#define _SPECIAL 3
#define _COLEMAK 4
#define _DVORAK 5
#define _LOWER 6
#define _RAISE 7
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN0,
  FN1,
  SPECIAL,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO



enum {
  TD_A_AA = 0,
  TD_E_AE = 1,
  TD_O_OE = 2
};


// Custom
#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
// #define MEH_GRV MEH_T(KC_GRV)  // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define A_AA  TD(TD_A_AA)
#define E_AE TD(TD_E_AE)
#define O_OE TD(TD_O_OE)
#define MO_FN0 MO(1)
#define MO_FN1 MO(2)
#define MO_SPECIAL  MO(3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------------------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |   -  |  ]   |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   {  |   =  |  }   |   Y  |   U  |   I  |   O  |   P  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | capsl|   A  |   S  |   D  |   F  |   G  |   (  |   :  |  )   |   H  |   J  |   K  |   L  |   *  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | Home |  Up  | End  |   N  |   M  |   ,  |   .  |   -  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Fn0  | Alt  | GUI  |Lower |Space | Left | Down |Right |Space |Space |AltGr | Fn1  |Extra |RCtrl |
 * `--------------------------------------------------------------------------------------------------------'
 */

[_QWERTY] = {
	{KC_ESC,    KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_LBRC, KC_MINS,   KC_RBRC,    KC_6,   KC_7,   KC_8,       KC_9,   KC_0,    	KC_BSPC},
    {KC_TAB,    KC_Q,       KC_W,   E_AE,   KC_R,   KC_T,   KC_LCBR, KC_EQL,    KC_RCBR,    KC_Y,   KC_U,   KC_I,       O_OE,   KC_P,    	KC_INS}, 
	{KC_CAPS,   A_AA,       KC_S,   KC_D,   KC_F,   KC_G,   KC_LPRN, KC_SCLN,   KC_RPRN,    KC_H,   KC_J,   KC_K,       KC_L,   KC_QUOT, 	KC_ENT}, 
	{KC_LSFT,   KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_HOME, KC_UP,     KC_END,     KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_MINS, 	KC_RSFT}, 
	{KC_LCTL,   KC_LGUI, KC_LALT,   MO_FN0, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN,   KC_RGHT,    KC_SPC, KC_SPC, KC_RALT,    MO_FN1, MO_SPECIAL, KC_RCTL}
},

/* Fn0
 * ,--------------------------------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |      |      |      |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  up  |      |      |      |      |      |      |      |      |      |      |      |      | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | left | down | right|      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | Home |  Up  | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |      |      |      |      |      |      | Left | Down | Right|
 * `--------------------------------------------------------------------------------------------------------'
 */
[_FN0] = {
	{KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL}, 
	{KC_TAB,  _______, KC_UP,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS}, 
	{_______,KC_LEFT, KC_DOWN, KC_RIGHT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT}, 
	{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______ }, 
	{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Fn0
 * ,--------------------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  NUM |  /   |  *   |  F7  |  F8  |  F9  | F10  | F11  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  up  |      |      |      |      |  7   |  8   |  9   |      |      |      |      |      | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | left | down  right |      |      |      |  4   |  5   |  6   |      |      |      |      |  ~#  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  1   |  2   |  3   |Enter |      |      |      |  ?/  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |  0   | Del  |  .   |Enter |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_FN1] = {
	{KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_PSLS, KC_PAST, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12}, 
	{KC_TAB , _______, KC_UP,  _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, KC_INS}, 
	{_______, KC_LEFT,  KC_DOWN, KC_RIGHT, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, KC_NUHS, KC_ENT}, 
	{_______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, KC_SLSH, _______}, 
	{_______, _______, _______, _______, _______, _______, KC_P0,   KC_DEL,  KC_PDOT, KC_PENT, _______, _______, _______, _______, _______}
},

/* Special TODO: add Media and light control
 * ,--------------------------------------------------------------------------------------------------------.
 * | RESET|      |      |      |      |      |prev  | play | next |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | vup  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | vdown|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | mute |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_SPECIAL] = {
	{RESET,   _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______}, 
	{_______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______}, 
	{_______, _______, _______, _______, _______, _______, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______}, 
	{_______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______}, 
	{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},	
/* Colemak
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |      |      |      |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |      |      |      |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |      |      |      |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |      |      | Bksp |Raise | GUI  |AltGr | Ctrl |Adjust|
 * `--------------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { HPR_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC },
  { CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______, _______, _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT },
  { SFT_BSP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT },
  { ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  _______, _______, _______, SFT_BSP, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, ADJUST  },
},

/* Dvorak
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |      |      |      |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |      |      |      |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |      |      |      |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |      |      | Bksp |Raise | GUI  |AltGr | Ctrl |Adjust|
 * `--------------------------------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },  
  { HPR_TAB, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______, _______, _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC },
  { CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______, _______, _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH },
  { SFT_BSP, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    _______, _______, _______, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SFT_ENT },
  { ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  _______, _______, _______, SFT_BSP, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, ADJUST  },
},

/* Lower
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |      |      |   ^  |   &  |   *  |   (,  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 | MS L | MS D |MS U  | MS R |MS Btn|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
  */
[_LOWER] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC },
  { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1 },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY },
},

/* Raise
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 | Left | Down |  Up  | Rght |MS_BN2|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN2 },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY },
},

/* Adjust (Lower + Raise)
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset |      |Aud on|Audoff|AGnorm|      |      |      |AGswap|Qwerty|Colemk|Dvorak|Reset | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, RESET,   _______, AU_ON,   AU_OFF,  AG_NORM, _______, _______, _______, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  RESET,   KC_DEL  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
},
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(){
    set_unicode_input_mode(UC_LNX);
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for a, twice for å (Nordic APOS)
  [TD_A_AA]  = ACTION_TAP_DANCE_DOUBLE(KC_A, /*UC(0x00e5)*/KC_X),
  //Tap once for e, twice for æ (Nordic AE)
  [TD_E_AE]  = ACTION_TAP_DANCE_DOUBLE(KC_E, UC(0x00e6)),
  //Tap once for o, twice for ø (Nordic OSLH)
  [TD_O_OE]  = ACTION_TAP_DANCE_DOUBLE(KC_O, UC(0x00f8))
  
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
/*    case FN0:
      if (record->event.pressed) {
        layer_on(_FN0);
        update_tri_layer(_FN0, _FN1, _ADJUST);
      } else {
        layer_off(_FN0);
        update_tri_layer(_FN0, _FN1, _ADJUST);
      }
      return false;
      break;
    case FN1:
      if (record->event.pressed) {
        layer_on(_FN1);
        update_tri_layer(_FN0, _FN1, _ADJUST);
      } else {
        layer_off(_FN1);
        update_tri_layer(_FN0, _FN1, _ADJUST);
      }
      return false;
      break;
    case SPECIAL:
      if (record->event.pressed) {
        layer_on(_SPECIAL);
      } else {
        layer_off(_SPECIAL);
      }
      return false;
      break;
*/
	  case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
