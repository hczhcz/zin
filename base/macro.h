#ifndef ZIN_MACRO_H
#define ZIN_MACRO_H

// Inclusion modes
#define ZIN_MODE_ID 1
#define ZIN_MODE_HEADER_READ 2
#define ZIN_MODE_HEADER_WRITE 3
#define ZIN_MODE_READ 4
#define ZIN_MODE_WRITE 5
#define ZIN_MODE_LOAD_READ 6
#define ZIN_MODE_LOAD_WRITE 7
#define ZIN_MODE_TEST_READ 8
#define ZIN_MODE_TEST_WRITE 9
#define ZIN_MODE_DOC 10

// Functions' prototypes
#define ZIN_PROTO_PR(name) pzdata (* (name)) (pzdcontext zin, pzdata caller)
#define ZIN_PROTO_PW(name) void (* (name)) (pzdcontext zin, pzdata caller, pzdata input)
#define ZIN_PROTO_R(name) pzdata (zr##name) (pzdcontext zin, pzdata caller)
#define ZIN_PROTO_W(name) void (zw##name) (pzdcontext zin, pzdata caller, pzdata input)

// Functions' usage
#define ZIN_FUNC_R(name) (zr##name)
#define ZIN_FUNC_W(name) (zw##name)

// Enum (type id allocator)
#define ZIN_ID(name) ((ztype) (ze##name))
#define ZIN_ID_INIT(name) ze##name = za##name
#define ZIN_ID_DEF(name) , ze##name
#define ZIN_ID_ALLOC_HEAD() zainit
#define ZIN_ID_ALLOC(name, id) , za##name = (id)

// Memory management
#define ZIN_MEM_INIT() GC_INIT()
#define ZIN_CREATE(size) GC_malloc(size)
#define ZIN_CREATE_NO_OUT(size) GC_malloc_atomic(size)
#define ZIN_CREATE_NO_IN(size) GC_malloc_ignore_off_page(size)
#define ZIN_RESIZE(obj, size) GC_realloc(obj, size)
#define ZIN_FREE(obj) GC_free(obj)

// Memory management with type
#define ZIN_AS(type, data) ((pzd##type) data)
#define ZIN_CREATE_AS(type, size) ZIN_CREATE(sizeof(zd##type))

// Calling
#define ZIN_STATIC_READ(name, caller) ((zr##name) (zin, caller))
#define ZIN_STATIC_WRITE(name, caller, input) ((zw##name) (zin, caller, input))
#define ZIN_DYNAMIC_READ(name, caller) zrcode(zin, caller)
#define ZIN_DYNAMIC_WRITE(name, caller, input) zwcode(zin, caller, input)

#endif
