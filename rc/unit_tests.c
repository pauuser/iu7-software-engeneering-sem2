#include <stdio.h>
#include "functions.h"

void test_num_invert(void)
{
    int err_cnt = 0;

    //
    // Невозможные параметры
    //

    {
        int a = -10;

        if (num_invert(a) != NEGATIVE_NUM)
            err_cnt++;
    }

    //
    // Корректные данные
    //

    {
        int a = 12;
        int b = 1;
        int c = 342;

        if (num_invert(a) != 21)
            err_cnt++;

        if (num_invert(b) != 1)
            err_cnt++;

        if (num_invert(c) != 243)
            err_cnt++;
    }

    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}

void test_dec_to_bin(void)
{
    int err_cnt = 0;

    //
    // Невозможные параметры
    //

    {
        int a = -10;

        if (dec_to_bin(a) != NEGATIVE_NUM)
            err_cnt++;
    }

    //
    // Корректные данные
    //

    {
        int a = 0;
        int b = 13;
        int c = 6;

        if (dec_to_bin(a) != 0)
            err_cnt++;

        if (dec_to_bin(b) != 1101)
            err_cnt++;

        if (dec_to_bin(c) != 110)
            err_cnt++;
    }

    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}

void test_num_sum(void)
{
    int err_cnt = 0;

    //
    // Невозможные параметры
    //

    {
        int a = -10;

        if (dec_to_bin(a) != NEGATIVE_NUM)
            err_cnt++;
    }

    //
    // Корректные данные
    //

    {
        int a = 1;
        int b = 2;
        int c = 12;
        int d = 13;
        int e = 0;

        if (num_sum(a) != 0)
            err_cnt++;

        if (num_sum(b) != 1)
            err_cnt++;

        if (num_sum(c) != 0)
            err_cnt++;

        if (num_sum(d) != 1)
            err_cnt++;

        if (num_sum(e) != 1)
            err_cnt++;
    }

    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}

// вспомогательная функция сравнения массивов
int test_compare_mas(int *mas1, int *mas2, int n)
{
    int match = YES;
    for (int i = 0; i < n && match; i++)
        if (mas1[i] != mas2[i])
            match = NO;
    return match;
}

void test_mas_process(void)
{
    int err_cnt = 0;

    //
    // Неверные параметры
    //

    {
        int a[] = {1, 2, 3};

        if (mas_process(NULL, 2) != NO_MAS)
            err_cnt++;

        if (mas_process(a, -3) != INVALID_SIZE)
            err_cnt++;
    }

    //
    // Пустой массив
    //

    {
        int a[] = {};
        int n = 0;

        if (mas_process(a, n) != NO_DATA)
            err_cnt++;
    }

    //
    // Корректные данные
    //

    {
        int a[] = {1, 6};
        int b[] = {6};
        int c[] = {12};

        mas_process(a, 2);
        mas_process(b, 1);
        mas_process(c, 1);

        int ans1[] = {1, 110};
        int ans2[] = {110};
        int ans3[] = {21};

        if (test_compare_mas(a, ans1, 2) == NO)
            err_cnt++;

        if (test_compare_mas(b, ans2, 1) == NO)
            err_cnt++;

        if (test_compare_mas(c, ans3, 1) == NO)
            err_cnt++;
    }

    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    printf("--STARTED UNIT TESTING--\n");
    test_num_invert();
    test_dec_to_bin();
    test_num_sum();
    test_mas_process();
    printf("--ENDED UNIT TESTING--\n");
    return 0;
}
