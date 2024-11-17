/*
Copyright 2022 Dimitris Mantzouranis <d3xter93@gmail.com>
Copyright 2022 Pablo Ramirez
Copyright 2023 Santanu Paik (https://github.com/ITNerd69)

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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    DVORAK_MAC_BASE   = 0,
    DM_FN             = 1,
    DVORAK_WIN_BASE   = 2,
    DW_FN             = 3,
    WIN_BASE          = 4,
    WIN_FN            = 5,
    MAC_BASE          = 6,
    MAC_FN            = 7,
};
#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LALT  * LGUI  * SPC                                         * LGUI * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [DVORAK_MAC_BASE] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_MSCR,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_SLSH,    KC_7,       KC_5,       KC_3,       KC_1,       KC_9,       KC_0,       KC_2,       KC_4,       KC_6,       KC_8,       KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_SCLN,    KC_Y,       KC_O,       KC_P,       KC_COMM,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_A,       KC_I,       KC_E,       KC_U,       KC_DOT,     KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_MINS,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                KC_QUOT,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,                   KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                                        KC_SPC,                                         KC_RGUI,    MO(DM_FN),  KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             *      *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [DM_FN] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      QK_BOOT,    KC_BRID,    KC_BRIU,    KC_MSSN,    KC_FIND,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MSNP,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

  /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LGUI  * LALT  * SPC                                         * RALT * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [DVORAK_WIN_BASE] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_SLSH,    KC_7,       KC_5,       KC_3,       KC_1,       KC_9,       KC_0,       KC_2,       KC_4,       KC_6,       KC_8,       KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_SCLN,    KC_Y,       KC_O,       KC_P,       KC_COMM,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_A,       KC_I,       KC_E,       KC_U,       KC_DOT,     KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_MINS,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                KC_QUOT,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,                   KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LGUI,    KC_LALT,                                        KC_SPC,                                         KC_RALT,    MO(DW_FN),  KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             *      *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [DW_FN] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      QK_BOOT,    KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),










  /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LGUI  * LALT  * SPC                                         * RALT * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [WIN_BASE] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LGUI,    KC_LALT,                                        KC_SPC,                                         KC_RALT,    MO(WIN_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             *      *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [WIN_FN] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      QK_BOOT,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

    /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LALT  * LGUI  * SPC                                         * LGUI * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [MAC_BASE] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_MSCR,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                                        KC_SPC,                                         KC_RGUI,    MO(MAC_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             *      *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [MAC_FN] = LAYOUT_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      Q_RESET,      KC_BRID,    KC_BRIU,    KC_MSSN,    KC_FIND,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MSNP,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  )
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case RGB_MOD:
            {
                if (record->event.pressed && ((get_mods() & (MOD_MASK_CTRL | MOD_MASK_SHIFT)) != 0)) {
                  reset_keyboard();
                }
            }
        case KC_BSPC:
            {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
            }

    }
    return true;
};

bool dip_switch_update_user(uint8_t index, bool active) {
  switch(index) {
    case 0: // OS switch
      if (active) { // Mac/iOS mode
        layer_move(DVORAK_MAC_BASE);
      }
      else { // Windows/Android mode
        layer_move(DVORAK_WIN_BASE);
      }
      break;
    case 1: // Connection switch
      // Probably it's not possible to do anything sensible here as switching from Cable to BT requires turning off the board. (BT / OFF / Cable)
      if (active) { // BT mode
        // do stuff
      }
      else { //Cable mode
        // do stuff
      }
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable = true;
  // debug_matrix = true;
  // debug_keyboard = true;
  // debug_mouse = true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        // Current highest layer - returns enum value
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    if (layer == 1) {
                        // RGB_BLUE is a hex triplet macro expanding to 0x00, 0x00, 0xFF
                        rgb_matrix_set_color(index, RGB_BLUE);
                    } else {
                        rgb_matrix_set_color(index, RGB_RED);
                    }
                }
            }
        }
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 255, 255, 255); // assuming caps lock is at led #5
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 0, 0, 0);
    }

    return false;
}
