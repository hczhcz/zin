#if   ZIN_LEVEL_MODE == ZIN_LEVEL_MODE_ALLOC
    ZIN_ID_ALLOC(init_type, 10)
#elif ZIN_LEVEL_MODE == ZIN_LEVEL_MODE_LIB
    #define ZIN_LEVEL_CURRENT 0
#elif ZIN_LEVEL_MODE == ZIN_LEVEL_MODE_INC
    #include "type/_all.h"
    // #include ".../_all.h"
#else
    #error "bad mode"
#endif
