// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤Bsp├───┐   ┌───┤Ent├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,
                        KC_ESC,  KC_SPC,  KC_TAB,        KC_BSPC, KC_ENT,  KC_DEL
    )
    // [0] = LAYOUT(
    //     KC_Q,    KC_F,    KC_F,    KC_P,    KC_G,
    //     KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
    //     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
    //                     KC_ESC,  KC_SPC,  KC_TAB
    // )
    // [0] = LAYOUT_split_3x5_3(
    //     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    //     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    //                                KC_LGUI, KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    // )
};


void keyboard_pre_init_user(void) {
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
    uprintf("kc: %s\n", get_keycode_string(keycode));
    print("key pressed\n");

    #endif
    return true;
}
