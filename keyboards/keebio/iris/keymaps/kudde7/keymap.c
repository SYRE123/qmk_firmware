#include QMK_KEYBOARD_H
#include "keymap_nordic.h"
#include "action_layer.h"

enum {
  TD_QIT,
  TD_MIN,
};

enum combos {
  COMBO1,
  COMBO2,
  COMBO3,
  COMBO4,
  COMBO5,
  COMBO6,
  COMBO7,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  ADJUST,
  FL_MAIL,
  WIN_LOGIN,
};

#define KC_TD1 TD(TD_QIT)
#define KC_TD2 TD(TD_MIN)
#define KC_MOU LT(_MOUSE, KC_BSPC)

//Emojis
#define KC_EM1 LCTL(KC_P0)
#define KC_EM2 (KC_P9)
#define KC_EM3 (KC_P5)
#define KC_EM4 LCTL(KC_P1)
#define KC_EM5 (KC_P4)
#define KC_EM6 LCTL(KC_P2)
#define KC_EM7 LCTL(KC_P5)
#define KC_EM8 LCTL(KC_P4)
#define KC_EM9 (KC_P6)
#define KC_EM10 LCTL(KC_P3)
#define KC_EM11 (KC_P0)
#define KC_EM12 (KC_P1)
#define KC_EM13 (KC_P8)
#define KC_EM14 (KC_P7)
#define KC_EM15 (KC_P2)
#define KC_EM16 (KC_P3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,          KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, LOWER,   KC_MOU,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6,                             KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT, _______, KC_WH_U, KC_UP   , KC_WH_D, KC_PGUP,                            _______,   KC_7 ,  KC_8  ,  KC_9  , KC_BSLS, KC_UNDS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                            _______,  KC_4  ,  KC_5  ,  KC_6  , KC_PPLS, KC_PMNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______,   KC_1  ,  KC_2  ,  KC_3  , KC_PAST, KC_PSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    _______,  _______, KC_0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, _______, _______, _______, _______, _______,                            _______, _______, _______, RGB_RMOD, RGB_MOD, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RGB_SAD , RGB_SAI, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RGB_VAD , RGB_VAI, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RGB_SPD , RGB_SPI, _______, _______, _______, _______,          QK_BOOT, _______, _______, _______, _______, _______, WIN_LOGIN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, FL_MAIL, _______, _______,                            _______, _______, _______, _______, KC_UNDS, LCTL(KC_BSPC),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_HOME, KC_END, KC_MS_U, KC_BTN1, KC_WH_U,                            KC_EM1 , KC_EM2 , KC_EM3 , KC_EM4 , KC_EM5 , KC_EM6 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                           KC_EM9 , KC_EM10, KC_EM11, KC_EM12, KC_EM13, KC_EM14,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_EM15, KC_EM16, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, NK_TOGG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, CM_ON,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, CM_OFF,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

const uint16_t PROGMEM miniMize_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copyCopy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM pastePaste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM markAll_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM ctlBspc_combo[] = {KC_RBRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM flStudio_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM winBrave_combo[] = {KC_F, KC_G, COMBO_END};

combo_t key_combos[] = {
  [COMBO1] = COMBO(miniMize_combo, RALT(KC_X)),
  [COMBO2] = COMBO(copyCopy_combo, LCTL(KC_C)),
  [COMBO3] = COMBO(pastePaste_combo, LCTL(KC_V)),
  [COMBO4] = COMBO(markAll_combo, LCTL(KC_A)),
  [COMBO5] = COMBO(ctlBspc_combo, LCTL(KC_BSPC)),
  [COMBO6] = COMBO(flStudio_combo, LSFT(KC_F13)),
  [COMBO7] = COMBO(winBrave_combo, LGUI(KC_2)),
};


tap_dance_action_t tap_dance_actions[] = {
  //Tap once for change track, twice for play
  [TD_QIT]  = ACTION_TAP_DANCE_DOUBLE(KC_END, LALT(KC_F4)),
  [TD_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_Z)),
// Other declarations would go here, separated by commas, if you have them

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
  }
  return true;

  if (record->event.pressed) {
        switch(keycode){
          case FL_MAIL:
              SEND_STRING("malmsten.marcus"SS_DOWN(X_RALT)"2"SS_UP(X_RALT)"gmail.com");
              return false; break;
          case WIN_LOGIN:
              SEND_STRING("5155");
              return false; break;
        }
      }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    HSV hsv = {HSV_RED};
                        hsv.v = rgb_matrix_config.hsv.v;
                            RGB rgb = hsv_to_rgb(hsv);
                                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                }
            }
        }
    }
    return false;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F19, KC_F20), ENCODER_CCW_CW(_______, _______) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F19, KC_F20), ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F19, KC_F20), ENCODER_CCW_CW(_______, _______) },
};
#endif
