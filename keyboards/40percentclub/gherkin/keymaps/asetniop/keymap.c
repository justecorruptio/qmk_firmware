#include QMK_KEYBOARD_H
#include <string.h>

#define RAISE LT(1, KC_SPC)
#define LOWER LT(2, KC_BSPC)
#define K(x) (SAFE_RANGE + (x))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ortho_3x10(
    K(0),    K(1),    K(2),    K(3), _______, _______,    K(4),    K(5),    K(6),    K(7),
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______,    K(8),    K(9), _______, _______, _______, _______
)

};

static int last_map = 0;
static int combo_map = 0;
static uint16_t timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return false;
};

#define XS(x,y) case 0x ## x: ptr = (y); break;
#define XP(x,y) case 0x ## x: ptr = (y " "); break;

#define TTL 100

void upper(char* ptr) {
    //for(;*ptr;ptr++)
        if (*ptr >= 'a' && *ptr <= 'z') *ptr += 'A' - 'a';
}

void matrix_scan_user(void) {
    uint16_t map;
    map = ((matrix_get_row(4) & 0x20) >> 5 << 0) |
          ((matrix_get_row(4) & 0x10) >> 4 << 1) |
          ((matrix_get_row(4) & 0x08) >> 3 << 2) |
          ((matrix_get_row(4) & 0x04) >> 2 << 3) |
          ((matrix_get_row(3) & 0x20) >> 5 << 4) |
          ((matrix_get_row(3) & 0x10) >> 4 << 5) |
          ((matrix_get_row(3) & 0x08) >> 3 << 6) |
          ((matrix_get_row(3) & 0x04) >> 2 << 7) |
          ((matrix_get_row(0) & 0x20) >> 5 << 8) |
          ((matrix_get_row(0) & 0x10) >> 4 << 9) ;


    uint8_t a, b, c;
    uint16_t v;
    char buff[16];
    char* ptr = 0;

    uint16_t elapsed = timer_elapsed(timer);

    if (map > last_map && (elapsed < TTL || timer == 0)) {
        combo_map |= map;
        timer = timer_read();
    }
    else if ((map < last_map || elapsed >= TTL) && combo_map) {
        a = (combo_map >> 8) & 1;
        b = (combo_map >> 9) & 1;
        c = (combo_map) & 0xff;
        v = combo_map;
        buff[0] = 0;

        switch(v) {
        case 0x100: tap_code(KC_BSPC); break;

        case 0x200: tap_code(KC_SPC); break;
        case 0x210: tap_code(KC_ESC); break;
        case 0x240: tap_code(KC_TAB); break;
        case 0x280: tap_code(KC_ENT); break;

        case 0x3ff: bootloader_jump(); break;

        default:
            if (!b) {
                switch(c) {
                    XS(01,"a");XS(02,"s");XS(03,"w");XS(04,"e");XS(05,"x");XS(06,"d");
                    XS(08,"t");XS(09,"f");XS(0A,"c");XS(0C,"r");

                    XS(10,"n");XS(11,"q");XS(12,"j");XS(14,"y");XS(18,"b");
                    XS(20,"i");XS(21,"z");XS(22,"k");XS(24,",");XS(28,"v");
                    XS(30,"h");
                    XS(40,"o");XS(41,"(");XS(42,".");XS(44,"'");XS(48,"g");
                    XS(50,"u");
                    XS(60,"l");
                    XS(80,"p");XS(81,"?");XS(82,")");XS(84,"\"");XS(88,":");
                    XS(90,"m");
                    XS(A0,"!");
                    XS(C0,";");

                    XS(38,"th");
                    XS(51,"qu");
                    XS(70,"ing");
                }
            } else {
                switch(c) {
                    XP(01,"a");
                    XP(07,"we");
                    XP(0B,"what");
                    XP(0C,"are");
                    XP(0F,"were");
                    XP(11,"an");
                    XP(14,"any");
                    XP(16,"and");
                    XP(18,"be");
                    XP(20,"i");
                    XP(22,"is");
                    XP(28,"it");
                    XP(30,"in");
                    XP(38,"the");
                    XP(39,"that");
                    XP(3A,"this");
                    XP(3f,"with");
                    XP(48,"to");
                    XP(50,"on");
                }
            }
            if (ptr) {
                strcpy(buff, ptr);
                if (a) upper(buff);
                send_string(buff);
            }
        }
        combo_map = 0;
        timer = 0;
    }
    last_map = map;
}
