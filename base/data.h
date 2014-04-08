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

    static inline pzd zin_gen_atom(ztid tolayout, ztid totype) {
        pzdatom result = ZIN_ALLOCATE_NO_OUT(sizeof(zdatom));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_ATOM(totype) zin_gen_atom(ZIN_ID(atom), ZIN_ID(totype))

    ////////////////////////////////////////////////////////////////
    // Int: [head] [int]

    typedef struct {
        zd head;
        ztint value;
    } zdint;

    typedef zdint *pzdint;

    static inline pzd zin_gen_int(ztid tolayout, ztid totype) {
        pzdint result = ZIN_ALLOCATE_NO_OUT(sizeof(zdint));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_INT(totype) zin_gen_int(ZIN_ID(int), ZIN_ID(totype))

    ////////////////////////////////////////////////////////////////
    // Str: [head] [memsize (bit)] [realsize] [char] ...

    typedef struct {
        zd head;
        ztsize memsize;
        ztsize realsize;
        ztchar data[];
    } zdstr;

    typedef zdstr *pzdstr;

    static inline pzd zin_gen_str(ztid tolayout, ztid totype) {
        pzdstr result = ZIN_ALLOCATE_NO_OUT(sizeof(zdstr));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_STR(totype) zin_gen_str(ZIN_ID(str), ZIN_ID(totype))

    ////////////////////////////////////////////////////////////////
    // Code: [head] [ptr]

    typedef struct {
        zd head;
        pzd param;
    } zdcode;

    typedef zdcode *pzdcode;

    static inline pzd zin_gen_code(ztid tolayout, ztid totype) {
        pzdcode result = ZIN_ALLOCATE(sizeof(zdcode));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_CODE(totype) zin_gen_code(ZIN_ID(code), ZIN_ID(totype))

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

    static inline pzd zin_gen_arr(ztid tolayout, ztid totype) {
        pzdarr result = ZIN_ALLOCATE(sizeof(zdarr));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_ARR(totype) zin_gen_arr(ZIN_ID(arr), ZIN_ID(totype))

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

    static inline pzd zin_gen_dict(ztid tolayout, ztid totype) {
        pzddict result = ZIN_ALLOCATE(sizeof(zddict));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_DICT(totype) zin_gen_dict(ZIN_ID(dict), ZIN_ID(totype))

    ////////////////////////////////////////////////////////////////
    // Context: [head] [callbuf] [libbuf]

    typedef struct {
        zd head;
        pzdarr callbuf;
        pzdarr libbuf;
    } zdcontext;

    typedef zdcontext *pzdcontext;

    static inline pzd zin_gen_context(ztid tolayout, ztid totype) {
        pzdcontext result = ZIN_ALLOCATE(sizeof(zdcontext));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_CONTEXT(totype) zin_gen_context(ZIN_ID(context), ZIN_ID(totype))

    ////////////////////////////////////////////////////////////////
    // Func: [head] [funcr] [funcw]

    typedef struct {
        zd head;
        ZIN_PROTO_PR(funcr);
        ZIN_PROTO_PW(funcw);
    } zdfunc;

    typedef zdfunc *pzdfunc;

    static inline pzd zin_gen_func(ztid tolayout, ztid totype) {
        pzdfunc result = ZIN_ALLOCATE(sizeof(zdfunc));
        result->head.layout = tolayout;
        result->head.type = totype;
        return (pzd)result;
    }
    #define ZIN_NEW_FUNC(totype) zin_gen_func(ZIN_ID(func), ZIN_ID(totype))

    ////////////////////////////////////////////////////////////////

#endif
