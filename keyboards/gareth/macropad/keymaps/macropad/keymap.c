// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h"
#include QMK_KEYBOARD_H

char debug_buffer[100];

enum layers {
    _ONE,
    _TWO,
    _THREE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * └───┴───┴───┘
     */
    [_ONE] = LAYOUT_ortho_4x3(
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E,    KC_F,
        KC_G,    KC_H,    KC_I,
        KC_J,    KC_K,    KC_L
    ),
    [_TWO] = LAYOUT_ortho_4x3(
        KC_M,    KC_N,    KC_O,
        KC_P,    KC_Q,    KC_R,
        KC_S,    KC_T,    KC_U,
        KC_V,    KC_W,    KC_X
    ),
    [_THREE] = LAYOUT_ortho_4x3(
        KC_Y,    KC_Z,    KC_1,
        KC_2,    KC_3,    KC_4,
        KC_5,    KC_6,    KC_7,
        KC_8,    KC_9,    KC_0
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][2] = {
    [_ONE] = { ENCODER_CCW_CW(TO(_THREE), TO(_TWO)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_TWO] = { ENCODER_CCW_CW(TO(_ONE), TO(_THREE)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_THREE] = { ENCODER_CCW_CW(TO(_TWO), TO(_ONE)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

void keyboard_pre_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
    print("Debugging enabled\n");
}

void keyboard_post_init_user(void) {
    print("Keyboard post init\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    uprintf("kc: %s\n", get_keycode_string(keycode));
    print("key pressed\n");

    #endif
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    print("Layer changed: ");
    switch (get_highest_layer(state)) {
        case _ONE:
            print("One\n");
            break;
        case _TWO:
            print("Two\n");
            break;
        case _THREE:
            print("Three\n");
            break;
        default:
            print("Undefined\n");
    }
    return state;
}
