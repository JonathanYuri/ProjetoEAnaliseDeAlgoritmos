#include <stdio.h>

void Inverter (int n, int pilha[])
{
    int inicio = 0, fim = n-1, aux;
    
    for (int i = 0; i < n/2; i++)
    {
        aux = pilha[inicio];
        pilha[inicio] = pilha[fim];
        pilha[fim] = aux;
        inicio += 1;
        fim -= 1;
    }
}

int Check (int n, int pilha[], int i)
{
    while (i != n)
    {
        if (pilha[i] > pilha[i+1])
        {
            return -1;
        }
        i += 1;
    }
    return 0;
}

void Ordenar (int n, int pilha[], int i)
{
    
    if (i < n)
    {
        if (Check(n, pilha, 0) == 0)   return;
        
        int maior = -1;
        int indice = 0;
        
        for (int j = 0; j < n; j++)
        {
            if (maior < pilha[j])
            {
                maior = pilha[j];
                indice = j;
            }
        }
        
        if (indice == n-1)
        {
            Ordenar (n-1, pilha, 0); 
        }
        
        Inverter (indice+1, pilha);
        Inverter (n, pilha);
        
        Ordenar (n-1, pilha, 0);
    }
}

int main()
{
    int n;
    scanf ("%d", &n);
    
    int pilha[n];
    
    for (int i = 0; i < n; i++) scanf ("%d", &pilha[i]);
    
    Ordenar (n, pilha, 0);
    
    for (int i = 0; i < n; i++) printf ("%d ", pilha[i]);
    return 0;
}
