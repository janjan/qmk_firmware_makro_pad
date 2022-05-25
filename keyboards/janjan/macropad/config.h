#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x7983
#define PRODUCT_ID   0x0420
#define DEVICE_VER   0x0069
#define MANUFACTURER Sus
#define PRODUCT      O4L:5x12

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
// #define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { B6, B2, B3, B1, F7 }
// #define MATRIX_COL_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B5, B4, E6, D7 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

// #define BACKLIGHT_PIN F4
//#define BACKLIGHT_LEVELS 3
//#define BACKLIGHT_BREATHING

// #define RGB_DI_PIN F4
// #ifdef RGB_DI_PIN
// #    define RGBLED_NUM 20
// #    define RGBLIGHT_HUE_STEP 4
// #    define RGBLIGHT_SAT_STEP 4
// #    define RGBLIGHT_VAL_STEP 4
// #define RGBLIGHT_LIMIT_VAL 50
// //#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
// //#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
// #    define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
// //#    define RGBLIGHT_EFFECT_BREATHING
// //#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
// //#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// //#    define RGBLIGHT_EFFECT_SNAKE
// //#    define RGBLIGHT_EFFECT_KNIGHT
// //#    define RGBLIGHT_EFFECT_CHRISTMAS
// //#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// //#    define RGBLIGHT_EFFECT_RGB_TEST
// //#    define RGBLIGHT_EFFECT_ALTERNATING
// /*== customize breathing effect ==*/
// /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
// //#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
// /*==== use exp() and sin() ====*/
// //#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
// //#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
// #endif

// The pin connected to the data pin of the LEDs
#define RGB_DI_PIN F4
#ifdef RGB_DI_PIN
// The number of LEDs connected
#define DRIVER_LED_TOTAL 20
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define RGB_MATRIX_STARTUP_VAL 120

#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN

#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
