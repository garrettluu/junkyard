#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(ESC,  1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   BSPC, \
           TAB,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,    ENT, \
           LGUI, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, \
           LSFT, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, UP,  RSFT, \
           LCTL, LGUI,FN3, LALT, FN1, FN2,     LALT, FN4,LEFT,DOWN,RIGHT),

    KEYMAP( GRV,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  DEL, \
            INS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LBRC, RBRC, TRNS, BSLS, \
           CAPS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  FN5,  FN6, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, SLSH, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS, TRNS, FN7),

    KEYMAP(TRNS,  F11,  F12, VOLD, VOLU, TRNS, TRNS, TRNS, TRNS, MINS,  EQL, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS),

    KEYMAP(TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, SPC,        FN0,  TRNS,  TRNS, TRNS, TRNS),


    /* Blank keymap for function layers
     * KEYMAP(TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS),*/

};

enum macro_id {
	TERM,
	LCB,
	RCB,
	LEFT
};

const action_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1), //FN0, currently unused
  [1] = ACTION_LAYER_MOMENTARY(2), //FN1, layer 2
  [2] = ACTION_LAYER_TAP_KEY(1, KC_SPC), //Hold space for layer 1
  [3] = ACTION_MACRO(TERM), //Terminal Macro
  [4] = ACTION_LAYER_TOGGLE(3), //Game mode
  [5] = ACTION_MACRO(LCB),
  [6] = ACTION_MACRO(RCB),
  [7] = ACTION_MACRO(LEFT)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	switch(id){
		case TERM:
			return (record->event.pressed ?
				MACRO( D(LCTRL), D(LALT), D(T), END) : 
				MACRO( U(LCTRL), U(LALT), U(T), END)
					);
		case LCB:
			return (record->event.pressed ?
					MACRO( D(LSFT), D(LBRC), END) :
					MACRO( U(LSFT), U(LBRC), END)
			       );
		case RCB:
			return (record->event.pressed ?
					MACRO( D(LSFT), D(RBRC), END) :
					MACRO( U(LSFT), U(RBRC), END)
			       );
		case LEFT:
			return (record->event.pressed ?
					MACRO( D(MINS), D(LSFT), D(DOT), END) :
					MACRO( U(MINS), U(LSFT), U(DOT), END)
				);

	}
	return MACRO_NONE;
}
