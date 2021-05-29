/**
 * \file functions.h
 * \author Павел Иванов, ИУ7-25Б
 * \brief Заголовочный файл
 *
 * Подключение макросов и cигнатур функций
 */

 /**
  * \def N
  * \brief Максимальны размер массива
  */
#define N 100

/**
 * \def EVEN
 * \brief Флаг чётности
 */
#define EVEN 1

/**
 * \def ODD
 * \brief Флаг нечётности
 */
#define ODD 0

/**
 * \def OK
 * \brief Нулевой код возврата
 */
#define OK 0

/**
 * \def NO_FILE
 * \brief код ошибки - нет файла
 */
#define NO_FILE -1

/**
 * \def FILE_OVERFLOW
 * \brief код ошибки - переполнение файла
 */
#define FILE_OVERFLOW -2

/**
 * \def EMPRTY_FILE
 * \brief код возврата - пустой файл
 */
#define EMPRTY_FILE -3

/**
 * \def WRONG_INPUT
 * \brief код возврата - ошибка чтения
 */
#define WRONG_INPUT -4

/**
 * \def NEGATIVES_IN_FILE
 * \brief код возврата - есть отрицательные числа в файле
 */
#define NEGATIVES_IN_FILE -5

/**
 * \def NO_MAS
 * \brief код возврата - не передан массив
 */
#define NO_MAS -6

/**
 * \def INVALID_SIZE
 * \brief код возврата - передан неверный размер массива
 */
#define INVALID_SIZE -7

/**
 * \def NO_DATA
 * \brief код возврата - отсутствие данных
 */
#define NO_DATA -8

/**
 * \def NEGATIVE_NUM
 * \brief код возврата - отрицательное число
 */
#define NEGATIVE_NUM -9

/**
 * \def YES
 * \brief флаг "да"
 */
#define YES 1

/**
 * \def NO
 * \brief флаг "NO"
 */
#define NO 0

/**
 * \Сигнатура функции mas_input
 */
int mas_input(FILE *f, int *a, int *n);

/**
 * \Сигнатура функции mas_process
 */
int mas_process(int *a, int n);

/**
 * \Сигнатура функции mas_output
 */
void mas_output(int *a, int n);

/**
 * \Сигнатура функции num_sum
 */
int num_sum(int n);

/**
 * \Сигнатура функции dec_to_bin
 */
int dec_to_bin(int n);

/**
 * \Сигнатура функции num_invert
 */
int num_invert(int n);
