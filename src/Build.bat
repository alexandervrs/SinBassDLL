@echo off
title Compile
cls

set LibraryName=sin-bass

echo Compiling...

if not exist "release\" mkdir "release\"

windres "Resources\resources.rc" -O coff -o "Resources\resources.res"

"i686-w64-mingw32-g++.exe" "main.cpp" -m32 -static-libgcc -static-libstdc++ -D UNICODE -D _UNICODE -O3 -DNDEBUG -s -shared -o "release\%LibraryName%.dll" "Resources\resources.res"

pause