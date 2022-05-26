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

### find include paths of th c++ compiler

> gcc -E -Wp,-v -xc /dev/null

from https://stackoverflow.com/a/47914614
