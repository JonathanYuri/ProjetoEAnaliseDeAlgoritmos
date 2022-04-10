#include <stdio.h>

// 3, 2, 1
// 1 printa 1 vez
// 2 printa 2 vezes, e outra
// 3 printa 3 vezes e 2 outras na volta + 1 outra na volta da volta
// 4 printa 4 vezes e 3 2 1

// 26

// 3 + 2 + 1 + 4 + 3 + 2 + 1 = 10 + 3 + 2 + 1 = 16

// 3 -> 6, 2 -> 3, 1 -> 1

// 4+(3), 3+(2), 2(+1+1), 1
// ^11      ^7      ^4 + 1  ==   18 + 5 = 23

// 1, 2+1+1, 3+2+1+1+2+1+1, <-(4) + 4
// 1 + 4 + 6 + 1 + 4 + (4)


void Asterisco(int n, int *ast)
{
    if (n > 0)
    {
        //printf("Entrou\n");
        Asterisco(n - 1, ast);
        //printf("Saiu\n");
        printf ("%i ", n);
        for (int i = 0; i < n; i++)
        {
            printf("++ ");
            *ast = *ast + 1;
        }
        printf("\n");
        //printf("\n%i", ast);
        //printf("Entrou 2\n");
        Asterisco(n - 1, ast);
        //printf("Saiu 2\n");
    }
    //printf("\n%i", *ast);
}

// 4 Asterisco(3), print(4), Asterisco(3) -- > print(4) + 2.(print(3) + 2.(print(2) + 2.print(1))) == resposta
// 3 Asterisco(2), print(3), Asterisco(2) -- > print(3) + 2.(print(2) + 2.print(1))
// 2 Asterisco(1), print(2), Asterisco(1) -- > print(2) + 2.print(1)
// 1 Asterisco(0), print(1), Asterisco(0) -- > print(1)

// print(4) + 2.(print(3) + 2.(print(2) + 2.print(1))) == resposta
// print(4) + 2.(print(3) + 2.(print(2) + print(2)))
// print(4) + 2.(print(3) + 2.(print(4)))
// print(4) + 2.(print(3) + print(8))
// print(4) + 2.(print(11))
// print(4) + print(22)
// print(26)

/*
n
n-1 prints n-2 prints
n-2 prints n-3 prints
n-3 prints n-4 prints
...

somatorio n-1 ate 1 + somatorio n-2 ate 2

*/

int main()
{
    int a = 0;
    int *p = &a;
    Asterisco(4, p);
    //printf("\n\n%i", a);

    return 0;
}
