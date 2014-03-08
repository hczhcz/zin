#include "../../base/_all.h"

#define ZIN_MODE ZIN_MODE_HEADER_READ
#include "_list.inc"
#undef ZIN_MODE

#ifdef ZIN_ENABLE_WRITE
    #define ZIN_MODE ZIN_MODE_HEADER_WRITE
    #include "_list.inc"
    #undef ZIN_MODE
#endif
