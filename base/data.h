#ifndef ZIN_DATA_H
#define ZIN_DATA_H

// Internal data types
typedef long ztint;
typedef char ztchar;
typedef unsigned int ztid;
typedef unsigned int ztsize;

////////////////////////////////////////////////////////////////

struct zd;
struct zdatom;
struct zdint;
struct zdstr;
struct zdptr;
struct zdpair;
struct zdarr;
struct zddict;
struct zdcontext;
struct zdfunc;
typedef struct zd *pzd;
typedef struct zdatom *pzdatom;
typedef struct zdint *pzdint;
typedef struct zdstr *pzdstr;
typedef struct zdptr *pzdptr;
typedef struct zdpair *pzdpair;
typedef struct zdarr *pzdarr;
typedef struct zddict *pzddict;
typedef struct zdcontext *pzdcontext;
typedef struct zdfunc *pzdfunc;

////////////////////////////////////////////////////////////////
// IdNode: [id] [ptr]

typedef struct {
    ztid index;
    pzd data;
} ztidnode;

////////////////////////////////////////////////////////////////
// Func: [funcr] [funcw]

typedef struct {
    ZIN_PROTO_PR(funcr);
    ZIN_PROTO_PW(funcw);
} ztfunc;

typedef ztfunc *pztfunc;

////////////////////////////////////////////////////////////////
// Head: [layout] [type]

struct zd {
    ztid layout;
    ztid type;
    pztfunc func;
};

