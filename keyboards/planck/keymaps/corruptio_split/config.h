#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)

    #define DEFAULT_LAYER_SONGS { \
        SONG(QWERTY_SOUND), \
        SONG(COLEMAK_SOUND) \
    }
#endif

#define NO_DEBUG
#define NO_PRINT

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define TAPPING_TERM 300
//#define RETRO_TAPPING
