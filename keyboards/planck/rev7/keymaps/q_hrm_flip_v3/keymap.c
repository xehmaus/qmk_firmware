/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _NAVLR, _NUMLR, _SYMBL, _FNCTN, _GRSYM, _MIROR
	};

enum planck_keycodes { QWERTY = SAFE_RANGE, BACKLIT, 
    GR_LALP, GR_LBET, GR_LGAM, GR_LDEL, GR_LEPS, GR_LZET, GR_LETA, GR_LTHE, GR_LIOT, GR_LKAP, 
	GR_LLAM, GR_LMU,  GR_LNU,  GR_LXI,  GR_LOMC, GR_LPI,  GR_LRHO, GR_LSIG, GR_LTAU, GR_LUPS,
	GR_LPHI, GR_LCHI, GR_LPSI, GR_LOMG
};

#define NAVLR LT(_NAVLR, KC_ENT)
#define NUMLR LT(_NUMLR, KC_SPC)
#define SYMBL LT(_SYMBL, KC_BSPC)
#define MIROR LT(_MIROR, KC_TAB)
#define GRSYM LT(_GRSYM, KC_BSPC) 
#define FNCTN LT(_FNCTN, KC_Z) 


// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | MIROR| NUM  |      |      | NAV  | SYM  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS, KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_TRNS, KC_TRNS, KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,     
    FNCTN,   KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS, KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, 
    KC_TRNS, KC_TRNS, KC_TRNS, MIROR,   NUMLR,   KC_TRNS, KC_TRNS, NAVLR,   SYMBL,   KC_TRNS, KC_TRNS, KC_TRNS  
),

