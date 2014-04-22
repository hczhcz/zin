#if   ZIN_LEVELMODE == ZIN_LEVELMODE_ALLOC
    #include "../level0/_all.h"
    // ZIN_ID_ALLOC(packname_filename, ???)
#elif ZIN_LEVELMODE == ZIN_LEVELMODE_INC
    #include "../level0/_all.h"
    // #include ".../_all.h"
#endif
