#include <stdio.h>

int check (int vetor[], int inicio, int fim)
{
    if (inicio > fim) return -1;
    
    int meio = (fim + inicio) / 2;
    
    if (vetor[meio] == meio)
    {
        return meio;
    }
    else
    {
        if (vetor[meio] > meio)   return check (vetor, inicio, meio-1);
        else    return check (vetor, meio+1, fim);
    }
}

int main()
{
    int vetor[10] = {-3, -1, 0, 1, 2, 3, 4, 5, 7, 9};
    int a = check (vetor, 0, 9);
    
    if (a == -1)
    {
        printf ("Nao existe no vetor");
    }
    else
    {
        printf ("Existe na posicao %d", a);
    }
    return 0;
}
