/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    COLEMAK,
    COLEMAK_FN,
    ALT,
    ALT_FN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)


// Tap Dance declarations
enum { 
  TD_PIPE,
  TD_HOME
 };

void dance_pipe_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_BSLS);
    } else {
        register_code16(KC_PIPE);
        register_code16(KC_RABK);
    }
}

void dance_pipe_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_BSLS);
    } else {
        unregister_code16(KC_PIPE);
        unregister_code16(KC_RABK);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_pipe_finished, dance_pipe_reset),
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAK] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    KC_BRID,  KC_BRIU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,    KC_RBRC,  TD(TD_PIPE),        KC_PGDN,
        KC_LGUI,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,              KC_ENT,             TD(TD_HOME),
        SC_LSPO,            KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,              SC_RSPC,  KC_UP,
        KC_LCTL,  MO(COLEMAK_FN),  KC_RGHT,                                KC_SPC,                                 QK_REP,   MO(COLEMAK_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [COLEMAK_FN] = LAYOUT_ansi_82(
        QK_BOOT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_SLEP,            _______,
        DM_PLY1,  DM_REC1,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RM_TOGG,  RM_NEXT, RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_PREV, RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  KC_UP,  KC_DOWN,  KC_LEFT,  KC_RGHT,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                QK_LLCK,                                KC_SYRQ,  _______,    _______,  _______,  _______,  _______),

    [ALT] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  TD(TD_PIPE),        KC_PGDN,
        KC_LGUI,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             TD(TD_HOME),
        SC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              SC_RSPC,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(ALT_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [ALT_FN] = LAYOUT_ansi_82(
        QK_BOOT,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  KC_BRID,  KC_BRIU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_SLEP,            _______,
        DM_PLY1,  DM_REC1,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RM_TOGG,  RM_NEXT, RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_PREV, RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                QK_LLCK,                                KC_SYRQ,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [COLEMAK_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [ALT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [ALT_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE

#if defined(RGB_MATRIX_ENABLE)
static bool macro_recording = false;

bool dynamic_macro_record_start_user(int8_t direction) {
    macro_recording = true;
    return true;
}

bool dynamic_macro_record_end_user(int8_t direction) {
    macro_recording = false;
    return true;
}

// Set a key's LED to the given colour at the current RGB brightness
static void set_key_hsv(uint8_t index, hsv_t hsv) {
    hsv.v     = rgb_matrix_get_val();
    rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

// Colour for an Fn layer key, grouped by what it does
static hsv_t fn_key_hsv(uint16_t keycode) {
    if (keycode == QK_BOOT) return (hsv_t){HSV_RED};
    if (keycode == QK_LLCK) return (hsv_t){HSV_GREEN};
    if (keycode >= KC_RGHT && keycode <= KC_UP) return (hsv_t){HSV_WHITE};
    if (IS_RGB_MATRIX_KEYCODE(keycode)) return (hsv_t){HSV_MAGENTA};
    if (keycode >= QK_DYNAMIC_MACRO_RECORD_START_1 && keycode <= QK_DYNAMIC_MACRO_PLAY_2) return (hsv_t){HSV_ORANGE};
    return (hsv_t){HSV_AZURE};
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Each base layer's Fn layer directly follows it in the layer enum
    uint8_t base      = get_highest_layer(default_layer_state);
    uint8_t fn        = base + 1;
    bool    fn_active = layer_state_is(fn);
    bool    blink_on  = timer_read() & 0x100;

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index == NO_LED || index < led_min || index >= led_max) continue;

            keypos_t pos     = {.col = col, .row = row};
            uint16_t base_kc = keymap_key_to_keycode(base, pos);
            uint16_t fn_kc   = keymap_key_to_keycode(fn, pos);

            if (macro_recording && fn_kc == DM_REC1) {
                // Blink the record key while a macro is recording
                if (blink_on) {
                    set_key_hsv(index, (hsv_t){HSV_RED});
                } else {
                    rgb_matrix_set_color(index, RGB_OFF);
                }
            } else if (is_caps_word_on() && (base_kc == SC_LSPO || base_kc == SC_RSPC)) {
                set_key_hsv(index, (hsv_t){HSV_WHITE});
            } else if (fn_active) {
                // While Fn is held or locked, only light keys that do something
                if (fn_kc > KC_TRNS) {
                    set_key_hsv(index, fn_key_hsv(fn_kc));
                } else {
                    rgb_matrix_set_color(index, RGB_OFF);
                }
            }
        }
    }
    return false;
}
#endif // RGB_MATRIX_ENABLE