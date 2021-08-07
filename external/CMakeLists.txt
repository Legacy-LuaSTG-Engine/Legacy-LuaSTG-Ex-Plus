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


add_library(zip SHARED IMPORTED GLOBAL)
target_include_directories(zip INTERFACE
    include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "unknown platform")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(zip PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/zip.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/zip.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(freetype SHARED IMPORTED GLOBAL)
target_compile_definitions(freetype INTERFACE
    DLL_IMPORT
)
target_include_directories(freetype INTERFACE
    include
    include/freetype2
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "unknown platform")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(freetype PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/freetype.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/freetype.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(ogg SHARED IMPORTED GLOBAL)
target_include_directories(ogg INTERFACE
    include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "unknown platform")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(ogg PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/ogg.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/ogg.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(vorbis SHARED IMPORTED GLOBAL)
target_include_directories(vorbis INTERFACE
    include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "unknown platform")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(vorbis PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/vorbis.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/vorbis.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(vorbisfile SHARED IMPORTED GLOBAL)
target_include_directories(vorbisfile INTERFACE
    include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "unknown platform")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(vorbisfile PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/vorbisfile.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/vorbisfile.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()
