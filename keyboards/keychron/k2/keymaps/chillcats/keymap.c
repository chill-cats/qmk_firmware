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
#include QMK_KEYBOARD_H

#define KC_MSCR LSFT(LGUI(KC_3))  // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))  // Mac snip tool

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    BASE_QWERTY,
    BASE_DVORAK,
    FN,
    FN2,
};

enum mac_keycode {
    KC_MSS_CTRL = SAFE_RANGE,
    KC_LNCH_PAD,
};

enum prog_dvorak_keycode {
    KC_PROG_DVK_1 = SAFE_RANGE + 2,
    KC_PROG_DVK_2,
    KC_PROG_DVK_3,
    KC_PROG_DVK_4,
    KC_PROG_DVK_5,
    KC_PROG_DVK_6,
    KC_PROG_DVK_7,
    KC_PROG_DVK_8,
    KC_PROG_DVK_9,
    KC_PROG_DVK_0,
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
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,        KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_MSCR,    KC_DEL,     KC_NO      ,
      KC_GRV,     KC_1,       KC_2,       KC_3,         KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP    ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,         KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN    ,
      KC_ESC,     KC_A,       KC_S,       KC_D,         KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,                 KC_HOME    ,
      KC_LSFT,                KC_Z,       KC_X,         KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_UP,      KC_END     ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                                          KC_SPC,                                         KC_RGUI,    MO(FN),     MO(FN2),    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  [BASE_DVORAK] = LAYOUT_75_ansi(
  /*  0           1           2           3             4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,        KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_MSCR,    KC_DEL,     KC_NO      ,
      KC_DOLLAR,  KC_AMPR,    KC_LBRC,    KC_LCBR,      KC_RCBR,    KC_LPRN,    KC_EQUAL,   KC_ASTR,    KC_RPRN,    KC_PLUS,    KC_RBRC,    KC_EXCLAIM, KC_HASH,    KC_BSPC,                KC_PGUP    ,
      KC_TAB,     KC_SCLN,    KC_COMMA,   KC_DOT,       KC_P,       KC_Y,       KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_SLASH,   KC_AT,      KC_BSLS,                KC_PGDN    ,
      KC_ESC,     KC_A,       KC_O,       KC_E,         KC_U,       KC_I,       KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_MINS,                KC_ENT,                 KC_HOME    ,
      KC_LSFT,                KC_QUOTE,   KC_Q,         KC_J,       KC_K,       KC_X,       KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,                   KC_RSFT,    KC_UP,      KC_END     ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                                          KC_SPC,                                         KC_RGUI,    MO(FN),     MO(FN2),    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  [FN] = LAYOUT_75_ansi(
  /*  0           1           2           3             4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_MSS_CTRL,  KC_LNCH_PAD,RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MSNP,    KC_INS,     _______    ,
      _______,    _______,    _______,    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_VOLD,    KC_VOLU,    _______,                _______    ,
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

layer_state_t layer_state_set_user(layer_state_t layer_state) { return layer_state; }

layer_state_t default_layer_state_set_user(layer_state_t default_layer_state) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    switch (biton32(default_layer_state)) {
        case BASE_DVORAK:
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;
        case BASE_QWERTY:
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            break;
    }
    return default_layer_state;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:                                       // keymap switch
            if (active) {                             // dvorak
                default_layer_set(1 << BASE_QWERTY);  // default layer is indicated by nth bit in the layer mask
            } else {                                  // qwerty
                default_layer_set(1 << BASE_DVORAK);
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
    }
    return true;
}
