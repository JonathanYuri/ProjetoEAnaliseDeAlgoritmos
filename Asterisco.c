#include <stdio.h>
#include <math.h>

double somatorio2 (int n, double i)
{
    for(int j = 0; j < n; j++)
    {
        i += pow(2, j) * (n-j);
    }
    
    return i;
}

double somatorio (int n, double i)
{
    for(int j = 1; j <= n; j++)
    {
        i += pow(2, (n-j)) * j;
    }
    
    return i;
}

void Asterisco(int n, int *ast)
{
    if (n > 0)
    {
        Asterisco(n - 1, ast);
        
        for (int i = 0; i < n; i++)
        {
            //printf("++ ");
            *ast = *ast + 1;
        }
        
        Asterisco(n - 1, ast);
    }
}

int main()
{
    int a = 0;
    int *p = &a;
    for (int n = 0; n < 10; n++)
    {
        Asterisco(n, p);
        double soma = somatorio (n, 0);
        double soma2 = somatorio2 (n, 0);
        printf ("iteracao %d: %d -- %.0lf || %.0lf\n", n, *p, soma, soma2);
        *p = 0;
    }

    return 0;
}
