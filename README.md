# Legacy LuaSTG Ex Plus

LuaSTG EX Plus branch.  LuaSTG EX Plus 分支。

## What's this 这是什么

This is a continued maintenance version of the [LuaSTG Ex Plus](https://github.com/Xiliusha/LuaSTG-EX-Plus) (used to be maintained by @Xiliusha). We upgrade the working flow, using CMake to manage the project.

这是一个[LuaSTG Ex Plus](https://github.com/Xiliusha/LuaSTG-EX-Plus)（曾经由@Xiliusha维护）的继续维护版本。我们与时俱进，通过CMake管理项目。

Even this, we recommend that you use [LuaSTG x](https://github.com/Xrysnow/LuaSTG-x) branch.

即使如此，我们也推荐您使用[LuaSTG x](https://github.com/Xrysnow/LuaSTG-x)。

## Build 构建

1. clone repository 拉取仓库到本地
```batch
git clone --recursive https://github.com/Legacy-LuaSTG-Engine/Legacy-LuaSTG-Ex-Plus.git
```
2. using CMake to generate project files 用CMake生成项目文件
```batch
cd Legacy-LuaSTG-Ex-Plus
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A Win32
cd ..
```
3. compile 编译
```batch
cmake --build build --config Release
```
