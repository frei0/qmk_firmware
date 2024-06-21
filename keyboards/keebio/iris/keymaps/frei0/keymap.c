#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLE 1
#define _GAME 2
#define _NUM 3
#define _STENO 4
#define _STENOR 5
#define _SETT 6
#define _LOWER 7
#define _RAISE 8
#define _ALTGR 9

enum custom_keycodes {
  KC_000 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
        // N.B.: This is for an iris v4 with rotary encoders.
        // Even though I use colemak, I prefer qwerty hardware with software colemak, if possible.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_AUDIO_MUTE,    KC_BTN3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, LT(_LOWER, KC_SPC),        KC_SPC,  MO(_LOWER),MO(_RAISE)
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
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
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
     _______, _______, _______, _______, _______, _______, _______,          KC_NUM,  KC_000,     KC_P0,KC_P0,   KC_PDOT, TG(_NUM), KC_PENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    KC_SPC,  KC_P0, MO(_LOWER)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_STENO] = LAYOUT( 
        // Steno layer for plover
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, STN_N1, STN_N2,  STN_N3,  STN_N4,  STN_N5,                              STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  _______,  
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                            STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, XXXXXXX,          XXXXXXX, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    STN_A,   STN_O,   MO(_STENOR),              MO(_LOWER),STN_E,   STN_U
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_STENOR] = LAYOUT(
        // raise layer for steno
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    TG(_STENO), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_AUDIO_MUTE,    KC_BTN3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, _______,                  _______, KC_SPC, KC_LSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SETT] = LAYOUT(
        // This is an on/off layer just for keyboard magicks and settings.
        // Mnemonics: B->BACKLIGHT, S->SATURATION->HSV, 6->6KRO, Y->Gooey, C->Colemak, G->toGGle
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    TG(_SETT),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            NK_OFF,  NK_ON,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            GU_OFF, GU_ON,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX,TG(_COLE),XXXXXXX, BL_STEP, DB_TOGG,            QK_BOOT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, _______, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT( 
        // The main layer for rest of tkl keys (except right mods and menu key), mousing, and toggling more layers! Has to be
        // above the layers it toggles, so the toggle keys can't be covered up and get you stuck!
        // Mouse, Arrows, pUp/Down, Home/End, same as Ducky Mini, because I have one and don't want to learn new things.
        // Mnemonics: Z->GameZ, B->Back2Base, T->TakeAScreenshot, Y->InsertY, ?->Misc->Settings. '->Numpad.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_PSCR,                            KC_INS,  KC_LBRC, KC_RBRC, KC_UP,   KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,                            KC_WBAK, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, TG(_NUM),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TG(_GAME),KC_0,  KC_MINS, KC_EQL, TO(_QWERTY),KC_SCRL,        KC_PAUS, KC_WFWD, KC_PGDN, KC_HOME, KC_END, TG(_SETT), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT( 
        // Always shifted, for use with LM(shift). It's almost the same as LOWER, but with some replaced keys that don't usually get shifted.
        // Currently, the only change is that DB_TOGG and QK_BOOT appear on the rotary pushes, replacing scroll lock and pause.
        // More stuff could be added in the future, replacing layer keys, rotary turns, etc.
        //
        // N.B. even if this was exactly the same as LOWER, making a copy of the layer is helpful to check what layer lighting to turn on in
        // layer_state_set_user. For some reason, get_mods() wasn't working as expected.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_PSCR,                            KC_INS,  KC_LBRC, KC_RBRC, KC_UP,   KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_9,    KC_0,    KC_LBRC, KC_RBRC, XXXXXXX,                           KC_WBAK, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, TG(_NUM),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,TG(_STENO),XXXXXXX,KC_MINS, KC_EQL, TO(_QWERTY),DB_TOGG,          QK_BOOT,   KC_WFWD, KC_PGDN, KC_HOME, KC_END, TG(_SETT), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ALTGR] = LAYOUT(
        // copy of alphas layer, since altgr needs to be back to alphas.
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_AUDIO_MUTE,    KC_BTN3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT,  _______,                  KC_SPC,  _______, _______
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

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // short ec-11 sends reversed signal of long ec-11?
        clockwise = !clockwise;
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
    return false;
}


// Lighting for indicating toggled layers.
// Whole backlight red when caps lock is on. There's no Caps Lock on this board,
// so this should be rare.
const rgblight_segment_t PROGMEM led_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 12, HSV_RED}      // Light all LEDs
);
// Purple right hand when setting board settings.
const rgblight_segment_t PROGMEM led_sett_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{6, 6, HSV_PURPLE}    // Light LEDs 6-11 inclusive
);
// Cyan right hand when numpadding.
const rgblight_segment_t PROGMEM led_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{6, 6, HSV_CYAN}      // Light LEDs 0-5
);
// Green left hand for lower.
const rgblight_segment_t PROGMEM led_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 6, HSV_GREEN}
);
// Green right hand for raise.
const rgblight_segment_t PROGMEM led_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{6, 6, HSV_GREEN}
);
const rgblight_segment_t PROGMEM led_steno_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 12, HSV_ORANGE}      // Light all LEDs
);
const rgblight_segment_t PROGMEM led_game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 12, HSV_CORAL}      // Light all LEDs
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
      led_capslock_layer,
      led_sett_layer,
      led_num_layer,
      led_lower_layer,
      led_raise_layer,
      led_steno_layer,
      led_game_layer
);
// Update lighting layers on layer updates.
layer_state_t layer_state_set_user(layer_state_t state) {
   state=update_tri_layer_state(state, _LOWER, _RAISE, _ALTGR);

   if (layer_state_cmp(state, _ALTGR)){
      register_code(KC_RALT);
   } else {
      unregister_code(KC_RALT);
   }

   if ( layer_state_cmp(state, _RAISE) &&
         !layer_state_cmp(state, _ALTGR)){
      register_code(KC_RSFT);
   } else {
      unregister_code(KC_RSFT);
   }

	rgblight_set_layer_state(1, layer_state_cmp(state, _SETT));
	rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
	rgblight_set_layer_state(3, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(4, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(5, layer_state_cmp(state, _STENO));
	rgblight_set_layer_state(6, layer_state_cmp(state, _GAME));

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

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}