/* Nav Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |  MS2 | MSUP | MS1  | MSWU |      |      | caps | Pg Up|  Up  | Ins  | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  MSLF| MSDN | MSRT | MS3  |      |      | Home | Left | Down | Rght | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  MSWL| MSWR |      | MSWD |      |      | nmlk | Pg Dn| bksp | del  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVLR] = LAYOUT_planck_grid(
    KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_TRNS, KC_TRNS, KC_CAPS, KC_PGUP, KC_UP,   KC_INS,  KC_ESC,   
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,   
    KC_TRNS, KC_WH_L, KC_WH_R, KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS, KC_NUM,  KC_PGDN, KC_BSPC, KC_DEL,  KC_TRNS,     
    KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Numpad Layer
 * ,-----------------------------------------------------------------------------------.
 * |   *  |   -  |   +  |   =  |   .  |      |      |      | F11  |  F12 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   4  |   3  |   2  |   1  |   0  |      |      |  F10 | F1   |  F2  |  F3  | F4   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   9  |   8  |   7  |   6  |   5  |      |      |  F5  | F6   |  F7  |  F8  | F9   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMLR] = LAYOUT_planck_grid(
	KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
    KC_4,    KC_3,    KC_2,    KC_1,    KC_0,    KC_TRNS, KC_TRNS, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F4, 
    KC_9,    KC_8,    KC_7,    KC_6,    KC_5,    KC_TRNS, KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Symbol Layer
 * ,-----------------------------------------------------------------------------------.
 * |   *  |   -  |   +  |   =  |   .  |      |      |      |   |  |  ?   |   ~  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   $  |   #  |   @  |   !  |   )  |      |      |   _  |   /  |  (   |  [   |  {   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   (  |   *  |   &  |   ^  |   %  |      |      |      |   \  |  )   |  ]   |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |             |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBL] = LAYOUT_planck_grid(
	KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_QUES, KC_TILD, KC_GRV,  
    KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_RPRN, KC_TRNS, KC_TRNS, KC_UNDS, KC_SLSH, KC_LPRN, KC_LBRC, KC_LCBR, 
    KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Function Layer                     
 * ,-----------------------------------------------------------------------------------.
 * |  esc |  ins |      |      |      |      |      |Vol Up| qwer |eerst | debug| reset|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Vol Dn| rgb  | brt+ | sat+ | hue+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | bksp | del  |      |      |      |      | Mute |rgbmd | brt- | sat- |  hue-|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ent |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FNCTN] = LAYOUT_planck_grid(
    KC_ESC,  KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, QWERTY,  EE_CLR,  DB_TOGG, QK_BOOT, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, RGB_TOG, RGB_VAI, RGB_SAI, RGB_HUI, 
    KC_TRNS, KC_BSPC, KC_DEL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, RGB_MOD, RGB_VAD, RGB_SAD, RGB_HUD, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* GREEK SYMBOLS
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |      |      |      |   L  |   U  |   Y  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |      |      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |      |      |      |   K  |   H  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GRSYM] = LAYOUT_planck_grid(
    GR_LTHE, GR_LOMG, GR_LPHI, GR_LPSI, GR_LBET, KC_TRNS, KC_TRNS, KC_TRNS, GR_LLAM, GR_LUPS, GR_LUPS, KC_TRNS, 
    GR_LALP, GR_LRHO, GR_LSIG, GR_LTAU, GR_LGAM, KC_TRNS, KC_TRNS, GR_LMU,  GR_LNU,  GR_LEPS, GR_LIOT, GR_LOMC, 
    GR_LZET, GR_LXI,  GR_LCHI, GR_LDEL, KC_TRNS, KC_TRNS, KC_TRNS, GR_LKAP, GR_LETA, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* MIROR
 * ,-----------------------------------------------------------------------------------.
 * |   ;  |   Y  |   U  |   L  |   J  |      |      |  +   |  7   |  8   |  9   |  0   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   O  |   I  |   E  |   N  |   M  |      |      |  -   |  4   |  5   |  6   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   '  |   .  |   ,  |   H  |   K  |      |      |  =   |  1   |  2   |  3   |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | ENT  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MIROR] = LAYOUT_planck_grid(
    KC_SCLN, KC_Y,    KC_U,    KC_L,    KC_J,    KC_TRNS, KC_TRNS, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_P0,    
    KC_O,    KC_I,    KC_E,    KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PSLS,    
    KC_QUOT, KC_DOT,  KC_COMM, KC_H,    KC_K,    KC_TRNS, KC_TRNS, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PAST,  
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS   
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case GR_LALP:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("alpha");
            }
            return false;
        case GR_LBET:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("beta");
            }
            return false;
        case GR_LGAM:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("gamma");
            }
            return false;
        case GR_LDEL:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("delta");
            }
            return false;
        case GR_LEPS:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("epsilon");
            }
            return false;
        case GR_LZET:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("zeta");
            }
            return false;
        case GR_LETA:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("eta");
            }
            return false;
        case GR_LTHE:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("theta");
            }
            return false;
        case GR_LIOT:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("iota");
            }
            return false;
        case GR_LKAP:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("kappa");
            }
            return false;
        case GR_LLAM:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("lambda");
            }
            return false;
        case GR_LMU:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("mu");
            }
            return false;
        case GR_LNU:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("nu");
            }
            return false;
        case GR_LXI:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("xi");
            }
            return false;
        case GR_LOMC:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("omicron");
            }
            return false;
        case GR_LPI:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("pi");
            }
            return false;
        case GR_LRHO:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("rho");
            }
            return false;
        case GR_LSIG:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("sigma");
            }
            return false;
        case GR_LTAU:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("tau");
            }
            return false;
        case GR_LUPS:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("upsilon");
            }
            return false;
        case GR_LPHI:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("phi");
            }
            return false;
        case GR_LCHI:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("chi");
            }
            return false;
        case GR_LPSI:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("psi");
            }
            return false;
        case GR_LOMG:  // Types Greek Letter
            if (record->event.pressed) {
                SEND_STRING("omega");
            }
            return false;
    }
    return true;
}

