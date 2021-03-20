#include"my_strcspn.h"
#include<string.h>
#include<stdio.h>


int main()
{
    char str[MAX_LENGTH + 1] = "HelloWorld";
    char sym[TESTS][MAX_LENGTH + 1] = { "d", "e", "z", "l" };

    printf("String - HelloWorld \n\n");

    for (int i = 0; i < TESTS; i++)
    {
        printf("Stop symbole : %s \n\n", sym[i]);
        printf("Length (library function): %zu \n", strcspn(str, sym[i]));
        printf("Length (my function): %zu \n\n\n", my_strcspn(str, sym[i]));
    }

    return OK;
}