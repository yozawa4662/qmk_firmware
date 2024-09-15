#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
// #define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
  /* ADJUST, */
  /* BACKLIT, */
  /* RGBRST */
};

enum tap_dances {
  // once CLEAR, twice RESET
  CLRE_DANCE,
  // once i, twice *
  //ASTR_DANCE,
  // once -, twice _
  //MINS_DANCE,
  // once =, twice +
  //EQL_DANCE,
  // once \, twice |
  //BSLS_DANCE,
  // once ', twice "
  //QUOT_DANCE,
  // once ;, twice :
  //SCLN_DANCE,
  // once [, twice {, thrice (
  //LPRN_DANCE,
  // once ], twice }, thrice )
  //RPRN_DANCE
};

void dance_CLRE_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // clear Modifiers, Keys, Macros and Layers
    clear_keyboard();
    // clear OSM
    clear_oneshot_mods();
    // clear layer
    layer_clear();
  } else {
    reset_keyboard();
  }
}

// Double Tap Dance register
/* void dance_DP_register (qk_tap_dance_state_t *state, uint8_t dp1, uint8_t dp2, uint8_t single) { */
/*   if (state->count == 2) { */
/*     register_code(dp1); */
/*     register_code(dp2); */
/*   } else { */
/*     register_code(single); */
/*   } */
/* } */

// Double Tap Dance unregister
/* void dance_DP_unregister (qk_tap_dance_state_t *state, uint8_t dp1, uint8_t dp2, uint8_t single) { */
/*   if (state->count == 2) { */
/*     unregister_code(dp1); */
/*     unregister_code(dp2); */
/*   } else { */
/*     unregister_code(single); */
/*   } */
/* } */

// Double Tap finished
/* void dance_DP_finished (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(ASTR_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_8, KC_I); */
/*     break; */
/*   case TD(MINS_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_MINS, KC_MINS); */
/*     break; */
/*   case TD(EQL_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_EQL, KC_EQL); */
/*     break; */
/*   case TD(BSLS_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_BSLS, KC_BSLS); */
/*     break; */
/*   case TD(QUOT_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_QUOT, KC_QUOT); */
/*     break; */
/*   case TD(SCLN_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_SCLN, KC_SCLN); */
/*     break; */
/*   } */
/* } */

// Double Tap reset
/* void dance_DP_reset (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(ASTR_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_8, KC_I); */
/*     break; */
/*   case TD(MINS_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_MINS, KC_MINS); */
/*     break; */
/*   case TD(EQL_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_EQL, KC_EQL); */
/*     break; */
/*   case TD(BSLS_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_BSLS, KC_BSLS); */
/*     break; */
/*   case TD(QUOT_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_QUOT, KC_QUOT); */
/*     break; */
/*   case TD(SCLN_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_SCLN, KC_SCLN); */
/*     break; */
/*   } */
/* } */

/* void dance_PRN_tapped (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(LPRN_DANCE): */
/*     if (state->count == 1) { */
/*       // input [ during tapping */
/*       register_code(KC_LBRC); */
/*       unregister_code(KC_LBRC); */
/*     } */
/*     break; */
/*   case TD(RPRN_DANCE): */
/*     if (state->count == 1) { */
/*       // input ] during tapping */
/*       register_code(KC_RBRC); */
/*       unregister_code(KC_RBRC); */
/*     } */
/*     break; */
/*   } */
/* } */

/* void dance_PRN_finished (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(LPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       // delete [ and input { */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_LBRC); */
/*     } else if (state->count % 3 == 0) { */
/*       // delete [ and input ( */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_9); */
/*     } */
/*     break; */
/*   case TD(RPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       // delete ] and input } */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_RBRC); */
/*     } else if (state->count % 3 == 0) { */
/*       // delete ] and input ) */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_0); */
/*     } */
/*     break; */
/*   } */
/* } */

/* void dance_PRN_reset (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(LPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_LBRC); */
/*     } else if(state->count % 3 == 0) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_9); */
/*     } */
/*     break; */
/*   case TD(RPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_RBRC); */
/*     } else if (state->count % 3 == 0) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_0); */
/*     } */
/*     break; */
/*   } */
/* } */

// rarely taps TD
//#define RARELY_TD_TIME 120
// sometimes taps TD
//#define SOMETIMES_TD_TIME 140
// often taps TD
//#define OFTEN_TD_TIME 170
// usually taps TD
#define USUALLY_TD_TIME 200
// triple tap dance
//#define TRIPLE_TD_TIME 160

