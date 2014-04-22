#define ZIN_LIBMODE ZIN_LIBMODE_SKIP
    #include "_list.h"
#undef ZIN_LIBMODE

#ifdef ZIN_SKIP_FILE
    #undef ZIN_SKIP_FILE
#else
    #include "../../base/_all.h"

        enum {
            #define ZIN_MODE ZIN_MODE_ID
                #include "_list.h"
            #undef ZIN_MODE
        };

        #define ZIN_MODE ZIN_MODE_HEADER_READ
            #include "_list.h"
        #undef ZIN_MODE

        #ifdef ZIN_ENABLE_WRITE
            #define ZIN_MODE ZIN_MODE_HEADER_WRITE
                #include "_list.h"
            #undef ZIN_MODE
        #endif

    #undef ZIN_LIBMODE
#endif
