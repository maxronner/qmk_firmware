void shift_key(uint16_t keycode) {
    register_code  (KC_LSFT);
    tap_code       (keycode);
    unregister_code(KC_LSFT);
}

void ctrl_key(uint16_t keycode) {
    register_code  (KC_LCTL);
    tap_code       (keycode);
    unregister_code(KC_LCTL);
}

void ctrl_two_keys(uint16_t keycode1, uint16_t keycode2) {
    register_code  (KC_LCTL);
    tap_code       (keycode1);
    tap_code       (keycode2);
    unregister_code(KC_LCTL);
}

void alt_key(uint16_t keycode) {
    register_code  (KC_LALT);
    tap_code       (keycode);
    unregister_code(KC_LALT);
}