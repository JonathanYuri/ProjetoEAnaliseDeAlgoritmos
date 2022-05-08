#include <stdio.h>

void Ponto_Max (int vetor[], int inicio, int fim)
{
    int p = (fim + inicio) / 2;
    
    if (vetor[p] > vetor[p+1])
    {
        if (vetor[p] > vetor[p-1])
        {
            printf ("Indice %d\nValor %d", p, vetor[p]);
        }
        else
        {
            return Ponto_Max(vetor, inicio, p-1);
        }
    }
    else
    {
        return Ponto_Max(vetor, p+1, fim);
    }
}

int main()
{
    int vetor[10] = {1, 4, 6, 7, 15, 18, 20, 21, 22, 23};
    
    Ponto_Max (vetor, 0, 9);

    return 0;
}
