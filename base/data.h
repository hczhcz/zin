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

    ////////////////////////////////////////////////////////////////
    // Int: [head] [int]

    struct zdint {
        struct zd head;
        ztint value;
    } zdint;

    pzd zin_gen_int(ztid tolayout, ztid totype, pztfunc tofunc, ztint tovalue);

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

    ////////////////////////////////////////////////////////////////
    // Ptr: [head] [ptr]

    struct zdptr {
        struct zd head;
        pzd data;
    };

    pzd zin_gen_ptr(ztid tolayout, ztid totype, pztfunc tofunc, pzd todata);

    ////////////////////////////////////////////////////////////////
    // Pair: [head] [ptr] [ptr]

    struct zdpair {
        struct zd head;
        pzd left;
        pzd right;
    };

    pzd zin_gen_pair(ztid tolayout, ztid totype, pztfunc tofunc, pzd toleft, pzd toright);

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

    ////////////////////////////////////////////////////////////////
    // Dict: [head] [memsize (bit)] [realsize] [[index] [ptr]] ...

    struct zddict {
        struct zd head;
        ztsize memsize;
        ztsize realsize;
        ztidnode node[];
    };

    pzd zin_gen_dict(ztid tolayout, ztid totype, pztfunc tofunc, ztsize tomemsize);

    ////////////////////////////////////////////////////////////////
    // Context: [head] [callbuf] [libbuf]

    struct zdcontext {
        struct zd head;
        pzd callbuf;
        pzd libbuf;
    };

    pzd zin_gen_context(ztid tolayout, ztid totype, pztfunc tofunc, pzd tocallbuf, pzd tolibbuf);

    ////////////////////////////////////////////////////////////////
    // Func: [head] [funcr] [funcw]

    struct zdfunc {
        struct zd head;
        ztfunc func;
    };

    pzd zin_gen_func(ztid tolayout, ztid totype, pztfunc tofunc, ZIN_PROTO_PR(tofuncr), ZIN_PROTO_PW(tofuncw));

    ////////////////////////////////////////////////////////////////

#else
    #error "bad inc"
#endif
