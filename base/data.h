#ifndef ZIN_DATA_H
#define ZIN_DATA_H

typedef int zint;
typedef char zchar;
typedef unsigned int ztype;
typedef unsigned int zsize;

typedef struct {
    ztype type;
} zhead;

typedef zhead *pzdata;

// Int: [head] [int]
typedef struct {
    zhead head;
    zint data;
} zdint;

// Str: [head] [memsize] [realsize] [char] ...
typedef struct {
    zhead head;
    zsize memsize;
    zsize realsize;
    zchar data[];
} zdstr;

// Arr: [head] [memsize] [realsize] [ptr] ...
typedef struct {
    zhead head;
    zsize memsize;
    zsize realsize;
    pzdata data[];
} zdarr;

// Codenil: [head]
typedef struct {
    zhead head;
} zdcodenil;

// Codemono: [head] [ptr]
typedef struct {
    zhead head;
    pzdata data;
} zdcodemono;

// Codebi: [head] [l] [r]
typedef struct {
    zhead head;
    pzdata ldata;
    pzdata rdata;
} zdcodebi;

#endif
