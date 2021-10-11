bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case LALT_T(KC_R):
        case LSFT_T(KC_S):
        case LCTL_T(KC_T):
        case RCTL_T(KC_N):
        case RSFT_T(KC_E):
        case LALT_T(KC_I):
        case RGUI_T(KC_O):
            return true;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSPO:
        case KC_RSPC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}