
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID      0x4F53
#define PRODUCT_ID     0x4C49
#define DEVICE_VER     0x0001
#define MANUFACTURER   -
#define PRODUCT        Linked65

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS {B13,A1,A2,A3,A4 }
#define MATRIX_COL_PINS {A6,B12,B4,B11,B3,A15,B14,B15,A8,B10,B9,B8,B7,B6,B5}
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define FORCE_NKRO
