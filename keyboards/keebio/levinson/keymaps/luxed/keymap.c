#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1 
#define _LRAISE 2
#define _RRAISE 3
#define _RLOWER 4
#define _MEDIA  5

enum custom_keycodes {
    CEDILLE = SAFE_RANGE,
    CBOPEN,
    CBCLOSE,
    SBOPEN,
    SBCLOSE,
    GT,
    BKSLSH,
    OPAREN,
    CPAREN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            // The following macros are shortcuts for the French Canadian layout
            case CEDILLE:
                SEND_STRING("]c"); // c cédille
                return false;
            case CBOPEN:
                SEND_STRING(SS_RALT("'")); // open a curly bracket
                return false;
            case CBCLOSE:
                SEND_STRING(SS_RALT("\\")); // close a curly bracket
                return false;
            case SBOPEN:
                SEND_STRING(SS_RALT("[")); // open a square bracket
                return false;
            case SBCLOSE:
                SEND_STRING(SS_RALT("]")); // close a square bracket
                return false;
            case GT:
                SEND_STRING("|");
                return false;
            case BKSLSH:
                SEND_STRING(SS_RALT("`"));
                return false;
            case OPAREN:
                SEND_STRING("(");
                return false;
            case CPAREN:
                SEND_STRING(")");
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .-----------------------------------------.-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Raise|  Alt |  GUI | FN   |    Space    | Enter| Bksp | Left | Down |  Up  |Right |
 * '-----------------------------------------'-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_LSFT,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTL,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL , \
  MO(_LRAISE),  KC_LALT, KC_LGUI, MO(_FN),XXXXXXX,  KC_SPC,  KC_ENT,  KC_BSPC, KC_ESC,  MO(_RRAISE), MO(_MEDIA), MO(_RLOWER)\
),

[_FN]     = LAYOUT_ortho_4x12( \
  KC_GRV,      BKSLSH,  OPAREN, CBOPEN,  SBOPEN, KC_BSLS,    GT,   SBCLOSE, CBCLOSE, CPAREN,  _______,    _______,\
  _______,     _______,_______,_______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, RALT(KC_SCLN),    _______,\
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    KC_MINS,\
  _______,     _______,_______,_______, _______, _______, _______, KC_DEL,  _______, _______, _______,    _______ \
),

[_RRAISE] = LAYOUT_ortho_4x12( \
  KC_F1,        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______,\
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______,\
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______ \
),

[_LRAISE] = LAYOUT_ortho_4x12( \
  _______,     _______,_______,_______, _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,\
  _______,     _______,_______,_______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
  _______,     _______,_______,_______, _______, _______, RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0), _______,\
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______ \
),

[_RLOWER] = LAYOUT_ortho_4x12( \
  _______,     S(KC_1),   S(KC_2),   S(KC_3),    S(KC_4),    S(KC_5),    _______, _______, _______, _______, _______,    _______,\
  _______,     S(KC_6),   S(KC_7),   S(KC_8),    S(KC_9),    S(KC_0),    _______, _______, _______, _______, _______,    _______,\
  _______,     RALT(KC_1),RALT(KC_2),RALT(KC_3), RALT(KC_4), RALT(KC_5), _______, _______, _______, _______, _______,    _______,\
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______ \
),

[_MEDIA]  = LAYOUT_ortho_4x12( \
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT,    KC_MPLY, \
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______, \
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______, \
  _______,     _______,_______,_______, _______, _______, _______, _______, _______, _______, _______,    _______ \
)

};
