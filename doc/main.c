/**
 * \file main.c
 * \author Павел Иванов, ИУ7-25Б
 * \brief Основная программа обработки чисел из файла.
 * На вход подается число 1 и имя файла.
 *
 * Постановка задачи:
 * В текстовом файле содержатся целые числа. Найти сумму цифр каждого числа
 * и если она четная, то перевести его в двоичную систему счисления,
 * а если нечетная, то преобразовать число в обратном порядке следования цифр.
 * Результат вывести на экран.
 *
 * Программа подготовлена для домашнего задания
 * по ОПИ (1 курс 2 семестр) 2021 год
 */

#include <stdio.h>
#include "functions.h"

/**
 * \fn int main(int args, char **argv)
 * \brief Основная функция
 *
 * \param [in] args подаётся число 1
 * \param [in] argv имя файла
 * \return rc код ошибки
 */
int main(int args, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;

    int mas[N + 1] = { 0 };
    int n = 0;

    FILE *f = fopen(argv[2], "r");
    if (f == NULL)
    {
        rc = NO_FILE;
        printf("File does not exist!");
    }
    else
    {
        int input_success = mas_input(f, mas, &n);
        fclose(f);

        if (input_success == FILE_OVERFLOW)
        {
            rc = FILE_OVERFLOW;
            printf("Too many elements!");
        }
        else if (input_success == EMPRTY_FILE)
        {
            rc = EMPRTY_FILE;
            printf("Empty file!");
        }
        else if (input_success == WRONG_INPUT)
        {
            rc = WRONG_INPUT;
            printf("Invalid input!");
        }
        else if (input_success == NEGATIVES_IN_FILE)
        {
            rc = NEGATIVES_IN_FILE;
            printf("There can't be any negative numbers!");
        }
        else
        {
            mas_process(mas, n);
            mas_output(mas, n);
        }
    }
    return rc;
}
