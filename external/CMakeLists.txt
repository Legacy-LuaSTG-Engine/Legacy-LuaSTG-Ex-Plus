add_library(zlib SHARED IMPORTED GLOBAL)
target_compile_definitions(zlib INTERFACE
    ZLIB_DLL
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_include_directories(zlib INTERFACE
        x64/include
    )
    set_target_properties(zlib PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/x64/lib/zlib.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/x64/bin/zlib.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_include_directories(zlib INTERFACE
        include
    )
    set_target_properties(zlib PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/zlib.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/zlib.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(zip SHARED IMPORTED GLOBAL)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_include_directories(zip INTERFACE
        x64/include
    )
    set_target_properties(zip PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/x64/lib/zip.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/x64/bin/zip.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_include_directories(zip INTERFACE
        include
    )
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
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_include_directories(freetype INTERFACE
        x64/include
        x64/include/freetype2
    )
        set_target_properties(freetype PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/x64/lib/freetype.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/x64/bin/freetype.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_include_directories(freetype INTERFACE
        include
        include/freetype2
    )
    set_target_properties(freetype PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/freetype.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/freetype.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(ogg SHARED IMPORTED GLOBAL)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_include_directories(ogg INTERFACE
        x64/include
    )
    set_target_properties(ogg PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/x64/lib/ogg.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/x64/bin/ogg.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_include_directories(ogg INTERFACE
        include
    )
    set_target_properties(ogg PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/ogg.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/ogg.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(vorbis SHARED IMPORTED GLOBAL)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_include_directories(vorbis INTERFACE
        x64/include
    )
    set_target_properties(vorbis PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/x64/lib/vorbis.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/x64/bin/vorbis.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_include_directories(vorbis INTERFACE
        include
    )
    set_target_properties(vorbis PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/vorbis.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/vorbis.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(vorbisfile SHARED IMPORTED GLOBAL)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_include_directories(vorbisfile INTERFACE
        x64/include
    )
    set_target_properties(vorbisfile PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/x64/lib/vorbisfile.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/x64/bin/vorbisfile.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_include_directories(vorbisfile INTERFACE
        include
    )
    set_target_properties(vorbisfile PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/vorbisfile.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/vorbisfile.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()


add_library(luajit SHARED IMPORTED GLOBAL)
target_compile_definitions(freetype INTERFACE
    LUA_BUILD_AS_DLL
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_include_directories(luajit INTERFACE
        x64/include
    )
    set_target_properties(luajit PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/x64/lib/lua51.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/x64/bin/lua51.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_include_directories(luajit INTERFACE
        include
    )
    set_target_properties(luajit PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/lua51.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/bin/lua51.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()
