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
#define _ADJUST 3
#define _FFXIV 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,  Q,  W,  E,  R,  T,                   Y,  U,  I,  O,  P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   SPC,      ENT, RAISE, LALT \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB,  MUTE,  VOLD,  VOLU,  PGUP,  PGDN,                   LEFT,   DOWN,   UP, RIGHT,  HOME,   END,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   MINS,   EQL,  LCBR,  RCBR,  PIPE,   GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   UNDS,  PLUS,  LBRC,  RBRC,  BSLS,  TILD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_RST,  KC_LRST, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,                DF(_FFXIV),  KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_LTOG,  KC_LHUI,  KC_LSAI,  KC_LVAI, KC_XXXXX, KC_XXXXX,    KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_LMOD,  KC_LHUD,  KC_LSAD,  KC_LVAD, KC_XXXXX, KC_XXXXX,                  KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_GUIEI, KC_LOWER,   KC_SPC,      KC_ENT, KC_RAISE, KC_ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_FFXIV] = LAYOUT( \
  //,-----------------------------------------.                        ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                         KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,\
  //|------+------+------+------+------+------|                        |------+------+------+------+------+------|
     KC_ALT,KC_MINS, KC_Q,  KC_S,  KC_E,KC_EQL,                         KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,\
  //|------+------+------+------+------+------|                        |------+------+------+------+------+------|
     KC_SPC,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,                         KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,\
  //|------+------+------+------+------+------+--------------|  |------+------+------+------+------+------+------|
                                  KC_LSFT, KC_LCTL, KC_TAB,    DF(_QWERTY), KC_RAISE, KC_ALTKN \
                              //`----------------------------'  `--------------------'
  ),
  // _GW2
  // _TERA
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

const char *read_rgb_info(void);
//const char *read_mode_icon(bool swap);
//const char *read_host_led_state(void);
//void set_timelog(void);
//const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_rgb_info());
//    matrix_write_ln(matrix, read_keylogs());
//    matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
//    matrix_write_ln(matrix, read_host_led_state());
//    matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
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
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    //set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
