// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h"
#include QMK_KEYBOARD_H

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
     * └───┴───┴───┘
     */
    [_ONE] = LAYOUT_ortho_2x3(
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E,    KC_F
    ),
    [_TWO] = LAYOUT_ortho_2x3(
        KC_G,    KC_H,    KC_I,
        KC_J,    KC_K,    KC_L
    ),
    [_THREE] = LAYOUT_ortho_2x3(
        KC_M,    KC_N,    KC_O,
        KC_P,    KC_Q,    KC_R
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][2] = {
    [_ONE] = { ENCODER_CCW_CW(KC_A, KC_B), ENCODER_CCW_CW(TO(_THREE), TO(_TWO)) },
    [_TWO] = { ENCODER_CCW_CW(KC_G, KC_H), ENCODER_CCW_CW(TO(_ONE), TO(_THREE)) },
    [_THREE] = { ENCODER_CCW_CW(KC_M, KC_N), ENCODER_CCW_CW(TO(_TWO), TO(_ONE)) },
};
#endif

void keyboard_pre_init_user(void) {
    print("Keyboard pre init\n");
    // Light the internal led
    gpio_set_pin_output(GP13);
    // gpio_write_pin_high(GP13);
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
    print("Debugging enabled\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    uprintf("kc: %s\n", get_keycode_string(keycode));
    print("key pressed\n");
    // gpio_write_pin_high(GP13);

    #endif
    return true;
}

bool oled_task_user(void) {
    gpio_set_pin_output(GP13);
    gpio_write_pin_high(GP13);
    print("OLED Task");
    oled_write_P(PSTR("Hello world"), false);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    print("Layer changed: ");
    oled_buffer_reader_t reader = oled_read_raw(0);
    uprintf("OLED buffer: %u\n", reader.remaining_element_count);
    uprintf("Brightness: %u\n", oled_get_brightness());
    oled_on();
    if (is_oled_on()) {
        print("OLED is on\n");
    } else {
        print("OLED is off\n");
    }
    switch (get_highest_layer(state)) {
        case _ONE:
            print("One\n");
            oled_write_ln_P(PSTR("Layer One"), false);
            gpio_write_pin_low(GP13);
            break;
        case _TWO:
            print("Two\n");
            oled_write_ln_P(PSTR("Layer Two"), false);
            gpio_write_pin_high(GP13);
            break;
        case _THREE:
            print("Three\n");
            oled_write_ln_P(PSTR("Layer Three"), false);
            gpio_write_pin_low(GP13);
            break;
        default:
            print("Undefined\n");
    }
    return state;
}
