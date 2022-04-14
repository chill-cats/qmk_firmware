/*
Copyright 2022 Dimitris Mantzouranis <d3xter93@gmail.com>
Copyright 2022 Pablo Ramirez

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
#include "debug.h"
#include "keyboard.h"
#include "print.h"
#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"

#if defined(MODULE_ITON_BT)
#    include "iton_bt.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    BASE_QWERTY,
    FN,
    FN2,
};

enum custom_keycode {
    KC_MSS_CTRL = SAFE_RANGE,
    KC_LNCH_PAD,
    BT_PAIR,
    BT_PRO1,
    BT_PRO2,
    BT_PRO3,
};

// =================== COMBO ===================================
static const uint16_t PROGMEM semiFJCombo[] = {KC_F, KC_J, COMBO_END};
static const uint16_t PROGMEM tabDKCombo[]  = {KC_D, KC_K, COMBO_END};
static const uint16_t PROGMEM escJKCombo[]  = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(semiFJCombo, KC_SEMICOLON),
    COMBO(tabDKCombo, KC_TAB),
    COMBO(escJKCombo, KC_ESC),
};

// ================== COMBO END =================================
// ================== TAP DANCE END =============================

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE_QWERTY] = LAYOUT_75_ansi(
  /*  0           1           2           3             4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,        KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_DEL,     KC_NO      ,
      KC_GRV,     KC_1,       KC_2,       KC_3,         KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP    ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,         KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN    ,
      KC_ESC,     KC_A,       KC_S,       KC_D,         KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,                 KC_HOME    ,
      KC_LSFT,                KC_Z,       KC_X,         KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_UP,      KC_END     ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                                          KC_SPC,                                         KC_RGUI,    MO(FN),     MO(FN2),    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  [FN] = LAYOUT_75_ansi(
  /*  0           1           2           3             4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_MSS_CTRL,  KC_LNCH_PAD,RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     _______    ,
      BT_PAIR,    BT_PRO1,    BT_PRO2,    BT_PRO3,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_VOLD,    KC_VOLU,    _______,                _______    ,
      _______,    _______,    KC_UP,      _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______    ,
      _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______    ,
      _______,                _______,    _______,      _______,    _______,    _______,    _______,    KC_MUTE,    _______,    _______,    _______,                _______,    RGB_SAI,    _______    ,
      _______,    _______,    _______,                                          _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

  [FN2] = LAYOUT_75_ansi(
  /*  0           1           2           3              4           5           6           7           8           9           10          11          12          13          14          15       */
      _______,    _______,    _______,    _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______   ,
      _______,    _______,    _______,    _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______   ,
      _______,    _______,    _______,    _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______   ,
      _______,    _______,    _______,    _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______   ,
      _______,                _______,    _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______   ,
      _______,    _______,    _______,                                           _______,                                        _______,    _______,    _______,    _______,    _______,    _______
  ),
};
// clang-format on

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:            // keymap switch
            if (active) {  // dvorak
            } else {       // qwerty
            }
            break;
        case 1:  // Connection switch
            // Probably it's not possible to do anything sensible here as switching from Cable to BT requires turning off the board. (BT / OFF / Cable)
            if (active) {  // BT mode
                           // do stuff
            } else {       // Cable mode
                // do stuff
            }
            break;
    }
    return true;
}

void keyboard_post_init_user() {
    debug_matrix   = 1;
    debug_keyboard = 1;
    debug_enable   = 1;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MSS_CTRL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0x000);
            }
            return false;
        case KC_LNCH_PAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0x000);
            }
            return false;
        case BT_PAIR:
#ifdef MODULE_ITON_BT
            iton_bt_enter_pairing();
            print("Start pairing!");
#endif
            break;
        case BT_PRO1:
#ifdef MODULE_ITON_BT
            iton_bt_switch_profile(0);
            print("Switch profile 1!");
#endif
            break;
        case BT_PRO2:
#ifdef MODULE_ITON_BT
            iton_bt_switch_profile(1);
            print("Switch profile 2!");
#endif
            break;
        case BT_PRO3:
#ifdef MODULE_ITON_BT
            iton_bt_switch_profile(2);
            print("Switch profile 3!");
#endif
            break;
        default:
            break;
    }
    return true;
}
