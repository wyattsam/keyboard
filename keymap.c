#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 4 // symbols
#define MDIA 2 // media keys
#define NAV  3 // navigation layer
#define BASE_SFT 1 // applies shift to all keys in base layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  =     |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Alt    |A/~L1 |   O  |   E  | U/SFT|   I  |------|           |------|   D  | H/SFT|   T  |   N  | S/L3 | - / L2 |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/SHFT|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RESET |  '"  |  :   | Left | Right|                                       |  Up  | Down |   [  |   ]  | LSFT |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | App  |       | Alt  |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | BkSp | Esc  |------|       |------|  Tab   |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default

    // left Hand
    KC_EQUAL,   KC_1,                   KC_2,               KC_3,       KC_4,       KC_5,       KC_WAKE,
    KC_TAB,     KC_QUOT,                KC_COMM,            KC_DOT,     KC_P,       KC_Y,       KC_LEFT,
    KC_LALT,    KC_A,                   KC_O,               KC_E,       KC_U,       KC_I,
    KC_LSFT,   MT(MOD_LSFT, KC_SCLN),  KC_Q,               KC_J,       KC_K,       KC_X,       KC_RGHT,
    KC_LCTRL,    KC_QUOT,                LSFT(KC_SCOLON),    KC_LEFT,    KC_RGHT,

    // Left Thumb Group
    KC_LGUI,     KC_PGUP,
    KC_LSFT,
    MO(BASE_SFT),  KC_BSPC, KC_ESC,

    // Right Hand
    KC_PWR,     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSLS,
    KC_UP,      KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_SLSH,
                KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       LT(MDIA, KC_MINS),
    KC_DOWN,    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_LSFT,
    KC_UP,      KC_DOWN,    KC_PGUP,    KC_PGDN,    KC_LCTRL,

    //Right Thumb Group
    KC_PGDN,    KC_LCTRL,
    MO(NAV),
    KC_ENT,     KC_SPACE,  MO(SYMB)
),


[BASE_SFT] = KEYMAP(
    // Left Hand
    LSFT(KC_EQUAL), LSFT(KC_1),         LSFT(KC_2),     LSFT(KC_3),   LSFT(KC_4), LSFT(KC_5),   LSFT(KC_LEFT),  
    LSFT(KC_TAB),   LSFT(KC_QUOT),      LSFT(KC_COMM),  LSFT(KC_DOT), LSFT(KC_P), LSFT(KC_Y),   LALT(KC_LEFT), 
    KC_SPACE,       LSFT(KC_A),         LSFT(KC_O),     LSFT(KC_E),   LSFT(KC_U), LSFT(KC_I),   
    LSFT(KC_LSFT),  LSFT(KC_SCLN),      LSFT(KC_Q),     LSFT(KC_J),   LSFT(KC_K), LSFT(KC_X),   LALT(KC_RGHT),    
    RESET,          KC_UP,              KC_DOWN,        KC_LEFT,      KC_RGHT,    

    // Left Thumb Group
    KC_TRNS,    KC_TRNS,    
    KC_TRNS,    
    KC_TRNS,    KC_TRNS,    KC_TRNS,    
    
    // Right Hand
    LSFT(KC_RGHT),  LSFT(KC_6),     LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),     LSFT(KC_0),     LSFT(KC_BSLS),  
    KC_TRNS,        LSFT(KC_F),     LSFT(KC_G),     LSFT(KC_C),     LSFT(KC_R),     LSFT(KC_L),     LSFT(KC_SLSH),  
    LSFT(KC_D),     LSFT(KC_H),     LSFT(KC_T),     LSFT(KC_N),     LSFT(KC_S),     LSFT(KC_MINS),  
    KC_TRNS,        LSFT(KC_B),     LSFT(KC_M),     LSFT(KC_W),     LSFT(KC_V),     LSFT(KC_Z),     KC_SPACE,   
    LSFT(KC_UP),    KC_DOWN,        LSFT(KC_LBRC),  LSFT(KC_RBRC),  LSFT(KC_LSFT),  
    //ighthumb
    KC_TRNS,    KC_TRNS,    
    KC_TRNS,    
    KC_TRNS,    KC_TRNS,    KC_BSPC
    ),  


        /* Keymap 1: Symbol Layer
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |        |  F1  |  F2  |  F3  |  F4  |  F5  | $    |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |      |   =  |   (  |   )  |   #  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |      |      |      |      |                                       |   0  |    . |   0  |   =  |      |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      | ALT  |      |       |      |      |      |
         *                                 |      | TILDE|------|       |------|      |      |
         *                                 |      |      |      |       |      |      |      |
         *                                 `--------------------'       `--------------------'
         */
