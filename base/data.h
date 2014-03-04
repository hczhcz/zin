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
        zint value;
    } zdint;

    typedef zdint *pzdint;

    // Str: [head] [memsize (bit)] [realsize] [char] ...
    typedef struct {
        zhead head;
        zsize memsize;
        zsize realsize;
        zchar data[];
    } zdstr;

    typedef zdstr *pzdstr;

    // Arr: [head] [memsize (bit)] [front] [back] [ptr] ...
    // 0: nil, 1: nil, 2=front: ptr, 3: ptr, 4: ptr, 5=back: nil, ...
    typedef struct {
        zhead head;
        zsize memsize;
        zsize front;
        zsize back;
        pzdata buf[];
    } zdarr;

    typedef zdarr *pzdarr;

    // Code: [head] [ptr] ...
    typedef struct {
        zhead head;
        pzdata param[];
    } zdcode;

    typedef zdcode *pzdcode;

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

    typedef zddict *pzddict;

    // Context: [head] [callbuf] [libbuf]
    typedef struct {
        zhead head;
        pzdata callbuf;
        pzdata libbuf;
    } zdcontext;

    typedef zdcontext *pzdcontext;

    // Func: [head] [funcr] [funcw]
    typedef struct {
        zhead head;
        pzdata (*funcr)(pzdcontext zin, pzdata caller);
        void (*funcw)(pzdcontext *zin, pzdata caller, pzdata input);
    } zdfunc;

    typedef zdfunc *pzdfunc;

#endif
