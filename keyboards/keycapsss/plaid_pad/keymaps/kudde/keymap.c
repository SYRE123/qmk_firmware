/* Copyright 2021 Ben Roesner (keycapsss.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _FLSTUDIO,
    _NUM,
    _MEDIA
};

enum combos {
  COMBO1,
  COMBO2,
  COMBO3
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* NUMPAD layer
    * ,-----------------------,
    * |  7  |  8  |  9  |  /  |
    * |-----+-----+-----+-----|
    * |  4  |  5  |  6  |  *  |
    * |-----+-----+-----+-----|
    * |  1  |  2  |  3  |  -  |
    * |-----+-----+-----+-----|
    * |  0  |  .  |  =  |  +  |
    * `-----------------------'
    */
    [_FLSTUDIO] = LAYOUT_ortho_4x4(
        KC_F6, KC_F7, KC_F9, XXXXXXX,
        KC_P, KC_B, KC_T, XXXXXXX,
        KC_R, LCTL(KC_M), LCTL(KC_T), KC_UP,
        KC_TAB, KC_F15, KC_SPC, KC_DOWN
    ),
    /* Navigation layer
    */
    [_NUM] = LAYOUT_ortho_4x4(
        KC_P7, KC_P8,   KC_P9,    KC_PMNS,
        KC_P4, KC_P5,   KC_P6,    KC_PPLS,
        KC_P1, KC_P2,   KC_P3,    KC_BSPC,
        KC_P0, KC_PDOT, KC_NUM,  KC_ENT
    ),
    /* MEDIA layer
    */
    [_MEDIA] = LAYOUT_ortho_4x4(
        XXXXXXX,     XXXXXXX,             XXXXXXX,             KC_AUDIO_MUTE,
        XXXXXXX,             XXXXXXX,             XXXXXXX,             XXXXXXX,
        KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,     XXXXXXX,
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, XXXXXXX
    ),

};

// Combos for switching layers
const uint16_t PROGMEM zeroDot_combo[] = {KC_LSFT, KC_F15, COMBO_END};
const uint16_t PROGMEM leftDown_combo[] = {KC_P0, KC_PDOT, COMBO_END};
const uint16_t PROGMEM prevPlay_combo[] = {KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO1] = COMBO_ACTION(zeroDot_combo),
  [COMBO2] = COMBO_ACTION(leftDown_combo),
  [COMBO3] = COMBO_ACTION(prevPlay_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO1:
      if (pressed) {
        layer_move(_NUM);
      }
      break;
    case COMBO2:
      if (pressed) {
        layer_move(_MEDIA);
      }
      break;
    case COMBO3:
      if (pressed) {
        layer_move(_FLSTUDIO);
      }
      break;
  }
}

#ifdef OLED_ENABLE

void render_space(void) {
  oled_write_P(PSTR("     "), false);
}


void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  if(layer_state_is(_MEDIA)) {
    oled_write_ln_P(PSTR("Media"), false);
  } else if(layer_state_is(_NUM)) {
    oled_write_ln_P(PSTR("Numpad"), false);
  } else {
    oled_write_ln_P(PSTR("FL Studio"), false);
  }
}


bool oled_task_user(void) {
  oled_write_ln_P(PSTR("Syres Plaid-Pad"), false);
  oled_render_layer_state();
    return false;
}

#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_FLSTUDIO] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F20, KC_F19), ENCODER_CCW_CW(KC_F22, KC_F21) },
    [_NUM] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F20, KC_F19), ENCODER_CCW_CW(KC_F22, KC_F21) },
    [_MEDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_F20, KC_F19), ENCODER_CCW_CW(KC_F22, KC_F21) },
};
#endif
