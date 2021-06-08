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
  MEGA_BSLS = 0,
  MEGA_SHIFT,
};


// Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void mega_bsls_finished (qk_tap_dance_state_t *state, void *user_data);
void mega_bsls_reset (qk_tap_dance_state_t *state, void *user_data);

void mega_shift_finished (qk_tap_dance_state_t *state, void *user_data);
void mega_shift_reset (qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
    KC_GRV,         KC_1,            KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_BSPC,       KC_HOME,
    LT(1, KC_TAB),  KC_Q,            KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,               TD(MEGA_BSLS), KC_PGUP,
    LCTL_T(KC_ESC), KC_A,            KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                      KC_PGDN,
    TD(MEGA_SHIFT), KC_LSFT,         KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,               KC_UP,         KC_END,
    KC_CAPS,        KC_LALT,         KC_LGUI,           KC_NO,            KC_SPC,           KC_NO,            KC_RGUI, KC_RALT,          KC_LEFT,      KC_DOWN,      KC_RGHT
  ),
  [1] = LAYOUT_all(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, LCTL(LGUI(KC_Q)),
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
static tap mega_shift_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap mega_bsls_tap_state = {
  .is_press_action = true,
  .state = 0
};

void mega_bsls_finished (qk_tap_dance_state_t *state, void *user_data) {
  mega_bsls_tap_state.state = cur_dance(state);
  switch (mega_bsls_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_BSLS);
      break;
    case SINGLE_HOLD:
      layer_on(1);
      register_code16(KC_LGUI);
      break;
  }
}

void mega_bsls_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (mega_bsls_tap_state.state==SINGLE_HOLD) {
    layer_off(1);
    clear_keyboard();
  }
  mega_bsls_tap_state.state = 0;
}

void mega_shift_finished (qk_tap_dance_state_t *state, void *user_data) {
  mega_shift_tap_state.state = cur_dance(state);
  switch (mega_shift_tap_state.state) {
    case SINGLE_HOLD:
      register_code(KC_LSFT);
      break;
    case DOUBLE_HOLD:
      register_code(KC_LSFT);
      register_code(KC_LALT);
      register_code(KC_LGUI);
      register_code(KC_LCTL);
      break;
  }
}

void mega_shift_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (mega_shift_tap_state.state==SINGLE_HOLD) {
    clear_keyboard();
  }
  if (mega_shift_tap_state.state==DOUBLE_HOLD) {
    clear_keyboard();
  }
  mega_shift_tap_state.state = 0;
}


//Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [MEGA_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mega_bsls_finished, mega_bsls_reset),
  [MEGA_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, mega_shift_finished, mega_shift_reset, 275),
};

