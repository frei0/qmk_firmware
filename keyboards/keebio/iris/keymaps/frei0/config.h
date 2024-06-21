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

// #define USE_I2C
#define EE_HANDS

#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LED_COUNT 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Allow GESC to jive with CTRL-SHIFT-ESC (windows taskman).
#define GRAVE_ESC_CTRL_OVERRIDE
// Speed up mouse reporting to about 60Hz
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 3
#define MOUSEKEY_DELAY 200
#define MOUSEKEY_TIME_TO_MAX 100
#define MOUSEKEY_WHEEL_TIME_TO_MAX 255
#define MOUSEKEY_WHEEL_MAX_SPEED 3
// Report layer status through LEDs
#define RGBLIGHT_LAYERS

#define TAPPING_FORCE_HOLD
#define RETRO_TAPPING
#define PERMISSIVE_HOLD


// These deprecated features aren't compatible with link time optimization,
// which we use to save ~2300 bytes. More shiny features, fewer rusty features!

// Disables F() and fn_actions[]. Use custom keycodes and process_record_user().
#define NO_ACTION_FUNCTION
// Disables M() and action_get_macro(). Use custom keycodes instead.
#define NO_ACTION_MACRO

