@echo off
title Compile Dynamic Link Library
cls

set LibraryName=sin-bass

echo "Compiling Dynamic Link Library..."

windres "resources\resources.rc" -O coff -o "resources\resources.res"

g++ "main.cpp" -static-libgcc -static-libstdc++ -O3 -DNDEBUG -s -shared -o "%LibraryName%.dll" "resources\resources.res"

pause