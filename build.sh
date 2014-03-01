# simple build script

splint wrap/main.c -checks #-strict
clang wrap/main.c -o zin -std=c99 -pedantic -Wall -Werror -Wextra
./zin
