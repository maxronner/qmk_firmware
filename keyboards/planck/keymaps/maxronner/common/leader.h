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
    } else if (leader_sequence_one_key(KC_V)) {
        SEND_STRING(
                    SS_TAP(X_ESC)  // Ensure Vim is in normal mode
                    ":set updatetime=50" SS_TAP(X_ENTER)
                    ":set splitright" SS_TAP(X_ENTER)
                    ":set isfname+=@-@" SS_TAP(X_ENTER)
                    ":set scrolloff=8" SS_TAP(X_ENTER)
                    ":set signcolumn=yes" SS_TAP(X_ENTER)
                    ":set colorcolumn=80" SS_TAP(X_ENTER)
                    ":set relativenumber" SS_TAP(X_ENTER)
                    ":set number" SS_TAP(X_ENTER)
                    ":set tabstop=4" SS_TAP(X_ENTER)
                    ":set softtabstop=4" SS_TAP(X_ENTER)
                    ":set shiftwidth=4" SS_TAP(X_ENTER)
                    ":set expandtab" SS_TAP(X_ENTER)
                    ":set smartindent" SS_TAP(X_ENTER)
                    ":set nowrap" SS_TAP(X_ENTER)
                    ":set hlsearch" SS_TAP(X_ENTER)
                    ":set incsearch" SS_TAP(X_ENTER)
                    ":set ignorecase" SS_TAP(X_ENTER)
                    ":set smartcase" SS_TAP(X_ENTER)
                );
    }
}
