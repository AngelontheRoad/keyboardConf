
#include "linked65h.h"

void matrix_init_kb(void) {  
  setPinOutput(A5);
  matrix_init_user();
}
void led_set_kb(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(A5);
  } else {
    writePinHigh(A5);
  }
  led_set_user(usb_led);
}

