/* Copyright 2023 CMM.S Freather
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

#include "quantum.h"

#define _BASIC 0
#define _ADD 1
#define _MOUSEKEY 2
#define _FN 3
#define _CAPSPLUS 4
#define _CAPSPRO 5

const rgblight_segment_t PROGMEM layer_basic[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_CHARTREUSE},
    {1,3, HSV_PURPLE},
    {4,3, HSV_PINK},
    {7,3, HSV_GOLDENROD},
    {10,3, HSV_GOLD}
);
const rgblight_segment_t PROGMEM layer_add[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,3, HSV_MAGENTA}, // between purple and red
    {3,2, HSV_CORAL},
    {5,2, HSV_YELLOW},
    {7,2, HSV_YELLOW},
    {9,2, HSV_CORAL},
    {11,2, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM layer_mousekey[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,4, HSV_BLUE},
    {4,3, HSV_RED},
    {7,3, HSV_RED},
    {10,3, HSV_BLUE}
);
const rgblight_segment_t PROGMEM layer_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,4, HSV_TURQUOISE},
    {4,3, HSV_SPRINGGREEN},
    {7,3, HSV_SPRINGGREEN},
    {10,3, HSV_TURQUOISE}
);
const rgblight_segment_t PROGMEM layer_capsplus[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,3, HSV_CYAN},
    {3,2, HSV_YELLOW},
    {5,2, HSV_CHARTREUSE},
    {7,2, HSV_CHARTREUSE},
    {9,2, HSV_YELLOW},
    {11,2, HSV_CYAN}
);
const rgblight_segment_t PROGMEM layer_capspro[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,13, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_basic,
    layer_add,
    layer_mousekey,
    layer_fn,
    layer_capsplus,
    layer_capspro
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(_BASIC, layer_state_cmp(state, _BASIC));
    rgblight_set_layer_state(_ADD, layer_state_cmp(state, _ADD));
    rgblight_set_layer_state(_MOUSEKEY, layer_state_cmp(state, _MOUSEKEY));
    rgblight_set_layer_state(_FN, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(_CAPSPLUS, layer_state_cmp(state, _CAPSPLUS));
    rgblight_set_layer_state(_CAPSPRO, layer_state_cmp(state, _CAPSPRO));

    return state;
}
