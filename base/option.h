#ifndef ZIN_OPTION_H
#define ZIN_OPTION_H

#define ZIN_ENABLE_WRITE
#define ZIN_ENABLE_TEST
#define ZIN_ENABLE_DOC

#define ZIN_FORCE_COPY // Always copy on read

#else
    #error "bad inc"
#endif
