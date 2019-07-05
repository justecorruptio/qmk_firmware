#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOL,
  _LOWER,
  _RAISE,
  _EXTRA,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOL
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRA MO(_EXTRA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP, KC_QUOT,
    KC_LCTL, KC_LGUI, KC_LALT,   EXTRA,   LOWER,  KC_SPC,  KC_SPC,   RAISE, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

[_LOL] = LAYOUT_planck_grid(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_P, XXXXXXX,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LALT,   LOWER,  KC_SPC,  KC_SPC,   RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_TILD, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_HOME, KC_PGDN,  KC_END
),

[_RAISE] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
     KC_GRV, _______, _______, _______, _______, _______, _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, KC_VOLU, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MRWD, KC_VOLD, KC_MFFD
),

[_EXTRA] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6, _______,  KC_ENT,
    _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_0,  KC_DOT, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______,   RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  QWERTY, _______,     LOL, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed)
                set_single_persistent_default_layer(_QWERTY);
            return false;
        case LOL:
            if (record->event.pressed)
                set_single_persistent_default_layer(_LOL);
            return false;
  }
  return true;
}
