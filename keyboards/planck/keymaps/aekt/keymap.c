#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _DUMMY_LED_LEFT = 3,
  _DUMMY_LED_RIGHT = 4,
  _DUMMY_NONE = 5,
  _DUMMY_LED_BOTH = 6,
  _FN_XX,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define FN_XX MO(_FN_XX)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)
#define DVORAK DF(_DVORAK)

#define CTL_ESC MT(MOD_LCTL, KC_ESCAPE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
    CTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_COLEMAK] = LAYOUT_planck_mit(
    KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_BSPC ,
    CTL_ESC , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT ,
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
    FN_XX   , KC_LCTL , KC_LALT , KC_LGUI , LOWER   , KC_SPC            , RAISE   , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),
[_DVORAK] = LAYOUT_planck_mit(
    KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_BSPC ,
    CTL_ESC , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_SLSH ,
    KC_LSFT , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_ENT  ,
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
    KC_DEL  , _______ , _______ , _______ , _______ , _______ , _______ , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_HOME , KC_END  , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
    KC_DEL  , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_NUHS , KC_NUBS , KC_PGUP , KC_PGDN , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),
[_ADJUST] = LAYOUT_planck_mit(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    DEBUG   , _______ , _______ , AU_ON   , AU_OFF  , _______ , _______ , QWERTY  , COLEMAK , DVORAK  , _______ , RESET   ,
    _______ , _______ , _______ , MU_ON   , MU_OFF  , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
}
return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
