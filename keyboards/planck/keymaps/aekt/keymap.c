#include QMK_KEYBOARD_H

enum layers {
  _WQWERTY,
  _WNUMBER,
  _WSYMBOL,
  _WADJUST,

  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _FN_XX,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define FN_XX MO(_FN_XX)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)
#define DVORAK DF(_DVORAK)

#define CTL_ESC MT(MOD_LCTL, KC_ESCAPE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


// Wide

#define WNUMESC LT(_WNUMBER, KC_ESC)
#define WSYMENT LT(_WSYMBOL, KC_ENT)
#define WADJUST MO(_WADJUST)

[_WQWERTY] = LAYOUT_planck_mit(
    KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_NO   , KC_NO   , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
    KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_NO   , KC_NO   , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN ,
    KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_NO   , KC_NO   , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH ,
    WADJUST , KC_LGUI , KC_LCTL , WNUMESC , KC_SPC  , KC_TAB            , KC_BSPC , WSYMENT , KC_LSFT , KC_LALT , WADJUST
),
[_WNUMBER] = LAYOUT_planck_mit(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_7    , KC_8    , KC_9    , KC_EQL  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_ASTR , KC_4    , KC_5    , KC_6    , KC_PLUS  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_SLSH , KC_1    , KC_2    , KC_3    , KC_ENT  ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , KC_0    , KC_DOT  , KC_COMM
),
[_WSYMBOL] = LAYOUT_planck_mit(
    KC_GRV  , KC_AMPR , KC_ASTR , KC_QUOT , KC_UNDS , _______ , _______ , _______ , KC_LCBR , KC_RCBR , _______ , _______ ,
    KC_TILD , KC_DLR  , KC_PERC , KC_CIRC , KC_DQUO , _______ , _______ , _______ , KC_LPRN , KC_RPRN , _______ , _______ ,
    KC_PIPE , KC_EXLM , KC_AT   , KC_HASH , KC_BSLS , _______ , _______ , _______ , KC_LBRC , KC_RBRC , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),
[_WADJUST] = LAYOUT_planck_mit(
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , _______ , RESET   , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , _______ ,
    KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ ,
    KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , QWERTY            , _______ , _______ , _______ , _______ , _______
),

// Escape

[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
    CTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_ENT  ,
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_QUOT ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_COLEMAK] = LAYOUT_planck_mit(
    KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_BSPC ,
    CTL_ESC , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_ENT  ,
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_QUOT ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_DVORAK] = LAYOUT_planck_mit(
    KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_BSPC ,
    CTL_ESC , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_ENT  ,
    KC_LSFT , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_SLSH ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_FN_XX] = LAYOUT_planck_mit(
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC ,
    KC_DEL  , _______ , _______ , _______ , _______ , _______ , _______ , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_HOME , KC_END  , KC_PIPE ,
    _______ , _______ , _______ , _______ , _______ , _______           , ADJUST  , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
    KC_DEL  , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_NUHS , KC_NUBS , KC_PGUP , KC_PGDN , KC_BSLS ,
    _______ , _______ , _______ , _______ , ADJUST  , _______           , _______ , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),
[_ADJUST] = LAYOUT_planck_mit(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    DEBUG   , _______ , _______ , AU_ON   , AU_OFF  , _______ , _______ , QWERTY  , COLEMAK , DVORAK  , _______ , RESET   ,
    _______ , _______ , _______ , MU_ON   , MU_OFF  , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),

};
