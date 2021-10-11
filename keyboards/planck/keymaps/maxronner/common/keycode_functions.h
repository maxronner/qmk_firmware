// .......................................................... Modifiers with key tap

void shift_key(uint16_t keycode)
{
    register_code  (KC_LSFT);
    tap_code       (keycode);
    unregister_code(KC_LSFT);
}

void ctrl_key(uint16_t keycode)
{
    register_code  (KC_LCTL);
    tap_code       (keycode);
    unregister_code(KC_LCTL);
}

void ctrl_two_keys(uint16_t keycode1, uint16_t keycode2)
{
    register_code  (KC_LCTL);
    tap_code       (keycode1);
    tap_code       (keycode2);
    unregister_code(KC_LCTL);
}

void alt_key(uint16_t keycode)
{
    register_code  (KC_LALT);
    tap_code       (keycode);
    unregister_code(KC_LALT);
}

// ................................................................... BSPC Tap Dance

void bspc_tap(qk_tap_dance_state_t *state, void *user_data) {
    tap_code(KC_BSPC);
}

void bspc_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        register_code(KC_LCTL);
        register_code(KC_BSPC);
    }
}

void bspc_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LCTL);
    unregister_code(KC_BSPC);
}

// ................................................................... ESC Tap Dance

void esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code(KC_ESC); break;
        case TD_SINGLE_HOLD: alt_key(KC_F4); break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP: register_code(KC_CAPS); break;
        default: break;
    }
}

void esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        default: break;
    }
}

// ................................................................... Tap Dance

qk_tap_dance_action_t tap_dance_actions[] = {
    [_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(bspc_tap, bspc_finished, bspc_reset),
    [_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset),
};

// // ................................................................... LEFT Tap Dance

// void left_tap(qk_tap_dance_state_t *state, void *user_data) {
//     tap_code(KC_LEFT);
// }

// void left_finished(qk_tap_dance_state_t *state, void *user_data) {
//     if (state->pressed && !state->interrupted) {
//         register_code(KC_LCTL);
//         register_code(KC_LEFT);
//     }
// }

// void left_reset(qk_tap_dance_state_t *state, void *user_data) {
//     unregister_code(KC_LCTL);
//     unregister_code(KC_LEFT);
// }

// // ................................................................... RIGHT Tap Dance

// void right_tap(qk_tap_dance_state_t *state, void *user_data) {
//     tap_code(KC_RIGHT);
// }

// void right_finished(qk_tap_dance_state_t *state, void *user_data) {
//     if (state->pressed && !state->interrupted) {
//         register_code(KC_LCTL);
//         register_code(KC_RIGHT);
//     }
// }

// void right_reset(qk_tap_dance_state_t *state, void *user_data) {
//     unregister_code(KC_LCTL);
//     unregister_code(KC_RIGHT);
// }