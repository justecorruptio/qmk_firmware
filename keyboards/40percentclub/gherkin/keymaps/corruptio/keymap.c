#include QMK_KEYBOARD_H

#define RAISE LT(1, KC_SPC)
#define LOWER LT(2, KC_BSPC)
#define ADJUS LT(4, KC_DOT)

#define t(kc) LT(3, kc)
#define s(kc) S(kc)
#define c(kc) MT(MOD_LCTL,kc)
#define g(kc) MT(MOD_LGUI,kc)
#define a(kc) MT(MOD_LALT,kc)

enum custom_keycodes {
    FQUIT = SAFE_RANGE,
    SCRCAP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
 t(KC_Z), a(KC_X), g(KC_C), c(KC_V),   LOWER,   RAISE, c(KC_N), g(KC_M), a(KC_B), t(KC_DOT)
),

[1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3, KC_PIPE, _______, _______, _______,   KC_UP,  KC_TAB,  KC_ESC,
    KC_4,    KC_5,    KC_6, KC_BSLS, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN,
    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT
),

[2] = LAYOUT_ortho_3x10(
 KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  _______, KC_LPRN, KC_RPRN, KC_QUOT, KC_DQUO,
 KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_MINS,  _______, KC_LCBR, KC_RCBR, KC_QUES, KC_SCLN,
  KC_GRV, KC_TILD, KC_SLSH,  KC_EQL, _______,  _______, KC_LBRC, KC_RBRC,   KC_LT,   KC_GT
),

[3] = LAYOUT_ortho_3x10(
 s(KC_Q), s(KC_W), s(KC_E), s(KC_R), s(KC_T), s(KC_Y), s(KC_U), s(KC_I), s(KC_O), s(KC_P),
 s(KC_A), s(KC_S), s(KC_D), s(KC_F), s(KC_G), s(KC_H), s(KC_J), s(KC_K), s(KC_L), KC_UNDS,
 s(KC_Z), s(KC_X), s(KC_C), s(KC_V), _______, _______, s(KC_N), s(KC_M), s(KC_B), KC_COMM
),

[4] = LAYOUT_ortho_3x10(
   RESET, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_BRID, KC_BRIU,
   FQUIT,  SCRCAP, _______, _______, _______, _______, KC_MRWD, KC_VOLD, KC_MFFD, KC_MPLY,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, 1, 2, 4);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed)
    switch (keycode) {
        case FQUIT:
            tap_code16(A(G(KC_ESC)));
            break;
        case SCRCAP:
            tap_code16(G(S(KC_4)));
            break;
    }
    return true;
};
