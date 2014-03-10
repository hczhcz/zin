#ifndef ZIN_DATA_H
#define ZIN_DATA_H

// Internal data types
typedef long zint;
typedef char zchar;
typedef unsigned long ztype;
typedef unsigned long zsize;

// Head: [type]
typedef struct {
    ztype type;
} zhead;

typedef zhead *pzdata;

    // Atom: [head]
    typedef struct {
        zhead head;
    } zdatom;

    typedef zdatom *pzdatom;

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

    // Code: [head] [ptr] ...
    typedef struct {
        zhead head;
        pzdata param[];
    } zdcode;

    typedef zdcode *pzdcode;

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
        pzdarr callbuf;
        pzdarr libbuf;
    } zdcontext;

    typedef zdcontext *pzdcontext;

    // Func: [head] [funcr] [funcw]
    typedef struct {
        zhead head;
        ZIN_PROTO_PR(funcr);
        ZIN_PROTO_PW(funcw);
    } zdfunc;

    typedef zdfunc *pzdfunc;

#endif