// SYMBOLS
[SYMB] = KEYMAP(
        // Left Hand
        KC_GRV,         KC_F1,          KC_F2,          KC_F3,          KC_F4,      KC_F5,      LSFT(KC_4), 
        LSFT(KC_TAB),   LSFT(KC_QUOT),  LSFT(KC_COMMA), LSFT(KC_DOT),   KC_LCBR,    KC_RCBR,    KC_PIPE,    
        KC_EXLM,        KC_BSPC,        KC_EQUAL,       KC_LPRN,        KC_RPRN,    KC_HASH,    
        KC_TRNS,        LSFT(KC_SCLN),  KC_CIRC,        KC_LBRC,        KC_RBRC,    KC_TILD,    LSFT(KC_SLSH),  
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    

        // Left Thumb Group
        KC_TRNS,    KC_TRNS,    
        KC_TRNS,    
        KC_SPACE,   KC_TRNS,    KC_TRNS,    

        // Right Hand
        KC_TRNS,    KC_F6,      KC_F7,  KC_F8,      KC_F9,      KC_F10,         KC_F11,   
        KC_AT,      KC_COMMA,   KC_7,   KC_8,       KC_9,       KC_ASTR,        KC_BSLS,   
        KC_DOT,     KC_4,       KC_5,   KC_6,       KC_PLUS,    LSFT(KC_MINS), 
        LSFT(KC_5), KC_AMPR,    KC_1,   KC_2,       KC_3,       KC_BSLS,        KC_TRNS,   
        KC_0,       KC_DOT,     KC_0,   KC_EQL,     KC_POWER, 

        // Right Thumb Group
        KC_TRNS,    KC_TRNS,    
        KC_TRNS,    
        KC_TRNS,    KC_TRNS,     KC_TRNS
        ),

        /* Keymap 2: Media and mouse keys
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | VolDn| Mute | VolUp| Play |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      |      |       |      |      |Play  |
         *                                 |      |      |------|       |------|      |      |
         *                                 |      |      |      |       |SLEEP |      |      |
         *                                 `--------------------'       `--------------------'
         */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
        // Left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,

        // Left thumb
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_POWER, KC_TRNS,

        // Right hand
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_VOLD,  KC_MUTE, KC_VOLU, KC_MPLY, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
        KC_VOLU,  KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
        // Right thumb
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        LCTL(LSFT(KC_SLCK)), KC_MPLY, KC_TRNS
    ),
         /* NAVIGATION LAYER
          *
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |        |      |      | LEFT |RIGHT |      |      |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |      |      |LALT(LEFT)|LALT(RIGHT)|      |------|           |------|      |  UP  | DOWN |      |      |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |      |      |      |      |                                       |      |      |      |      |      |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      |      |       |      | Web  |Browser|
         *                                 |      |      |------|       |------| Full |Back|
         *                                 |      |      |      |       |      | Reload|      |
         *                                 `--------------------'       `--------------------'
         */
// NAV
[NAV] = KEYMAP(
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_LEFT,KC_RGHT,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,LALT(KC_LEFT),LALT(KC_RGHT),KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        // left thumb
        KC_TRNS,KC_TRNS,
                KC_TRNS,
        KC_TRNS,KC_ENTER,KC_TRNS,

        // right hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_HOME,KC_PGUP,KC_UP,LGUI(KC_C),LGUI(KC_R),KC_TRNS,LCTL(LSFT(KC_TAB)),
        KC_PGDN,KC_DOWN,LGUI(KC_T),LGUI(KC_TAB),KC_TRNS,LCTL(KC_TAB),
        KC_END,KC_TRNS,KC_TRNS,LGUI(KC_W),LGUI(KC_V),KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        // right thumb
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
        )       
/* LAYER TEMPLATE
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
// LAYER_NAME
[LAYER_NAME] = KEYMAP(
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        // left thumb
        KC_TRNS,KC_TRNS,
                KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,

        // right hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        // right thumb
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
        ),
*/

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB), // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_KEY(SYMB, KC_A) // FN2 - Key <A> on tap, Symbols on press
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
        case 1:
            if(record->event.pressed) {
                register_code(KC_ESC);
                unregister_code(KC_ESC);
                register_code(KC_LSFT);
                register_code(KC_SCLN);
                unregister_code(KC_SCLN);
                unregister_code(KC_LSFT);
                register_code(KC_X);
                unregister_code(KC_X);
                register_code(KC_ENTER);
                unregister_code(KC_ENTER);
           } 
       break;
         case 2:
            if(record->event.pressed) {
                register_code(KC_ESC);
                unregister_code(KC_ESC);
                register_code(KC_LSFT);
                register_code(KC_SCLN);
                unregister_code(KC_SCLN);
                unregister_code(KC_LSFT);
                register_code(KC_Q);
                unregister_code(KC_Q);
                register_code(KC_ENTER);
                unregister_code(KC_ENTER);
           } 
       break;
        case 3:
            if(record->event.pressed) {
                register_code(KC_ESC);
                unregister_code(KC_ESC);
                register_code(KC_LSFT);
                register_code(KC_SCLN);
                unregister_code(KC_SCLN);
                unregister_code(KC_LSFT);
                register_code(KC_W);
                unregister_code(KC_W);
                register_code(KC_ENTER);
                unregister_code(KC_ENTER);
           } 
       break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off(); // Red
    ergodox_right_led_2_off(); // Green
    ergodox_right_led_3_off(); // Blue
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_3_on(); //
            break;
        case BASE_SFT:
            ergodox_right_led_2_on();
            break;
        case NAV: 
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            ergodox_right_led_1_on();
        default:
            // none
            break;
    }

};
