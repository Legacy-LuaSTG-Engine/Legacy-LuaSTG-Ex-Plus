# LuaSTG Ex Plus

## What's this

This is an archive of [LuaSTG Ex Plus](https://github.com/Xiliusha/LuaSTG-EX-Plus) (used to be maintained by @Xiliusha), no new features are being developed, only critical bug fixes. We upgrade the working flow, using CMake to manage the project.

The life cycle of LuaSTG Ex Plus has ended, we recommend you:
* If you are using LuaSTG (vanilla), please consider migrating to [LuaSTG Plus V2](https://github.com/9chu/LuaSTGPlus) or [LuaSTG Sub](https://github.com/Legacy-LuaSTG-Engine/LuaSTG-Sub)
* If you are using LuaSTG Plus, please consider migrating to [LuaSTG Plus V2](https://github.com/9chu/LuaSTGPlus)
* If you are using LuaSTG Ex Plus, please consider migrating to [LuaSTG Sub](https://github.com/Legacy-LuaSTG-Engine/LuaSTG-Sub)

## Build

1. clone repository
```batch
git clone --recursive https://github.com/Legacy-LuaSTG-Engine/Legacy-LuaSTG-Ex-Plus.git
```
2. using CMake to generate project files
```batch
cd Legacy-LuaSTG-Ex-Plus
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A Win32
cd ..
```
3. compile
```batch
cmake --build build --config Release
```

---

## 这是什么

这是一个[LuaSTG Ex Plus](https://github.com/Xiliusha/LuaSTG-EX-Plus)（曾经由@Xiliusha维护）的存档，不再开发新功能，仅修复重要 bug。我们与时俱进，通过CMake管理项目。

LuaSTG Ex Plus 的生命周期已经结束，我们推荐您：
* 如果正在使用 LuaSTG 最初版本，请考虑迁移到 [LuaSTG Plus V2](https://github.com/9chu/LuaSTGPlus) 或者 [LuaSTG Sub](https://github.com/Legacy-LuaSTG-Engine/LuaSTG-Sub)
* 如果正在使用 LuaSTG Plus，请考虑迁移到 [LuaSTG Plus V2](https://github.com/9chu/LuaSTGPlus)
* 如果正在使用 LuaSTG Ex Plus，请考虑迁移到 [LuaSTG Sub](https://github.com/Legacy-LuaSTG-Engine/LuaSTG-Sub)

## 构建

1. 拉取仓库到本地
```batch
git clone --recursive https://github.com/Legacy-LuaSTG-Engine/Legacy-LuaSTG-Ex-Plus.git
```
2. 用 CMake 生成项目文件
```batch
cd Legacy-LuaSTG-Ex-Plus
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A Win32
cd ..
```
3. 编译
```batch
cmake --build build --config Release
```
