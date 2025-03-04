void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_E, KC_R)) {
        // E(mail) R(onner)
        SEND_STRING("max@ronner.dev");
    } else if (leader_sequence_two_keys(KC_E, KC_G)) {
        // E(mail) G(mail)
        SEND_STRING("max.ronner@gmail.com");
    } else if (leader_sequence_two_keys(KC_K, KC_Q)) {
        // K(eyboard) L(ayer) Q(werty)
        set_single_persistent_default_layer(_QWERTY);
    } else if (leader_sequence_three_keys(KC_K, KC_G, KC_G)) {
        // K(eyboard) L(ayer) Q(werty) G(aming)
        set_single_persistent_default_layer(_GAMING);
    } else if (leader_sequence_two_keys(KC_K, KC_C)) {
        // K(eyboard) L(ayer) C(olemak DH)
        set_single_persistent_default_layer(_COLEMAK_DH);
    } else if (leader_sequence_two_keys(KC_K, KC_G)) {
        // K(eyboard) L(ayer) C(olemak DH) G(aming)
        set_single_persistent_default_layer(_GAME_CLMK_DH);
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        // K(eyboard) T(oggle) G(ame) S(trafe)
        exclusivity_enabled = !exclusivity_enabled;
        custom_toggle_sound(exclusivity_enabled);
    } else if (leader_sequence_two_keys(KC_T, KC_E)) {
        // K(eyboard) T(oggle) G(ame) E(sc-lock)
        ignore_escape = !ignore_escape;
        custom_toggle_sound(ignore_escape);
    } else if (leader_sequence_two_keys(KC_T, KC_V)) {
        // K(eyboard) T(oggle) T(yping) E(sc-lock)
        ergo_swap_enabled = !ergo_swap_enabled;
        custom_toggle_sound(ergo_swap_enabled);
    } else if (leader_sequence_two_keys(KC_Q, KC_B)) {
        // K(eyboard) S(etup) B(ootloader)
        soft_reset_keyboard();
    }
}
