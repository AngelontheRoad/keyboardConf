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

#include "quantum.h"

//Initialize B12 for in-switch caps lock
void keyboard_pre_init_kb(void){
    setPinOutput(B12);
    keyboard_pre_init_user();
}

//Initialize all RGB indicators to 'off'
__attribute__((weak))
void keyboard_post_init_user(void) {
    rgblight_setrgb_at(0, 0, 0, 0); // [..., 0] = top LED
    rgblight_setrgb_at(0, 0, 0, 1); // [..., 1] = middle LED
    rgblight_setrgb_at(0, 0, 0, 2); // [..., 2] = bottom LED
}

//Indicator light function
/*
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
 //       writePin(B12, !led_state.caps_lock);  //Un-comment this line to enable in-switch capslock indicator
    if (led_state.caps_lock) {
        rgblight_setrgb_at(0, 255, 0, 0); //green
    } else {
        rgblight_setrgb_at(0, 0, 0, 0);
    }
    if (led_state.num_lock) {
        rgblight_setrgb_at(0, 0, 255, 1); //blue
    } else {
        rgblight_setrgb_at(0, 0, 0, 1);
    }
   if (led_state.scroll_lock) {          
        rgblight_setrgb_at(255, 0, 0, 2); //red
    } else {
        rgblight_setrgb_at(0, 0, 0, 2);
    }
}
    return res;
}
*/

//Below is an exmaple of layer indication using one of the RGB indicatiors. As configured, uses the bottom indicator (2) to light up red when layer 1 is in use. 

layer_state_t layer_state_set_kb(layer_state_t state) {
        switch (get_highest_layer(state)) {
                case 0:
                        rgblight_setrgb_at(205, 50, 50, 0);
                        rgblight_setrgb_at(50, 205, 50, 1);
                        rgblight_setrgb_at(50, 50, 205, 2);
                        // light_set_red(0);
                        // light_set_orange(1);
                        // light_set_yellow(2);
                        break;
                case 1:
                        rgblight_setrgb_at(255, 140, 0, 0);
                        rgblight_setrgb_at(140, 0, 255, 1);
                        rgblight_setrgb_at(0, 255, 140, 2);
                        // light_set_orange(0);
                        // light_set_yellow(1);
                        // light_set_green(2);
                        break;
                case 2:
                        rgblight_setrgb_at(255, 255, 0, 0);
                        rgblight_setrgb_at(0, 255, 255, 1);
                        rgblight_setrgb_at(255, 0, 255, 2);
                        // light_set_yellow(0);
                        // light_set_green(1);
                        // light_set_blue(2);
                        break;
                case 3:
                        rgblight_setrgb_at(173, 255, 47, 0);
                        rgblight_setrgb_at(255, 47, 173, 1);
                        rgblight_setrgb_at(47, 173, 255, 2);
                        // light_set_green(0);
                        // light_set_blue(1);
                        // light_set_cyan(2);
                        break;
                case 4:
                        rgblight_setrgb_at(30, 144, 255, 0);
                        rgblight_setrgb_at(255, 254, 30, 1);
                        rgblight_setrgb_at(255, 30, 32, 2);
                        // light_set_blue(0);
                        // light_set_cyan(1);
                        // light_set_purple(2);
                        break;
                case 5:
                        rgblight_setrgb_at(0, 255, 255, 0);
                        rgblight_setrgb_at(0, 128, 255, 1);
                        rgblight_setrgb_at(0, 255, 128, 2);
                        // light_set_cyan(0);
                        // light_set_purple(1);
                        // light_set_red(2);
                        break;
                case 6:
                        rgblight_setrgb_at(147, 112, 219, 0);
                        rgblight_setrgb_at(219, 201, 112, 1);
                        rgblight_setrgb_at(131, 219, 112, 2);
                        // light_set_purple(0);
                        // light_set_red(1);
                        // light_set_orange(2);
                        break;
                case 7:
                        rgblight_setrgb_at(89, 113, 178, 0);
                        rgblight_setrgb_at(80, 215, 111, 1);
                        rgblight_setrgb_at(255, 255, 125, 2);
                        // light_set_purple(0);
                        // light_set_red(1);
                        // light_set_orange(2);
                        break;
                default:
                        rgblight_setrgb_at(205, 50, 50, 0);
                        rgblight_setrgb_at(50, 205, 50, 1);
                        rgblight_setrgb_at(50, 50, 205, 2);
        }
        return state;
}
