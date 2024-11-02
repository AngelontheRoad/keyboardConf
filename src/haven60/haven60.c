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
#define _SYMBOL 1
#define _MOUSEKEY 2
#define _FN 3
#define _CAPSPLUS 4
#define _WM 5

const rgblight_segment_t PROGMEM layer_basic[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_BLACK},
    {1,1, HSV_CHARTREUSE},
    {2,1, HSV_MAGENTA},
    {3,2, HSV_PINK},
    {5,1, HSV_MAGENTA},
    {6,1, HSV_RED},
    {7,1, HSV_YELLOW},
    {8,1, HSV_CORAL},
    {9,1, HSV_GOLD},
    {10,1, HSV_GOLDENROD},
    {11,1, HSV_ORANGE},
    {12,1, HSV_CORAL}
);
const rgblight_segment_t PROGMEM layer_symbol[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_BLACK},
    {1,2, HSV_YELLOW},
    {3,2, HSV_GOLDENROD},
    {4,2, HSV_AZURE},
    {7,3, HSV_AZURE},
    {10,1, HSV_CORAL},
    {11,2, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM layer_mousekey[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_BLACK},
    {1,3, HSV_RED},
    {4,3, HSV_BLUE},
    {7,3, HSV_BLUE},
    {10,3, HSV_RED}
);
const rgblight_segment_t PROGMEM layer_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_BLACK},
    {1,1, HSV_TURQUOISE},
    {2,3, HSV_BLUE},
    {5,2, HSV_TEAL},
    {7,2, HSV_TEAL},
    {9,3, HSV_BLUE},
    {12,1, HSV_TURQUOISE}
);
const rgblight_segment_t PROGMEM layer_capsplus[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_BLACK},
    {1,2, HSV_CYAN},
    {3,2, HSV_YELLOW},
    {5,2, HSV_CHARTREUSE},
    {7,2, HSV_CHARTREUSE},
    {9,2, HSV_YELLOW},
    {11,2, HSV_CYAN}
);
const rgblight_segment_t PROGMEM layer_wm[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_BLACK},
    {1,2, HSV_CHARTREUSE},
    {3,1, HSV_SPRINGGREEN},
    {4,3, HSV_GREEN},
    {7,3, HSV_GREEN},
    {10,1, HSV_SPRINGGREEN},
    {11,2, HSV_CHARTREUSE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_basic,
    layer_symbol,
    layer_mousekey,
    layer_fn,
    layer_capsplus,
    layer_wm
);

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
