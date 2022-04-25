#pragma once

#define HOME_MODS
#define PREVENT_STUCK_MODIFIERS

// Fixes dual function key timings
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
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
    #define STARTUP_SONG SONG(MARIO_MUSHROOM)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                }
#endif