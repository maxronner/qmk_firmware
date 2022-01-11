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