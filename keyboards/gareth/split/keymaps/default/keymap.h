enum layers {
    _BASE,
    _NUMBERS,
    _NAV,
    _SYMBOLS,
    _FUN,
    _QWERTY
};

enum custom_keycodes {
    G_EM_DASH = SAFE_RANGE,
    G_DEGREES,
    G_SEL_LN,
};

// Tap Dance declarations
enum {
    TD_CAPS,
    TD_REBOOT,
    TD_QWERTY,
    TD_JIGGLE
};

bool mouse_jiggle_mode = false;

void dance_caps(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Single tap: Toggle Caps Word
        caps_word_toggle();
    } else if (state->count == 2) {
        // Double tap: Send Caps Lock
        tap_code16(KC_CAPS);
    }
}

void dance_reboot(tap_dance_state_t *state, void *user_data) {
    // Ignore single tap
    if (state->count == 2) {
        // Double tap: Reboot
        soft_reset_keyboard();
    } else if (state->count == 3) {
        // Triple tap: Bootloader
        reset_keyboard();
    }
};

void dance_qwerty(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Single tap: Switch to QWERTY layer
        layer_on(_QWERTY);
    } else if (state->count == 2) {
        // Double tap: Toggle QWERTY layer
        layer_invert(_QWERTY);
    }
};

deferred_token jiggle_token;
uint32_t jiggle_callback(uint32_t trigger_time, void *cb_arg){
    static bool positive = true;
    if (mouse_jiggle_mode) {
        report_mouse_t mouse_report = {
            .x = positive ? 2 : -2,
            .y = positive ? 2 : -2,
        };
        host_mouse_send(&mouse_report);
        positive = !positive;
    }
    return JIGGLER_INTERVAL;
}

void dance_jiggle(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
        print("Disabling mouse jiggle mode\n");
        cancel_deferred_exec(jiggle_token);
        mouse_jiggle_mode = false;
    } else if (state->count == 2) {
        print("Enabling mouse jiggle mode\n");
        jiggle_token = defer_exec(500, jiggle_callback, NULL);
        mouse_jiggle_mode = true;
    }
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_REBOOT] = ACTION_TAP_DANCE_FN(dance_reboot),
    [TD_CAPS] = ACTION_TAP_DANCE_FN(dance_caps),
    [TD_QWERTY] = ACTION_TAP_DANCE_FN(dance_qwerty),
    [TD_JIGGLE] = ACTION_TAP_DANCE_FN(dance_jiggle)
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

    switch (keycode) {
        case G_EM_DASH:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    // If shift is down, send an en dash
                    SEND_STRING(SS_UP(X_RSFT) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0)) SS_DOWN(X_RSFT));
                } else {
                    // Otherwise, send an em dash like you'd expect
                    SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
                }
            }
            return false;
        case G_DEGREES:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
            }
            return false;
        case G_SEL_LN:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            }
            return false;
    }

    return true;
}
