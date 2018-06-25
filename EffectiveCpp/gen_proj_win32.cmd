@echo off

md proj_win32 > nul 2>&1
cd proj_win32
cmake ..
cd ..