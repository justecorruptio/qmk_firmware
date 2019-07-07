#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOL,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOL,
  LGUI,
  RGUI,
  ARUP, ARDN, ARLT, ARRT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP, KC_QUOT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_BSLS,   RAISE,  KC_SPC,  KC_SPC,   LOWER, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

[_LOL] = LAYOUT_planck_grid(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_P, XXXXXXX,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LALT,   RAISE,  KC_SPC,  KC_SPC,   LOWER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, _______, _______, _______, _______,    ARUP,    ARDN, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______,    ARLT,    ARRT, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,    LGUI,    RGUI, KC_TILD
),

[_RAISE] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6, _______,  KC_ENT,
    _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______,   RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  QWERTY, _______,     LOL, KC_MUTE, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MRWD, KC_VOLD, KC_MFFD
)

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define PRESSED_SEND_STRING(kc, str) \
    kc: \
        if (record->event.pressed) \
            SEND_STRING(str); \
        return false; \

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
        case PRESSED_SEND_STRING(LGUI, SS_LALT("00AB"));
        case PRESSED_SEND_STRING(RGUI, SS_LALT("00BB"));

        case PRESSED_SEND_STRING(ARUP, SS_LALT("2191"));
        case PRESSED_SEND_STRING(ARDN, SS_LALT("2193"));
        case PRESSED_SEND_STRING(ARLT, SS_LALT("2190"));
        case PRESSED_SEND_STRING(ARRT, SS_LALT("2192"));
  }
  return true;
}
