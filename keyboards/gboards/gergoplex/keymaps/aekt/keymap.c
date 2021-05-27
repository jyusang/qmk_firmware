#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _SYMBOL,
    _COMMON,
    _POINT,
    _FUNCT,
};

#define QWERTY DF(_QWERTY)

#define POINT MO(_POINT)
#define FUNCT MO(_FUNCT)

#define LS_Z MT(MOD_LSFT, KC_Z)
#define LS_GRV MT(MOD_LSFT, KC_GRV)
#define RS_SLSH MT(MOD_RSFT, KC_SLSH)
#define RS_BSLS MT(MOD_RSFT, KC_BSLS)

#define LG_BSPC MT(MOD_LGUI, KC_BSPC)
#define LC_ESC MT(MOD_LCTL, KC_ESC)
#define LS_TAB MT(MOD_LSFT, KC_TAB)
#define SM_ENT LT(_SYMBOL, KC_ENT)
#define CM_QUOT LT(_COMMON, KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT_gergoplex(
        KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
        KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN ,
        LS_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , RS_SLSH ,
                            LG_BSPC , LC_ESC  , KC_SPC  , LS_TAB  , SM_ENT  , CM_QUOT
    ),
    [_SYMBOL] = LAYOUT_gergoplex(
        KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
        KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN ,
        LS_GRV  , KC_LBRC , KC_RBRC , KC_UNDS , KC_MINS , KC_PLUS , KC_EQL  , KC_LCBR , KC_RCBR , RS_BSLS ,
                            KC_LGUI , KC_LCTL , _______ , _______ , _______ , _______
    ),
    [_COMMON] = LAYOUT_gergoplex(
        _______ , _______ , _______ , _______ , _______ , KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_MPLY ,
        _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ ,
        KC_CAPS , _______ , _______ , _______ , _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_DEL  ,
                            POINT   , FUNCT   , _______ , _______ , _______ , _______
    ),
    [_POINT] = LAYOUT_gergoplex(
        _______ , _______ , KC_MS_U , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , KC_MS_L , KC_MS_D , KC_MS_R , _______ , _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ ,
        _______ , KC_ACL0 , KC_ACL1 , KC_ACL2 , _______ , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , _______ ,
                            _______ , _______ , _______ , _______ , _______ , _______
    ),
    [_FUNCT] = LAYOUT_gergoplex(
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , _______ , _______ , _______ , _______ , _______ ,
        KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , _______ , AU_OFF  , AU_ON   , _______ , RESET   ,
        KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , MU_OFF  , MU_ON   , _______ , KC_LSFT ,
                            _______ , _______ , KC_LALT , KC_RALT , KC_RCTL , KC_RGUI
    ),
    // clang-format on
};
