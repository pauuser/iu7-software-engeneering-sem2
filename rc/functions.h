#define N 100
#define EVEN 1
#define ODD 0
#define OK 0
#define NO_FILE -1
#define FILE_OVERFLOW -2
#define EMPRTY_FILE -3
#define WRONG_INPUT -4
#define NEGATIVES_IN_FILE -5
#define NO_MAS -6
#define INVALID_SIZE -7
#define NO_DATA -8
#define NEGATIVE_NUM -9
#define YES 1
#define NO 0

int mas_input(FILE *f, int *a, int *n);

int mas_process(int *a, int n);

void mas_output(int *a, int n);

int num_sum(int n);

int dec_to_bin(int n);

int num_invert(int n);
