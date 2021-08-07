add_library(eyes2d STATIC)
luastg_target_common_options(eyes2d)
target_include_directories(eyes2d PUBLIC
    .
)
target_sources(eyes2d PRIVATE
    E2DCodePage.cpp
    E2DCodePage.hpp
    E2DException.hpp
    E2DFileManager.cpp
    E2DFileManager.hpp
    E2DFilePath.hpp
    E2DGlobal.hpp
    E2DLogSystem.cpp
    E2DLogSystem.hpp
    E2DMath.hpp
    E2DXInputImpl.cpp
    E2DXInputImpl.hpp
)
target_link_libraries(eyes2d PUBLIC
    Xinput9_1_0.lib
    fancylib
    zlib
    zip
)
