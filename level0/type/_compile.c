#include "../../base/_all.h"
#define ZIN_LEVEL_MODE ZIN_LEVEL_MODE_LIB
    #include "../_all.h"
#undef ZIN_LEVEL_MODE
#include "../../base/_lib.h"

#include "_all.h"

#define ZIN_LIB_MODE ZIN_LIB_MODE_INC
    #define ZIN_MODE ZIN_MODE_READ
        #include "_list.h"
    #undef ZIN_MODE

    #ifdef ZIN_ENABLE_WRITE
        #define ZIN_MODE ZIN_MODE_WRITE
            #include "_list.h"
        #undef ZIN_MODE
    #endif
#undef ZIN_LIB_MODE
