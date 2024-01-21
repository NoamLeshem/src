#include <stdio.h>
#include "NumClass.h"

int fucktorial(int x)
{
    if (!x)
        return 1;
    return x * fucktorial(x - 1);
}

int isStrong(int x)
{
    int temp = x;
    int sum = 0;
    while (x)
    {
        sum += fucktorial(x % 10);
        x /= 10;
    }
    return sum == temp;
}

int isPrime(int x)
{
    int flag = 1;
    for (int i = 2; i * i <= x && flag; i++)
        if (x % i == 0)
            flag = 0;
    return flag;
}