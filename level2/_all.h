#if   ZIN_LEVEL_MODE == ZIN_LEVEL_MODE_ALLOC
    #include "../level1/_all.h"
    // ZIN_ID_ALLOC(packname_filename, ???)
#elif ZIN_LEVEL_MODE == ZIN_LEVEL_MODE_LIB
    #define ZIN_LEVEL_CURRENT 2
#elif ZIN_LEVEL_MODE == ZIN_LEVEL_MODE_INC
    #include "../level1/_all.h"
    // #include ".../_all.h"
#endif
