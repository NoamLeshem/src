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

int reverse(int num)
{
    int reversed = 0;
    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int isPalindrome(int x)
{
    return x == reverse(x);
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