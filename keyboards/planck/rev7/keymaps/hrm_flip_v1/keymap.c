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

enum planck_layers { _COLEMAK, _NAVLR, _NUMLR, _SYMBL, _FNCTN, _GRSYM, _MIROR
	};

enum planck_keycodes { COLEMAK = SAFE_RANGE, BACKLIT, 
    GR_LALP, GR_LBET, GR_LGAM, GR_LDEL, GR_LEPS, GR_LZET, GR_LETA, GR_LTHE, GR_LIOT, GR_LKAP, 
	GR_LLAM, GR_LMU,  GR_LNU,  GR_LXI,  GR_LOMC, GR_LPI,  GR_LRHO, GR_LSIG, GR_LTAU, GR_LUPS,
	GR_LPHI, GR_LCHI, GR_LPSI, GR_LOMG
};

#define NAVLR LT(_NAVLR, KC_ENT)
#define NUMLR LT(_NUMLR, KC_SPC)
#define SYMBL LT(_SYMBL, KC_BSPC)
#define MIROR LT(_MIROR, KC_TAB)
#define GRSYM LT(_GRSYM, KC_BSPC) 
#define FNCTN LT(_FNCTN, KC_SCLN) 


// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |      |      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |      |      |   K  |   H  |   ,  |   .  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | MIROR| NUM  |      |      | NAV  | SYM  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_TRNS, KC_TRNS, KC_J,    KC_L,    KC_U,    KC_Y,    FNCTN,   
    HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,    KC_TRNS, KC_TRNS, KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,    
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_TRNS, KC_TRNS, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_QUOT, 
    KC_TRNS, KC_TRNS, KC_TRNS, MIROR,   NUMLR,   KC_TRNS, KC_TRNS, NAVLR,   SYMBL,   KC_TRNS, KC_TRNS, KC_TRNS  
),

/* Nav Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |  MS2 | MSUP | MS1  | MSWU |      |      | INS  | Pg Up|  Up  | CAPS | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  MSLF| MSDN | MSRT | MSWD |      |      | Home | Left | Down | Rght | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  MSWL|      | MSWR |      |      |      |      | Pg Dn|Web BK|Web FD| Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVLR] = LAYOUT_planck_grid(
    KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_TRNS, KC_TRNS, KC_INS,  KC_PGUP, KC_UP,   KC_CAPS, KC_DEL,   
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,   
    KC_TRNS, KC_WH_L, KC_TRNS, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_WBAK, KC_WFWD, KC_ESC,     
    KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Numpad Layer
 * ,-----------------------------------------------------------------------------------.
 * |   -  |   7  |   8  |   9  |   0  |      |      |      | F1   |  F2  |  F3  | F4   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   +  |   4  |   5  |   6  |   .  |      |      |      | F5   |  F6  |  F7  | F8   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   *  |   1  |   2  |   3  |   =  |      |      |      | F9   |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | del  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMLR] = LAYOUT_planck_grid(
	KC_MINS, KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4, 
    KC_PLUS, KC_4,    KC_5,    KC_6,    KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8, 
    KC_ASTR, KC_1,    KC_2,    KC_3,    KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Symbol Layer
 * ,-----------------------------------------------------------------------------------.
 * |  -   |   &  |   *  |   (  |   )  |      |      |      |      |  ?   |   ~  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  +   |   $  |   %  |   ^  |   _  |      |      |   |  |   /  |  (   |  [   |  {   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  *   |   !  |   @  |   #  |   =  |      |      |      |   \  |  )   |  ]   |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |             |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBL] = LAYOUT_planck_grid(
	KC_MINS, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUES, KC_TILD, KC_GRV,  
    KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_UNDS, KC_TRNS, KC_TRNS, KC_PIPE, KC_SLSH, KC_LPRN, KC_LBRC, KC_LCBR, 
    KC_ASTR, KC_EXLM, KC_AT,   KC_HASH, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Function Layer                     
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | eerst|cole  |      |      |Vol Up|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | HUE+ | SAT+ |BRGTH+| RGB  |      |      |      |Vol Dn|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | HUE- | SAT- |BRGTH-|RGBMD |      |      |      | Mute |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FNCTN] = LAYOUT_planck_grid(
    KC_TRNS, QK_BOOT, DB_TOGG, EE_CLR,  COLEMAK, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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

/* COLEMAK-DH
 * ,-----------------------------------------------------------------------------------.
 * |   ;  |   Y  |   U  |   L  |   J  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   O  |   I  |   E  |   N  |   M  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   '  |   .  |   ,  |   H  |   K  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MIROR] = LAYOUT_planck_grid(
    KC_SCLN, KC_Y,    KC_U,    KC_L,    KC_J,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
    KC_O,    KC_I,    KC_E,    KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    
    KC_QUOT, KC_DOT,  KC_COMM, KC_H,    KC_K,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS   
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
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

