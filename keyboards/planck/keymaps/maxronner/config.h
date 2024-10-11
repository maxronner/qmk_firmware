#pragma once

#define HOME_MODS
#define PREVENT_STUCK_MODIFIERS

// Fixes dual function key timings
#define TAPPING_FORCE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD

#define TAPPING_TERM 200

#ifdef LEADER_ENABLE
    #define LEADER_TIMEOUT 250
#endif

#ifdef MOUSEKEY_ENABLE
    #define MK_KINETIC_SPEED
    #define MOUSEKEY_INTERVAL 12
    #define MOUSEKEY_DELAY 12
    #define MOUSEKEY_MOVE_DELTA 4
    #define MOUSEKEY_INITIAL_SPEED 2
    #define MOUSEKEY_BASE_SPEED 1000
#endif

#ifdef AUDIO_ENABLE
    #define DEFAULT_LAYER_SONGS { SONG(COLEMAK_SOUND), \
                                  SONG(QWERTY_SOUND), \
                                  SONG(PLANCK_SOUND), \
                                }
    #define CUSTOM_TOGGLE_ON_SOUND E__NOTE(_A6), S__NOTE(_REST), Q__NOTE(_E7),
    #define CUSTOM_TOGGLE_OFF_SOUND E__NOTE(_E7), S__NOTE(_REST), Q__NOTE(_A6),
#endif

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD