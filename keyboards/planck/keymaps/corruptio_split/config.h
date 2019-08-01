#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(Q__NOTE(_C5), Q__NOTE(_G5))
    #define GOODBYE_SONG SONG(Q__NOTE(_G5), Q__NOTE(_C5))

    #define DEFAULT_LAYER_SONGS { \
        SONG(Q__NOTE(_C5), Q__NOTE(_E5), Q__NOTE(_G5)), \
        SONG(Q__NOTE(_C5), Q__NOTE(_F5), Q__NOTE(_A5)), \
        SONG(Q__NOTE(_C5), Q__NOTE(_G5), Q__NOTE(_B5))  \
    }
#endif

#define NO_DEBUG
#define NO_PRINT

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

//#define TAPPING_TERM 300
//#define RETRO_TAPPING
