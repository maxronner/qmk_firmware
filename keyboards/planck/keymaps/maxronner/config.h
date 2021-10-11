#pragma once

// Space Cadet for Swedish layout
#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8 
#define RSPC_KEYS KC_RSFT, KC_RSFT, KC_9 

// Home row modifiers
#define HOME_MODS

// Probably not necessary
#define PREVENT_STUCK_MODIFIERS

// Fixes dual function key timings
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD

#define TAPPING_TERM 200

#ifdef LEADER_ENABLE
    #define LEADER_TIMEOUT 250
    #define LEADER_PER_KEY_TIMING
#endif

#ifdef MOUSEKEY_ENABLE
    #define MK_KINETIC_SPEED
    #define MOUSEKEY_INTERVAL 12
    #define MOUSEKEY_DELAY 12
    #define MOUSEKEY_MOVE_DELTA 4
    #define MOUSEKEY_INITIAL_SPEED 2
    #define MOUSEKEY_BASE_SPEED 1000
#endif

#ifdef AUTO_SHIFT_ENABLE
    #define AUTO_SHIFT_NO_AUTO_REPEAT
    #define AUTO_SHIFT_TIMEOUT 125
    #define NO_AUTO_SHIFT_SPECIAL
#endif

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(NO_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                }
#endif