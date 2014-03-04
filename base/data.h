#ifndef ZIN_DATA_H
#define ZIN_DATA_H

typedef int zint;
typedef char zchar;
typedef unsigned int ztype;
typedef unsigned int zsize;

// Head: [type]
typedef struct {
    ztype type;
} zhead;

typedef zhead *pzdata;

// Int: [head] [int]
typedef struct {
    zhead head;
    zint data;
} zdint;

// Str: [head] [memsize (bit)] [realsize] [char] ...
typedef struct {
    zhead head;
    zsize memsize;
    zsize realsize;
    zchar data[];
} zdstr;

// Arr: [head] [memsize (bit)] [front] [back] [ptr] ...
// 0: nil, 1: nil, 2=front: ptr, 3: ptr, 4: ptr, 5=back: nil, ...
typedef struct {
    zhead head;
    zsize memsize;
    zsize front;
    zsize back;
    pzdata data[];
} zdarr;

// Code nil: [head]
typedef struct {
    zhead head;
} zdcodenil;

// Code mono: [head] [ptr]
typedef struct {
    zhead head;
    pzdata data;
} zdcodemono;

// Code bi: [head] [l] [r]
typedef struct {
    zhead head;
    pzdata ldata;
    pzdata rdata;
} zdcodebi;

// Node of dict
typedef struct {
    pzdata index;
    pzdata data;
} zddictnode;

// Dict: [head] [memsize (bit)] [realsize] [ptr] ...
typedef struct {
    zhead head;
    zsize memsize;
    zsize realsize;
    zddictnode node[];
} zddict;

// Context:
typedef struct {
    zhead head;
    pzdata callbuf;
    pzdata libbuf;
} zdcontext;

typedef zdcontext *pzin;

typedef pzdata (*zfuncr)(pzin zin, pzdata caller);
typedef void (*zfuncw)(pzin *zin, pzdata caller, pzdata input);

#endif
