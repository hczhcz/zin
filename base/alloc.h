#ifndef ZIN_ALLOC_H
#define ZIN_ALLOC_H

enum {
    ZIN_ID_ALLOC_HEAD()
    #include "../level0/_alloc.h"
    #include "../level1/_alloc.h"
    #include "../level2/_alloc.h"
};

#endif
