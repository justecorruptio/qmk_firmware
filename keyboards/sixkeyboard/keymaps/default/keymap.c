#include QMK_KEYBOARD_H
#include "matrix.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

//const uint16_t PROGMEM combos[] = { };

static int last_map = 0;
static int combo_map = 0;
static int shift = 0;

void matrix_scan_user(void) {
  // jump to bootloaer when all keys are pressed
  uint16_t map;

  //map = matrix_get_row(0) << 3 | matrix_get_row(1);
  map =
    ((matrix_get_row(1) & 1) << 2) |
    ((matrix_get_row(1) & 2) << 0) |
    ((matrix_get_row(1) & 4) >> 2) |
    ((matrix_get_row(0) & 1) << 5) |
    ((matrix_get_row(0) & 2) << 3) |
    ((matrix_get_row(0) & 4) << 1) ;

  if (map == 0b111111) {
    clear_keyboard();
    bootloader_jump();
  }
  else if (map > last_map) {
    combo_map |= map;
    //tap_code16(KC_Z);
  }
  else if (map < last_map && combo_map) {
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
