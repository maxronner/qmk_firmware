void leader_end_user(void) {
    if (leader_sequence_three_keys(KC_S, KC_W, KC_J)) {
        // windows: open taskmanager
        register_code(KC_LSFT);
        ctrl_key(KC_ESC);
        unregister_code(KC_LSFT);
    } else if (leader_sequence_three_keys(KC_E, KC_M, KC_R)) { 
        // E(mail) M(ax) R(onner)
        SEND_STRING("max@ronner.dev");
    } else if (leader_sequence_three_keys(KC_E, KC_M, KC_G)) { 
        // E(mail) M(ax) G(mail)
        SEND_STRING("max.ronner@gmail.com");
    } else if (leader_sequence_three_keys(KC_S, KC_L, KC_R)) { 
        // S(ystem) L(inux) R(eboot)
        alt_key(KC_F2);
        tap_code(KC_R);
        tap_code(KC_ENT);
    } else if (leader_sequence_three_keys(KC_V, KC_C, KC_C)) { 
        // V(isual studio) C(ode) C(omment)
        ctrl_two_keys(KC_K, KC_C);
    } else if (leader_sequence_three_keys(KC_V, KC_C, KC_U)) { 
        // V(isual studio) C(ode) U(ncomment)
        ctrl_two_keys(KC_K, KC_U);
    } else if (leader_sequence_three_keys(KC_K, KC_L, KC_Q)) { 
        // K(eyboard) L(ayer) Q(werty)
        set_single_persistent_default_layer(_QWERTY);
    } else if (leader_sequence_four_keys(KC_K, KC_L, KC_Q, KC_G)) { 
        // K(eyboard) L(ayer) Q(werty) G(aming)
        set_single_persistent_default_layer(_GAMING);
    } else if (leader_sequence_three_keys(KC_K, KC_L, KC_C)) { 
        // K(eyboard) L(ayer) C(olemak DH)
        set_single_persistent_default_layer(_COLEMAK_DH);
    } else if (leader_sequence_four_keys(KC_K, KC_L, KC_C, KC_G)) { 
        // K(eyboard) L(ayer) C(olemak DH) G(aming)
        set_single_persistent_default_layer(_GAME_CLMK_DH);
    } else if (leader_sequence_four_keys(KC_K, KC_T, KC_G, KC_S)) { 
        // K(eyboard) T(oggle) G(ame) S(trafe)
        exclusivity_enabled = !exclusivity_enabled;
        custom_toggle_sound(exclusivity_enabled);
    } else if (leader_sequence_four_keys(KC_K, KC_T, KC_G, KC_E)) { 
        // K(eyboard) T(oggle) G(ame) E(sc-lock)
        ignore_escape = !ignore_escape;
        custom_toggle_sound(ignore_escape);
    } else if (leader_sequence_four_keys(KC_K, KC_T, KC_T, KC_E)) { 
        // K(eyboard) T(oggle) T(yping) E(sc-lock)
        is_leader_swap = !is_leader_swap;
        custom_toggle_sound(is_leader_swap);
    } else if (leader_sequence_three_keys(KC_K, KC_S, KC_B)) { 
        // K(eyboard) S(etup) B(ootloader)
        soft_reset_keyboard();
    }
}