#include <stdio.h>

int gcd(int, int);

main()
{
    printf("%d\n%d\n", gcd(893729, 163), gcd(512, 320));
}

int gcd(int i, int j)
{
    if (i%j == 0) return j;
    else return gcd(j, i%j);
}
