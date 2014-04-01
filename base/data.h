#ifndef ZIN_DATA_H
#define ZIN_DATA_H

// Internal data types
typedef long ztint;
typedef char ztchar;
typedef unsigned long ztid;
typedef unsigned long ztsize;

////////////////////////////////////////////////////////////////
// Head: [type]
typedef struct {
    ztid layout;
    ztid type;
} zd;

typedef zd *pzd;

#define ZIN_NEW(target, layout, type) {\
    target->layout = ZIN_ID(layout);\
    target->type = ZIN(type);\
}

////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////
    // Atom: [head]

    typedef struct {
        zd head;
    } zdatom;

    typedef zdatom *pzdatom;

    #define ZIN_NEW_ATOM(target, type) {\
        target = ZIN_ALLOCATE_NO_OUT(sizeof(zdatom));\
        ZIN_NEW(target, atom, type)\
    }

    ////////////////////////////////////////////////////////////////
    // Int: [head] [int]

    typedef struct {
        zd head;
        ztint value;
    } zdint;

    typedef zdint *pzdint;

    #define ZIN_NEW_INT(target, type) {\
        target = ZIN_ALLOCATE_NO_OUT(sizeof(zdint));\
        ZIN_NEW(target, int, type)\
    }

    ////////////////////////////////////////////////////////////////
    // Str: [head] [memsize (bit)] [realsize] [char] ...

    typedef struct {
        zd head;
        ztsize memsize;
        ztsize realsize;
        ztchar data[];
    } zdstr;

    typedef zdstr *pzdstr;

    #define ZIN_NEW_STR(target, type) {\
        target = ZIN_ALLOCATE_NO_OUT(sizeof(zdstr));\
        ZIN_NEW(target, str, type)\
    }

    ////////////////////////////////////////////////////////////////
    // Code: [head] [ptr]

    typedef struct {
        zd head;
        pzd param;
    } zdcode;

    typedef zdcode *pzdcode;

    #define ZIN_NEW_CODE(target, type) {\
        target = ZIN_ALLOCATE(sizeof(zdcode));\
        ZIN_NEW(target, code, type)\
    }

    ////////////////////////////////////////////////////////////////
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

    #define ZIN_NEW_ARR(target, type) {\
        target = ZIN_ALLOCATE(sizeof(zdarr));\
        ZIN_NEW(target, arr, type)\
    }

    ////////////////////////////////////////////////////////////////
    // Dict: [head] [memsize (bit)] [realsize] [ptr] ...

        // Node of dict
        typedef struct {
            pzd index;
            pzd data;
        } zddictnode;

    typedef struct {
        zd head;
        ztsize memsize;
        ztsize realsize;
        zddictnode node[];
    } zddict;

    typedef zddict *pzddict;

    #define ZIN_NEW_DICT(target, type) {\
        target = ZIN_ALLOCATE(sizeof(zddict));\
        ZIN_NEW(target, dict, type)\
    }

    ////////////////////////////////////////////////////////////////
    // Context: [head] [callbuf] [libbuf]

    typedef struct {
        zd head;
        pzdarr callbuf;
        pzdarr libbuf;
    } zdcontext;

    typedef zdcontext *pzdcontext;

    #define ZIN_NEW_CONTEXT(target, type) {\
        target = ZIN_ALLOCATE(sizeof(zdcontext));\
        ZIN_NEW(target, context, type)\
    }

    ////////////////////////////////////////////////////////////////
    // Func: [head] [funcr] [funcw]

    typedef struct {
        zd head;
        ZIN_PROTO_PR(funcr);
        ZIN_PROTO_PW(funcw);
    } zdfunc;

    typedef zdfunc *pzdfunc;

    #define ZIN_NEW_FUNC(target, type) {\
        /* target = ZIN_ALLOCATE_NO_OUT(sizeof(zdfunc)); */\
        target = ZIN_ALLOCATE(sizeof(zdfunc));\
        ZIN_NEW(target, func, type)\
    }

    ////////////////////////////////////////////////////////////////

#endif
