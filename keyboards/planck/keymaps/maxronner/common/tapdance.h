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
enum td_keycodes { _DM1, _BSPC };

// Shorthand used for keymap
#define TD_DM1 TD(_DM1)
#define TD_BSPC TD(_BSPC)
#define TD_ESC TD(_ESC)

// Create a global instance of the tapdance state type
static td_state_t td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

// ................................................................... BSPC Tap Dance
void bspc_tap(tap_dance_state_t *state, void *user_data) {
    tap_code(KC_BSPC);
}

void bspc_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        register_code(KC_LCTL);
        register_code(KC_BSPC);
    }
}

void bspc_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LCTL);
    unregister_code(KC_BSPC);
}

// ................................................................... ESC Tap Dance
void dm1_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code(DM_PLY1);
            break;
        case TD_SINGLE_HOLD:
            register_code(DM_REC1);
            break;
        default:
            break;
    }
}

void dm1_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code(DM_PLY1);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(DM_REC1);
            break;
        default:
            break;
    }
}

// ...................................................................

qk_tap_dance_action_t tap_dance_actions[] = {
    [_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(bspc_tap, bspc_finished, bspc_reset),
    [_DM1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dm1_finished, dm1_reset),
};
