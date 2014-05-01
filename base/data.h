#ifndef ZIN_DATA_H
#define ZIN_DATA_H

// Internal data types
typedef long ztint;
typedef char ztchar;
typedef unsigned int ztid;
typedef unsigned int ztsize;

////////////////////////////////////////////////////////////////
// Head: [type]
typedef struct {
    ztid layout;
    ztid type;
} zd;

typedef zd *pzd;

////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////
    // Atom: [head]

    typedef struct {
        zd head;
    } zdatom;

    typedef zdatom *pzdatom;

    pzd zin_gen_atom(ztid tolayout, ztid totype);
    #define ZIN_NEW_ATOM(totype) zin_gen_atom(ZIN_ID(atom), ZIN_ID(totype))

    ////////////////////////////////////////////////////////////////
    // Int: [head] [int]

    typedef struct {
        zd head;
        ztint value;
    } zdint;

    typedef zdint *pzdint;
    pzd zin_gen_int(ztid tolayout, ztid totype, ztint tovalue);
    #define ZIN_NEW_INT(totype, tovalue) zin_gen_int(ZIN_ID(int), ZIN_ID(totype), tovalue)

    ////////////////////////////////////////////////////////////////
    // Str: [head] [memsize (bit)] [front] [back] [char] ...

    typedef struct {
        zd head;
        ztsize memsize;
        ztsize front;
        ztsize back;
        ztchar strdata[];
    } zdstr;

    typedef zdstr *pzdstr;
    pzd zin_gen_str(ztid tolayout, ztid totype, ztsize tomemsize);
    #define ZIN_NEW_STR(totype, tomemsize) zin_gen_str(ZIN_ID(str), ZIN_ID(totype), tomemsize)

    ////////////////////////////////////////////////////////////////
    // Ptr: [head] [ptr]

    typedef struct {
        zd head;
        pzd data;
    } zdptr;

    typedef zdptr *pzdptr;
    pzd zin_gen_ptr(ztid tolayout, ztid totype, pzd todata);
    #define ZIN_NEW_PTR(totype, todata) zin_gen_ptr(ZIN_ID(ptr), ZIN_ID(totype), todata)


    ////////////////////////////////////////////////////////////////
    // Pair: [head] [ptr] [ptr]

    typedef struct {
        zd head;
        pzd left;
        pzd right;
    } zdpair;

    typedef zdpair *pzdpair;
    pzd zin_gen_pair(ztid tolayout, ztid totype, pzd toleft, pzd toright);
    #define ZIN_NEW_PAIR(totype, toleft, toright) zin_gen_pair(ZIN_ID(pair), ZIN_ID(totype), toleft, toright)

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
    pzd zin_gen_arr(ztid tolayout, ztid totype, ztsize tomemsize);
    #define ZIN_NEW_ARR(totype, tomemsize) zin_gen_arr(ZIN_ID(arr), ZIN_ID(totype), memsize)

    ////////////////////////////////////////////////////////////////
    // Dict: [head] [memsize (bit)] [realsize] [[index] [ptr]] ...

        // Node of dict
        typedef struct {
            ztint index;
            pzd data;
        } zddictnode;

    typedef struct {
        zd head;
        ztsize memsize;
        ztsize realsize;
        zddictnode node[];
    } zddict;

    typedef zddict *pzddict;
    pzd zin_gen_dict(ztid tolayout, ztid totype, ztsize tomemsize);
    #define ZIN_NEW_DICT(totype, tomemsize) zin_gen_dict(ZIN_ID(dict), ZIN_ID(totype), memsize)

    ////////////////////////////////////////////////////////////////
    // Context: [head] [callbuf] [libbuf]

    typedef struct {
        zd head;
        pzdarr callbuf;
        pzdarr libbuf;
    } zdcontext;

    typedef zdcontext *pzdcontext;
    pzd zin_gen_context(ztid tolayout, ztid totype, pzdarr tocallbuf, pzdarr tolibbuf);
    #define ZIN_NEW_CONTEXT(totype, tocallbuf, tolibbuf) zin_gen_context(ZIN_ID(context), ZIN_ID(totype), tocallbuf, tolibbuf)

    ////////////////////////////////////////////////////////////////
    // Func: [head] [funcr] [funcw]

    typedef struct {
        zd head;
        ZIN_PROTO_PR(funcr);
        ZIN_PROTO_PW(funcw);
    } zdfunc;

    typedef zdfunc *pzdfunc;
    pzd zin_gen_func(ztid tolayout, ztid totype, ZIN_PROTO_PR(tofuncr), ZIN_PROTO_PW(tofuncw));
    #define ZIN_NEW_FUNC(totype, tofuncr, tofuncw) zin_gen_func(ZIN_ID(func), ZIN_ID(totype), tofuncr, tofuncw)

    ////////////////////////////////////////////////////////////////
    // Bind: [head] [funcr] [funcw] [caller]

    typedef struct {
        zd head;
        ZIN_PROTO_PR(funcr);
        ZIN_PROTO_PW(funcw);
        pzd caller;
    } zdbind;

    typedef zdbind *pzdbind;
    pzd zin_gen_bind(ztid tolayout, ztid totype, ZIN_PROTO_PR(tofuncr), ZIN_PROTO_PW(tofuncw), pzd tocaller);
    #define ZIN_NEW_BIND(totype, tofuncr, tofuncw, tocaller) zin_gen_bind(ZIN_ID(bind), ZIN_ID(totype), tofuncr, tofuncw, tocaller)

    ////////////////////////////////////////////////////////////////

#else
    #error "bad inc"
#endif
