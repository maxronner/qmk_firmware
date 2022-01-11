// Tap dance states
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

// Tap Dance keycodes
enum td_keycodes {
    _BSPC,
    _ESC,
};

// Shorthand used for keymap
#define TD_BSPC TD(_BSPC)
#define TD_ESC  TD(_ESC)

// Create a global instance of the tapdance state type
static td_state_t td_state;

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
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
        case TD_DOUBLE_HOLD: alt_key(KC_F4); break;
        case TD_TRIPLE_TAP: register_code(KC_CAPS); break;
        default: break;
    }
}

void esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_TRIPLE_TAP: unregister_code(KC_CAPS); break;
        default: break;
    }
}

// ...................................................................

qk_tap_dance_action_t tap_dance_actions[] = {
    [_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(bspc_tap, bspc_finished, bspc_reset),
    [_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset),
};