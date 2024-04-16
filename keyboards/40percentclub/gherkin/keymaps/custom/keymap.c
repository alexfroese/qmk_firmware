#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define CTL_Z LCTL_T(KC_Z)
#define ALT_X LALT_T(KC_X)
#define FN3_C LT(3, KC_C)
#define FN4_V LT(4, KC_V)
#define FN2_BSPC LT(2, KC_BSPC)
#define FN1_SPC LT(1, KC_SPC)
#define FN5_B LT(5, KC_B)
#define ALT_N RALT_T(KC_N)
#define CTL_M RCTL_T(KC_M)
#define SHFT_ENT LSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,
    KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_ESC,
    CTL_Z,  ALT_X,  FN3_C,  FN4_V,  FN2_BSPC, FN1_SPC, FN5_B,  ALT_N,  CTL_M,  SHFT_ENT
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_F1, KC_F2, KC_F3, KC_F4, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
    KC_F5, KC_F6, KC_F7, KC_F8, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_GRV,
    KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, _______, _______, _______, _______, _______
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, _______, _______, KC_7, KC_8, KC_9, _______,
    KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,_______, KC_NLCK, KC_4, KC_5, KC_6, KC_GRV,
    KC_LPRN, KC_RPRN, KC_MINS, KC_EQL, _______, KC_0, KC_1, KC_2, KC_3, _______
  ),

  [3] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TAB, _______, _______, _______, _______, KC_COMM, KC_DOT, KC_SLSH, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [4] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TAB, _______, _______, _______, _______, KC_LT, KC_GT, KC_QUES, KC_COLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [5] = LAYOUT_ortho_3x10(
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
    KC_TAB, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_L), _______,
    KC_LGUI, _______, _______, LSFT(KC_INS), _______, _______, _______, _______, LGUI(KC_UP), LSFT(KC_ENT)
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  keyevent_t event = record->event;
    (void)event;

  switch (id) {

  }
  return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 0); PORTB &= ~(1 << 0);
  } else {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
