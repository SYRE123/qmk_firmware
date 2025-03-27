#include QMK_KEYBOARD_H
#include "keymap_nordic.h"
#include "action_layer.h"

enum {
  TD_QIT,
  TD_MIN,
  TD_EMO,
};

enum combos {
  COMBO1,
  COMBO2,
  COMBO3,
  COMBO4,
  COMBO5,
  COMBO6,
  COMBO7,
  COMBO8,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

enum custom_keycodes {
    FL_MAIL = SAFE_RANGE,
    WIN_LOGIN,
};

//Tapdance
#define KC_TD1 TD(TD_QIT)
#define KC_TD2 TD(TD_MIN)
#define KC_TD3 TD(TD_EMO)

//Windows
#define KC_WN1 LGUI(KC_1)
#define KC_WN2 LGUI(KC_2)
#define KC_WN3 LGUI(KC_3)
#define KC_WN4 LGUI(KC_4)
#define KC_WN5 LGUI(KC_5)
#define KC_WN6 LGUI(KC_6)
#define KC_WN7 LGUI(KC_7)
#define KC_WN8 LGUI(KC_8)
#define KC_WN9 LGUI(KC_9)



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
  [0] = LAYOUT_80(  
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME,  KC_F18,
    KC_TD3,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, _______,  KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    KC_RSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,   KC_END,
    KC_LCTL, KC_LGUI, KC_LALT, MO(1),   _______,  LT(2, KC_SPC), _______,           KC_SPC,  KC_RALT, KC_RCTL, MO(3), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80(
    EE_CLR, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, FL_MAIL, _______, _______, _______,    KC_7,    KC_8,    KC_9, _______, _______, _______,  _______, _______, _______,
    _______, KC_MPLY, KC_WH_U, KC_UP  , KC_WH_D, KC_PGUP, _______,    KC_4,    KC_5,    KC_6, _______, _______, _______, _______, _______,
    _______,  KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,    KC_1,    KC_2,    KC_3, _______, _______,          _______, _______,
    KC_TRNS,          KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_0, KC_NUBS, S(KC_NUBS), _______, _______, _______, _______,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______,          _______, _______, KC_TRNS, KC_TRNS, _______, _______, _______, _______
  ),
  [2] = LAYOUT_80(
    _______, KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_WN1, KC_WN2, KC_WN3, KC_WN4, KC_WN5, KC_WN6, KC_WN7, KC_WN8, KC_WN9, _______, _______, _______,  _______, LCTL(KC_BSPC), _______,
    KC_CAPS, KC_HOME, KC_END, KC_MS_U, KC_BTN1, KC_WH_U, KC_EM1 , KC_EM2 , KC_EM3 , KC_EM4 , KC_EM5 , KC_EM6 , KC_EM7 , KC_EM8 , _______,
    KC_RSFT, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_EM9 , KC_EM10, KC_EM11, KC_EM12, KC_EM13, KC_EM14,          _______, _______,
    KC_TRNS,          RALT(KC_X), KC_MPLY, KC_VOLD, KC_VOLU, _______, KC_EM15, KC_EM16, _______, _______, _______, _______, _______, _______,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______,          _______, _______, KC_TRNS, KC_TRNS, _______, _______, _______, _______
  ),
  [3] = LAYOUT_80(
    _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______, _______,
    RGB_TOG, _______  , _______ , _______, _______, _______, _______,   KC_P7,   KC_P8,   KC_P9, _______,  RGB_RMOD, RGB_MOD,  _______, _______, NK_TOGG,
    _______, RGB_SAD  , RGB_SAI , _______, _______, _______, _______,   KC_P4,   KC_P5,   KC_P6, _______, _______, TO(4), _______, EE_CLR,
    _______, RGB_VAD  , RGB_VAI , _______, _______, _______, _______,   KC_P1,   KC_P2,   KC_P3, _______, _______,          _______, QK_BOOT,
    KC_TRNS,            RGB_SPD , RGB_SPI, _______, _______, _______,   KC_P0, _______, _______, _______, _______, _______, CM_ON, _______,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______,          _______, _______, KC_TRNS, KC_TRNS, _______, _______, CM_OFF, WIN_LOGIN
  ),
  [4] = LAYOUT_80(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME,  KC_F18,
    KC_TD3,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, _______,  KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, TO(0), KC_PGUP,
    KC_RSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,   KC_END,
    KC_LCTL, KC_LGUI, KC_LALT, MO(1),   _______,  KC_SPC, _______,           KC_SPC,  KC_RALT, KC_RCTL, MO(3), KC_LEFT, KC_DOWN, KC_RGHT
  ),
};

const uint16_t PROGMEM miniMize_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copyCopy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM pastePaste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM markAll_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM ctlBspc_combo[] = {KC_EQL, KC_BSPC, COMBO_END};
const uint16_t PROGMEM flStudio_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM winBrave_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM markEve_combo[] = {KC_X, KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
  [COMBO1] = COMBO(miniMize_combo, RALT(KC_X)), 
  [COMBO2] = COMBO(copyCopy_combo, LCTL(KC_C)),
  [COMBO3] = COMBO(pastePaste_combo, LCTL(KC_V)),
  [COMBO4] = COMBO(markAll_combo, LCTL(KC_A)),
  [COMBO5] = COMBO(ctlBspc_combo, LCTL(KC_BSPC)),
  [COMBO6] = COMBO(flStudio_combo, KC_MPLY),
  [COMBO7] = COMBO(winBrave_combo, LGUI(KC_2)),
  [COMBO8] = COMBO(markEve_combo, LCTL(KC_A)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
};

tap_dance_action_t tap_dance_actions[] = {
  //Tap once for change track, twice for play
  [TD_QIT]  = ACTION_TAP_DANCE_DOUBLE(KC_END, LALT(KC_F4)),
  [TD_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_Z)),
  [TD_EMO]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LGUI(KC_DOT)),
// Other declarations would go here, separated by commas, if you have them

};

// Red layer indicator, only used keys in layer.
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    HSV hsv = {HSV_BLUE};
                        hsv.v = rgb_matrix_config.hsv.v;
                            RGB rgb = hsv_to_rgb(hsv);
                                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                }
            }
        }
    }
    return false;
}


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F19, KC_F20) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F21, KC_F22) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F23, KC_F24) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F19, KC_F20) },
};
#endif