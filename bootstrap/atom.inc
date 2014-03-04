#if   ZIN_MODE == ZIN_MODE_ENUM
    zefalse, zetrue

#elif ZIN_MODE == ZIN_MODE_HEADER
    //#define ZIN_MAKE_FALSE()

#elif ZIN_MODE == ZIN_MODE_READ
    ZIN_PROTO_R(zffalse) {
        //
    }

    ZIN_PROTO_R(zftrue) {
        //
    }

#elif ZIN_MODE == ZIN_MODE_WRITE
    ZIN_PROTO_W(zffalse) {
        // Error
    }

    ZIN_PROTO_W(zftrue) {
        // Error
    }

#elif ZIN_MODE == ZIN_MODE_LOAD
    // ZIN_LIB_ADD(ZIN_MAKE_FUNC(&zffalse), ...)
    // ZIN_LIB_ADD(ZIN_MAKE_FUNC(&zftrue), ...)

#elif ZIN_MODE == ZIN_MODE_TEST
    // ZIN_EXEC(...)

#endif