# simple build script

clang wrap/main.c -fsyntax-only -std=c99 -pedantic -Wall -Werror -Wextra
splint wrap/main.c -checks #-strict
