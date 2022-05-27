# jans macropad 

## qmk helper

### install qmk tool:

pip install --upgrade qmk

### setup qmk:

qmk setup

### run qmk diagnostics:

qmk doctor

### make and flash:

make janjan/makropad:default:flash

## qmk internals for rgb

main loop in `quantum/main.c`:

```
void protocol_task(void) {
    protocol_pre_task();

    keyboard_task(); // <- important

    protocol_post_task();
}

int main(void) {
    platform_setup();
    protocol_setup();
    keyboard_setup();

    protocol_init();

    while (true) {
        protocol_task();
    }
}

```

in `quantum/keyboard.c`

```
void keyboard_task(void) {
    bool matrix_changed = matrix_scan_task();
    (void)matrix_changed;

    quantum_task();

    rgblight_task();
    led_matrix_task();
    rgb_matrix_task(); <-- rgb
    backlight_task();

    led_task();
}
```

in `quantum/rgb_matrix/rgb_matrix.c`

```
void rgb_matrix_task(void) {
    rgb_task_timers();

    uint8_t effect = !rgb_matrix_config.enable ? 0 : rgb_matrix_config.mode;

    switch (rgb_task_state) {
        case STARTING:
            rgb_task_start();
            break;
        case RENDERING:
            rgb_task_render(effect);
            if (effect) {
                rgb_matrix_indicators();
                rgb_matrix_indicators_advanced(&rgb_effect_params);
            }
            break;
        case FLUSHING:
            rgb_task_flush(effect);
            break;
        case SYNCING:
            rgb_task_sync();
            break;
    }
}
```

## setting up vscode

### c_cpp_properties.json

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "/usr/lib/gcc/x86_64-linux-gnu/9/include/**",
                "/usr/local/include/**",
                "/usr/include/x86_64-linux-gnu/**",
                "/usr/lib/avr/include/**",
                "${workspaceFolder}/*",
                "${workspaceFolder}/**",
                "${workspaceFolder}/quantum/**",
                "${workspaceFolder}/tmk_core/**",
                "${workspaceFolder}/quantum/audio/**",
                "${workspaceFolder}/quantum/rgb_matrix/**",
                "${workspaceFolder}/quantum/process_keycode/**",
                "${workspaceFolder}/lib/chibios/**",
                "${workspaceFolder}/lib/lufa/**"
            ],
            "defines": [
                "QMK_KEYBOARD_H=<quantum.h>",
                "IGNORE_ATOMIC_BLOCK",
                "DRIVER_LED_TOTAL=20",
                "MATRIX_ROWS=5",
                "MATRIX_COLS=4"
            ],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c11",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64",
            "forcedInclude": [
                "stdint.h",
                "stdbool.h",
                "led_matrix.h"
            ],
            "browse": {
                "limitSymbolsToIncludedHeaders": false
            }
        }
    ],
    "version": 4
}
```

### find include paths of th c++ compiler

> gcc -E -Wp,-v -xc /dev/null

from https://stackoverflow.com/a/47914614