// All tap dance functions would go here. Only showing this one.
tap_dance_action_t tap_dance_actions[] = {
  // double
  [CLRE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_CLRE_finished, NULL)
  //[CLRE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_CLRE_finished, NULL, USUALLY_TD_TIME)
  /* [ASTR_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, RARELY_TD_TIME), */
  /* [MINS_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */
  /* [EQL_DANCE]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */
  /* [BSLS_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, OFTEN_TD_TIME), */
  /* [QUOT_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */
  /* [SCLN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */
  // triple
  /* [LPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset, TRIPLE_TD_TIME), */
  /* [RPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset, TRIPLE_TD_TIME) */
};


// double
// #define SFT_SPC SFT_T(KC_SPC)
// #define SFT_ENT SFT_T(KC_ENT)
#define CTL_SPC CTL_T(KC_SPC)
#define CTL_ENT RCTL_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
// #define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSL_LOW OSL(_LOWER)
#define OSL_RAI OSL(_RAISE)
// #define OSL_QWE OSL(_QWERTY)
#define TD_CLRE TD(CLRE_DANCE)
/* #define TD_ASTR TD(ASTR_DANCE) */
/* #define TD_MINS TD(MINS_DANCE) */
/* #define TD_EQL  TD(EQL_DANCE) */
/* #define TD_BSLS TD(BSLS_DANCE) */
/* #define TD_QUOT TD(QUOT_DANCE) */
/* #define TD_SCLN TD(SCLN_DANCE) */
/* #define TD_LEFT TD(LEFT_DANCE) */
/* #define TD_DOWN TD(DOWN_DANCE) */
/* #define TD_UP   TD(UP_DANCE) */
/* #define TD_RGHT TD(RGHT_DANCE) */

// triple
/* #define TD_LPRN TD(LPRN_DANCE) */
/* #define TD_RPRN TD(RPRN_DANCE) */

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

  /* [_ADJUST] = LAYOUT( \ */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*       RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\ */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\ */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\ */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LGUI,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RALT \ */
  /*                                     //`--------------------------'  `--------------------------' */
  /* ) */
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
/* void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) { */
/*   if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) { */
/*     layer_on(layer3); */
/*   } else { */
/*     layer_off(layer3); */
/*   } */
/* } */

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
//const char *read_keylogs(void);

//const char *read_mode_icon(bool swap);
//const char *read_host_led_state(void);
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
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_timelog());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
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
    /* case LOWER: */
    /*   if (record->event.pressed) { */
    /*     layer_on(_LOWER); */
    /*     //update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } else { */
    /*     layer_off(_LOWER); */
    /*     //update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } */
    /*   return false; */
    /* case RAISE: */
    /*   // RAISE pressed and layer != RAISE, then change RAISE layer */
    /*   if (record->event.pressed) { */
    /*     layer_on(_RAISE); */
    /*     //update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } else { */
    /*     layer_off(_RAISE); */
    /*     //update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } */
    /*   return false; */
    /* case ADJUST: */
    /*     if (record->event.pressed) { */
    /*       layer_on(_ADJUST); */
    /*     } else { */
    /*       layer_off(_ADJUST); */
    /*     } */
    /*     return false; */
    /* case RGB_MOD: */
    /*   #ifdef RGBLIGHT_ENABLE */
    /*     if (record->event.pressed) { */
    /*       rgblight_mode(RGB_current_mode); */
    /*       rgblight_step(); */
    /*       RGB_current_mode = rgblight_config.mode; */
    /*     } */
    /*   #endif */
    /*   return false; */
    /* case RGBRST: */
    /*   #ifdef RGBLIGHT_ENABLE */
    /*     if (record->event.pressed) { */
    /*       eeconfig_update_rgblight_default(); */
    /*       rgblight_enable(); */
    /*       RGB_current_mode = rgblight_config.mode; */
    /*     } */
    /*   #endif */
    /*   break; */
  }
  return true;
}

// TAPPING_TERM for each keycode
// Tap Dances settings are in tap_dance_actions[]
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
  switch(keycode){
//case SFT_SPC:
//case SFT_ENT:
  case TD_CLRE:
    return USUALLY_TD_TIME;
  case CTL_ENT:
  case CTL_SPC:
    return 170;
  case CTL_ESC:
    return 120;
  // 通常キーは80
  default:
    return TAPPING_TERM;
  }
}
