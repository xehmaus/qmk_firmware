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

enum planck_layers { _QWERTY, _COLEMAK, _LOWER, _RAISE, _SYMBL, _FNCTN, _PLOVER, _ADJUST, _GRSYM
	};

enum planck_keycodes { QWERTY = SAFE_RANGE,BACKLIT, COLEMAK, PLOVER, EXT_PLV, 
    GR_LALP, GR_LBET, GR_LGAM, GR_LDEL, GR_LEPS, GR_LZET, GR_LETA, GR_LTHE, GR_LIOT, GR_LKAP, 
	GR_LLAM, GR_LMU,  GR_LNU,  GR_LXI,  GR_LOMC, GR_LPI,  GR_LRHO, GR_LSIG, GR_LTAU, GR_LUPS,
	GR_LPHI, GR_LCHI, GR_LPSI, GR_LOMG
};


//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)
#define LOWER LT(_LOWER, KC_ENT)
#define SYMBL LT(_SYMBL, KC_SPC)
#define RAISE LT(_RAISE, KC_BSPC)
#define GRSYM LT(_GRSYM, KC_TAB)
#define FNCTN MO(_FNCTN)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | Del  | Bksp |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | Tab  | Enter|   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | Esc  | FNCTN|   N  |   M  |   ,  |   .  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Gui  |Lower | Space| Tab  | Del  | Shift|Raise | Gui  | Ctrl | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,  KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  FNCTN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, 
    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SYMBL,   GRSYM,   KC_DEL,  KC_LSFT, RAISE,   KC_LGUI, KC_LCTL, KC_LALT 
),

/* COLEMAK-DH
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  | Del  | Bksp |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  | Tab  | Enter|   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  | Esc  | FNCTN|   K  |   H  |   ,  |   .  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Gui  |Lower | Space| Tab  | Del  | Shift|Raise | Gui  | Ctrl | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_DEL,  KC_BSPC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, 
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_TAB,  KC_ENT,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_ESC,  FNCTN,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_QUOT, 
    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SYMBL,   GRSYM,   KC_DEL,  KC_LSFT, RAISE,   KC_LGUI, KC_LCTL, KC_LALT 
),

/* Lower/Nav
 * ,-----------------------------------------------------------------------------------.
 * | Del  |  Ins |  Up  | PG UP|      |      |      |Vol Up|  MS1 | MSUP | MS2  | MSWU |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Home | Left | Down | Rght | End  |      |      |Vol Dn|  MSLF| MSDN | MSRT | MSWD |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Web BK|Web FD| PG DN|      |      |      | Mute |  MSWL|      | MSWR |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_DEL,  KC_INS,  KC_UP,   KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, 
    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_TRNS, KC_TRNS, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, 
    KC_TRNS, KC_WBAK, KC_WFWD, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_WH_L, KC_TRNS, KC_WH_R, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  #   |  @   |   %  |   ^  |   $  |      |      |   =  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  <   |  {   |   [  |   (  |   /  |      |   /  |   .  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  >   |  }   |   ]  |   )  |   \  |      |      |   0  |   1  |   2  |   3  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
	KC_HASH, KC_AT,   KC_PERC, KC_CIRC, KC_DLR,  KC_TRNS, KC_TRNS, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_MINS, 
    KC_LT,   KC_LCBR, KC_LBRC, KC_LPRN, KC_SLSH, KC_TRNS, KC_SLSH, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_PLUS, 
    KC_GT,   KC_RCBR, KC_RBRC, KC_RPRN, KC_BSLS, KC_TRNS, KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_ASTR, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Symbol Layer
 * ,-----------------------------------------------------------------------------------.
 * |  #   |  @   |   %  |   ^  |   $  |      |      |   =  |   &  |   `  |   ~  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  <   |  {   |   [  |   (  |   /  |      |      |   |  |   _  |   ?  |   !  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  >   |  }   |   ]  |   )  |   \  |      |      | ALPHA|      |      |      |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBL] = LAYOUT_planck_grid(
	KC_HASH, KC_AT,   KC_PERC, KC_CIRC, KC_DLR,  KC_TRNS, KC_TRNS, KC_EQL,  KC_AMPR, KC_GRV,  KC_TILD, KC_MINS, 
    KC_LT,   KC_LCBR, KC_LBRC, KC_LPRN, KC_SLSH, KC_TRNS, KC_TRNS, KC_PIPE, KC_UNDS, KC_QUES, KC_EXLM, KC_PLUS, 
    KC_GT,   KC_RCBR, KC_RBRC, KC_RPRN, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
),

/* Function Layer
 * ,-----------------------------------------------------------------------------------.
 * |  Del |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  | F2   |  F3  |  F4  | F5   |  F6  |  F7  | F8   | F9   |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FNCTN] = LAYOUT_planck_grid(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______,  PLOVER,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
)

};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
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
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
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

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307	

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}