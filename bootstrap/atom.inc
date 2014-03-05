#if   ZIN_MODE == ZIN_MODE_ENUM
    zefalse, zetrue

#elif ZIN_MODE == ZIN_MODE_HEADER_PROTO
    //#define ZIN_MAKE_FALSE() ...
    //#define ZIN_MAKE_TRUE() ...

#elif ZIN_MODE == ZIN_MODE_HEADER_READ
    ZIN_PROTO_R(zrfalse);
    ZIN_PROTO_R(zrtrue);

#elif ZIN_MODE == ZIN_MODE_HEADER_WRITE
    ZIN_PROTO_W(zwfalse);
    ZIN_PROTO_W(zwtrue);

#elif ZIN_MODE == ZIN_MODE_READ
    ZIN_PROTO_R(zrfalse) {
        //
    }

    ZIN_PROTO_R(zrtrue) {
        //
    }

#elif ZIN_MODE == ZIN_MODE_WRITE
    ZIN_PROTO_W(zwfalse) {
        // Error
    }

    ZIN_PROTO_W(zwtrue) {
        // Error
    }

#elif ZIN_MODE == ZIN_MODE_LOAD
    // ZIN_LIB_ADD(ZIN_MAKE_FUNC(&zffalse), ...)
    // ZIN_LIB_ADD(ZIN_MAKE_FUNC(&zftrue), ...)

#elif ZIN_MODE == ZIN_MODE_TEST
    // ZIN_EXEC(...)

#endif
