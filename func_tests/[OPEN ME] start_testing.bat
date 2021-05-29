@echo off
gcc -std=c99 -Wall -Werror -c ../rc/main.c
gcc -std=c99 -Wall -Werror -c ../rc/functions.c
gcc -o main.exe main.o functions.o
move main.exe ./datas
cd datas
start run_tests.bat
