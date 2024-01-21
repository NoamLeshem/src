#include <stdio.h>
#include "NumClass.h"

int power(int x, int y)
{
    int res = 1;
    while (y)
    {
        res *= x;
        y--;
    }
    return res;
}

int isPalindrome(int x)
{
    int flag = 1;
    while (flag && x)
    {
        int len = snprintf(NULL, 0, "%i", x);
        int pow = power(10, len - 1);
        flag = x / pow == x % 10;
        x = (x % pow) / 10;
    }
    return flag;
}

int isArmstrong(int x)
{
    int temp = x;
    int sum = 0;
    int len = snprintf(NULL, 0, "%i", x);
    while(temp)
    {
        sum += power(temp % 10, len);
        temp /= 10;
    }
    return sum == temp;
}