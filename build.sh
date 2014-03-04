# simple build script

splint wrap/main.c -checks #-strict
clang wrap/main.c -o build/zin -std=c99 -pedantic -Wall -Werror -Wextra
./build/zin
