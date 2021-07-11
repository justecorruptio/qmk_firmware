#include QMK_KEYBOARD_H
#include "matrix.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

//const uint16_t PROGMEM combos[] = { };

static int last_map = 0;
static int combo_map = 0;
static int shift = 0;

//static int page = 4;

void matrix_scan_user(void) {
  uint16_t map;
  uint8_t low, high;

  map =
    (!!(matrix_get_row(1) & 1) << 0) |
    (!!(matrix_get_row(1) & 2) << 1) |
    (!!(matrix_get_row(1) & 4) << 4) |
    (!!(matrix_get_row(0) & 1) << 2) |
    (!!(matrix_get_row(0) & 2) << 3) |
    (!!(matrix_get_row(0) & 4) << 5) ;


  if (map == 0b111111) {
    clear_keyboard();
    bootloader_jump();
  }
  else if (map > last_map) {
    combo_map |= map;
  }
  else if (map < last_map && combo_map) {
  //low = map & 0xf;
  //high = map & 0x30 >> 4;
    if (combo_map == 32 && !shift) {
        shift = 1;
    }
    else {
        if (shift == 1){
            register_code(KC_LSFT);
            tap_code(3 + combo_map);
            unregister_code(KC_LSFT);
        }
        else {
            tap_code(3 + combo_map);
        }
        shift = 0;
    }
    combo_map = 0;
  }

  last_map = map;
};
