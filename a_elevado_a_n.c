#include <stdio.h>
#include <math.h>

int DC(int a, float n)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        return DC(a, ceil(n/2)) * DC(a, floor(n/2));
    }
}

int main()
{
    int a;
    int n;
    
    scanf("%i %i", &a, &n);
    
    int c = DC(a, n);
    printf("%i", c);

    return 0;
}
