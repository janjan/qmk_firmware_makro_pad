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
