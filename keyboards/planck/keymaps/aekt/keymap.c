#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _FN_XX,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define FN_XX MO(_FN_XX)
#define LOWER LT(_LOWER, KC_ESC)
#define RAISE LT(_RAISE, KC_ENT)
#define ADJUST MO(_ADJUST)

#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)
#define DVORAK DF(_DVORAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
    KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_LSPO , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_COLEMAK] = LAYOUT_planck_mit(
    KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_BSPC ,
    KC_LCTL , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT ,
    KC_LSPO , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_DVORAK] = LAYOUT_planck_mit(
    KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_BSPC ,
    KC_LCTL , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_SLSH ,
    KC_LSPO , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_RSPC ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_FN_XX] = LAYOUT_planck_mit(
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_HOME , KC_END  , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , ADJUST  , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_PGUP , KC_PGDN , _______ ,
    _______ , _______ , _______ , _______ , ADJUST  , _______           , _______ , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),
[_ADJUST] = LAYOUT_planck_mit(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    DEBUG   , _______ , _______ , AU_ON   , AU_OFF  , _______ , _______ , QWERTY  , COLEMAK , DVORAK  , _______ , RESET   ,
    _______ , _______ , _______ , MU_ON   , MU_OFF  , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),

};
