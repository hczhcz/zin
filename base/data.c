#include "_all.h"

pzd zin_gen_atom(ztid tolayout, ztid totype, pztfunc tofunc) {
    pzdatom result = ZIN_ALLOCATE_NO_OUT(sizeof(struct zdatom));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    return (pzd)result;
}

pzd zin_gen_int(ztid tolayout, ztid totype, pztfunc tofunc, ztint tovalue) {
    pzdint result = ZIN_ALLOCATE_NO_OUT(sizeof(struct zdint));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->value = tovalue;
    return (pzd)result;
}

pzd zin_gen_str(ztid tolayout, ztid totype, pztfunc tofunc, ztsize tomemsize) {
    pzdstr result = ZIN_ALLOCATE_NO_OUT(sizeof(struct zdstr) + (sizeof(ztchar) << tomemsize));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->memsize = tomemsize;
    result->front = 0;
    result->back = 0;
    return (pzd)result;
}

pzd zin_gen_ptr(ztid tolayout, ztid totype, pztfunc tofunc, pzd todata) {
    pzdptr result = ZIN_ALLOCATE(sizeof(struct zdptr));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->data = todata;
    return (pzd)result;
}

pzd zin_gen_pair(ztid tolayout, ztid totype, pztfunc tofunc, pzd toleft, pzd toright) {
    pzdpair result = ZIN_ALLOCATE(sizeof(struct zdpair));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->left = toleft;
    result->right = toright;
    return (pzd)result;
}

pzd zin_gen_arr(ztid tolayout, ztid totype, pztfunc tofunc, ztsize tomemsize) {
    pzdarr result = ZIN_ALLOCATE(sizeof(struct zdarr) + (sizeof(pzd) << tomemsize));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->memsize = tomemsize;
    result->front = 0;
    result->back = 0;
    return (pzd)result;
}

pzd zin_gen_dict(ztid tolayout, ztid totype, pztfunc tofunc, ztsize tomemsize) {
    ztsize index;
    pzddict result = ZIN_ALLOCATE(sizeof(struct zddict) + (sizeof(ztidnode) << tomemsize));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->memsize = tomemsize;
    result->realsize = 0;
    for (index = 0; index < (1u << tomemsize); ++index) {
        result->node[index].data = 0;
    }
    return (pzd)result;
}

pzd zin_gen_context(ztid tolayout, ztid totype, pztfunc tofunc, pzd tocallbuf, pzd tolibbuf) {
    pzdcontext result = ZIN_ALLOCATE(sizeof(struct zdcontext));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->callbuf = tocallbuf;
    result->libbuf = tolibbuf;
    return (pzd)result;
}

pzd zin_gen_func(ztid tolayout, ztid totype, pztfunc tofunc, ZIN_PROTO_PR(tofuncr), ZIN_PROTO_PW(tofuncw)) {
    pzdfunc result = ZIN_ALLOCATE(sizeof(struct zdfunc));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->head.func = tofunc;
    result->func.funcr = tofuncr;
    result->func.funcw = tofuncw;
    return (pzd)result;
}
