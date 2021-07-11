#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
enum planck_layers {_QWERTY, _LOWER, _RAISE, _LOL, _ADJUST};
enum planck_keycodes {QWERTY=SAFE_RANGE, LOL, FQUIT, SCRCAP};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define mS(kc) MT(MOD_LSFT,kc)
#define mC(kc) MT(MOD_LCTL,kc)
#define mG(kc) MT(MOD_LGUI,kc)
#define mA(kc) MT(MOD_LALT,kc)

#define l_BSPC  LT(LOWER, KC_BSPC)
#define r_SPC   LT(RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
       KC_Q,    KC_W,    KC_E,    KC_R,mA(KC_T), XXXXXXX, XXXXXXX,mA(KC_Y),    KC_U,    KC_I,    KC_O,    KC_P,
       KC_A,    KC_S,    KC_D,    KC_F,mG(KC_G), XXXXXXX, XXXXXXX,mG(KC_H),    KC_J,    KC_K,    KC_L,  KC_ENT,
   mS(KC_Z),    KC_X,    KC_C,    KC_V,mC(KC_B), XXXXXXX, XXXXXXX,mC(KC_N),    KC_M, KC_COMM,  KC_DOT,mS(KC_QUOT),
    XXXXXXX,  XXXXXXX, XXXXXXX, KC_ESC,  l_BSPC, XXXXXXX, XXXXXXX,   r_SPC,  KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_QUES, KC_CIRC,  KC_DLR, KC_LPRN, KC_RPRN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PLUS, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_ASTR, KC_SLSH, KC_BSLS, KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
       KC_1,    KC_2,    KC_3, KC_PIPE, XXXXXXX, _______, _______, KC_EXLM, KC_HASH,   KC_UP,   KC_AT, KC_SCLN,
       KC_4,    KC_5,    KC_6, KC_UNDS, XXXXXXX, _______, _______, KC_AMPR, KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN,
       KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, _______, _______, KC_TILD, KC_PERC,   KC_LT,   KC_GT,  KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOL] = LAYOUT_planck_grid(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_P,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R, XXXXXXX, XXXXXXX,    KC_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F, XXXXXXX, XXXXXXX,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX,  QWERTY,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,  KC_SPC, XXXXXXX, XXXXXXX,  KC_SPC, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX
),

[_ADJUST] = LAYOUT_planck_grid(
      RESET,  QWERTY,     LOL, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, _______,
      FQUIT,  SCRCAP, _______, _______, _______, _______, _______, KC_MPLY, KC_MRWD, KC_VOLD, KC_MFFD, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FQUIT: tap_code16(A(G(KC_ESC))); break;
        case SCRCAP: tap_code16(G(S(KC_4))); break;
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
