#ifndef ZIN_ALLOC_H
#define ZIN_ALLOC_H

enum {
    ZIN_ID_ALLOC_HEAD()
    #define ZIN_LEVEL_MODE ZIN_LEVEL_MODE_ALLOC
        #if   ZIN_LEVEL_CURRENT == 0
            #include "../level0/_all.h"
        #elif ZIN_LEVEL_CURRENT == 1
            #include "../level1/_all.h"
        #elif ZIN_LEVEL_CURRENT == 2
            #include "../level2/_all.h"
        #else
            #error "bad level"
        #endif
    #undef ZIN_LEVEL_MODE
};

#else
    #error "bad inc"
#endif
