#include <stdio.h>
#include "NumClass.h"

int main(int argc, char *argv[])
{
    int start = 0, end = 0;
    printf("enter a number for the start of the range: ");
    scanf("%d", &start);
    printf("enter a number for the end of the range: ");
    scanf("%d", &end);

    printf("The Armstrong numbers are:");
    for (int i = start; i <= end; i++)
        if (isArmstrong(i))
            printf(" %d", i);
    printf("\n");
    printf("The Palindrome numbers are:");
    for (int i = start; i <= end; i++)
        if (isPalindrome(i))
            printf(" %d", i);
    printf("\n");
    printf("The Prime numbers are:");
    for (int i = start; i <= end; i++)
        if (isPrime(i))
            printf(" %d", i);
    printf("\n");
    printf("The Strong numbers are:");
    for (int i = start; i <= end; i++)
        if (isStrong(i))
            printf(" %d", i);
    printf("\n");
}
