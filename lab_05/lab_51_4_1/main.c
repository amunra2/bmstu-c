#include<stdio.h>
#include"func.h"


int main()
{
	int count;
	int check = process(stdin, &count);

	if (check == 1)
	{
		return INPUT_IS_CLEAR;
	}
	else if (check == 2)
	{
		return NOT_ENOUGH_NUMS;
	}
	printf("%d", count);
	return OK;
}
