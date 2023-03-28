#include "kbd75.h"
#include "action_layer.h"
#include "keymap_nordic.h"

#define QWERTY 0
#define FUNCTION 1
#define MOUSE 2
#define STARCRAFT 3

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
  TD_FRA,
};

enum custom_keycodes {
    FL_OMNI = SAFE_RANGE,
    FL_ARC,
    FL_MAIL,
    FL_PASS,
    WIN_LOGIN,
};


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
#define KC_TD11 TD(TD_FRA)
#define KC_TD12 TD(TD_LOG)
#define KC_TDX SFT_T(KC_SPC)
#define KC_TDX1 LSFT_T(KC_ASTR)
#define KC_TDX2 RSFT_T(KC_LPRN)
#define KC_TDX3 CTL_T(KC_DEL)
#define KC_TDX4 CTL_T(KC_SPC)
#define KC_TDX5 LCTL(KC_J)
#define KC_TC1 LGUI(KC_1)
#define KC_TC2 LGUI(KC_2)
#define KC_TC3 LGUI(KC_3)
#define KC_TC4 LGUI(KC_4)
#define KC_TC5 LGUI(KC_5)
#define KC_TC6 LGUI(KC_6)
#define KC_TC7 LGUI(KC_7)
#define KC_TC8 LGUI(KC_8)
#define KC_TC9 LGUI(KC_9)
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
#define KC_BLT BL_TOGG
#define KC_BLON BL_ON
#define KC_BLOF BL_OFF
#define KC_BLST BL_STEP
#define KC_BLIN BL_INC
#define KC_BLDE BL_DEC
#define KC_BLBR BL_BRTG
#define KC_RGB RGB_TOG
#define KC_RGHI RGB_HUI
#define KC_RGHD RGB_HUD
#define KC_RGVI RGB_VAI
#define KC_RGVD RGB_VAD
#define KC_RGB1 RGB_MODE_PLAIN
#define KC_RGB2 RGB_MODE_BREATHE
#define KC_RGB3 RGB_MODE_RAINBOW
#define KC_RGB4 RGB_MODE_SWIRL
#define KC_RGB5 RGB_MODE_SNAKE
#define KC_RGB6 RGB_MODE_KNIGHT
#define KC_RGB7 RGB_MODE_GRADIENT
#define KC_WLEF LGUI(KC_LEFT)
#define KC_WRIG LGUI(KC_RGHT)
#define KC_BSP1 LCTL(KC_BSPC)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[QWERTY] =  LAYOUT(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PAUS, KC_BSP1, KC_DEL,
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, KC_HOME,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_TD1, KC_PGUP,
		KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
		KC_LSFT, KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_TD3,
		KC_LCTL, KC_TD2, KC_LALT, MO(FUNCTION), MO(MOUSE), KC_SPC, KC_RALT, KC_TRNS, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[FUNCTION] =  LAYOUT(
		TO(MOUSE), RGB_TOG, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, KC_RGB1, KC_RGB2, KC_RGB3, KC_RGB4, KC_RGB5, KC_RGB6, KC_RGB7, TO(STARCRAFT), MAGIC_TOGGLE_NKRO, QK_BOOT,
		TO(FUNCTION), FL_OMNI, FL_ARC, FL_MAIL, FL_PASS, KC_TC5, KC_TC6, KC_TC7, KC_TC8, KC_TC9, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSP1, KC_BSP1, KC_TRNS,
		KC_TRNS, KC_PGUP, KC_WH_U, KC_UP, KC_WH_D, KC_F13, KC_PAST, KC_PPLS, KC_7, KC_8, KC_9, KC_PAST, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_PSLS, KC_PMNS, KC_4, KC_5, KC_6, KC_PSLS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_F14, KC_VOLU, KC_F13, KC_WLEF, KC_WRIG, KC_NUBS, S(KC_NUBS), KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_NUM,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(QWERTY), KC_0, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, WIN_LOGIN),

[MOUSE] =  LAYOUT(
		KC_TRNS, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_TRNS, KC_TRNS, KC_TRNS,
		TO(FUNCTION), KC_TC1, KC_TC2, KC_TC3, KC_TC4, KC_TC5, KC_TC6, KC_TC7, KC_TC8, KC_TC9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_WH_L, KC_WH_R, KC_MS_U, KC_BTN1, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_WBAK, KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, TO(QWERTY), TO(QWERTY), TO(QWERTY), TO(QWERTY), KC_TRNS, TO(QWERTY), KC_TRNS, KC_TRNS, KC_TRNS),

