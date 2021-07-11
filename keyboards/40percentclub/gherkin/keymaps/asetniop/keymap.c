#include QMK_KEYBOARD_H

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return false;
};

//#define C(x, y) case x: kc = (y); break;

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

    if (map > last_map) {
        combo_map |= map;
    }
    else if (map < last_map && combo_map) {
        a = (combo_map >> 8) & 1;
        b = (combo_map >> 9) & 1;
        c = (combo_map) & 0xff;
        v = combo_map;
        buff[0] = 0;

        if (!a && !b) {
            buff[0] =
        //   0123456789ABCDEF
            " aswexd tfc r  \t" //0
            "nqj y   b       " //1
            "izk ,   v       " //2
            "h               " //3
            "o(. -   g       " //4
            "u               " //5
            "l               " //6
            "                " //7
            "p?)             " //8
            "m               " //9
            "!               " //a
            "                " //b
            ";               " //c
            "                " //d
            "                " //e
            "\n               " //f
            [c];
            buff[1] = 0;
            if (buff[0] != ' ')
                send_string(buff);
        } else {
            switch(v) {
                case 0x100: tap_code(KC_BSPC); break;
                case 0x200: tap_code(KC_SPC); break;

                case 0x301: bootloader_jump(); break;
            }
        }
        combo_map = 0;
    }
    last_map = map;
}
