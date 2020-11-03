#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _SYMBOL,
  _LFNCTN,
  _RFNCTN,
  _ADJUST,
};

#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)
#define DVORAK DF(_DVORAK)

#define ADJUST MO(_ADJUST)
#define CTL_SPC MT(MOD_LCTL, KC_SPC)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define LFN_ESC LT(_LFNCTN, KC_ESC)
#define RFN_DEL LT(_RFNCTN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit(
    KC_GRV  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
    KC_BSPC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_LSPO , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC ,
    KC_LCTL , KC_LALT , KC_LGUI , LFN_ESC , CTL_SPC , SFT_TAB           , SYM_ENT , RFN_DEL , KC_RGUI , KC_RALT , KC_RCTL
),
[_COLEMAK] = LAYOUT_planck_mit(
    KC_GRV  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_BSLS ,
    KC_BSPC , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT ,
    KC_LSPO , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC ,
    KC_LCTL , KC_LALT , KC_LGUI , LFN_ESC , CTL_SPC , SFT_TAB           , SYM_ENT , RFN_DEL , KC_RGUI , KC_RALT , KC_RCTL
),
[_DVORAK] = LAYOUT_planck_mit(
    KC_GRV  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_BSLS ,
    KC_BSPC , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_SLSH ,
    KC_LSPO , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_RSPC ,
    KC_LCTL , KC_LALT , KC_LGUI , LFN_ESC , CTL_SPC , SFT_TAB           , SYM_ENT , RFN_DEL , KC_RGUI , KC_RALT , KC_RCTL
),
[_SYMBOL] = LAYOUT_planck_mit(
    _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE ,
    _______ , _______ , KC_LBRC , KC_RBRC , KC_UNDS , KC_MINS , KC_PLUS , KC_EQL  , KC_LCBR , KC_RCBR , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),
[_LFNCTN] = LAYOUT_planck_mit(
    KC_ACL2 , _______ , KC_MS_U , KC_WH_U , _______ , _______ , KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_MPLY , KC_MUTE ,
    KC_ACL1 , KC_MS_L , KC_MS_D , KC_MS_R , _______ , _______ , _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ , _______ ,
    KC_ACL0 , KC_WH_L , KC_WH_R , KC_WH_D , _______ , _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_BRID , KC_BRIU ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , ADJUST  , _______ , _______ , _______
),
[_RFNCTN] = LAYOUT_planck_mit(
    KC_NLCK , KC_F12  , KC_F7   , KC_F8   , KC_F9   , KC_PSCR , _______ , _______ , _______ , KC_UP   , _______ ,  _______ ,
    KC_SLCK , KC_F11  , KC_F4   , KC_F5   , KC_F6   , KC_PAUS , _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT ,  _______ ,
    KC_CLCK , KC_F10  , KC_F1   , KC_F2   , KC_F3   , KC_INS  , _______ , _______ , _______ , _______ , _______ ,  _______ ,
    _______ , _______ , _______ , ADJUST  , _______ , _______           , _______ , _______ , _______ , _______ , _______
),
[_ADJUST] = LAYOUT_planck_mit(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    DEBUG   , _______ , _______ , AU_ON   , AU_OFF  , _______ , _______ , QWERTY  , COLEMAK , DVORAK  , _______ , RESET   ,
    _______ , _______ , _______ , MU_ON   , MU_OFF  , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),

};
