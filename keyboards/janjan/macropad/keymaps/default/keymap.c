#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty (Preonic Layer Style)
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_macropad(
        KC_1, RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_REVERSE,
        KC_Q, KC_W, RGB_SPD, RGB_SPI,
        KC_A, KC_S, KC_D, KC_F,
        KC_Z, KC_X, KC_C, KC_V,
        KC_5, RGB_VAD, KC_7, RGB_VAI
    ),

    /* Lower (Preonic Layer Style)
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_macropad(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,
        _______, KC_F7,   KC_F8,   KC_F9,
        _______, _______, _______, _______
    ),

    /* Raise (Preonic Layer Style)
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_macropad(
        KC_GRV,  KC_1,    KC_2,    KC_3,
        KC_GRV,  KC_1,    KC_2,    KC_3,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,
        _______, KC_F7,   KC_F8,   KC_F9,
        _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
    }
    return true;
};

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {  0,  1,  2,  3 },
        {  4,  5,  6,  7 },
        {  8,  9, 10, 11 },
        { 12, 13, 14, 15 },
        { 16, 17, 18, 19 },
    },
    {
        // this is pretty much the perfect setting with the correct aspect ration
        { 88,   0 }, { 104,  0 }, { 120,  0 }, { 136,  0 },
        { 136, 16 }, { 120, 16 }, { 104, 16 }, {  88, 16 },
        {  88, 32 }, { 104, 32 }, { 120, 32 }, { 136, 32 },
        { 136, 48 }, { 120, 48 }, { 104, 48 }, {  88, 48 },
        {  88, 64 }, { 104, 64 }, { 120, 64 }, { 136, 64 },

    // this stretches the keys over a full size board. therefore effects are not square on a 5x4 macro pad
    //   { 0,  0 }, {  75,  0 }, { 149,  0 }, { 224, 0 },
    // { 224, 16 }, { 149, 16 }, {  75, 16 }, {   0, 16 },
    // {   0, 32 }, {  75, 32 }, { 149, 32 }, { 224, 32 },
    // { 224, 48 }, { 149, 48 }, {  75, 48 }, {   0, 48 },
    // {   0, 64 }, {  75, 64 }, { 149, 64 }, { 224, 64 },


    },
    {
        // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    }
};
