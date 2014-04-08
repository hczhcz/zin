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
    // Str: [head] [memsize (bit)] [realsize] [char] ...

    typedef struct {
        zd head;
        ztsize memsize;
        ztsize realsize;
        ztchar data[];
    } zdstr;

    typedef zdstr *pzdstr;
    pzd zin_gen_str(ztid tolayout, ztid totype, ztsize tomemsize);
    #define ZIN_NEW_STR(totype, tomemsize) zin_gen_str(ZIN_ID(str), ZIN_ID(totype), tomemsize)

    ////////////////////////////////////////////////////////////////
    // Code: [head] [ptr]

    typedef struct {
        zd head;
        pzd param;
    } zdcode;

    typedef zdcode *pzdcode;
    pzd zin_gen_code(ztid tolayout, ztid totype, pzd toparam);
    #define ZIN_NEW_CODE(totype, toparam) zin_gen_code(ZIN_ID(code), ZIN_ID(totype), toparam)

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

#endif
