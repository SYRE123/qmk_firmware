#include QMK_KEYBOARD_H
#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_nordic.h"

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
};

enum {
  TD_MSK,
  TD_ENG,
  TD_WIN,
  TD_QIT,
  TD_CAP,
  TD_LFT,
  TD_MIN,
  TD_COP,
  TD_CUT,
  TD_PAS,
  TD_ALL,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_MOU LT(_MOUSE, KC_DEL)
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_NOAT NO_AT
#define KC_TD1 TD(TD_ENG)
#define KC_TD2 TD(TD_WIN)
#define KC_TD3 TD(TD_QIT)
#define KC_TD4 TD(TD_CAP)
#define KC_TD5 TD(TD_LFT)
#define KC_TD6 TD(TD_MIN)
#define KC_TD7 TD(TD_COP)
#define KC_TD8 TD(TD_CUT)
#define KC_TD9 TD(TD_PAS)
#define KC_TD10 TD(TD_ALL)
#define KC_TDX SFT_T(KC_SPC)
#define KC_TDX1 CTL_T(KC_DEL)
#define KC_TDX2 CTL_T(KC_SPC)
#define KC_TDX3 SFT_T(KC_ENT)
#define KC_NODR NO_DLR
#define KC_NOPN NO_PND
#define KC_NOEU NO_EURO
#define KC_NOLB NO_LCBR
#define KC_NORB NO_RCBR
#define KC_NOF4 LALT(KC_F4)
#define KC_NOHS S(KC_NUHS)
#define KC_NOBS S(KC_NUBS)
#define KC_RGB RGB_TOG
#define KC_RGHI RGB_HUI
#define KC_RGHD RGB_HUD
#define KC_RGVI RGB_VAI
#define KC_RGVD RGB_VAD
#define KC_M1 OSM(MOD_RALT)
#define KC_M2 OSM(MOD_LSFT)
#define KC_M3 OSM(MOD_LCTL)
#define KC_M4 OSM(MOD_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TD3  , KC_1   ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                             KC_6  , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_TD9,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_M3  ,  KC_A  , KC_S   , KC_D   , KC_F   , KC_G   ,                             KC_H  , KC_J   ,  KC_K  , KC_L   ,KC_SCLN , KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_M2  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,KC_TD2  ,          KC_TD1 ,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_TD10 , KC_LOWR,  KC_MOU,                   KC_SPC , KC_RASE,  KC_M1
  //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                             KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NOAT , KC_TD5 ,_______, KC_MPLY ,KC_MPRV , KC_MNXT,                             KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_UNDS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_VOLD , KC_UP  , KC_VOLU, KC_PGUP,KC_HOME ,                            KC_PPLS,   KC_4 ,   KC_5 ,   KC_6 , KC_PPLS, KC_PMNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN ,KC_END  ,KC_LGUI ,          KC_RPRN, KC_BSLS,   KC_1 ,   KC_2 ,   KC_3 , KC_PAST, KC_PSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT,_______,  KC_DEL ,                     KC_0 ,_______,  KC_0 
  //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,_______,_______, _______, _______,   KC_ASTR,                            KC_LPRN , KC_RGVD, KC_RGVI, KC_RGHD, KC_RGHI,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,KC_EXLM ,  KC_AT , KC_HASH,KC_NODR , KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV , KC_MNXT, KC_NOEU, KC_NOPN, KC_NOLB,                            KC_NORB, KC_NOHS, KC_EQL ,  KC_N  , KC_RSFT ,KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE,  KC_MSTP, KC_MPLY, _______, KC_PGDN, KC_MINS, _______,          _______, KC_PLUS, KC_EQL , KC_NUBS, KC_NOBS, KC_RGB , KC_NOF4,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     DT_PRNT, _______, DT_DOWN, DT_UP, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  KC_BTN3, KC_WBAK, KC_WFWD,                            KC_WBAK, KC_WFWD, KC_BTN3, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_WH_L, KC_WH_R, KC_MS_U, KC_BTN1, KC_WH_U,                            KC_WH_U, KC_BTN1, KC_MS_U, KC_WH_L, KC_WH_R, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,          _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     MAGIC_TOGGLE_NKRO, _______, _______, _______, _______, _______,                  _______, _______, RGB_M_G, _______, _______, AS_TOGG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, _______, _______, _______, _______, _______,                            RGB_M_P,RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, NO_LCBR,                            NO_RCBR, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, NO_LBRC, _______,          _______, NO_RBRC,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, QK_BOOT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
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
}


tap_dance_action_t tap_dance_actions[] = {
  //Tap once for change track, twice for play
  [TD_MSK]  = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPLY),
  [TD_ENG]  = ACTION_TAP_DANCE_DOUBLE(KC_NUHS, S(KC_NUHS)),
  [TD_WIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),
  [TD_QIT]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)),
  [TD_CAP]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_LFT]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_LEFT), LGUI(KC_RGHT)),
  [TD_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_Z)),
  [TD_COP]  = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
  [TD_CUT]  = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X)),
  [TD_PAS]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_UNDS),
  [TD_ALL]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(LCTL(KC_X))),

// Other declarations would go here, separated by commas, if you have them
};
