#include QMK_KEYBOARD_H


LEADER_EXTERNS();


void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

		// focus next desktop
    SEQ_THREE_KEYS(KC_F, KC_N, KC_D) {
      SEND_STRING(SS_LGUI(SS_LALT("c")));
    }

		// focus recent desktop
		SEQ_THREE_KEYS(KC_F, KC_R, KC_D) {
      SEND_STRING(SS_LGUI(SS_LALT("x")));
    }

		// focus previous desktop
    SEQ_THREE_KEYS(KC_F, KC_P, KC_D) {
      SEND_STRING(SS_LGUI(SS_LALT("z")));
    }

		// focus next monitor
    SEQ_THREE_KEYS(KC_F, KC_N, KC_M) {
      SEND_STRING(SS_LCTL(SS_LALT("c")));
    }

		// focus recent monitor
		SEQ_THREE_KEYS(KC_F, KC_R, KC_M) {
      SEND_STRING(SS_LCTL(SS_LALT("x")));
    }

		// focus previous monitor
    SEQ_THREE_KEYS(KC_F, KC_P, KC_M) {
      SEND_STRING(SS_LCTL(SS_LALT("z")));
    }

		// move window left
    SEQ_THREE_KEYS(KC_M, KC_W, KC_L) {
      SEND_STRING(SS_LSFT(SS_LGUI("h")));
    }

		// move window right
    SEQ_THREE_KEYS(KC_M, KC_W, KC_R) {
      SEND_STRING(SS_LSFT(SS_LGUI("l")));
    }

		// move window up
    SEQ_THREE_KEYS(KC_M, KC_W, KC_U) {
      SEND_STRING(SS_LSFT(SS_LGUI("k")));
    }

		// move window down
    SEQ_THREE_KEYS(KC_M, KC_W, KC_D) {
      SEND_STRING(SS_LSFT(SS_LGUI("j")));
    }

		// swap window left
		SEQ_THREE_KEYS(KC_S, KC_W, KC_L) {
      SEND_STRING(SS_LSFT(SS_LALT("h")));
    }

		// swap window right
		SEQ_THREE_KEYS(KC_S, KC_W, KC_R) {
      SEND_STRING(SS_LSFT(SS_LALT("l")));
    }

		// swap window up
		SEQ_THREE_KEYS(KC_S, KC_W, KC_U) {
      SEND_STRING(SS_LSFT(SS_LALT("k")));
    }

		// swap window down
		SEQ_THREE_KEYS(KC_S, KC_W, KC_D) {
      SEND_STRING(SS_LSFT(SS_LALT("j")));
    }

		// send window to monitor next
		SEQ_THREE_KEYS(KC_S, KC_N, KC_M) {
			register_code(KC_LSFT);
			register_code(KC_LALT);
			register_code(KC_LGUI);
			register_code(KC_LCTL);
			register_code(KC_C);
			unregister_code(KC_C);
			unregister_code(KC_LSFT);
			unregister_code(KC_LALT);
			unregister_code(KC_LGUI);
			unregister_code(KC_LCTL);
    }

		// send window to monitor recent
		SEQ_THREE_KEYS(KC_S, KC_R, KC_M) {
			register_code(KC_LSFT);
			register_code(KC_LALT);
			register_code(KC_LGUI);
			register_code(KC_LCTL);
			register_code(KC_X);
			unregister_code(KC_X);
			unregister_code(KC_LSFT);
			unregister_code(KC_LALT);
			unregister_code(KC_LGUI);
			unregister_code(KC_LCTL);
    }

		// send window to monitor previous
		SEQ_THREE_KEYS(KC_S, KC_P, KC_M) {
			register_code(KC_LSFT);
			register_code(KC_LALT);
			register_code(KC_LGUI);
			register_code(KC_LCTL);
			register_code(KC_Z);
			unregister_code(KC_Z);
			unregister_code(KC_LSFT);
			unregister_code(KC_LALT);
			unregister_code(KC_LGUI);
			unregister_code(KC_LCTL);
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_all(
		KC_ESC,             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_BSPC,  KC_HOME,
		LT(1, KC_TAB),              KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    HYPR_T(KC_LBRC), KC_RBRC,           KC_BSLS,  TO(1),
		LCTL_T(KC_ESC),     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,    KC_QUOT,          KC_ENT,             KC_PGDN,
		KC_LSPO,         KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,    KC_N,    KC_M, KC_COMM,          KC_DOT,    KC_SLSH, KC_RSPC,             KC_UP,    LCTL(LGUI(KC_Q)),
		LCTL_T(KC_CAPS), KC_LALT, KC_LGUI,   KC_NO,                          KC_SPC,             KC_NO,         RGUI_T(KC_UNDS),    KC_LEAD,         KC_LEFT,   KC_DOWN,   KC_RGHT
	),
	[1] = LAYOUT_all(
		TO(0),    KC_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,       _______,
		_______, _______, _______, _______, KC_PGDN, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, RGUI(KC_TAB), RGUI(KC_GRV),          _______,                _______,
		_______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,             HYPR(KC_K), _______,
		_______, _______, _______,          _______,          _______,          _______,          _______, _______,          HYPR(KC_H), HYPR(KC_J), HYPR(KC_L)
	)
};
