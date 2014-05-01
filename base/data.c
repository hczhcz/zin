#include "_all.h"

pzd zin_gen_atom(ztid tolayout, ztid totype) {
    pzdatom result = ZIN_ALLOCATE_NO_OUT(sizeof(zdatom));
    result->head.layout = tolayout;
    result->head.type = totype;
    return (pzd)result;
}

pzd zin_gen_int(ztid tolayout, ztid totype, ztint tovalue) {
    pzdint result = ZIN_ALLOCATE_NO_OUT(sizeof(zdint));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->value = tovalue;
    return (pzd)result;
}

pzd zin_gen_str(ztid tolayout, ztid totype, ztsize tomemsize) {
    pzdstr result = ZIN_ALLOCATE_NO_OUT(sizeof(zdstr) + (sizeof(ztchar) << tomemsize));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->memsize = tomemsize;
    result->front = 0;
    result->back = 0;
    return (pzd)result;
}

pzd zin_gen_ptr(ztid tolayout, ztid totype, pzd todata) {
    pzdptr result = ZIN_ALLOCATE(sizeof(zdptr));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->data = todata;
    return (pzd)result;
}

pzd zin_gen_pair(ztid tolayout, ztid totype, pzd toleft, pzd toright) {
    pzdpair result = ZIN_ALLOCATE(sizeof(zdpair));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->left = toleft;
    result->right = toright;
    return (pzd)result;
}

pzd zin_gen_arr(ztid tolayout, ztid totype, ztsize tomemsize) {
    pzdarr result = ZIN_ALLOCATE(sizeof(zdarr) + (sizeof(pzd) << tomemsize));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->memsize = tomemsize;
    result->front = 0;
    result->back = 0;
    return (pzd)result;
}

pzd zin_gen_dict(ztid tolayout, ztid totype, ztsize tomemsize) {
    ztsize index;
    pzddict result = ZIN_ALLOCATE(sizeof(zddict) + (sizeof(zddictnode) << tomemsize));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->memsize = tomemsize;
    result->realsize = 0;
    for (index = 0; index < (1u << tomemsize); ++index) {
        result->node[index].data = 0;
    }
    return (pzd)result;
}

pzd zin_gen_context(ztid tolayout, ztid totype, pzdarr tocallbuf, pzdarr tolibbuf) {
    pzdcontext result = ZIN_ALLOCATE(sizeof(zdcontext));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->callbuf = tocallbuf;
    result->libbuf = tolibbuf;
    return (pzd)result;
}

pzd zin_gen_func(ztid tolayout, ztid totype, ZIN_PROTO_PR(tofuncr), ZIN_PROTO_PW(tofuncw)) {
    pzdfunc result = ZIN_ALLOCATE(sizeof(zdfunc));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->funcr = tofuncr;
    result->funcw = tofuncw;
    return (pzd)result;
}

pzd zin_gen_bind(ztid tolayout, ztid totype, ZIN_PROTO_PR(tofuncr), ZIN_PROTO_PW(tofuncw), pzd tocaller) {
    pzdbind result = ZIN_ALLOCATE(sizeof(zdbind));
    result->head.layout = tolayout;
    result->head.type = totype;
    result->funcr = tofuncr;
    result->funcw = tofuncw;
    result->caller = tocaller;
    return (pzd)result;
}
