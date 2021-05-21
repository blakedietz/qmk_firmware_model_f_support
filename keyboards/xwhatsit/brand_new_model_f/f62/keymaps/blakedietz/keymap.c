/* Copyright 2020 Purdea Andrei
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _DEV,
    _MOUSE,
    _MEDIA
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
        [_BASE] = LAYOUT_ansi_hhkb_split_shift_regular_backspace( //  default layer
            KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
            ALL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_MEDIA, KC_SCLN), KC_QUOT, ALL_T(KC_ENT),
            KC_LSFT, CTL_T(KC_Z), ALT_T(KC_X), GUI_T(KC_C), KC_V, KC_B, KC_N, KC_M, GUI_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_SLSH), KC_RSFT, TG(_DEV),
            TG(_DEV), TG(_DEV), TG(_MOUSE), LT(_DEV, KC_SPC), TG(_MOUSE), TG(_DEV), TG(_DEV)),

        /* Layer DEV: DEV mode (DEV Fn)
          TODO: Add a cmd/tab function to the developer layer for quick switching between different applications when debugging
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      | F1  | F2  | F3  | F4 | F5 | Left   |  Down          | Up           | Right     |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
                     |------+------+----------------------+------+------+
                     | **** | **** | ******************** | **** | **** |
                     |------+------+----------------------+------+------+
         */

        [_DEV] = LAYOUT_ansi_hhkb_split_shift_regular_backspace(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_DEV),
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

        /* Layer MOUSE: MOUSE mode (MOUSE Fn)
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
                     |------+------+----------------------+------+------+
                     | **** | **** | ******************** | **** | **** |
                     |------+------+----------------------+------+------+
         */

        [_MOUSE] = LAYOUT_ansi_hhkb_split_shift_regular_backspace(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_DEV),
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

        /* Layer MEDIA: mode (Hold Semi-colon)
          |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |    |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |    |                |              |           |             |     |       |       |     |
          |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |    |  Previous      | Next         |           |  Play/Pause |     |       |       |     |
          |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
          |      |     |     |     |    |    |    |  Volume Down   | Volume Up    | Mute      |             |     |       |       |     |
          |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
                     |------+------+----------------------+------+------+
                     | **** | **** | ******************** | **** | **** |
                     |------+------+----------------------+------+------+
         */

        [_MEDIA] = LAYOUT_ansi_hhkb_split_shift_regular_backspace(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, TG(_DEV),
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
