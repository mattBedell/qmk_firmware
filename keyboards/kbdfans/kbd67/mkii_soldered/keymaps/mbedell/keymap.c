#include QMK_KEYBOARD_H


LEADER_EXTERNS();

typedef struct {
  bool is_press_action;
  int state;
} tap;


enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6,
};

enum {
  MEGA_TAB = 0,
  MEGA_CAPS,
  MEGA_ENT,
};


// Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void mega_tab_finished (qk_tap_dance_state_t *state, void *user_data);
void mega_tab_reset (qk_tap_dance_state_t *state, void *user_data);

void mega_caps_finished (qk_tap_dance_state_t *state, void *user_data);
void mega_caps_reset (qk_tap_dance_state_t *state, void *user_data);

void mega_enter_finished (qk_tap_dance_state_t *state, void *user_data);
void mega_enter_reset (qk_tap_dance_state_t *state, void *user_data);


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

    // send window to desktop next
    SEQ_THREE_KEYS(KC_S, KC_N, KC_D) {
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

    // send window to desktop recent
    SEQ_THREE_KEYS(KC_S, KC_R, KC_D) {
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

    // send window to desktop previous
    SEQ_THREE_KEYS(KC_S, KC_P, KC_D) {
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

    // send window to monitor next
    SEQ_THREE_KEYS(KC_S, KC_N, KC_M) {
      register_code(KC_LGUI);
      register_code(KC_LCTL);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LGUI);
      unregister_code(KC_LCTL);
    }

    // send window to monitor recent
    SEQ_THREE_KEYS(KC_S, KC_R, KC_M) {
      register_code(KC_LGUI);
      register_code(KC_LCTL);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LGUI);
      unregister_code(KC_LCTL);
    }

    // send window to monitor previous
    SEQ_THREE_KEYS(KC_S, KC_P, KC_M) {
      register_code(KC_LGUI);
      register_code(KC_LCTL);
      register_code(KC_Z);
      unregister_code(KC_Z);
      unregister_code(KC_LGUI);
      unregister_code(KC_LCTL);
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
    KC_GRV,        KC_1,            KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_BSPC,      KC_HOME,
    TD(MEGA_TAB),  KC_Q,            KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,               KC_BSLS,      LGUI(LALT(KC_X)),
    TD(MEGA_CAPS), KC_A,            KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          TD(MEGA_ENT),               LGUI(LALT(KC_Z)),
    KC_LSPO,       KC_LSPO,         KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,               KC_UP,        LGUI(LALT(KC_C)),
    KC_LGUI,       LALT_T(KC_CAPS), KC_LGUI,           KC_NO,            KC_SPC,           KC_NO,            KC_RGUI, KC_LEAD,          KC_LEFT,      KC_DOWN,      KC_RGHT
  ),
  [1] = LAYOUT_all(
    _______,   KC_F1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(LGUI(KC_Q)),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, LCTL(LALT(KC_X)),
    _______,  KC_TAB,  KC_GRV, _______, KC_PGDN, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,          _______,          LCTL(LALT(KC_Z)),
    _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,          _______, LCTL(LALT(KC_C)),
    _______, _______, _______,          _______,          _______,          _______,          _______, _______,          _______, _______, _______
  )
};

// Determine the current tap dance state
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    if (!state->pressed) {
      return DOUBLE_TAP;
    } else {
      return DOUBLE_HOLD;
    }
  } else if (state->count == 3) {
    if (!state->pressed) {
      return TRIPLE_TAP;
    } else {
      return TRIPLE_HOLD;
    }
  } else return 8;
}

// Initialize tap structure associated with tap dance key
static tap mega_tab_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap mega_caps_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap mega_enter_tap_state = {
  .is_press_action = true,
  .state = 0
};

void mega_tab_finished (qk_tap_dance_state_t *state, void *user_data) {
  mega_tab_tap_state.state = cur_dance(state);
  switch (mega_tab_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_TAB);
      break;
    case SINGLE_HOLD:
      layer_on(1);
      break;
    case DOUBLE_TAP:
      SEND_STRING("-");
      break;
  }
}

void mega_tab_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (mega_tab_tap_state.state==SINGLE_HOLD) {
    layer_off(1);
  }
  if (mega_tab_tap_state.state==DOUBLE_HOLD) {
    clear_keyboard();
  }
  mega_tab_tap_state.state = 0;
}

void mega_caps_finished (qk_tap_dance_state_t *state, void *user_data) {
  mega_caps_tap_state.state = cur_dance(state);
  switch (mega_caps_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_ESC);
      break;
    case SINGLE_HOLD:
      register_code16(KC_LCTL);
      break;
  }
}

void mega_caps_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (mega_caps_tap_state.state==SINGLE_HOLD) {
    clear_keyboard();
  }
  mega_caps_tap_state.state = 0;
}

void mega_enter_finished (qk_tap_dance_state_t *state, void *user_data) {
  mega_enter_tap_state.state = cur_dance(state);
  switch (mega_enter_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_ENT);
      break;
    case SINGLE_HOLD:
      layer_on(1);
      register_code16(KC_LGUI);
      break;
  }
}

void mega_enter_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (mega_enter_tap_state.state==SINGLE_HOLD) {
    layer_off(1);
    clear_keyboard();
  }
  mega_enter_tap_state.state = 0;
}

//Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [MEGA_TAB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, mega_tab_finished, mega_tab_reset, 275),
  [MEGA_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, mega_caps_finished, mega_caps_reset, 275),
  [MEGA_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mega_enter_finished, mega_enter_reset)
};
