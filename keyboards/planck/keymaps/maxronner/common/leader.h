LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    
    SEQ_ONE_KEY(KC_J) {
        register_code(KC_LSFT);
        ctrl_key(KC_ESC);
        unregister_code(KC_LSFT);
    }
    SEQ_ONE_KEY(KC_L) {
        ctrl_two_keys(KC_K, KC_C);
    }    
    SEQ_ONE_KEY(KC_U) {
        ctrl_two_keys(KC_K, KC_U);
    }
    leader_end();
  }
} 