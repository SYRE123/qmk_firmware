/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

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
    DRAG_SCROLL,
};

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_ENT   ,
    KC_LCTL  , KC_LCTL  , KC_LGUI  , LT(2,KC_MPLY),KC_LALT,LT(1,KC_SPC),LT(3,KC_ENT),    KC_SPC,KC_BSPC,LT(1,KC_LNG2),KC_RGUI, _______ , KC_RALT  , KC_DEL
  ),

  [1] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_HOME  , KC_WH_U  , KC_UP    , KC_END   , KC_PGUP  ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
    KC_LCTL  , KC_DEL   , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_PGDN  ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_ENT   ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  ,_______ , _______  , _______ , _______
  ),

  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , KC_F12   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGUP  , KC_BTN1  , DRAG_SCROLL  , KC_BTN2  , KC_BTN3  , NK_TOGG  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  ,  CM_OFF  ,  CM_ON   ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______ , _______ , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  KC_EM1 , KC_EM2  , KC_EM3  , KC_EM4 , KC_EM5  , KC_EM6  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  KC_EM9 , KC_EM10 , KC_EM11 , KC_EM12  , KC_EM12 , KC_EM14  ,
    _______  , _______  , _______ , _______ , _______ , _______ , KC_EM8   ,            KC_EM7   , KC_EM15  , KC_EM16  , KC_PGUP  , KC_END   , _______  , _______  ,
    QK_BOOT  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , QK_BOOT
  ),
};
// clang-format on
 

const uint16_t PROGMEM miniMize_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copyCopy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM pastePaste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM markAll_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM ctlBspc_combo[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM flStudio_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM winBrave_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM markEve_combo[] = {KC_X, KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
  [COMBO1] = COMBO(miniMize_combo, RALT(KC_X)), 
  [COMBO2] = COMBO(copyCopy_combo, LCTL(KC_C)),
  [COMBO3] = COMBO(pastePaste_combo, LCTL(KC_V)),
  [COMBO4] = COMBO(markAll_combo, LCTL(KC_A)),
  [COMBO5] = COMBO(ctlBspc_combo, KC_BSPC),
  [COMBO6] = COMBO(flStudio_combo, KC_MPLY),
  [COMBO7] = COMBO(winBrave_combo, LGUI(KC_2)),
  [COMBO8] = COMBO(markEve_combo, LCTL(KC_A)),
};

bool set_scrolling = false;

#define SCROLL_DIVISOR_H 80.0
#define SCROLL_DIVISOR_V 80.0

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != AUTO_MOUSE_DEFAULT_LAYER) {
        set_scrolling = false;
    }
    return state;
}

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
      switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
};