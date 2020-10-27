#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK_DH 1
#define _DOTA 2
#define _LOWER 3
#define _RAISE 4
#define _CONFIG 5

bool configOn = false;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DOTA,
  LOWER,
  RAISE,
  CONFIG                     // config layer
};

/* Tap Dance */
enum {
  TD_LGUIAPP,                 // LGUI x1, app/menu x2
  TD_SHIFTCAPS,               // LSHIFT x1, CAPS x3
  TD_CTRLALTDL,               // CTRL+ALT+DEL x3
  TD_SHIFTCLAT,               // LSHIFT x1, LCRTL x2, LALT x3, CTRL+ALT x4
};

/* NOOP Key and Transparent */
#define KC_     KC_TRNS
#define KC_XXXX KC_NO

/* LAYERS / CUSTOM KEYS */
#define KC_QWER QWERTY
#define KC_COLE COLEMAK
#define KC_CONF CONFIG
#define KC_LOWR  LOWER
#define KC_DOTA  DOTA

/* Custom Shortened Keys (4 digits so they fit in my grid) */
#define KC_MCTB LCTL(KC_TAB)
#define KC_MCST LCTL(LSFT(KC_TAB))
#define KC_CTEC CTL_T(KC_ESC)
#define KC_SINS LSFT(KC_INS)
#define KC_LGU1 LGUI(KC_1)
#define KC_LGU2 LGUI(KC_2)
#define KC_LGU3 LGUI(KC_3)
#define KC_LGU4 LGUI(KC_4)
#define KC_LGU5 LGUI(KC_5)
#define KC_LGU6 LGUI(KC_6)
#define KC_LGU7 LGUI(KC_7)
#define KC_LGU8 LGUI(KC_8)
#define KC_LGU9 LGUI(KC_9)
#define KC_LGU0 LGUI(KC_0)
#define KC_SYSR KC_SYSREQ
#define KC_REST RESET

#define KC_CONF CONFIG
#define KC_RISE RAISE
#define KC_COLE COLEMAK
#define KC_QWER QWERTY

/* Tap Dance */
#define KC_LGUA TD(TD_LGUIAPP)
#define KC_SHCP TD(TD_SHIFTCAPS)
#define KC_CADL TD(TD_CTRLALTDL)
#define KC_SHCA TD(TD_SHIFTCLAT)

//void keyboard_post_init_user(void) {
//  // Customise these values to desired behaviour
//  debug_enable=true;
//  debug_matrix=true;
//  debug_keyboard=true;
//  //debug_mouse=true;
//}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
     ESC , 1  , 2  , 3  , 4  , 5  ,               6  , 7  , 8  , 9  , 0  ,BSPC,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     TAB , Q  , W  , E  , R  , T  ,               Y  , U  , I  , O  , P  ,QUOT,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     LSFT, A  , S  , D  , F  , G  ,               H  , J  , K  , L  ,SCLN,RSFT,
  //├────┼────┼────┼────┼────┼────┼────┐   ┌────┼────┼────┼────┼────┼────┼────┤
     LCTL, Z  , X  , C  , V  , B  ,XXXX,    XXXX, N  , M  ,COMM,DOT ,SLSH, ENT,
  //└────┴────┴────┴────┼────┼────┼────┼───┼────┼────┼────┼────┴────┴────┴────┘
                         LGUI,LOWR, SPC,    SPC , ENT,RISE
                     // └────┴────┴────┘   └────┴────┴────┘
  ),

  [_DOTA] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
     ESC , 1  , 2  , 3  , 4  , 5  ,               6  , 7  , 8  , 9  , 0  ,BSPC,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     TAB , Q  , W  , E  , R  , T  ,               Y  , U  , I  , O  , P  ,QUOT,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     LSFT, A  , S  , D  , F  , G  ,               H  , J  , K  , L  ,SCLN,RSFT,
  //├────┼────┼────┼────┼────┼────┼────┐   ┌────┼────┼────┼────┼────┼────┼────┤
     LCTL, Z  , X  , C  , V  , B  ,XXXX,    XXXX, N  , M  ,COMM,DOT ,SLSH, ENT,
  //└────┴────┴────┴────┼────┼────┼────┼───┼────┼────┼────┼────┴────┴────┴────┘
                         LALT,LOWR, SPC,    SPC , ENT,RISE
                     // └────┴────┴────┘   └────┴────┴────┘
  ),

  [_COLEMAK_DH] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
     CTEC, 1  , 2  , 3  , 4  , 5  ,               6  , 7  , 8  , 9  , 0  ,BSPC,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     TAB , Q  , W  , F  , P  , B  ,               J  , L  , U  , Y  ,SCLN,DEL ,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     LSFT, A  , R  , S  , T  , G  ,               M  , N  , E  , I  , O  ,RSFT,
  //├────┼────┼────┼────┼────┼────┼────┐   ┌────┼────┼────┼────┼────┼────┼────┤
     LSFT, Z  , X  , C  , D  , V  ,XXXX,    XXXX, K  , H  ,COMM,DOT ,SLSH,ENT,
  //└────┴────┴────┴────┼────┼────┼────┼───┼────┼────┼────┼────┴────┴────┴────┘
                         LGUI,LOWR,SPC ,    SPC, ENT, RISE
                     // └────┴────┴────┘   └────┴────┴────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_F1   , KC_F1,   KC_F3,   KC_F4,  KC_F5  ,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 LALT(KC_TAB),KC_1,    KC_2,    KC_3,  KC_NO, KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,  KC_LBRC,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_RGHT, LCTL(KC_TAB),   KC_LBRC,                            KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, KC_QUOT, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CONF,    _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_NO,   KC_RBRC,  KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_TILD, KC_PMNS, KC_PPLS, KC_PAST, KC_PSLS, KC_CIRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_GRV, S(KC_MINS),KC_EQL, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CONF, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_NO, KC_LBRC, S(KC_LBRC), KC_RBRC,S(KC_LBRC), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_CONFIG] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     REST,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,QWER,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,DOTA,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX,XXXX,COLE,XXXX,XXXX,    ,         ,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,    ,XXXX,        XXXX,    ,XXXX
  //                  `----+----+----'        `----+----+----'
  )
};

/* TAP DANCE */
void shift_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code (KC_CAPS);
  } else {
    register_code (KC_LSFT);
  }
}
void shift_caps_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code (KC_CAPS);
  } else {
    unregister_code (KC_LSFT);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFTCAPS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shift_caps_down, shift_caps_up),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DH);
      }
      return false;
      break;
    case DOTA:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DOTA);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case CONFIG:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CONFIG);
      }
      return false;
      break;
  }
  return true;
}
