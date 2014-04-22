#ifndef ZIN_ALLOC_H
#define ZIN_ALLOC_H

enum {
    ZIN_ID_ALLOC_HEAD()
    #define ZIN_LEVELMODE ZIN_LEVELMODE_ALLOC
        #include "../level2/_all.h"
    #undef ZIN_LEVELMODE
};

#endif
