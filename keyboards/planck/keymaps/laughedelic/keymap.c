/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _WORKMAN,
  _RUSSIAN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  WORKMAN = SAFE_RANGE,
  RUSSIAN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Russian alphabet
#define RU_A  UC(0x0430) // А
#define RU_B  UC(0x0431) // Б
#define RU_V  UC(0x0432) // В
#define RU_G  UC(0x0433) // Г
#define RU_D  UC(0x0434) // Д
#define RU_YE UC(0x0435) // Е
#define RU_ZH UC(0x0436) // Ж
#define RU_Z  UC(0x0437) // З
#define RU_I  UC(0x0438) // И
#define RU_YI UC(0x0439) // Й
#define RU_K  UC(0x043A) // К
#define RU_L  UC(0x043B) // Л
#define RU_M  UC(0x043C) // М
#define RU_N  UC(0x043D) // Н
#define RU_O  UC(0x043E) // О
#define RU_P  UC(0x043F) // П
#define RU_R  UC(0x0440) // Р
#define RU_S  UC(0x0441) // С
#define RU_T  UC(0x0442) // Т
#define RU_U  UC(0x0443) // У
#define RU_F  UC(0x0444) // Ф
#define RU_H  UC(0x0445) // Х
#define RU_TS UC(0x0446) // Ц
#define RU_CH UC(0x0447) // Ч
#define RU_SH UC(0x0448) // Ш
#define RU_X  UC(0x0449) // Щ
#define RU_HS UC(0x044A) // Ъ
#define RU_Y  UC(0x044B) // Ы
#define RU_SS UC(0x044C) // Ь
#define RU_E  UC(0x044D) // Э
#define RU_YU UC(0x044E) // Ю
#define RU_YA UC(0x044F) // Я
#define RU_YO UC(0x0451) // Ё

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman (https://workmanlayout.org) */
[_WORKMAN] = LAYOUT_planck_grid(
    LALT_T(KC_ESC), KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,          KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSLS,
    LCTL_T(KC_TAB), KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,          KC_N,    KC_E,    KC_O,    KC_I,    RCTL_T(KC_ENT),
    SFT_T(KC_TILD), KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,          KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
     LCMD(KC_TILD), RCMD(KC_LBRC), RCMD(KC_RBRC), KC_LCMD, LOWER, KC_BSPC, SFT_T(KC_SPC), RAISE, KC_RALT, RCMD(KC_LCBR), RCMD(KC_RCBR), RALT(KC_QUOT)
),

[_RUSSIAN] = LAYOUT_planck_grid(
    LALT_T(KC_ESC), RU_YI, RU_TS, RU_U,  RU_K,  RU_YE, RU_N,  RU_G,  RU_SH, RU_X,  RU_Z,  RU_H,
    LCTL_T(KC_TAB), RU_F,  RU_Y,  RU_V,  RU_A,  RU_P,  RU_R,  RU_O,  RU_L,  RU_D,  RU_ZH, RCTL_T(KC_ENT),
    SFT_T(KC_TILD), RU_YA, RU_S,  RU_CH, RU_M,  RU_I,  RU_T,  RU_SS, RU_B,  RU_YU, RU_E,  KC_QUOT,
     LCMD(KC_TILD), RCMD(KC_LBRC), RCMD(KC_RBRC), KC_LCMD, LOWER, KC_BSPC, SFT_T(KC_SPC), RAISE, KC_RALT, RCMD(KC_LCBR), RCMD(KC_RCBR), RALT(KC_QUOT)
),

[_LOWER] = LAYOUT_planck_grid(
  KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
  KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_PLUS, KC_MINS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX,
  KC_LSFT,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL, KC_UNDS, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
  _______, _______, _______, KC_LCMD,   LOWER, KC_BSPC, SFT_T(KC_SPC), _______, KC_RALT, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
  KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  KC_LSFT, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, KC_LCMD, KC_LALT, KC_BSPC, SFT_T(KC_SPC), RAISE, KC_RALT, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, _______,  DEBUG,   RESET,   WORKMAN, _______, _______, RUSSIAN, _______,  _______, _______, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, A(KC_LEFT), A(KC_DOWN), A(KC_UP), A(KC_RIGHT), _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RUSSIAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RUSSIAN);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
  }
  return true;
}

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

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
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
