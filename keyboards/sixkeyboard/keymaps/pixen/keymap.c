#include QMK_KEYBOARD_H
#include "matrix.h"

enum custom_keycodes {
    PEN = SAFE_RANGE,
    SELECT,
    DUP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    DUP, SELECT, PEN,
    G(KC_E), S(G(KC_Z)), G(KC_Z)
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PEN: if (record->event.pressed) {
        SEND_STRING(SS_LGUI("a"));
        SEND_STRING("pE");
    }
    break;
    case SELECT: if (record->event.pressed) {
        SEND_STRING(SS_LGUI("d"));
        SEND_STRING("sM");
    }
    break;
    case DUP: if (record->event.pressed) {
        SEND_STRING(SS_LGUI("cv"));
        SEND_STRING("\n");
    }
    break;
  }
  return true;
};
