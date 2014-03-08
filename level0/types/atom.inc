#if   ZIN_MODE == ZIN_MODE_ENUM
    ,zefalse, zetrue

#elif ZIN_MODE == ZIN_MODE_HEADER_READ
    ZIN_PROTO_R(zrfalse);
    ZIN_PROTO_R(zrtrue);

#elif ZIN_MODE == ZIN_MODE_HEADER_WRITE
    ZIN_PROTO_W(zwfalse);
    ZIN_PROTO_W(zwtrue);

#elif ZIN_MODE == ZIN_MODE_READ
    ZIN_PROTO_R(zrfalse) {
        pzdata result = ZIN_CREATE(sizeof(zdatom));

        (pzdatom) result->head.type = zefalse;

        return result;
    }

    ZIN_PROTO_R(zrtrue) {
        pzdata result = ZIN_CREATE(sizeof(zdatom));

        (pzdatom) result->head.type = zetrue;

        return result;
    }

#elif ZIN_MODE == ZIN_MODE_WRITE
    ZIN_PROTO_W(zwfalse) {
        // Error
    }

    ZIN_PROTO_W(zwtrue) {
        // Error
    }

#elif ZIN_MODE == ZIN_MODE_LOAD_READ
    // ZIN_LIB_ADD(ZIN_MAKE_FUNC(&zffalse), ...)
    // ZIN_LIB_ADD(ZIN_MAKE_FUNC(&zftrue), ...)

#elif ZIN_MODE == ZIN_MODE_LOAD_WRITE


#elif ZIN_MODE == ZIN_MODE_TEST_READ
    // ZIN_EXEC(...)

#elif ZIN_MODE == ZIN_MODE_TEST_WRITE


#elif ZIN_MODE == ZIN_MODE_DOC
    // ZIN_DOC(...)

#endif
