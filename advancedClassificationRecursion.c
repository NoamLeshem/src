#include <stdio.h>
#include "NumClass.h"

int power(int x, int y)
{
    if (!y)
        return 1;
    return x * power(x, y - 1);
}

int isPalindrome(int x)
{
    if (x % 10 == x)
        return 1;
    int len = snprintf(NULL, 0, "%i", x);
    int pow = power(10, len - 1);
    return x / pow == x % 10 && isPalindrome((x % pow) / 10);
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