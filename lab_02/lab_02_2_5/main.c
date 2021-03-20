#include<stdio.h>
#include<math.h>

#define INPUT_ERROR_ARRAY 2
#define INPUT_ERROR_AMMOUNT 1

#define OK 0
#define N 10
#define INPUT_AMMOUNT 1
#define NEGATIVE 1
#define POZITIVE 0

int read_array(long *p_begin, const long *const p_end)
{
    int k = 0;
    printf("Input array :\n");

    while (p_begin < p_end)
    {
        k += scanf("%ld", p_begin++);
    }
    return k;
}


long summary(long *p_begin, const long *const p_end)
{
    long rem = *p_begin, sum = rem;
    int flag = POZITIVE;

    if (*p_begin < 0)
    {
        return *p_begin;
    }
    p_begin++;

    while (p_begin < p_end)
    {
        if (*p_begin < 0)
        {
            flag = NEGATIVE;
        }
        rem *= *p_begin;
        sum += rem;
        p_begin++;
        if (flag == NEGATIVE)
        {
            break;
        }
    }
    return sum;
}


int main()
{
    long a[N];
    int n, k, l;


    setbuf(stdout, NULL);
    printf("Input ammount of elements :\n");
    l = scanf("%d", &n);
    if ((l != INPUT_AMMOUNT) || (n == 0))
    {
        printf("INPUT ERROR AMMOUNT");
        return INPUT_ERROR_AMMOUNT;
    }

    k = read_array(a, a + n);

    if (k != n)
    {
        printf("INPUT ERROR ARRAY");
        return INPUT_ERROR_ARRAY;
    }

    printf("Summary is %ld\n", summary(a, a + n));

    return OK;
}