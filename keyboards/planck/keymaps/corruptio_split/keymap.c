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
  LOL
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define mS(kc) MT(MOD_LSFT,kc)
#define mC(kc) MT(MOD_LCTL,kc)
#define mG(kc) MT(MOD_LGUI,kc)
#define mA(kc) MT(MOD_LALT,kc)


//#define l_ESC  LT(LOWER, KC_ESC)
#define l_BSPC  LT(LOWER, KC_BSPC)
//#define l_TAB  LT(LOWER, KC_TAB)

//#define r_TAB  LT(RAISE, KC_TAB)
#define r_SPC  LT(RAISE, KC_SPC)
//#define r_ENT  LT(RAISE, KC_ENT)

[_QWERTY] = LAYOUT_planck_grid(
   mC(KC_Q),mG(KC_W),mA(KC_E),    KC_R,    KC_T, XXXXXXX, XXXXXXX,    KC_Y,    KC_U,mA(KC_I),mG(KC_O),mC(KC_P),
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G, XXXXXXX, XXXXXXX,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
   mS(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT,mS(KC_QUOT),
    XXXXXXX,  XXXXXXX, XXXXXXX, KC_ESC,  l_BSPC,  KC_TAB,   KC_NO,   r_SPC,  KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOL] = LAYOUT_planck_grid(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_P,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R, XXXXXXX, XXXXXXX,    KC_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F, XXXXXXX, XXXXXXX,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,   RAISE,  KC_SPC,  KC_SPC,   LOWER, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
    _______, KC_LPRN, _______, KC_RPRN, _______, _______, _______, _______,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, KC_LCBR, KC_BSLS, KC_RCBR, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6, KC_QUES,
    _______, KC_LBRC, KC_SLSH, KC_RBRC, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, XXXXXXX, XXXXXXX, _______, _______,   KC_UP, _______, _______,
    KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_MINS, XXXXXXX, XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
     KC_GRV, KC_TILD, KC_SLSH,  KC_EQL, KC_PLUS, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
      RESET, _______, _______, _______, _______, _______, _______,  QWERTY,     LOL, KC_VOLU, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MRWD, KC_VOLD, KC_MFFD, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______,
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
