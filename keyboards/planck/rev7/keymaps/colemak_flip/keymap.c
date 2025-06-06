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
// 2/22/25 Setting up to match "C:\Users\jhsch\Documents\Development\zmk-urchin\Urchin Layouts.xlsx"
#include QMK_KEYBOARD_H

enum planck_layers { _DEFAULT, _FLIP, _NAV, _NUM, _FUN, _SYM, _SET };

enum planck_keycodes { PLOVER = SAFE_RANGE, BACKLIT, EXT_PLV };

enum combos {
  ARS_CTL,
  RST_SFT,
  ART_ALT,
  //ZXCD_GU,
  WF_ESC,
  FP_TAB,
  XC_BSPC,
  CD_GUI,
  RSG_CW,
  RFT_NAV,
  WSP_FUN
};

#define FLIP LT(_FLIP, KC_SPC)
#define NAV  LT(_NAV, KC_ENT)
#define SYM  LT(_SYM, KC_Q)
#define SYM2  LT(_SYM, KC_BSPC)
#define NUM  LT(_NUM, KC_Z)
#define FUN  LT(_FUN, KC_DEL)


/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = LAYOUT_planck_grid(
    SYM,     KC_W,    KC_F,    KC_P,    KC_B,    KC_NO,   KC_NO,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, 
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_NO,   KC_NO,   KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    
    NUM,     KC_X,    KC_C,    KC_D,    KC_V,    KC_NO,   KC_NO,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_QUOT, 
    MO(_SYM),KC_NO,   KC_NO,   NAV,     FLIP,    MO(_FUN),MO(_NAV),SYM2,    FUN,     KC_NO,   KC_NO,   _SET
),

[_FLIP] = LAYOUT_planck_grid(
    KC_SCLN, KC_Y,    KC_U,    KC_L,    KC_J,    _______, _______, _______, _______, _______, _______, _______, 
    KC_O,    KC_I,    KC_E,    KC_N,    KC_M,    _______, _______, _______, _______, _______, _______, _______, 
    KC_QUOT, KC_DOT,  KC_COMM, KC_H,    KC_K,    _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
),

[_NAV] = LAYOUT_planck_grid(
    LCTL(KC_W), KC_ENT,  KC_UP,   KC_PGUP, KC_TAB,  _______, _______, _______, _______, _______, _______, _______, 
    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______, _______, _______, _______, _______, _______, 
    KC_LCTL, KC_BSPC, KC_DEL,  KC_PGDN, KC_INS,  _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, KC_LALT, LSFT_T(KC_SPC),   _______, _______, _______, _______, _______, _______, _______  
),

[_NUM] = LAYOUT_planck_grid(
    _______, KC_9,    KC_8,    KC_7,    KC_PLUS, _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_6,    KC_5,    KC_4,    KC_DOT,  _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_3,    KC_2,    KC_1,    KC_0,    _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, KC_ENT,  LSFT_T(KC_EQL),   _______, _______, _______, _______, _______, _______, _______  
),

[_FUN] = LAYOUT_planck_grid(
    _______, KC_F9,   KC_F8,   KC_F7,   KC_F12,  _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_F6,   KC_F5,   KC_F4,   KC_F11,  _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_F3,   KC_F2,   KC_F1,   KC_F10,  _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
),

[_SYM] = LAYOUT_planck_grid(
    _______, KC_GRV,  KC_TILD, KC_QUES, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_LBRC, KC_RBRC, KC_SLSH, KC_UNDS, _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_BSPC, KC_DEL,  KC_BSLS, KC_MINS, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______, _______  
),

[_SET] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, 
    _______, _______, _______, _______, _______, _______, MU_NEXT, AU_ON,   AU_OFF,  _______, UG_SPDU, UG_SPDD, 
    _______, _______, _______, _______, _______, _______, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, 
    QK_BOOT, DB_TOGG, EE_CLR,  _______, _______, _______, _______, _______, _______, _______, _______, _______  
)

};

const uint16_t PROGMEM ars_combo[] = {KC_A, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM rst_combo[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM art_combo[] = {KC_A, KC_R, KC_T, COMBO_END};
//const uint16_t PROGMEM zxcd_combo[] = {KC_Z, KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM rsg_combo[] = {KC_R, KC_S, KC_G, COMBO_END};
const uint16_t PROGMEM rft_combo[] = {KC_R, KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM wsp_combo[] = {KC_W, KC_S, KC_P, COMBO_END};

combo_t key_combos[] = {
  [ARS_CTL] = COMBO(ars_combo, OSM(MOD_LCTL)),
  [RST_SFT] = COMBO(rst_combo, OSM(MOD_LSFT)),
  [ART_ALT] = COMBO(art_combo, OSM(MOD_LALT)),
//  [ZXCD_GU] = COMBO(zxcd_combo, OSM(MOD_LGUI)),
  [WF_ESC] = COMBO(wf_combo, KC_ESC),
  [FP_TAB] = COMBO(fp_combo, KC_TAB),
  [XC_BSPC] = COMBO(xc_combo, KC_BSPC),
  [CD_GUI] = COMBO(cd_combo, OSM(MOD_LGUI)),
  [RSG_CW] = COMBO(rsg_combo, CW_TOGG),
  [RFT_NAV] = COMBO(rft_combo, TG(_NAV)),
  [WSP_FUN] = COMBO(wsp_combo, OSL(_FUN))
};