// Copyright 2023 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0
#include "quantum.h"
#define _ADD 1
#define _MOUSEKEY 2
#define _FN 3
#define _ARROWKEY 4
#define _CAPSPLUS 5
#define _CAPSPRO 6
#define _BACKUP 7

const rgblight_segment_t PROGMEM layer_add[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_RED}
);
const rgblight_segment_t PROGMEM layer_mousekey[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM layer_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM layer_arrowkey[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_capsplus[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM layer_capspro[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM layer_backup[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_add,
    layer_mousekey,
    layer_fn,
    layer_arrowkey,
    layer_capsplus,
    layer_capspro,
    layer_backup
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _ADD));
    rgblight_set_layer_state(1, layer_state_cmp(state, _MOUSEKEY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ARROWKEY));
    rgblight_set_layer_state(4, layer_state_cmp(state, _CAPSPLUS));
    rgblight_set_layer_state(5, layer_state_cmp(state, _CAPSPRO));
    rgblight_set_layer_state(6, layer_state_cmp(state, _BACKUP));

    return state;
}
