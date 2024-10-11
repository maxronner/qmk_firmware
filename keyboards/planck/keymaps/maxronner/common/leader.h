void leader_end_user(void) {
    if (leader_sequence_one_key(KC_J)) {
        register_code(KC_LSFT);
        ctrl_key(KC_ESC);
        unregister_code(KC_LSFT);
    } else if (leader_sequence_one_key(KC_L)) {
        ctrl_two_keys(KC_K, KC_C);
    } else if (leader_sequence_one_key(KC_B)) {
        set_single_persistent_default_layer(_COLEMAK_DH);
    } else if (leader_sequence_one_key(KC_G)) {
        set_single_persistent_default_layer(_GAMING);
    } else if (leader_sequence_one_key(KC_U)) {
        ctrl_two_keys(KC_K, KC_U);
    }
} 