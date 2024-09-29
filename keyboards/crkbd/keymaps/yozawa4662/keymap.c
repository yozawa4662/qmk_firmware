#include QMK_KEYBOARD_H


//
// Layers
//
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2


//
// Tap dances
//
enum tap_dances {
  ESRE_DANCE
};

void dance_ESRE_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // Once ESC
    tap_code(KC_ESC);
  } else if (state->count == 2) {
    // Twice reset (not boot)
    soft_reset_keyboard();
  } else {
    // Or more...
    reset_keyboard();
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [ESRE_DANCE] = ACTION_TAP_DANCE_FN (dance_ESRE_finished)
};


//
// Custom modifiers
//
#define CTL_SPC CTL_T(KC_SPC)
#define CTL_ENT RCTL_T(KC_ENT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSL_LOW OSL(_LOWER)
#define OSL_RAI OSL(_RAISE)
#define TD_ESRE TD(ESRE_DANCE)


//
// Keymaps
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSM_SFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TD_ESRE,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OSM_GUI, OSL_LOW, CTL_SPC,    CTL_ENT, OSL_RAI, OSM_ALT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,    KC_0, KC_BSPC, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_GRV, KC_BSLS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};


//
// OLED
//
#ifdef SSD1306OLED

const char *read_layer_state(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
void set_timelog(void);
const char *read_timelog(void);
const char *read_pikatyu(void) {
  static const char PROGMEM logo[] ={
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
  };
  return logo;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_timelog(), false);
    oled_write_ln(read_keylog(), false);
  } else {
    oled_write_P(read_pikatyu(), false);
  }
  return false;
}

void oled_render_boot(bool bootloader) {
  oled_clear();
  if (bootloader) {
    oled_write_P(PSTR("Boot Reset"), false);
  } else {
    oled_write_P(PSTR("Soft Reset"), false);
  }
  oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
  oled_render_boot(jump_to_bootloader);
  return false;
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
    set_timelog();
#endif
  }
  return true;
}


//
// Tapping terms
//
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
  switch(keycode){
  case TD_ESRE:
    return 150;
  case CTL_ENT:
  case CTL_SPC:
    return 170;
  // normal: 80
  default:
    return TAPPING_TERM;
  }
}
