/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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

#pragma once

//#include "config_common.h"

#define AUTO_SHIFT_TIMEOUT 90
//#define NO_AUTO_SHIFT_SPECIAL
#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 4000  /* Time (in ms) before the one shot key is released */
#define MOUSEKEY_DELAY             20
#define MOUSEKEY_INTERVAL          16
#define MOUSEKEY_MAX_SPEED         18
#define MOUSEKEY_TIME_TO_MAX       65
#define MOUSEKEY_WHEEL_MAX_SPEED   6
#define MOUSEKEY_WHEEL_TIME_TO_MAX 55

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define IGNORE_MOD_TAP_INTERRUPT
#define MASTER_LEFT
#define TAPPING_TERM 155
// #define MASTER_RIGHT
// #define EE_HANDS


//#undef RGBLED_NUM
//#define RGBLED_NUM 12
//#define RGBLIGHT_SPLIT
//#define RGBLED_SPLIT { 6, 6 }
#undef RGBLED_SPLIT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

