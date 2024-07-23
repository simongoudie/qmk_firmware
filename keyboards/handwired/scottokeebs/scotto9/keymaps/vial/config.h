/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x09, 0xD0, 0xA3, 0xBE, 0x64, 0x05, 0x25, 0x64}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 2, 2 }

#define VIAL_COMBO_ENTRIES 12

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B0);
    writePinLow(D5);
    switch (get_highest_layer(state)) {
        case 1:
            writePinHigh(B0);
            break;
        case 2:
            writePinHigh(D5);
            break;
        default:
            writePinHigh(B0);
            writePinHigh(D5);
            break;
    }
    return state;
}

#define BACKLIGHT_LED_COUNT 10
#undef BACKLIGHT_PIN
#define BACKLIGHT_PINS { D3 }