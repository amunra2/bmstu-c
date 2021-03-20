#include<stdio.h>

#define INPUT_ERROR 1
#define OK 0
#define UNRIGHT_INPUT 2
#define ITS_OK 1
#define MISTAKE 1

int search(int n)
{
    int i = 2;
    while (1)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            break;
        }
        i++;
    }
    return i;
}

void result(int n)
{
    while (n != 1)
    {
        n /= search(n);
    }
}

int check_input(int n)
{
    if (n <= 0)
    {
        return MISTAKE;
    }
    else
    {
        return OK;
    }
}

int main()
{
    int n, count;

    printf("Enter an integer: ");
    count = scanf("%d", &n);
    if (count == ITS_OK)
    {   
        printf("Result : ");
        
        if (check_input(n) == MISTAKE)
        {
            printf("Unright Input");
            return UNRIGHT_INPUT;
        }
        else
        {
            result(n);
        }
    }
    else
    {
        printf("Error : it isn't an integer\n");
        return INPUT_ERROR;
    }
    return OK;
}