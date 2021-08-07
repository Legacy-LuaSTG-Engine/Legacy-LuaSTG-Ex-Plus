function(luastg_target_common_options __TARGET__)
    target_compile_options(${__TARGET__} PRIVATE
        "/MP"
        "/utf-8"
    )
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        target_compile_options(${__TARGET__} PRIVATE
            "/arch:SSE2"
        )
    endif()
    set_target_properties(${__TARGET__} PROPERTIES
        C_STANDARD 17
        C_STANDARD_REQUIRED ON
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )
    target_compile_definitions(${__TARGET__} PRIVATE
        _UNICODE
        UNICODE
    )
endfunction()
