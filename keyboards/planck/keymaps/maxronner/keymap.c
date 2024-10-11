#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum planck_layers {
  _COLEMAK_DH,
  _QWERTY,
  _GAMING,
  _FPSLOWER,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _MODIFY
};

enum planck_keycodes {
    CLMK_DH = SAFE_RANGE,
    GAMING,
    QWERTY,
    FAKE_ESC,
    FAKE_ESC_TRIGGER,
    EXCL_A,
    EXCL_D,
    TOGGLE_EXCLUSIVITY,
};

bool ignore_escape = false;
bool a_registered = false;
bool d_registered = false;
bool a_down = false;
bool d_down = false;
bool exclusivity_enabled = false;

float on_sound[][2] = SONG(CUSTOM_TOGGLE_ON_SOUND);
float off_sound[][2] = SONG(CUSTOM_TOGGLE_OFF_SOUND);

// Uncomment this for tapdance logic
// #include "common/tapdance.h"

// Layers
#define LOWER   LT(_LOWER, KC_ENT)
#define RAISE   LT(_RAISE, KC_DEL)
#define MODIFY  OSL(_MODIFY)
#define FPSLOWER MO(_FPSLOWER)

// Home row mods for Colemak
#ifdef HOME_MODS
    #define HOME_A LGUI_T(KC_A)
    #define HOME_R LALT_T(KC_R)
    #define HOME_S LSFT_T(KC_S)
    #define HOME_T LCTL_T(KC_T)
    #define HOME_N RCTL_T(KC_N)
    #define HOME_E RSFT_T(KC_E)
    #define HOME_I LALT_T(KC_I)
    #define HOME_O RGUI_T(KC_O)
#else
    #define HOME_A  KC_A
    #define HOME_R  KC_R
    #define HOME_S  KC_S
    #define HOME_T  KC_T
    #define HOME_N  KC_N
    #define HOME_E  KC_E
    #define HOME_I  KC_I
    #define HOME_O  KC_O
#endif

