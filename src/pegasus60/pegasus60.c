#include "quantum.h"

#define _BASIC 0
#define _SYMBOL 1
#define _MOUSEKEY 2
#define _FN 3
#define _CAPSPLUS 4
#define _WM 5

const rgblight_segment_t PROGMEM layer_basic[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GOLDENROD});
const rgblight_segment_t PROGMEM layer_symbol[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_CORAL});
const rgblight_segment_t PROGMEM layer_mousekey[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM layer_fn[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE});
const rgblight_segment_t PROGMEM layer_capsplus[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_PURPLE});
const rgblight_segment_t PROGMEM layer_wm[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_SPRINGGREEN});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] =
    RGBLIGHT_LAYERS_LIST(layer_basic, layer_symbol, layer_mousekey, layer_fn,
                         layer_capsplus, layer_wm);

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
