@mkdir build
@cd build
cmake .. -G "Visual Studio 17 2022" -A Win32
@cd ..
cmake --build build --config Release
