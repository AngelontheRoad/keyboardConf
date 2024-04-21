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

// 注册灯光搭配方案，一种灯光方案对应一个rgblight_segment_t
// 名字layer_basic可以任起
const rgblight_segment_t PROGMEM layer_basic[] = RGBLIGHT_LAYER_SEGMENTS(
    // HAVEN 60共有13颗灯珠，编号0~12
    // 编号0对应capslock键位灯，位于P C B正面
    // 编号1~7对应键盘左侧灯珠，顺序从下往上
    // 编号8~12对应键盘右侧灯珠，顺序从上往下
    {0, 1, HSV_CHARTREUSE}, // 将caplock键位灯设置为黄绿色
    {1, 3, HSV_PURPLE}, // 将从1号开始的3个灯，即左侧下方3个灯设置为紫色
    {4, 3, HSV_PINK}, // 同理，4号开始的3个灯，即左侧上方的3个灯设置为粉色
    {7, 3, HSV_GOLDENROD}, // 注意此处7，8，9三个灯为右侧上方的三个灯
    {10, 3, HSV_GOLD} // 左右异色
);
const rgblight_segment_t PROGMEM layer_add[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_BLUE}, // 红蓝交锋,左右同色
    {4, 3, HSV_RED}, {7, 3, HSV_RED}, {10, 3, HSV_BLUE});
const rgblight_segment_t PROGMEM layer_fn[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 13, HSV_PURPLE} // 简单粗暴都是紫色
    );

// 固定流程，将灯光方案注册到my_rgb_layers数组中
const rgblight_segment_t *const PROGMEM my_rgb_layers[] =
    RGBLIGHT_LAYERS_LIST(layer_basic, layer_add, layer_fn);

// 同固定流程
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// 将灯光方案和键盘层对应起来
layer_state_t layer_state_set_kb(layer_state_t state) {
    // 左侧的数字代表灯光方案编号，对应上方my_rgb_layers的添加顺序
    // 右侧的数字代表键盘层，0是默认层
    // 该函数表示通电和切回基本层时使用灯光方案0
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    // 该函数表示切至第一层时，使用灯光方案1
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    // 一个灯光方案可以应用到多个层
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));

    return state;
}
