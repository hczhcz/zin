#if   ZIN_MODE == ZIN_MODE_ID
    ZIN_ID_INIT(init_types, 0)

#elif ZIN_MODE == ZIN_MODE_HEADER_READ
    ZIN_PROTO_R(init_types);

#elif ZIN_MODE == ZIN_MODE_HEADER_WRITE
    ZIN_PROTO_W(init_types);

#elif ZIN_MODE == ZIN_MODE_READ
    ZIN_PROTO_R(init_types) {
        pzdata result = 0; // TODO: = zrdict(...)

        #undef ZIN_MODE

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

        #define ZIN_MODE ZIN_MODE_READ

        return result;
    }

#elif ZIN_MODE == ZIN_MODE_WRITE
    ZIN_PROTO_W(init_types) {
        // Error
    }

#elif ZIN_MODE == ZIN_MODE_LOAD_READ
    // dict(init) => func(types)

#elif ZIN_MODE == ZIN_MODE_LOAD_WRITE


#elif ZIN_MODE == ZIN_MODE_TEST_READ
    // ZIN_EXEC(...)

#elif ZIN_MODE == ZIN_MODE_TEST_WRITE


#elif ZIN_MODE == ZIN_MODE_DOC
    // ZIN_DOC(...)

#endif
