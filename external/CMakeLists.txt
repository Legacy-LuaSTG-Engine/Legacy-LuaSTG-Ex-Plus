add_library(zlib SHARED IMPORTED GLOBAL)
target_compile_definitions(zlib INTERFACE
    ZLIB_DLL
)
target_include_directories(zlib INTERFACE
    include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "unknown platform")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(zlib PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/zlib.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/zlib.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()
