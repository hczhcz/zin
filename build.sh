# simple build script

splint bootstrap/_compile.c -checks
splint wrap/main.c          -checks
clang bootstrap/_compile.c  -o output/bootstrap.o -c -std=c99 -pedantic -Wall -Wextra
clang wrap/main.c           -o output/main.o      -c -std=c99 -pedantic -Wall -Wextra

clang output/*.o -o output/zin -lgc
./output/zin
