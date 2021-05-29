@echo off
:: This batch file runs a single test ::
echo %1
main.exe 1 in_%1.txt > out.txt
fc out.txt out_%1.txt
del out.txt
pause