// For cursor selection and movement
#define GUI_F1  LGUI_T(KC_F1)
#define ALT_F2  LALT_T(KC_F2)
#define SFT_F3  LSFT_T(KC_F3)
#define CTL_F4  LCTL_T(KC_F4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak DH
    * ,-----------------------------------------------------------------------------------.
    * | ESC  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   Å  |  Ä   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  Ö   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   ;  | RSFT |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LEAD | CTRL | LALT | LGUI |_LOWER|SPACE | BSPC |_RAISE| Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_COLEMAK_DH] = LAYOUT_planck_grid(
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,    KC_J,    KC_L,   KC_U,    KC_Y,    SE_ARNG, SE_ADIA,
        KC_TAB,  HOME_A,  HOME_R,  HOME_S,  HOME_T, KC_G,    KC_M,    HOME_N, HOME_E,  HOME_I,  HOME_O,  SE_ODIA,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,   KC_V,    KC_K,    KC_H,   KC_COMM, KC_DOT,  SE_SCLN, KC_RSFT,
        QK_LEAD, KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_BSPC, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ä  |  Ö   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LSFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ;  | RSFT |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LEAD | CTRL | LALT | LGUI |_LOWER|SPACE | BSPC |_RAISE| Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_grid(
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    SE_ARNG,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    SE_ADIA, SE_ODIA,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   SE_COMM,  SE_DOT,  SE_SCLN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Gaming
    * ,-----------------------------------------------------------------------------------.
    * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BSPC |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ä  |ENTER |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LSFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ;  | RSFT |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | CTRL | CTRL | LALT | LALT | NUMS |SPACE | BSPC |RAISE | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */

    [_GAMING] = LAYOUT_planck_grid(
        FAKE_ESC,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
        _______, EXCL_A,  KC_S,    EXCL_D,  KC_F,    KC_G,   KC_H,    KC_J,   KC_K,    KC_L,    SE_ADIA, KC_ENT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,   SE_COMM, SE_DOT,  SE_SCLN, _______,
        KC_LCTL, _______, _______, KC_LALT, FPSLOWER,KC_SPC, KC_BSPC, RAISE,  _______, _______, _______, _______
    ),

    /* LOWER
    * ,-----------------------------------------------------------------------------------.
    * | CAPS |   ´  |   |  |   [  |   ]  |   #  |   ^  |   <  |   >  |   @  |   %  | XXXX |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | SLCK |   +  |   -  |   {  |   }  |   !  |   ?  |   (  |   )  |   /  |   *  | XXXX |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |DMPLY1|   ~  |   _  |   :  |   =  |   $  |   &  |   "  |   '  |   \  |   `  |DMPLY2|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_planck_grid(
        KC_CAPS, SE_ACUT, SE_PIPE, SE_LBRC, SE_RBRC, SE_HASH, SE_CIRC, SE_LABK, SE_RABK, SE_AT,   SE_PERC, XXXXXXX,
        KC_SCRL, SE_PLUS, SE_MINS, SE_LCBR, SE_RCBR, SE_EXLM, SE_QUES, SE_LPRN, SE_RPRN, SE_SLSH, SE_ASTR, XXXXXXX,
        DM_PLY1, SE_TILD, SE_UNDS, SE_COLN, SE_EQL,  SE_DLR,  SE_AMPR, SE_DQUO, SE_QUOT, SE_BSLS, SE_GRV,  DM_PLY2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* RAISE
    * ,-----------------------------------------------------------------------------------.
    * |   ,  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  .   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |  Up  | Right| XXXX |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | PgDn | PgUp | End  | Ins  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      | Play | Vol- | Vol+ | Next |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_planck_grid(
        SE_COMM, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_DOT,
        _______, GUI_F1,  ALT_F2,  SFT_F3,  CTL_F4,  KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
    ),

    /* FPS-LOWER
    * ,-----------------------------------------------------------------------------------.
    * |   1  |   2  |      |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | XXXX |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |   5  |      |      |      |      |      |      |      | 
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   9  |   8  |   7  |   6  |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |Modify|
    * `-----------------------------------------------------------------------------------'
    */
    [_FPSLOWER] = LAYOUT_planck_grid(
        KC_1,    KC_2,    _______, KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MODIFY,
        _______, _______, _______, _______, KC_5,    _______, _______, _______, _______, _______, _______, FAKE_ESC_TRIGGER,
        _______, KC_9,    KC_8,    KC_7,    KC_6,    KC_0,    _______, _______, _______, _______, _______, TOGGLE_EXCLUSIVITY,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* FUNCTION
    * ,-----------------------------------------------------------------------------------.
    * | SLEEP|  M4  |  M1  |  M2  |  M5  | XXXX | XXXX |  M4  |  M1  |  M2  |  M5  |MODIFY|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | PAUSE|  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |MLeft |MDown | MUp  |MRight| XXXX |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |DMREC1|  F19 |  F20 |  F21 |  F22 |  F23 |  F24 | XXXX | WH D | WH U | XXXX |DMREC2|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FUNCTION] = LAYOUT_planck_grid(
        KC_SLEP, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN5, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN5, MODIFY,
        KC_PAUS, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
        DM_REC1, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, DM_REC2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* MODIFY
    * ,-----------------------------------------------------------------------------------.
    * |RESET |      |      |      |      |      |      |CLMKDH|QWERTY|GAMING|      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_MODIFY] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLMK_DH, QWERTY,  GAMING,  XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

#include "common/keycode_functions.h"
#include "common/leader.h"
#include "common/per_key_config.h"

void custom_toggle_sound(bool state) {
    if (state) {
        PLAY_SONG(on_sound);
    }
    else {
        PLAY_SONG(off_sound);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _FUNCTION);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CLMK_DH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        case FAKE_ESC:
            if (record->event.pressed && !ignore_escape) {
                register_code(KC_ESC);
            } 
            else {
                unregister_code(KC_ESC);
            }
            return false;
        case FAKE_ESC_TRIGGER:
            if (record->event.pressed) {
                ignore_escape = !ignore_escape;
                custom_toggle_sound(ignore_escape);
            }
            return false;
        case TOGGLE_EXCLUSIVITY:
            if (record->event.pressed) {
                exclusivity_enabled = !exclusivity_enabled;
                custom_toggle_sound(exclusivity_enabled);
            }
            return false;
        case EXCL_A:
            if (record->event.pressed) {
                if (exclusivity_enabled && d_registered) {
                    unregister_code(KC_D);
                }
                a_down = true;
                register_code(KC_A);
                a_registered = true;
            } else {
                a_down = false;
                unregister_code(KC_A);
                a_registered = false;

                if (exclusivity_enabled && d_down) {
                    register_code(KC_D);
                    d_registered = true;
                }
            }
            return false;
        case EXCL_D:
            if (record->event.pressed) {
                if (exclusivity_enabled && a_registered) {
                    unregister_code(KC_A);
                }
                d_down = true;
                register_code(KC_D);
                d_registered = true;
            } else {
                d_down = false;
                unregister_code(KC_D);
                d_registered = false;

                if (exclusivity_enabled && a_down) {
                    register_code(KC_A);
                    a_registered = true;
                }
            }
            return false;
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}