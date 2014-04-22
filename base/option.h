#ifndef ZIN_OPTION_H
#define ZIN_OPTION_H

#define ZIN_ENABLE_WRITE
#define ZIN_ENABLE_TEST
#define ZIN_ENABLE_DOC

#define ZIN_FORCE_COPY // Always copy on read

#define ZIN_CORE_READ ZIN_STATIC_READ
#define ZIN_LIB_READ ZIN_DYNAMIC_READ
#define ZIN_CORE_WRITE ZIN_STATIC_WRITE
#define ZIN_LIB_WRITE ZIN_DYNAMIC_WRITE

#else
    #error "bad inc"
#endif
