// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h"
#include "quantum.h"
#include "keymap.h"
#include QMK_KEYBOARD_H

#define _______ KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LEFT_TOP_ROW        TD(TD_REBOOT),  TD(TD_QWERTY), MS_UP,   _______, KC_VOLU
#define LEFT_MIDDLE_ROW            KC_NUM,        MS_LEFT, MS_DOWN, MS_RGHT, KC_VOLD
#define LEFT_BOTTOM_ROW           _______,        _______, _______, _______, KC_MUTE
#define LEFT_THUMBS                                        _______, _______, _______

#define RIGHT_TOP_ROW       KC_VOLU ,_______ ,MS_UP   ,TG(_QWERTY) ,TD(TD_REBOOT)
#define RIGHT_MIDDLE_ROW    KC_VOLD ,MS_LEFT ,MS_DOWN ,MS_RGHT     ,TD(TD_JIGGLE)
#define RIGHT_BOTTOM_ROW    KC_MUTE ,_______ ,_______ ,_______     ,_______
#define RIGHT_THUMBS        _______ ,_______ ,_______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                KC_Q,         KC_W,                KC_F,   RALT_T(KC_P),            KC_G,              KC_J,    RALT_T(KC_L),    KC_U,              KC_Y,           KC_QUOT,
                KC_A,         KC_R,                KC_S,           KC_T,            KC_D,              KC_H,    KC_N,            KC_E,              KC_I,           KC_O,
        LSFT_T(KC_Z), LCTL_T(KC_X),        LGUI_T(KC_C),   LALT_T(KC_V),            KC_B,              KC_K,    LALT_T(KC_M),    RGUI_T(KC_COMM),   RCTL_T(KC_DOT), RSFT_T(KC_SLASH),
                                    LT(_NUMBERS,KC_ESC),         KC_SPC, LT(_NAV,KC_TAB),              KC_BSPC, LT(_FUN,KC_ENT), LT(_SYMBOLS,KC_DEL)
    ),
    [_QWERTY] = LAYOUT(
                KC_Q,         KC_W,                KC_E,   RALT_T(KC_R),            KC_T,              KC_Y,    RALT_T(KC_U),    KC_I,              KC_O,           KC_P,
                KC_A,         KC_S,                KC_D,           KC_F,            KC_G,              KC_H,    KC_J,            KC_K,              KC_L,           KC_SCLN,
        LSFT_T(KC_Z), LCTL_T(KC_X),        LGUI_T(KC_C),   LALT_T(KC_V),            KC_B,              KC_N,    LALT_T(KC_M),    RGUI_T(KC_COMM),   RCTL_T(KC_DOT), RSFT_T(KC_SLASH),
                                    LT(_NUMBERS,KC_ESC),         KC_SPC, LT(_NAV,KC_TAB),              KC_BSPC, LT(_FUN,KC_ENT), LT(_SYMBOLS,KC_DEL)
    ),

    [_NUMBERS] = LAYOUT_wrapper(
           LEFT_TOP_ROW,      KC_LBRC,            KC_KP_7, KC_KP_8, KC_KP_9, KC_RBRC,
        LEFT_MIDDLE_ROW,      KC_EQL,             KC_KP_4, KC_KP_5, KC_KP_6, KC_SCLN,
        LEFT_BOTTOM_ROW,      KC_NONUS_BACKSLASH, KC_KP_1, KC_KP_2, KC_KP_3, KC_GRV,
            LEFT_THUMBS,      KC_MINUS,           KC_KP_0, KC_DOT
    ),

    [_NAV] = LAYOUT_wrapper(
           LEFT_TOP_ROW,      KC_INS,       KC_HOME,       KC_UP,    KC_END,        KC_PGUP,
        LEFT_MIDDLE_ROW,      TD(TD_CAPS),  KC_LEFT,       KC_DOWN,  KC_RIGHT,      KC_PGDN,
        LEFT_BOTTOM_ROW,      LCS(KC_HOME), LCTL(KC_PGUP), G_SEL_LN, LCTL(KC_PGDN), LCS(KC_END),
            LEFT_THUMBS,      _______,      _______,       _______
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
              KC_LCBR, KC_AMPR, KC_ASTR,    KC_LPRN,   KC_RCBR,       RIGHT_TOP_ROW,
            G_DEGREES,  KC_DLR, KC_PERC,    KC_CIRC,   KC_PLUS,       RIGHT_MIDDLE_ROW,
        KC_NONUS_HASH, KC_EXLM,   KC_AT, LSFT(KC_3),   KC_PIPE,       RIGHT_BOTTOM_ROW,
                                KC_LPRN,    KC_RPRN, G_EM_DASH,       RIGHT_THUMBS
    ),

    [_FUN] = LAYOUT_wrapper(
            KC_F12, KC_F7, KC_F8, KC_F9,  KC_PSCR,      RIGHT_TOP_ROW,
            KC_F11, KC_F4, KC_F5, KC_F6,  KC_SCRL,      RIGHT_MIDDLE_ROW,
            KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUSE,      RIGHT_BOTTOM_ROW,
                        MS_BTN2, _______, _______,      RIGHT_THUMBS
    ),
};



