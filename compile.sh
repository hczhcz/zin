echo
echo ================================================================
echo
echo $1
echo $2
echo
echo ================================================================
echo

splint $1 -checks
clang $1 -o $2 -c -std=c99 -pedantic -Wall -Wextra
