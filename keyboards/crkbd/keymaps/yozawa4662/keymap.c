#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

enum tap_dances {
  CLRE_DANCE
};

void dance_CLRE_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    soft_reset_keyboard();
  } else {
    reset_keyboard();
  }
}

// All tap dance functions would go here. Only showing this one.
tap_dance_action_t tap_dance_actions[] = {
  // double
  [CLRE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_CLRE_finished, NULL)
};


// modifiers
#define CTL_SPC CTL_T(KC_SPC)
#define CTL_ENT RCTL_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSL_LOW OSL(_LOWER)
#define OSL_RAI OSL(_RAISE)
#define TD_CLRE TD(CLRE_DANCE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSM_SFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TD_CLRE,\
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

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef OLED_DRIVER_ENABLE
  iota_gfx_init(!has_usb());   // turns on the display
#endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef OLED_DRIVER_ENABLE

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
void set_timelog(void);
const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

const char *read_pikatyu(void) {
  static char logo[] =
    {
     0x80, 0x81, 0x82, 0x83, 0x84, 0x80, 0x81, 0x82, 0x83, 0x84, 0x80, 0x81, 0x82, 0x83, 0x84, 0x80, 0x81, 0x82, 0x83, 0x84, 0x20,
     0x85, 0x86, 0x87, 0x88, 0x89, 0x85, 0x86, 0x87, 0x88, 0x89, 0x85, 0x86, 0x87, 0x88, 0x89, 0x85, 0x86, 0x87, 0x88, 0x89, 0x20,
     0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x20,
     0x8f, 0x90, 0x91, 0x92, 0x93, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x20
    };
  return logo;
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_timelog());
    matrix_write_ln(matrix, read_keylog());
  }
  /* else { */
  /*   matrix_write(matrix, read_pikatyu()); */
  /* } */
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
    set_timelog();
#endif
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
  }
  return true;
}

// TAPPING_TERM for each keycode
// Tap Dances settings are in tap_dance_actions[]
#define USUALLY_TD_TIME 200
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
  switch(keycode){
  case TD_CLRE:
    return USUALLY_TD_TIME;
  case CTL_ENT:
  case CTL_SPC:
    return 170;
  case CTL_ESC:
    return 120;
  // normal: 80
  default:
    return TAPPING_TERM;
  }
}
