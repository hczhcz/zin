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

#define ZIN_LIB_MODE_SKIP 257
#define ZIN_LIB_MODE_INC 258

#define ZIN_LEVEL_MODE_ALLOC 513
#define ZIN_LEVEL_MODE_LIB 514
#define ZIN_LEVEL_MODE_INC 515

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

// Not finished: begin
#if 0

// Context
#define ZIN_EXEC_THEN(data) // TODO: push_front(zin->callbuf, data)
#define ZIN_EXEC_LATER(data) // TODO: push_back(zin->callbuf, data)
#define ZIN_LIB_PUSH(data) // TODO: push_back(zin->libbuf, data)
#define ZIN_LIB_POP() // TODO: pop_back(zin->libbuf)
#define ZIN_LIB_GET(id) // (zin, )???
#define ZIN_LIB_SET(id, value) // ()???

// Calling
#define ZIN_READ(name, caller) ((zr##name) (zin, caller))
#define ZIN_WRITE(name, caller, input) ((zw##name) (zin, caller, input))
#define ZIN_GET_READ(caller) ((ZIN_LIB_GET((caller)->type)->funcr) (zin, caller))
#define ZIN_GET_WRITE(caller, input) ((ZIN_LIB_GET((caller)->type)->funcw) (zin, caller, input))
#define ZIN_STATIC_READ(name, param) ZIN_READ(name, ZIN_NEW_CODE(ze##name, param))
#define ZIN_STATIC_WRITE(name, param, input) ZIN_WRITE(name, ZIN_NEW_CODE(ze##name, param), input)
#define ZIN_DYNAMIC_READ(name, param) ZIN_GET_READ(ZIN_NEW_CODE(ze##name, param))
#define ZIN_DYNAMIC_WRITE(name, param, input) ZIN_GET_WRITE(ZIN_NEW_CODE(ze##name, param), input)

// Not finished: end
#endif

#else
    #error "bad inc"
#endif