[STARCRAFT] =  LAYOUT(
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PAUS, KC_NUM, KC_DEL,
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, TO(QWERTY),
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_TD1, KC_PGUP,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
    KC_LSFT, KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_TD3,
    KC_LCTL, KC_TD2, KC_TD6, KC_SPC, MO(FUNCTION), KC_SPC, KC_RALT, KC_TRNS, TO(FUNCTION), KC_LEFT, KC_DOWN, KC_RGHT),
};

/*
/
#define rgblight_set_blue        rgblight_setrgb (0x00,  0x00, 0xFF);
#define rgblight_set_white       rgblight_setrgb (227, 229, 216);
#define rgblight_set_blue1       rgblight_setrgb (7, 54, 66);
#define rgblight_set_red         rgblight_setrgb (0xFF,  0x00, 0x00);
#define rgblight_set_green       rgblight_setrgb (13, 181, 0);
#define rgblight_set_teal1       rgblight_setrgb (7, 129, 255);
#define rgblight_set_teal        rgblight_setrgb (0, 199, 179);
#define rgblight_set_greenish    rgblight_setrgb (0, 233, 168);
#define rgblight_set_magenta     rgblight_setrgb (0xFF,  0x00, 0xFF);
#define rgblight_set_purple      rgblight_setrgb (0x7A,  0x00, 0xFF);
#define rgblight_set_darkpurple  rgblight_setrgb (86, 0, 233);
#define rgblight_set_pink        rgblight_setrgb (255, 20, 147);
#define rgblight_set_test        rgblight_setrgb (127,255,0);
//#define rgblight_set_led1        rgblight_setrgb_at(0x00, 0xFF, 0x00, 10);
//#define rgblight_set_led2        rgblight_setrgb_at(255, 20, 147, 10);
//#define rgblight_set_led3        rgblight_setrgb_at(86, 0, 233, 10);

void rgblight_setrgb_layer (uint8_t r, uint8_t g, uint8_t b) {
  rgblight_setrgb_at(r, g, b, 8);
  rgblight_setrgb_at(r, g, b, 9);
  rgblight_setrgb_at(r, g, b, 10);
  rgblight_setrgb_at(r, g, b, 11);
  rgblight_setrgb_at(r, g, b, 12);
  rgblight_setrgb_at(r, g, b, 13);
  rgblight_setrgb_at(r, g, b, 14);
  rgblight_setrgb_at(r, g, b, 15);
}

// GMK Solarized Dark
#define rgblight_set_led_fn        rgblight_setrgb_layer(0, 35, 44);
#define rgblight_set_led_mouse     rgblight_setrgb_layer(7, 129, 255);
#define rgblight_set_led_sc2       rgblight_setrgb_layer(86, 0, 233);


#define rgblight_set_led_fn        rgblight_setrgb_layer(36, 143, 0);
#define rgblight_set_led_mouse     rgblight_setrgb_layer(0x00,  0x00, 0xFF);
#define rgblight_set_led_sc2       rgblight_setrgb_layer(7, 129, 255);
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      if (record->event.pressed) {
        switch(keycode){
          case FL_OMNI:
              SEND_STRING(SS_TAP(X_F8)"omni"SS_TAP(X_ENT));
              return false; break;
          case FL_ARC:
              SEND_STRING(SS_TAP(X_F8)"arc"SS_TAP(X_ENT));
              return false; break;
          case FL_MAIL:
              SEND_STRING("malmsten.marcus"SS_DOWN(X_RALT)"2"SS_UP(X_RALT)"gmail.com");
              return false; break;
          case FL_PASS:
              SEND_STRING("albatross");
              return false; break;
          case WIN_LOGIN:
              SEND_STRING("5155");
              return false; break;
        }
      }
    return true;
};

/*
uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
    case FUNCTION:
      rgblight_set_led_fn;
      break;
    case MOUSE:
      rgblight_set_led_mouse;
      break;
    case STARCRAFT:
      rgblight_set_led_sc2;
      break;
    default: //  for any other layers, or the default layer
      rgblight_set_darkpurple;
      break;}
#endif
  return state;
}
*/


tap_dance_action_t tap_dance_actions[] = {
  //Tap once for change track, twice for play
  [TD_MSK]  = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPLY),
  [TD_ENG]  = ACTION_TAP_DANCE_DOUBLE(KC_NUHS, S(KC_NUHS)),
  [TD_WIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),
  [TD_QIT]  = ACTION_TAP_DANCE_DOUBLE(KC_END, LALT(KC_F4)),
  [TD_CAP]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_LFT]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_LEFT), LGUI(KC_RGHT)),
  [TD_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_Z)),
  [TD_COP]  = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, LALT(KC_Z)),
  [TD_CUT]  = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X)),
  [TD_PAS]  = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
  [TD_ALL]  = ACTION_TAP_DANCE_DOUBLE(KC_A, LCTL(KC_A)),
  [TD_FRA]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),

// Other declarations would go here, separated by commas, if you have them

};