////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////
    // Atom: [head]

    struct zdatom {
        struct zd head;
    };

    pzd zin_gen_atom(ztid tolayout, ztid totype, pztfunc tofunc);
    #define ZIN_NEW_ATOM(totype) zin_gen_atom(ZIN_ID(atom), ZIN_ID(totype), zin->head.func)
    #define ZIN_NEW_ATOM_BIND(totype, tofunc) zin_gen_atom(ZIN_ID(atom), ZIN_ID(totype), tofunc)

    ////////////////////////////////////////////////////////////////
    // Int: [head] [int]

    struct zdint {
        struct zd head;
        ztint value;
    } zdint;

    pzd zin_gen_int(ztid tolayout, ztid totype, pztfunc tofunc, ztint tovalue);
    #define ZIN_NEW_INT(totype, tovalue) zin_gen_int(ZIN_ID(int), ZIN_ID(totype), zin->head.func, tovalue)
    #define ZIN_NEW_INT_BIND(totype, tofunc, tovalue) zin_gen_int(ZIN_ID(int), ZIN_ID(totype), tofunc, tovalue)

    ////////////////////////////////////////////////////////////////
    // Str: [head] [memsize (bit)] [front] [back] [char] ...

    struct zdstr {
        struct zd head;
        ztsize memsize;
        ztsize front;
        ztsize back;
        ztchar strdata[];
    };

    pzd zin_gen_str(ztid tolayout, ztid totype, pztfunc tofunc, ztsize tomemsize);
    #define ZIN_NEW_STR(totype, tomemsize) zin_gen_str(ZIN_ID(str), ZIN_ID(totype), zin->head.func, tomemsize)
    #define ZIN_NEW_STR_BIND(totype, tofunc, tomemsize) zin_gen_str(ZIN_ID(str), ZIN_ID(totype), tofunc, tomemsize)

    ////////////////////////////////////////////////////////////////
    // Ptr: [head] [ptr]

    struct zdptr {
        struct zd head;
        pzd data;
    };

    pzd zin_gen_ptr(ztid tolayout, ztid totype, pztfunc tofunc, pzd todata);
    #define ZIN_NEW_PTR(totype, todata) zin_gen_ptr(ZIN_ID(ptr), ZIN_ID(totype), zin->head.func, todata)
    #define ZIN_NEW_PTR_BIND(totype, tofunc, todata) zin_gen_ptr(ZIN_ID(ptr), ZIN_ID(totype), tofunc, todata)

    ////////////////////////////////////////////////////////////////
    // Pair: [head] [ptr] [ptr]

    struct zdpair {
        struct zd head;
        pzd left;
        pzd right;
    };

    pzd zin_gen_pair(ztid tolayout, ztid totype, pztfunc tofunc, pzd toleft, pzd toright);
    #define ZIN_NEW_PAIR(totype, toleft, toright) zin_gen_pair(ZIN_ID(pair), ZIN_ID(totype), zin->head.func, toleft, toright)
    #define ZIN_NEW_PAIR_BIND(totype, tofunc, toleft, toright) zin_gen_pair(ZIN_ID(pair), ZIN_ID(totype), tofunc, toleft, toright)

    ////////////////////////////////////////////////////////////////
    // Arr: [head] [memsize (bit)] [front] [back] [ptr] ...
    // 0: nil, 1: nil, 2=front: ptr, 3: ptr, 4: ptr, 5=back: nil, ...

    struct zdarr {
        struct zd head;
        ztsize memsize;
        ztsize front;
        ztsize back;
        pzd buf[];
    };

    pzd zin_gen_arr(ztid tolayout, ztid totype, pztfunc tofunc, ztsize tomemsize);
    #define ZIN_NEW_ARR(totype, tomemsize) zin_gen_arr(ZIN_ID(arr), ZIN_ID(totype), zin->head.func, memsize)
    #define ZIN_NEW_ARR_BIND(totype, tofunc, tomemsize) zin_gen_arr(ZIN_ID(arr), ZIN_ID(totype), tofunc, memsize)

    ////////////////////////////////////////////////////////////////
    // Dict: [head] [memsize (bit)] [realsize] [[index] [ptr]] ...

    struct zddict {
        struct zd head;
        ztsize memsize;
        ztsize realsize;
        ztidnode node[];
    };

    pzd zin_gen_dict(ztid tolayout, ztid totype, pztfunc tofunc, ztsize tomemsize);
    #define ZIN_NEW_DICT(totype, tomemsize) zin_gen_dict(ZIN_ID(dict), ZIN_ID(totype), zin->head.func, memsize)
    #define ZIN_NEW_DICT_BIND(totype, tofunc, tomemsize) zin_gen_dict(ZIN_ID(dict), ZIN_ID(totype), tofunc, memsize)

    ////////////////////////////////////////////////////////////////
    // Context: [head] [callbuf] [libbuf]

    struct zdcontext {
        struct zd head;
        pzdarr callbuf;
        pzdarr libbuf;
    };

    pzd zin_gen_context(ztid tolayout, ztid totype, pztfunc tofunc, pzdarr tocallbuf, pzdarr tolibbuf);
    #define ZIN_NEW_CONTEXT(totype, tocallbuf, tolibbuf) zin_gen_context(ZIN_ID(context), ZIN_ID(totype), zin->head.func, tocallbuf, tolibbuf)
    #define ZIN_NEW_CONTEXT_BIND(totype, tofunc, tocallbuf, tolibbuf) zin_gen_context(ZIN_ID(context), ZIN_ID(totype), tofunc, tocallbuf, tolibbuf)

    ////////////////////////////////////////////////////////////////
    // Func: [head] [funcr] [funcw]

    struct zdfunc {
        struct zd head;
        ztfunc func;
    };

    pzd zin_gen_func(ztid tolayout, ztid totype, pztfunc tofunc, ZIN_PROTO_PR(tofuncr), ZIN_PROTO_PW(tofuncw));
    #define ZIN_NEW_FUNC(totype, tofuncr, tofuncw) zin_gen_func(ZIN_ID(func), ZIN_ID(totype), zin->head.func, tofuncr, tofuncw)
    #define ZIN_NEW_FUNC_BIND(totype, tofunc, tofuncr, tofuncw) zin_gen_func(ZIN_ID(func), ZIN_ID(totype), tofunc, tofuncr, tofuncw)

    ////////////////////////////////////////////////////////////////

#else
    #error "bad inc"
#endif
