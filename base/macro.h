#ifndef ZIN_MACRO_H
#define ZIN_MACRO_H

// Modes
#define ZIN_MODE_ENUM 1
#define ZIN_MODE_HEADER_PROTO 2
#define ZIN_MODE_HEADER_READ 3
#define ZIN_MODE_HEADER_WRITE 4
#define ZIN_MODE_READ 5
#define ZIN_MODE_WRITE 6
#define ZIN_MODE_LOAD 7
#define ZIN_MODE_TEST 8
#define ZIN_MODE_HELP 9

// Function prototypes
#define ZIN_PROTO_R(x) pzdata (x)(pzdcontext zin, pzdata caller)
#define ZIN_PROTO_W(x) void (x)(pzdcontext zin, pzdata caller, pzdata input)

// Memory management
#define ZIN_MEM_INIT() GC_INIT()
#define ZIN_CREATE(size) GC_malloc(size)
#define ZIN_CREATE_NO_OUT(size) GC_malloc_atomic(size)
#define ZIN_CREATE_NO_IN(size) GC_malloc_ignore_off_page(size)
#define ZIN_RESIZE(obj, size) GC_realloc(obj, size)
#define ZIN_FREE(obj) GC_free(obj)

#endif
