/* Copyright 2025 Cipulot & ai03 Design Studio
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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
#include "quantum.h"

#define _BASIC 0
#define _SYMBOL 1
#define _MOUSEKEY 2
#define _FN 3
#define _CAPSPLUS 4
#define _WM 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [0] = LAYOUT_60_hhkb(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
        KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(1),
                 KC_LALT, KC_LGUI,                                     KC_SPC,                                      KC_RGUI, KC_RALT
    ),

    [1] = LAYOUT_60_hhkb(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,          _______,
        _______,          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,          _______,
        _______,          _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN,          _______, _______,
                 _______, _______,                                     _______,                                     _______, MO(2)
    ),

    [2] = LAYOUT_60_hhkb(
        QK_BOOT, NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
                 _______, _______,                                     _______,                                     _______, _______
    ),

    [3] = LAYOUT_60_hhkb(
        QK_BOOT, NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
                 _______, _______,                                     _______,                                     _______, _______
    ),

    [4] = LAYOUT_60_hhkb(
        QK_BOOT, NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
                 _______, _______,                                     _______,                                     _______, _______
    ),

    [5] = LAYOUT_60_hhkb(
        QK_BOOT, NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
                 _______, _______,                                     _______,                                     _______, _______
    )
    // clang-format on
};

const rgblight_segment_t PROGMEM layer_basic[]    = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_CORAL}, {1, 1, HSV_GOLDENROD}, {2, 1, HSV_CORAL} /* {3,2, HSV_PINK}, */
                                                                                                                                        /* {5,1, HSV_MAGENTA}, */
                                                                                                                                        /* {6,1, HSV_RED}, */
                                                                                                                                        /* {7,1, HSV_YELLOW}, */
                                                                                                                                        /* {8,1, HSV_CORAL}, */
                                                                                                                                        /* {9,1, HSV_GOLD}, */
                                                                                                                                        /* {10,1, HSV_GOLDENROD}, */
                                                                                                                                        /* {11,1, HSV_ORANGE}, */
                                                                                                                                        /* {12,1, HSV_CORAL} */
);
const rgblight_segment_t PROGMEM layer_symbol[]   = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_SPRINGGREEN}, {1, 1, HSV_ORANGE}, {2, 1, HSV_SPRINGGREEN} /* {4,2, HSV_AZURE}, */
                                                                                                                                                 /* {7,3, HSV_AZURE}, */
                                                                                                                                                 /* {10,1, HSV_CORAL}, */
                                                                                                                                                 /* {11,2, HSV_ORANGE} */
);
const rgblight_segment_t PROGMEM layer_mousekey[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_BLUE}, {1, 1, HSV_RED}, {2, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM layer_fn[]       = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_PINK}, {1, 1, HSV_TURQUOISE}, {2, 1, HSV_PINK});
const rgblight_segment_t PROGMEM layer_capsplus[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_TEAL}, {1, 2, HSV_MAGENTA}, {2, 1, HSV_TEAL});
const rgblight_segment_t PROGMEM layer_wm[]       = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_CHARTREUSE}, {1, 2, HSV_CYAN}, {2, 1, HSV_CHARTREUSE});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(layer_basic, layer_symbol, layer_mousekey, layer_fn, layer_capsplus, layer_wm);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(_BASIC, layer_state_cmp(state, _BASIC));
    rgblight_set_layer_state(_SYMBOL, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(_MOUSEKEY, layer_state_cmp(state, _MOUSEKEY));
    rgblight_set_layer_state(_FN, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(_CAPSPLUS, layer_state_cmp(state, _CAPSPLUS));
    rgblight_set_layer_state(_WM, layer_state_cmp(state, _WM));

    return state;
}
