@echo off
setlocal

:: Move to project root
cd ..

:: Create bld directory if it doesn't exist
if not exist "bld" mkdir bld

:: Generate project for Visual Studio 2022 (x64)
cmake -S . -B bld -G "Visual Studio 17 2022" -A x64

:: Build using Debug configuration, explicitly setting platform
cmake --build bld --config Debug -- /p:Platform=x64

echo Project successfully built with Visual Studio 2022 in Debug mode.
endlocal