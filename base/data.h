#ifndef ZIN_DATA_H
#define ZIN_DATA_H

// Internal data types
typedef long ztint;
typedef char ztchar;
typedef unsigned long ztid;
typedef unsigned long ztsize;

// Head: [type]
typedef struct {
    ztid layout;
    ztid type;
} zd;

typedef zd *pzd;

    // Atom: [head]
    typedef struct {
        zd head;
    } zdatom;

    typedef zdatom *pzdatom;

    // Int: [head] [int]
    typedef struct {
        zd head;
        ztint value;
    } zdint;

    typedef zdint *pzdint;

    // Str: [head] [memsize (bit)] [realsize] [char] ...
    typedef struct {
        zd head;
        ztsize memsize;
        ztsize realsize;
        ztchar data[];
    } zdstr;

    typedef zdstr *pzdstr;

    // Code: [head] [ptr]
    typedef struct {
        zd head;
        pzd param;
    } zdcode;

    typedef zdcode *pzdcode;

    // Arr: [head] [memsize (bit)] [front] [back] [ptr] ...
    // 0: nil, 1: nil, 2=front: ptr, 3: ptr, 4: ptr, 5=back: nil, ...
    typedef struct {
        zd head;
        ztsize memsize;
        ztsize front;
        ztsize back;
        pzd buf[];
    } zdarr;

    typedef zdarr *pzdarr;

        // Node of dict
        typedef struct {
            pzd index;
            pzd data;
        } zddictnode;

    // Dict: [head] [memsize (bit)] [realsize] [ptr] ...
    typedef struct {
        zd head;
        ztsize memsize;
        ztsize realsize;
        zddictnode node[];
    } zddict;

    typedef zddict *pzddict;

    // Context: [head] [callbuf] [libbuf]
    typedef struct {
        zd head;
        pzdarr callbuf;
        pzdarr libbuf;
    } zdcontext;

    typedef zdcontext *pzdcontext;

    // Func: [head] [funcr] [funcw]
    typedef struct {
        zd head;
        ZIN_PROTO_PR(funcr);
        ZIN_PROTO_PW(funcw);
    } zdfunc;

    typedef zdfunc *pzdfunc;

#endif
