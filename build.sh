# simple build script

splint */*.c */*/*.c -checks -strict-lib -paramuse -mustfreeonly -temptrans -nullret #-strict

./compile.sh base/data.c output/data.o
./compile.sh level0/type/_compile.c output/type.o
./compile.sh wrapper/zin.c output/zin.o
./compile.sh wrapper/main.c output/main.o

clang output/*.o -o output/zin -lgc
./output/zin
