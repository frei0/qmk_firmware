#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLE 1
#define _GAME 2
#define _NUM 3
#define _SETT 4
#define _LOWER 5
#define _RAISE 6

enum custom_keycodes {
  KC_000 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
        // N.B.: This is for an iris v4 with rotary encoders.
        // Even though I use colemak, I prefer qwerty hardware with software colemak, if possible.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_AUDIO_MUTE,    KC_BTN3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_LSFT, KC_ENT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, LT(_LOWER, KC_SPC),        KC_SPC,  MO(_LOWER),LM(_RAISE, MOD_LSFT)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_COLE] = LAYOUT( 
        // Hardware colemak, for those IMEs that don't let you set a software keymap. Or, the system colemak is otherwise not accessible.
        // It's just a regular layer, not a base layer for now.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_F,    KC_P,    KC_G,                               KC_J,    KC_L   , KC_U,    KC_Y,    KC_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_R,    KC_S,    KC_T,    KC_D,                               _______, KC_N,    KC_E,    KC_I,    KC_O,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_K,    _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAME] = LAYOUT( 
        // The purpose of this layer is to unbind any tap keys (lt/mt) so there's no input delay. Now you'll definitely win!
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_SPC,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT( 
        // A tenkeyish thing.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TG(_NUM),_______, _______, _______, _______, _______,                            KC_ESC,  KC_P7,   KC_P8,   KC_P9,    KC_BSPC,KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PAST,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          KC_NLCK, KC_000,     KC_P0,KC_P0,   KC_PDOT, TG(_NUM), KC_PENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    KC_SPC,  KC_P0, MO(_LOWER)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SETT] = LAYOUT(
        // This is an on/off layer just for keyboard magicks and settings.
        // Mnemonics: B->BACKLIGHT, S->SATURATION->HSV, 6->6KRO, Y->Gooey, C->Colemak
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    TG(_SETT),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            NK_OFF,  NK_ON,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            GUI_OFF, GUI_ON,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX,TG(_COLE),XXXXXXX, BL_STEP, DEBUG,          RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, _______, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT( 
        // The main layer for rest of tkl keys (except right mods and menu key), mousing, and toggling more layers! Has to be
        // above the layers it toggles, so the toggle keys can't be covered up and get you stuck!
        // Mouse, Arrows, pUp/Down, Home/End, same as Ducky Mini, because I have one and don't want to learn new things.
        // Mnemonics: G->Game, B->Back2Base, T->TakeAScreenshot, I->Insert, ?->Misc->Settings. Quote is numpad.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_MINS, KC_EQL,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_PSCR,                            KC_SLCK, KC_PSCR, KC_INS,  KC_UP,   KC_LBRC, KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, TG(_GAME),                          KC_WBAK, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, TG(_NUM),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,TO(_QWERTY),DEBUG,           RESET,   KC_WFWD, KC_PGDN, KC_HOME, KC_END, TG(_SETT), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT( 
        // Always shifted, for use with LM(shift). The same as above, but with some replaced keys that don't usually get shifted.
        // Currently, the only change is that '(', ')' is on 'Y', 'U' so I can reach it easier one-handed.
        // More stuff can be added in the future, replacing layers, rotaries, etc.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_MINS, KC_EQL,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_PSCR,                            KC_9,    KC_0,    KC_INS,  KC_UP,   KC_LBRC, KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, TG(_GAME),                          KC_WBAK, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, TG(_NUM),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,TO(_QWERTY),DEBUG,           RESET,   KC_WFWD, KC_PGDN, KC_HOME, KC_END, TG(_SETT), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_000:
      if (record->event.pressed) {
         SEND_STRING("000");
      } else {
         // n o t h i n g
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
}


// Lighting for indicating toggled layers.
// Whole backlight red when caps lock is on. There's no Caps Lock on this board,
// so this should be rare.
const rgblight_segment_t PROGMEM led_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 12, HSV_RED}       // Light all LEDs
);
// Purple right hand when setting board settings.
const rgblight_segment_t PROGMEM led_sett_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{6, 6, HSV_PURPLE}
);
// Cyan left hand when numpadding.
const rgblight_segment_t PROGMEM led_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 6, HSV_CYAN}
);
// Green left hand for lower.
const rgblight_segment_t PROGMEM led_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 6, HSV_GREEN}
);
// Green right hand for raise.
const rgblight_segment_t PROGMEM led_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{6, 6, HSV_GREEN}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
      led_capslock_layer,
      led_sett_layer,
      led_num_layer,
      led_lower_layer,
      led_raise_layer
);
// Update lighting layers on layer updates.
layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(1, layer_state_cmp(state, _SETT));
	rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
	rgblight_set_layer_state(3, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(4, layer_state_cmp(state, _RAISE));
	return state;
}
// Update lighting layers on capslock/numlock/scrollock LED updates.
bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(0, led_state.caps_lock);
	return true;
}

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = my_rgb_layers;
}
