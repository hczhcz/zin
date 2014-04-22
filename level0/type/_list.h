#if   ZIN_LIBMODE == ZIN_LIBMODE_SKIP
    #ifdef ZIN_TYPE_ALL_H
        #define ZIN_SKIP_FILE
    #else
        #define ZIN_TYPE_ALL_H
    #endif
#elif ZIN_LIBMODE == ZIN_LIBMODE_INC
    #define zr_ZIN_CURRENT_INIT zrinit_type // ZIN_FUNC_R
    #define zw_ZIN_CURRENT_INIT zwinit_type // ZIN_FUNC_W
    #define za_ZIN_CURRENT_INIT zainit_type // ZIN_ID_ALLOC
    #define ze_ZIN_CURRENT_INIT zeinit_type // ZIN_ID

        #include "_init.zc"

    #undef zr_ZIN_CURRENT_INIT
    #undef zw_ZIN_CURRENT_INIT
    #undef za_ZIN_CURRENT_INIT
    #undef ze_ZIN_CURRENT_INIT

    #include "arr.zc"
    #include "atom.zc"
    #include "code.zc"
    #include "context.zc"
    #include "dict.zc"
    #include "func.zc"
    #include "int.zc"
    #include "str.zc"
#endif
