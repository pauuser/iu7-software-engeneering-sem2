@echo off
cls
for %%i in (1 2 3 4 5 6 7 8 9) do call test.bat %%i
del main.exe
cd ..
del main.o
del functions.o
