#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
enum planck_layers {_QWERTY, _LOWER, _RAISE, _LOL, _GAME, _ADJUST};
enum planck_keycodes {QWERTY=SAFE_RANGE, LOL, GAME};

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
    _______, KC_LPRN, KC_QUES, KC_RPRN, KC_LALT, _______, _______, _______,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, KC_LCBR, KC_BSLS, KC_RCBR, KC_LGUI, _______, _______, _______,    KC_4,    KC_5,    KC_6, _______,
    KC_LSFT, KC_LBRC, KC_SLSH, KC_RBRC, KC_LCTL, _______, _______, _______,    KC_1,    KC_2,    KC_3, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, _______, KC_LALT, KC_PGUP,   KC_UP, KC_PGDN, _______,
    KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_MINS, _______, _______, KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN,
     KC_GRV, KC_TILD, KC_SLSH,  KC_EQL, KC_PLUS, _______, _______, KC_LCTL, _______, _______, _______, KC_SCLN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOL] = LAYOUT_planck_grid(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4, XXXXXXX, XXXXXXX,  QWERTY, XXXXXXX, XXXXXXX, XXXXXXX,    KC_P,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R, XXXXXXX, XXXXXXX,    KC_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F, XXXXXXX, XXXXXXX,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,  KC_SPC, XXXXXXX, XXXXXXX,  KC_SPC, KC_LGUI, XXXXXXX, XXXXXXX,  QWERTY
),

[_GAME] = LAYOUT_planck_grid(
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R, XXXXXXX, XXXXXXX,  QWERTY, XXXXXXX, XXXXXXX, XXXXXXX,    KC_P,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F, XXXXXXX, XXXXXXX,    KC_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V, XXXXXXX, XXXXXXX,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,  KC_SPC, XXXXXXX, XXXXXXX,  KC_SPC, KC_LGUI, XXXXXXX, XXXXXXX,  QWERTY
),

[_ADJUST] = LAYOUT_planck_grid(
      RESET, _______, _______, _______,    GAME, _______, _______,  QWERTY,     LOL, KC_VOLU, _______, _______,
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
        case GAME:
            if (record->event.pressed)
                set_single_persistent_default_layer(_GAME);
            return false;
  }
  return true;
}
