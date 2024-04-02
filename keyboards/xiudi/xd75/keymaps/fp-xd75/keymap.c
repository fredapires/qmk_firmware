/*
fp-xd75 keyboard mapping

*/
#include "xd75.h"
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"
#include "eeconfig.h"
#include "eeprom.h"
#include "config.h"

extern keymap_config_t keymap_config;

enum ergodox_layers {
   _BASE
  ,_LNUM
  ,_RNAV
  ,_BOTH
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};


// -----------------------------------
// Layer switch keycodes
// -----------------------------------
#define TO_BASE TO(_BASE)
#define MO_LNUM MO(_LNUM)
#define MO_RNAV MO(_RNAV)
#define MO_BOTH MO(_BOTH)

// -----------------------------------
// Custom Keycodes
// -----------------------------------
// System
#define KC_ALF4 LALT(KC_F4)   // Alt + F4
#define KC_CADE LCTL(LALT(KC_DEL)) // Ctrl + Alt + Del ; 
#define KC_WNME LGUI(KC_X)             // GUI + X ; Windows menu
#define KC_GTAB LGUI(KC_TAB)           // GUI + Tab

#define KC_CTLW LCTL(KC_W)             // Ctrl + W ; close tab in various applications
#define KC_CTF4 LCTL(KC_F4)             // Ctrl + F4 ; close tab in various applications

#define KC_SSHK MEH(KC_F12)            // Ctrl + Shift + Alt + F12 ; WHAT IS THIS?
#define KC_MEHT MEH(KC_TAB)            // Ctrl + Shift + Alt + Tab ; WHAT IS THIS?


// Navigation
#define KC_LSGU SWIN(KC_LEFT)          // GUI + Shift + Left ; desktop left
#define KC_RSGU SWIN(KC_RGHT)          // GUI + Shift + Right ; desktop right
#define KC_LCGU LCTL(LGUI(KC_LEFT))    // GUI + Ctrl + Left ;
#define KC_RCGU LCTL(LGUI(KC_RGHT))    // GUI + Ctrl + Right ;


#define KC_ALTT LALT(KC_TAB)           // Alt + Tab ; Alt tab right
#define KC_ALTL LALT(LSFT(KC_TAB))     // Alt + Shift + Tab ; Alt tab left

#define KC_ESCT LALT(KC_ESC)           // Alt + Esc ; Esc tab right
#define KC_ESCL LALT(LSFT(KC_ESC))     // Alt + Shift + Esc ; Esc tab left

#define KC_CTAB LCTL(KC_TAB)           // Ctrl + Tab ; next tab in various applications
#define KC_CSTA LCTL(LSFT(KC_TAB))     // Ctrl + Shift + Tab ; previous tab in various applications

#define KC_CPGD LCTL(KC_PGDN)          // Ctrl + PgDn ; next tab in various applications
#define KC_CPGU LCTL(KC_PGUP)          // Ctrl + PgUp ; previous tab in various applications
#define KC_STAB LSFT(KC_TAB)           // Shift + Tab ; 

// Shift Layer (OLD)
#define KC_SFTA LSFT(KC_A)
#define KC_SFTQ LSFT(KC_Q)
#define KC_SFTW LSFT(KC_W)
#define KC_SFTE LSFT(KC_E)
#define KC_SFTR LSFT(KC_R)
#define KC_SFTT LSFT(KC_T)
#define KC_SFTG LSFT(KC_G)
#define KC_SFTZ LSFT(KC_Z)
#define KC_SFTX LSFT(KC_X)
#define KC_SFTV LSFT(KC_V)
#define KC_SFTB LSFT(KC_B)

// Arithmetic
#define KC_UNDR LSFT(KC_MINS)   // Minus
#define KC_PLUS LSFT(KC_EQL)    // Plus
#define KC_GRTN LSFT(KC_DOT)    // Greater than
#define KC_LSTN LSFT(KC_COMM)   // Less than
#define KC_MULT LSFT(KC_8)      // Multiply

// Coding
#define KC_CSPC LCTL(KC_SPC)        // Ctrl + Space ; Intellisense / Auto Suggest
#define KC_CSLS LCTL(KC_SLSH)       // Ctrl + Slash ; comment / uncomment
#define KC_CENT LCTL(KC_ENT)        // Ctrl + Enter ; execute code
#define KC_CANT LALT(LCTL(KC_ENT))  // Ctrl + Alt + Enter ; Replace all
#define KC_CENT LCTL(KC_ENT)        // Ctrl + Enter ; execute code

#define KC_VSCP LCTL(LSFT(KC_P))    // Ctrl + Shift + P ; VS Code Command pallete
#define KC_ALTQ LALT(KC_Q)          // Alt + Q ; VS Code Command pallete ; various office search
#define KC_ASFZ LALT(LSFT(KC_0))    // Alt + Shift + 0 ; VS Code pivot view

#define KC_SF12 LSFT(KC_F12)        // Shift + F12 ; VS Code peek definition
#define KC_AS12 LALT(LSFT(KC_F12))  // Alt + Shift + F12 ; VS Code go to definition


