#include "zin.h"

void zin_init(void) {
    ZIN_MEM_INIT();
}

pzdcontext zin_new(void) {
    // TODO


    // TODO: load boorstrap
    // TODO: load std lib

#ifdef ZIN_ENABLE_TEST
    // TODO: run test cases

#endif

#ifdef ZIN_ENABLE_HELP
    // TODO: load doc strings

#endif


    // TODO: return a zdcontext
    return 0;
}

