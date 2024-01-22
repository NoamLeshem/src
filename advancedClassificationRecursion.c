#include <stdio.h>
#include "NumClass.h"

int power(int x, int y)
{
    if (!y)
        return 1;
    return x * power(x, y - 1);
}

int reverse(int num)
{
    if(!num)
        return 0;
    int len = snprintf(NULL, 0, "%i", num);
    return num % 10 * power(10, len-1) + reverse(num / 10);
}

int isPalindrome(int x)
{
    return x == reverse(x);
}

int armstrongHelper(int x, int len)
{
    if (x % 10 == x)
        return power(x, len);
    return power(x % 10, len) + armstrongHelper(x / 10, len);
}

int isArmstrong(int x)
{
    int len = snprintf(NULL, 0, "%i", x);
    return armstrongHelper(x, len) == x;
}