add_library(lualib STATIC)
luastg_target_common_options2(lualib) # no UNICODE
target_include_directories(lualib PRIVATE
    cjson
    lfs/src
)
target_compile_options(lualib PRIVATE
    #"/Dinline=__inline"
    #"/Dsnprintf=_snprintf"
    #"/Dstrncasecmp=_strnicmp"
)
target_compile_definitions(lualib PRIVATE
    DISABLE_INVALID_NUMBERS
    _CRT_SECURE_NO_WARNINGS
    USE_INTERNAL_ISINF
    ENABLE_CJSON_GLOBAL
    strcasecmp=stricmp
    strncasecmp=strnicmp
)
target_sources(lualib PRIVATE
    cjson/fpconv.c
    cjson/lua_cjson.c
    cjson/strbuf.c
)
target_sources(lualib PRIVATE
    lfs/src/lfs.c
    lfs/src/lfs.h
)
target_link_libraries(lualib PUBLIC
    luajit
)
