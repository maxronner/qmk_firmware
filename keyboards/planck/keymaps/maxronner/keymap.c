#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum planck_layers {
  _COLEMAK_DH,
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _MODIFY
};

enum planck_keycodes {
    CLMK_DH = SAFE_RANGE,
    QWERTY
};

#include "common/tapdance.h"

// Layers
#define LOWER   LT(_LOWER, KC_ENT)
#define RAISE   LT(_RAISE, KC_DEL)
#define MODIFY  OSL(_MODIFY)

#define COPY  LCTL(KC_C)
#define CUT   LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define UNDO  LCTL(KC_Z)
#define REDO  LCTL(KC_Y)

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

#define GUI_F1  LGUI_T(KC_F1)
#define ALT_F2  LALT_T(KC_F2)
#define SFT_F3  LSFT_T(KC_F3)
#define CTL_F4  LCTL_T(KC_F4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak DH
    * ,-----------------------------------------------------------------------------------.
    * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   Å  |  Ä   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  Ö   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Shift |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   ;  |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LEAD | Ctrl | Alt  | GUI  |Lower |SPACE | BSPC |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_COLEMAK_DH] = LAYOUT_planck_grid(
        TD_ESC,        KC_Q,     KC_W,     KC_F,     KC_P,   KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    SE_ARNG, SE_ADIA,
        C_S_T(KC_TAB), HOME_A,   HOME_R,   HOME_S,   HOME_T, KC_G,    KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  SE_ODIA,
        KC_LSPO,       KC_Z,     KC_X,     KC_C,     KC_D,   KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  SE_SCLN, KC_RSPC,
        KC_LEAD,       KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,  KC_SPC,  TD_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ä  |  Ö   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ;  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SE_ADIA, SE_ODIA,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    SE_COMM, SE_DOT,  SE_SCLN, KC_RSFT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* LOWER
    * ,-----------------------------------------------------------------------------------.
    * |      |      |   |  |   [  |   ]  |      |      |   <  |   >  |   @  |   %  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   #  |   /  |   {  |   }  |   !  |   ?  |   -  |   +  |   *  |   &  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   ~  |   _  |   :  |   =  |   ^  |   $  |   "  |   '  |   \  |   `  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      | Home | PgDn | PgUp | End  |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_planck_grid(
        _______, XXXXXXX, SE_PIPE, SE_LBRC, SE_RBRC, XXXXXXX, XXXXXXX, SE_LABK, SE_RABK, SE_AT,   SE_PERC, XXXXXXX,
        _______, SE_HASH, SE_SLSH, SE_LCBR, SE_RCBR, SE_EXLM, SE_QUES, SE_MINS, SE_PLUS, SE_ASTR, SE_AMPR, XXXXXXX,
        _______, SE_TILD, SE_UNDS, SE_COLN, SE_EQL,  SE_CIRC, SE_DLR,  SE_DQUO, SE_QUOT, SE_BSLS, SE_GRV,  _______ ,
        _______, _______, _______, _______, _______, _______, KC_BSPC, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    /* RAISE
    * ,-----------------------------------------------------------------------------------.
    * |   ,  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  .   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |  Up  | Right| Ctrl |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | PgDn | PgUp | End  | Ins  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      | Play | Vol- | Vol+ | Next |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_planck_grid(
        SE_COMM, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_DOT,
        _______, GUI_F1,  ALT_F2,  SFT_F3,  CTL_F4,  KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
    ),

    /* FUNCTION
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |  M4  |  M1  |  M2  |  M5  |MODIFY|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |  Ins |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 | Left | Down |  Up  | Right|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |      | WH D | WH U |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FUNCTION] = LAYOUT_planck_grid(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN5, MODIFY,
        KC_INS,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
        _______, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* MODIFY
    * ,-----------------------------------------------------------------------------------.
    * |RESET |      |      |      |      |      |      |CLMKDH|QWERTY|      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_MODIFY] = LAYOUT_planck_grid(
        QK_RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLMK_DH, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

#include "common/keycode_functions.h"
#include "common/leader.h"
#include "common/per_key_config.h"


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
    }
  return true;
}
