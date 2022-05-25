add_executable(LuaSTGPlus WIN32)
luastg_target_common_options(LuaSTGPlus)
target_compile_definitions(LuaSTGPlus PRIVATE
    ____LDEVVERSION
)
target_include_directories(LuaSTGPlus PRIVATE
    .
    LuaWrapper
    LuaWrapper/IO
    LuaWrapper/Misc
    Resource
)
target_sources(LuaSTGPlus PRIVATE
    AppFrame.cpp
    AppFrame.h
    AppFrameFontRenderer.cpp
    AppFrameRender.cpp
    ArchiveWrapper.cpp
    Bencode.cpp
    Bencode.h
    CirularQueue.hpp
    CollisionDetect.cpp
    CollisionDetect.h
    Config.h
    Dictionary.hpp
    ESC.cpp
    ESC.h
    FileManagerWrapper.cpp
    GameObject.cpp
    GameObject.hpp
    GameObjectBentLaser.cpp
    GameObjectBentLaser.hpp
    GameObjectClass.hpp
    GameObjectColliderWrapper.cpp
    GameObjectPool.cpp
    GameObjectPool.h
    Global.h
    LogSystem.cpp
    LogSystem.h
    LuaCustomLoader.cpp
    LuaCustomLoader.hpp
    LuaInternalSource.cpp
    LuaInternalSource.hpp
    LuaStringToEnum.cpp
    LuaStringToEnum.hpp
    LuaTableToOption.cpp
    LuaTableToOption.hpp
    LuaWrapperGlobal.cpp
    LW_SteamAPI.cpp
    LW_SteamAPI.h
    Main.cpp
    Network.cpp
    Network.h
    ObjectPool.hpp
    RemoteDebuggerClient.cpp
    RemoteDebuggerClient.h
    ResourceAnimation.cpp
    ResourceAnimation.hpp
    ResourceAudio.cpp
    ResourceAudio.hpp
    ResourceBase.hpp
    ResourceFont.cpp
    ResourceFont.hpp
    ResourceFX.cpp
    ResourceFX.hpp
    ResourceMgr.cpp
    ResourceMgr.h
    ResourceModel.hpp
    ResourceParticle.cpp
    ResourceParticle.hpp
    ResourcePassword.cpp
    ResourcePassword.hpp
    ResourcePool.cpp
    ResourceSprite.hpp
    ResourceTexture.hpp
    RuntimeCheck.hpp
    SplashWindow.cpp
    SplashWindow.h
    SteamAPI.cpp
    SteamAPI.hpp
    SystemDirectory.cpp
    SystemDirectory.hpp
    UnicodeStringEncoding.cpp
    UnicodeStringEncoding.h
    Utility.cpp
    Utility.h
    XInputWrapper.cpp
    LuaWrapper/LuaWrapper.cpp
    LuaWrapper/LuaWrapper.hpp
    LuaWrapper/LuaWrapperMisc.hpp
    LuaWrapper/IO/LW_IO.cpp
    LuaWrapper/IO/LW_IO_BinaryReader.cpp
    LuaWrapper/IO/LW_IO_BinaryWriter.cpp
    LuaWrapper/IO/LW_IO_Stream.cpp
    LuaWrapper/Misc/LW_BentLaser.cpp
    LuaWrapper/Misc/LW_Color.cpp
    LuaWrapper/Misc/LW_Randomizer.cpp
    LuaWrapper/Misc/LW_StopWatch.cpp
)
target_sources(LuaSTGPlus PRIVATE
    Resource/app.ico
    Resource/LuaSTGPlus.rc
    Resource/resource.h
    Resource/splash.png
)
target_link_libraries(LuaSTGPlus PRIVATE
    fancylib
    eyes2d
    fancy2d
    xmath
    luajit
    lualib
    Gdiplus.lib
)

luastg_target_copy_to_output_directory(LuaSTGPlus LuaSTGPlus)
luastg_target_copy_to_output_directory(LuaSTGPlus luajit)
luastg_target_copy_to_output_directory(LuaSTGPlus zlib)
luastg_target_copy_to_output_directory(LuaSTGPlus zip)
luastg_target_copy_to_output_directory(LuaSTGPlus ogg)
luastg_target_copy_to_output_directory(LuaSTGPlus vorbis)
luastg_target_copy_to_output_directory(LuaSTGPlus vorbisfile)
luastg_target_copy_to_output_directory(LuaSTGPlus freetype)
luastg_target_copy_to_output_directory(LuaSTGPlus DXSDK_D3DX9)
luastg_target_copy_to_output_directory(LuaSTGPlus DXSDK_D3DXCompiler)
