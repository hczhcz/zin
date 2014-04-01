#ifndef ZIN_MACRO_H
#define ZIN_MACRO_H

// za: id allocator
// ze: id

// zd: zin data
// zt: simple data

// zr: read func
// zw: write func

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
#define ZIN_PROTO_PR(name) pzd (* (name)) (pzdcontext zin, pzd caller)
#define ZIN_PROTO_PW(name) void (* (name)) (pzdcontext zin, pzd caller, pzd input)
#define ZIN_PROTO_R(name) pzd (zr##name) (pzdcontext zin, pzd caller)
#define ZIN_PROTO_W(name) void (zw##name) (pzdcontext zin, pzd caller, pzd input)

// Functions' usage
#define ZIN_FUNC_R(name) (zr##name)
#define ZIN_FUNC_W(name) (zw##name)

// Enum (type id allocator)
#define ZIN_ID(name) ((ztid) (ze##name))
#define ZIN_ID_INIT(name) ze##name = za##name
#define ZIN_ID_DEF(name) , ze##name
#define ZIN_ID_ALLOC_HEAD() zainit
#define ZIN_ID_ALLOC(name, id) , za##name = (id)

// Memory management
#define ZIN_MEM_INIT() GC_INIT()
#define ZIN_ALLOCATE(size) GC_malloc(size)
#define ZIN_ALLOCATE_NO_OUT(size) GC_malloc_atomic(size)
#define ZIN_ALLOCATE_NO_IN(size) GC_malloc_ignore_off_page(size)
#define ZIN_RESIZE(obj, size) GC_realloc(obj, size)
#define ZIN_FREE(obj) GC_free(obj)

// Casting
#define ZIN_AS(type, data) ((pzd##type) data)

// Calling
#define ZIN_STATIC_READ(name, caller) ((zr##name) (zin, caller))
#define ZIN_STATIC_WRITE(name, caller, input) ((zw##name) (zin, caller, input))
#define ZIN_DYNAMIC_READ(name, caller) zrcode(zin, caller)
#define ZIN_DYNAMIC_WRITE(name, caller, input) zwcode(zin, caller, input)

#endif
