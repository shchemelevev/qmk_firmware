#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include <print.h>

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
#define KC_ATAB LALT(KC_TAB)
#define KC_UNDR S(KC_MINS)
#define KC_SLBR LSFT(KC_LBRC)
#define KC_SRBR LSFT(KC_RBRC)
#define KC_CTAB LCTL(KC_TAB)
#define KC_SINS LSFT(KC_INS)
#define KC_SLAN LCTL(KC_SPC)
#define KC_ALAN LALT(KC_LSFT)
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
                         LGUI,LOWR,SPC ,    SPC, RISE,SLAN
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
                         LALT,LALT,SPC ,    SPC, RISE, ALAN
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
                         LGUI,LOWR,SPC ,    SPC, RISE, DEL
                     // └────┴────┴────┘   └────┴────┴────┘
  ),

  [_LOWER] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
     TILD, F1 , F1 , F3 , F4 , F5 ,               F6 , F7 , F8 , F9 , F10,BSPC,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     ATAB, 1  , 2  , 3  , NO , 5  ,               6  , 7  , 8  , 9  ,LBRC,XXXX,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     DEL ,XXXX,LEFT,RGHT,CTAB,LBRC,              LEFT,DOWN, UP ,RGHT,QUOT,PIPE,
  //├────┼────┼────┼────┼────┼────┼────┐   ┌────┼────┼────┼────┼────┼────┼────┤
     CONF,XXXX,XXXX,XXXX,DOWN,LCBR,LPRN,    RPRN, NO ,RBRC, P2 , P3 ,MINS,XXXX,
  //└────┴────┴────┴────┼────┼────┼────┼───┼────┼────┼────┼────┴────┴────┴────┘
                             ,    ,    ,        ,    ,
                     // └────┴────┴────┘   └────┴────┴────┘
  ),

  [_RAISE] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
     F12 , F1 , F2 , F3 , F4 , F5 ,               F6 , F7 , F8 , F9 , F10,BSPC,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     TAB ,EXLM, AT ,HASH, DLR,PERC,              TILD,PMNS,PPLS,PAST,PSLS,CIRC,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     LSFT,MPRV,MNXT,VOLU,PGUP,UNDS,              GRV, UNDR, EQL,BSLS,XXXX,XXXX,
  //├────┼────┼────┼────┼────┼────┼────┐   ┌────┼────┼────┼────┼────┼────┼────┤
     CONF,XXXX,XXXX,XXXX,PGDN,MINS,LPRN,    XXXX,XXXX,LBRC,RBRC,SLBR,SRBR,XXXX,
  //└────┴────┴────┴────┼────┼────┼────┼───┼────┼────┼────┼────┴────┴────┴────┘
                             ,    ,    ,        ,    ,
                     // └────┴────┴────┘   └────┴────┴────┘
  ),


  [_CONFIG] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
     REST,XXXX,XXXX,XXXX,XXXX,XXXX,              XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     XXXX,QWER,XXXX,XXXX,XXXX,XXXX,              XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
     XXXX,XXXX,XXXX,DOTA,XXXX,XXXX,              XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //├────┼────┼────┼────┼────┼────┼────┐   ┌────┼────┼────┼────┼────┼────┼────┤
     XXXX,XXXX,XXXX,COLE,XXXX,XXXX,    ,        ,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //└────┴────┴────┴────┼────┼────┼────┼───┼────┼────┼────┼────┴────┴────┴────┘
                             ,    ,    ,        ,    ,XXXX
                     // └────┴────┴────┘   └────┴────┴────┘
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
        print("qwerty on\n");
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        print("colemak on\n");
        set_single_persistent_default_layer(_COLEMAK_DH);
      }
      return false;
      break;
    case DOTA:
      if (record->event.pressed) {
        print("dota on\n");
        set_single_persistent_default_layer(_DOTA);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        print("lower on\n");
        layer_on(_LOWER);
      } else {
        print("lower off\n");
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        print("raise on\n");
        layer_on(_RAISE);
      } else {
        print("raise off\n");
        layer_off(_RAISE);
      }
      return false;
      break;
    case CONFIG:
      if (record->event.pressed) {
        print("config off\n");
        set_single_persistent_default_layer(_CONFIG);
      }
      return false;
      break;
  }
  return true;
}
