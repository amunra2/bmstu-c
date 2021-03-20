#include"../inc/my_snprintf.h"


int main(void)
{
    char test_my_snprintf[BUF_LEN];
    char test_snprintf[BUF_LEN];

    short int data = SHRT_MAX;

    int len_my_snprintf = my_snprintf(test_my_snprintf, BUF_LEN, "%hd", data);
    int len_snprintf = snprintf(test_snprintf, BUF_LEN, "%hd", data);

    printf("\nmy_snprintf\n%d\n", len_my_snprintf);
    printf("%s\n\n", test_my_snprintf);

    printf("snprintf\n%d\n", len_snprintf);
    printf("%s\n", test_snprintf);

    return OK;
}
