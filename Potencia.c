#include <stdio.h>
#include <math.h>

int Potencia (int a, float n)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        return pow (Potencia (a, floor (n/2)), 2) * pow(a, (ceil(n/2)) - (floor(n/2)));
    }
}

int main()
{
    int a;
    double n;
    scanf ("%d %lf", &a, &n);
    
    printf ("Resultado: %d", Potencia (a, n));

    return 0;
}
