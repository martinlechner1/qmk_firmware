#include QMK_KEYBOARD_H
#include "action_layer.h"

#define BASE 0
#define FN 1
#define COOL 2

#define XXXXXX KC_NO
#define ______ KC_TRNS

enum custom_keycodes { MAC_AE = SAFE_RANGE, MAC_OE, MAC_SS, MAC_UE, MAC_SHFT };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // 0: Base Layer
    [BASE] = LAYOUT_all(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV, \
                        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, \
                        MO(FN), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NO, KC_ENT, \
                        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RSFT, MO(FN), \
                        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),

    // 1: Function Layer
    [FN] = LAYOUT_all(TO(COOL), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL, KC_CAPS, ______, ______, KC_WH_D, ______, KC_HOME, KC_CALC, MAC_UE, KC_INS, MAC_OE, KC_PSCR, KC_UP, KC_PAUS, ______, ______, MAC_AE, MAC_SS, KC_RIGHT, ______, KC_PLUS, KC_ASTR, KC_SLSH, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT, ______, KC_ENT, ______, ______, ______, KC_APP, ______, ______, ______, KC_PLUS, KC_MINS, KC_END, KC_PGDN, KC_DOWN, KC_RSFT, KC_RSFT, ______, ______, ______, ______, KC_SPC, KC_RGUI, KC_MUTE, KC_VOLD, KC_VOLU, KC_HOME),

    [COOL] = LAYOUT_all(RESET, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLU, KC_VOLD, XXXXXX, XXXXXX, RGB_TOG, RGB_M_P, RGB_MOD, RGB_VAD, RGB_VAI, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, BL_TOGG, BL_DEC, BL_INC, BL_BRTG, BL_OFF, BL_ON, BL_STEP, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, ______, ______, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, TO(BASE)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MAC_UE:
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    clear_keyboard();
                    SEND_STRING(SS_LALT("u") SS_LSFT("u"));
                } else {
                    SEND_STRING(SS_LALT("u") "u");
                }
                return false;
            case MAC_AE:
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    clear_keyboard();
                    SEND_STRING(SS_LALT("u") SS_LSFT("a"));
                } else {
                    SEND_STRING(SS_LALT("u") "a");
                }
                return false;
            case MAC_OE:
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    clear_keyboard();
                    SEND_STRING(SS_LALT("u") SS_LSFT("o"));
                } else {
                    SEND_STRING(SS_LALT("u") "o");
                }
                return false;
            case MAC_SS:
                SEND_STRING(SS_LALT("s"));
                return false;
        }
    }
    return true;
};

// // Custom Actions
// const uint16_t PROGMEM fn_actions[] = {
//     [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
// };

// // Macros
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

//   // MACRODOWN only works in this function
//   switch(id) {
//     case 0:
//       if (record->event.pressed) { register_code(KC_RSFT); }
//       else { unregister_code(KC_RSFT); }
//       break;
//   }

//   return MACRO_NONE;
// };

// Loop
void matrix_scan_user(void){
    // Empty
};
