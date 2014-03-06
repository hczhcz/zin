# simple build script

splint bootstrap/_compile.c -checks
splint wrap/main.c          -checks
clang bootstrap/_compile.c  -o build/bootstrap.o -c -std=c99 -pedantic -Wall -Wextra
clang wrap/main.c           -o build/main.o      -c -std=c99 -pedantic -Wall -Wextra

clang build/*.o -o build/zin -lgc
./build/zin
