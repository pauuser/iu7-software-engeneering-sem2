@echo off
gcc -std=c99 -Wall -Werror -c functions.c
gcc -std=c99 -Wall -Werror -c unit_tests.c
gcc -o unit.exe functions.o unit_tests.o
