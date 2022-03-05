#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _COLEMAK,
    _SYMBOL,
    _COMMON,
    _CURSOR,
    _ADJUST,
};

#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)

#define CURSOR MO(_CURSOR)
#define ADJUST MO(_ADJUST)

#define LS_Z MT(MOD_LSFT, KC_Z)
#define RS_SLSH MT(MOD_RSFT, KC_SLSH)

#define LG_DEL MT(MOD_LGUI, KC_DEL)
#define LA_BSPC MT(MOD_LALT, KC_BSPC)
#define LC_ESC MT(MOD_LCTL, KC_ESC)
#define SM_ENT LT(_SYMBOL, KC_ENT)
#define CM_TAB LT(_COMMON, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT_planck_grid(
        _______ , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , _______ ,
        _______ , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , _______ ,
        _______ , LS_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , RS_SLSH , _______ ,
        _______ , KC_LSFT , LG_DEL  , LA_BSPC , LC_ESC  , KC_SPC  , KC_SPC  , SM_ENT  , CM_TAB  , KC_QUOT , KC_RSFT , _______
    ),
    [_COLEMAK] = LAYOUT_planck_grid(
        _______ , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , _______ ,
        _______ , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , _______ ,
        _______ , LS_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_K    , KC_M    , KC_COMM , KC_DOT  , RS_SLSH , _______ ,
        _______ , KC_LSFT , LG_DEL  , LA_BSPC , LC_ESC  , KC_SPC  , KC_SPC  , SM_ENT  , CM_TAB  , KC_QUOT , KC_RSFT , _______
    ),
    [_SYMBOL] = LAYOUT_planck_grid(
        _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
        _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ ,
        _______ , KC_GRV  , KC_LBRC , KC_RBRC , KC_UNDS , KC_MINS , KC_PLUS , KC_EQL  , KC_LCBR , KC_RCBR , KC_BSLS , _______ ,
        _______ , _______ , _______ , _______ , ADJUST  , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),
    [_COMMON] = LAYOUT_planck_grid(
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_MPLY , _______ ,
        _______ , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
        _______ , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_CAPS , _______ ,
        _______ , _______ , _______ , CURSOR  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),
    [_CURSOR] = LAYOUT_planck_grid(
        _______ , _______ , _______ , KC_MS_U , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , KC_MS_L , KC_MS_D , KC_MS_R , _______ , _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ , _______ ,
        _______ , _______ , KC_ACL0 , KC_ACL1 , KC_ACL2 , _______ , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),
    [_ADJUST] = LAYOUT_planck_grid(
        _______ , RESET   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , AU_ON   , AU_OFF  , _______ , _______ , _______ , QWERTY  , COLEMAK , _______ , _______ , _______ ,
        _______ , _______ , MU_ON   , MU_OFF  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),
    // clang-format on
};
