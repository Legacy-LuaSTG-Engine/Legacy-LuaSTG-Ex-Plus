#pragma once

//DLL base macro
#ifdef EYES2D_BUILDDLL
    #ifdef EYES2D_EXPORTS
        #define EYESDLLAPI _declspec(dllexport)
    #else
        #define EYESDLLAPI _declspec(dllimport)
    #endif
#else
    #define EYESDLLAPI
#endif

//Windows base header
#include <Windows.h>
#include <wrl.h>

//usefull tool
#include "E2DException.hpp"
