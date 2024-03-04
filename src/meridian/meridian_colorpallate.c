/*
Copyright 2020 Holten Campbell

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

// Another color pallate
// It seems that cannot convert rgb to hsv in qmk?

#define _BASIC 0
#define _ADD 1
#define _MOUSEKEY 2
#define _FN 3
#define _CAPSPLUS 4
#define _SYMBOL 5
#define _ARROWKEY 6
#define _BACKUP 7

#include "quantum.h"

const rgblight_segment_t PROGMEM layer_basic[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}, {1, 1, HSV_GREEN}, {2, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM layer_add[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ORANGE}, {1, 1, HSV_CORAL}, {2, 1, HSV_ORANGE});
const rgblight_segment_t PROGMEM layer_mousekey[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}, {1, 1, HSV_GOLDENROD}, {2, 1, HSV_GOLD});
const rgblight_segment_t PROGMEM layer_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_SPRINGGREEN}, {1, 1, HSV_GREEN}, {2, 1, HSV_CHARTREUSE});
const rgblight_segment_t PROGMEM layer_capsplus[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_TEAL}, {1, 1, HSV_BLUE}, {2, 1, HSV_CYAN});
const rgblight_segment_t PROGMEM layer_symbol[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_TURQUOISE}, {1, 1, HSV_TEAL}, {2, 1, HSV_AZURE});
const rgblight_segment_t PROGMEM layer_arrowkey[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}, {1, 1, HSV_PURPLE}, {2, 1, HSV_MAGENTA});
const rgblight_segment_t PROGMEM layer_backup[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_AZURE}, {1, 1, HSV_WHITE}, {2, 1, HSV_PINK});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_basic, layer_add, layer_mousekey, layer_fn, layer_capsplus,
    layer_symbol, layer_arrowkey, layer_backup);

void keyboard_post_init_user(void) { rgblight_layers = my_rgb_layers; }

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(_BASIC, layer_state_cmp(state, _BASIC));
    rgblight_set_layer_state(_ADD, layer_state_cmp(state, _ADD));
    rgblight_set_layer_state(_MOUSEKEY, layer_state_cmp(state, _MOUSEKEY));
    rgblight_set_layer_state(_FN, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(_CAPSPLUS, layer_state_cmp(state, _CAPSPLUS));
    rgblight_set_layer_state(_SYMBOL, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(_ARROWKEY, layer_state_cmp(state, _ARROWKEY));
    rgblight_set_layer_state(_BACKUP, layer_state_cmp(state, _BACKUP));

    return state;
}
