/*
*	Summary
*	- use bit-wise operator & | ^ << >> ~ 
*   - use operators to set n bits of (x) at the p position with values of n bits of (y) at most right.
*/

#include <stdio.h>

int setbits(int x, int p, int n, int y);

void main()
{
    int x = 0xF2;
    int p = 2;
    int n = 4;
    int y = 0x09;

    const int resultX = setbits(x, p, n, y);
    printf("input x is %d and result is %d\n", x, resultX);
}

int setbits(int x, int p, int n, int y)
{
    return ((y & ~(~0 << n)) << p) | (x & ~(~(~0 << n) << p));
} 


/*
    x: 1 1 1 1  0 0 1 0
    p: 3
    n: 4
    y: 0 0 0 0 (1 0 0 1)
    r: 1 1(1 0  0 1)1 0

    1th:
    0 0 0 0  0 0 0 0    0
    1 1 1 1  1 1 1 1    ~0
    1 1 1 1  0 0 0 0    ~0 << n
    0 0 0 0  1 1 1 1    ~(~0 << n)

    2nd:
    0 0 0 0  1 0 0 1    y
    0 0 0 0  1 1 1 1    [1th]
    0 0 0 0  1 0 0 1    Y & [1th]
    0 0 1 0  0 1 0 0    (Y & [1th]) << p

    3rd:
    0 0 0 0  0 0 0 0    0
    1 1 1 1  1 1 1 1    ~0
    1 1 1 1  0 0 0 0    ~0 << n
    0 0 0 0  1 1 1 1    ~(~0 << n)
    0 0 1 1  1 1 0 0    ~(~0 << n) << p
    1 1 0 0  0 0 1 1    ~(~(~0 << n) << p)

    3rd:
    1 1 1 1  0 0 1 0    x
    1 1 0 0  0 0 1 1    [3rd]
    1 1 0 0  0 0 1 0    x & [3rd]

    4th:
    1 1 0 0  0 0 1 0    [3rd]
    0 0 1 0  0 1 0 0    [2nd]
    1 1 1 0  0 1 1 0    [3rd] | [2nd]
*/