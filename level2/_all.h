#if   ZIN_LEVELMODE == ZIN_LEVELMODE_ALLOC
    #include "../level1/_all.h"
    // ZIN_ID_ALLOC(packname_filename, ???)
#elif ZIN_LEVELMODE == ZIN_LEVELMODE_LIB
    #define ZIN_LEVEL_CURRENT 2
#elif ZIN_LEVELMODE == ZIN_LEVELMODE_INC
    #include "../level1/_all.h"
    // #include ".../_all.h"
#endif
