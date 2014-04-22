#define ZIN_LIB_MODE ZIN_LIB_MODE_SKIP
    #include "_list.h"
#undef ZIN_LIB_MODE

#ifdef ZIN_SKIP_FILE
    #error "bad inc lib"
    #undef ZIN_SKIP_FILE
#else
    #define ZIN_LIB_MODE ZIN_LIB_MODE_INC

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

    #undef ZIN_LIB_MODE
#endif
