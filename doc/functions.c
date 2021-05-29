/**
 * \file functions.c
 * \author Павел Иванов, ИУ7-25Б
 * \brief Файл со вспомогательными функциями
 *
 * Дополнительные функции для решения задачи
 */

#include <stdio.h>
#include "functions.h"

/**
 * \fn int mas_input(FILE *f, int *a, int *n)
 * \brief Функция ввода чисел из файла в массив
 *
 * \param [in] f файловая переменная
 * \param [out] a указатель на массив
 * \param [out] n указатель на количество элементов
 * \return error code
 */
int mas_input(FILE *f, int *a, int *n)
{
    int input_success = OK;
    int stop_reading = NO;
    while (!feof(f) && !stop_reading)
        while (!stop_reading && *n < N + 2)
        {
            if (fscanf(f, "%d", a + *n) != 1)
            {
                stop_reading = YES;
                input_success = (feof(f) != 0 ? OK : WRONG_INPUT);
            }
            else if (a[*n - 1] < 0)
            {
                stop_reading = YES;
                input_success = NEGATIVES_IN_FILE;
            }
            else
                (*n)++;
        }

    if (*n == N + 1)
        input_success = FILE_OVERFLOW;
    if (*n == 0)
        input_success = EMPRTY_FILE;
    return input_success;
}

/**
 * \fn int mas_process(int *a, int n)
 * \brief Функция обработки массива чисел: ищет сумму цифр очередного элемента, и
 * если она четная, то перевести его в двоичную систему счисления, а если нечетная,
 * то преобразовать число в обратном порядке следования цифр.
 *
 * \param [out] a указатель на массив
 * \param [in] n количество элементов
 * \return rc код ошибки
 */
int mas_process(int *a, int n)
{
    int rc = OK;
    if (a == NULL)
        rc = NO_MAS;
    else if (n < 0)
        rc = INVALID_SIZE;
    else if (n == 0)
        rc = NO_DATA;
    else
        for (int i = 0; i < n; i++)
        {
            if (num_sum(a[i]) == EVEN)
                a[i] = dec_to_bin(a[i]);
            else
                a[i] = num_invert(a[i]);
        }
    return rc;
}

/**
 * \fn void mas_output(int *a, int n)
 * \brief Функция вывода чисел массива в консоль
 *
 * \param [in] a указатель на массив
 * \param [in] n количество элементов
 */
void mas_output(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

/**
 * \fn int num_sum(int n)
 * \brief Функция ищет признак: четная сумма цифр или нечётная
 *
 * \param [in] n целое число
 * \return flag EVEN если четная сумма цифр, иначе ODD
 */
int num_sum(int n)
{
    int flag;
    int sum = 0;

    if (n < 0)
        flag = NEGATIVE_NUM;
    else
    {
        while (n != 0)
        {
            sum = sum + n % 10;
            n = n / 10;
        }

        if (sum % 2 == 0)
            flag = EVEN;
        else
            flag = ODD;
    }
    return flag;
}

/**
 * \fn int dec_to_bin(int n)
 * \brief Функция перевода числа из 10СС в 2СС
 *
 * \param [in] n целое число
 * \return new число в двоичной системе счисления
 */
int dec_to_bin(int n)
{
    int new;
    if (n < 0)
        new = NEGATIVE_NUM;
    else
    {
        int k = 1;
        new = 0;
        while (n != 0)
        {
            new = new + (n % 2) * k;
            k = k * 10;
            n = n / 2;
        }
    }
    return new;
}

/**
 * \fn int num_invert(int n)
 * \brief Функция "разворота" числа
 *
 * \param [in] n целое число
 * \return new число с обратным порядком следования цифр
 */
int num_invert(int n)
{
    int new;
    if (n < 0)
        new = NEGATIVE_NUM;
    else
    {
        new = 0;
        while (n != 0)
        {
            new = new * 10 + n % 10;
            n = n / 10;
        }
    }
    return new;
}
