#if   ZIN_LEVELMODE == ZIN_LEVELMODE_ALLOC
    ZIN_ID_ALLOC(init_type, 10)
#elif ZIN_LEVELMODE == ZIN_LEVELMODE_INC
    #include "type/_all.h"
    // #include ".../_all.h"
#endif
