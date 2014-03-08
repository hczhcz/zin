#if   ZIN_MODE == ZIN_MODE_ENUM
    ,zeinit_types = 0

#elif ZIN_MODE == ZIN_MODE_HEADER_READ
    ZIN_PROTO_R(zrinit_types);

#elif ZIN_MODE == ZIN_MODE_HEADER_WRITE
    ZIN_PROTO_W(zwinit_types);

#elif ZIN_MODE == ZIN_MODE_READ
    ZIN_PROTO_R(zrinit_types) {
        pzdata result = 0; // TODO: = zrdict(...)

        #define ZIN_MODE ZIN_MODE_LOAD_READ
        #include "_list.inc"
        #undef ZIN_MODE

        #ifdef ZIN_ENABLE_WRITE
            #define ZIN_MODE ZIN_MODE_LOAD_WRITE
            #include "_list.inc"
            #undef ZIN_MODE
        #endif

        #ifdef ZIN_ENABLE_TEST
            #define ZIN_MODE ZIN_MODE_TEST_READ
            #include "_list.inc"
            #undef ZIN_MODE

            #ifdef ZIN_ENABLE_WRITE
                #define ZIN_MODE ZIN_MODE_TEST_WRITE
                #include "_list.inc"
                #undef ZIN_MODE
            #endif
        #endif

        #ifdef ZIN_ENABLE_DOC
            #define ZIN_MODE ZIN_MODE_DOC
            #include "_list.inc"
            #undef ZIN_MODE
        #endif

        return result;
    }

#elif ZIN_MODE == ZIN_MODE_WRITE
    ZIN_PROTO_W(zwinit_types) {
        // Error
    }

#elif ZIN_MODE == ZIN_MODE_LOAD_READ
    // dict(init) => func(types)
    // ZIN_LIB_ADD(ZIN_MAKE_FUNC(&zftrue), ...)

#elif ZIN_MODE == ZIN_MODE_LOAD_WRITE


#elif ZIN_MODE == ZIN_MODE_TEST_READ
    // ZIN_EXEC(...)

#elif ZIN_MODE == ZIN_MODE_TEST_WRITE


#elif ZIN_MODE == ZIN_MODE_DOC
    // ZIN_DOC(...)

#endif
