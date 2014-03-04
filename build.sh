# simple build script

splint bootstrap/bootstrap.c -quiet -checks
splint wrap/main.c           -quiet -checks
clang bootstrap/bootstrap.c  -o build/bootstrap.o -c -std=c99 -pedantic -Wall -Wextra
clang wrap/main.c            -o build/main.o      -c -std=c99 -pedantic -Wall -Wextra

clang build/*.o -o build/zin -lgc
./build/zin
