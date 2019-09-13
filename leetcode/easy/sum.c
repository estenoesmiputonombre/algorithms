#include<stdio.h>
#include<stdlib.h>

int* testArr(int from, int to, int seq)
{
	int swap;
	if(seq == 0)
	{
		return NULL;
	}
	else if(seq > 0 && from > to)
	{
		swap = from;
		from = to;
		to   swap;		
	}
	else if(seq < 0 && from < to)
	{
		swap = from;
		from = to;
		to   = swap;
	}	
	int* result = malloc(sizeof(int) * abs((int) (abs(to) - abs(from)) / seq));
	for(;from < to; from += seq)
	{
		*result = from;
		result++;
	}
	return result;
}

int isHere(int* arr, int* trgt)
{
    int len = sizeof(arr) / sizeof(*arr);
    for(int i = 0; i < len; i++)
    {
        if(*(arr+i) == *trgt)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* result = malloc(2 * sizeof(int));
    int* tmpArr = malloc(numsSize * sizeof(int));
    int tmp, tm;
    for(int i = 0; i < numsSize; i++)
    {
        tmp = target + (*(nums+i) > 0 ? *(nums+i) : *(nums+i)*-1);
	printf("%d\n", tmp);
        tm  = isHere(tmpArr, (nums+i));
        if(i >= 1 && tm != -1)
        {
            *result     = tm;
            *(result+1) = i;
	    printf("%d\n", *result);
	    printf("%d\n", *(result+1));
            return result;
        }
        *(tmpArr+i) = tmp;
    }
    return NULL;
}

int main(void)
{
	int len    = 5,
	    trgt   = -8,
	    s	   = 2;
	int* arr   = malloc(len * sizeof(int));
	int* rSize = &s;
	for(int i = 0; i < len; i++)
	{
		*(arr+i) = i * -1 - 1;
	}
	twoSum(arr, len, trgt, rSize);
	
	return 0;
}