#define KC_LPAR LSFT(KC_9)          // Open parenthesis
#define KC_RPAR LSFT(KC_0)          // Close parenthesis

#define KC_LCBR LSFT(KC_LBRC)       // Open curly brackets
#define KC_RCBR LSFT(KC_RBRC)       // Close curly brackets

// Excel
#define KC_LCA9 LCA(KC_F9) // Ctrl + Alt + F9 ; Excel recalc all sheets
#define KC_SF11 LSFT(KC_F11) // Shft + F11 ; Excel new sheet // SOMEDAY 22-03-27: adapt excel convention to conform with other applications; aka change this to Ctrl + T or something

// Homerow tap-Hold definitions
#define KC_LCKA LCTL_T(KC_A)    // LCtl over A
#define KC_LGKS LGUI_T(KC_S)    // LGui over S
#define KC_LAKD LALT_T(KC_D)    // LAlt over D
#define KC_LSKF LSFT_T(KC_F)    // LSft over F
   // 
#define KC_RSKJ RSFT_T(KC_J)    // RSft over J
#define KC_RAKK RALT_T(KC_K)    // RAlt over K
#define KC_RGKL RGUI_T(KC_L)    // RGui over L
#define KC_RCKS RCTL_T(KC_SCLN) // RCtl over Semicolon


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 [_BASE] = {
  { QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_DEL,	 	KC_TRNS,    KC_DEL,     KC_6,       KC_7,    KC_8,    KC_9,    KC_0,   	KC_TRNS },
  { KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_LPAR,	KC_TRNS,    KC_RPAR,    KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,   	KC_DEL  },
  { KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_TRNS,	KC_TRNS,    KC_TRNS,    KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN,	KC_ENT	},
  { KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_LBRC,	KC_TRNS,    KC_RBRC,    KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT	},
  { KC_WNME,    KC_LGUI, KC_INS,  KC_APP,  KC_LALT, MO_LNUM,    KC_SPC,		KC_UNDR,    KC_BSPC,    MO_RNAV,    KC_RALT, KC_TRNS, KC_TRNS, KC_QUOT, KC_TRNS },
 },
 
[_LNUM] = {
  { KC_TRNS, 	KC_F1,   	KC_F2, KC_F3,  KC_F4,  KC_F5,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  },
  { KC_TRNS, 	KC_PAST, 	KC_7,  KC_8,   KC_9,   KC_PLUS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  },
  { KC_TRNS, 	KC_LSTN,    KC_4,  KC_5,   KC_6,   KC_GRTN, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  },
  { KC_TRNS, 	KC_SLSH, 	KC_1,  KC_2,   KC_3,   KC_MINS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  },
  { KC_SF11, 	KC_LCA9, 	KC_0,  KC_DOT, KC_EQL, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, MO_BOTH,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  },
 },

[_RNAV] = {
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_F6,   	KC_F7,      KC_F8,   KC_F9,   	KC_F10,  	KC_ALF4 },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_LCGU, 	KC_PGUP,    KC_UP,   KC_PGDN, 	KC_TRNS, 	KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_HOME, 	KC_LEFT,    KC_DOWN, KC_RGHT, 	KC_END,  	KC_RCTL },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_LSGU, 	KC_CSTA,    KC_TRNS, KC_CTAB, 	KC_RSGU, 	KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO_BOTH,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, 	KC_TRNS, 	KC_TRNS, KC_TRNS, 	KC_TRNS, 	KC_TRNS },
 },
 
[_BOTH] = {
  { KC_TRNS, 	KC_F1,   	KC_F2, KC_F3,  KC_F4,  KC_F5,   KC_TRNS,    KC_TRNS, KC_TRNS,   KC_F6,   	KC_F7,      KC_F8,   KC_F9,   	KC_F10,  	KC_ALF4 },
  { KC_TRNS, 	KC_PAST, 	KC_7,  KC_8,   KC_9,   KC_PLUS, KC_TRNS,    KC_TRNS, KC_TRNS,   KC_LCGU, 	KC_PGUP,    KC_UP,   KC_PGDN, 	KC_TRNS, 	KC_TRNS },
  { KC_TRNS, 	KC_LSTN,    KC_4,  KC_5,   KC_6,   KC_GRTN, KC_TRNS,    KC_TRNS, KC_TRNS,   KC_HOME, 	KC_LEFT,    KC_DOWN, KC_RGHT, 	KC_END,  	KC_RCTL },
  { KC_TRNS, 	KC_SLSH, 	KC_1,  KC_2,   KC_3,   KC_MINS, KC_TRNS,    KC_TRNS, KC_TRNS,   KC_LSGU, 	KC_CSTA,    KC_TRNS, KC_CTAB, 	KC_RSGU, 	KC_TRNS },
  { KC_SF11, 	KC_LCA9, 	KC_0,  KC_DOT, KC_EQL, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS, 	KC_TRNS, 	KC_TRNS, KC_TRNS, 	KC_TRNS, 	KC_TRNS },
}
}; 

const uint16_t PROGMEM fn_actions[] = {

};
