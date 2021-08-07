add_subdirectory(DirectShowClass)

add_library(DXSDK_D3DX9 SHARED IMPORTED GLOBAL)
target_include_directories(DXSDK_D3DX9 INTERFACE
    include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set_target_properties(DXSDK_D3DX9 PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/x64/d3dx9.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/x64/D3DX9_43.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(DXSDK_D3DX9 PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/d3dx9.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/D3DX9_43.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()

add_library(DXSDK_D3DXCompiler SHARED IMPORTED GLOBAL)
target_include_directories(DXSDK_D3DXCompiler INTERFACE
    include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set_target_properties(DXSDK_D3DXCompiler PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/x64/d3dx9.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/x64/D3DCompiler_43.dll
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set_target_properties(DXSDK_D3DXCompiler PROPERTIES
        IMPORTED_IMPLIB   ${CMAKE_CURRENT_LIST_DIR}/lib/d3dx9.lib
        IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/D3DCompiler_43.dll
    )
else()
    message(FATAL_ERROR "unknown platform")
endif()
