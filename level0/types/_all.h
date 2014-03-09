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
