#include <stdio.h>

int somas_dif_coluna(int q[][3], int coluna, int soma)
{
    int soma_coluna = 0;
    for (int i = 0; i < 3; i++)
    {
        if (q[i][coluna] == 0)  return 0;
        soma_coluna += q[i][coluna];
    }
    if (soma_coluna == soma)    return 0;
    else    return 1;
}

int somas_dif_linha(int q[][3], int linha, int soma)
{
    int soma_linha = 0;
    for (int j = 0; j < 3; j++)
    {
        if (q[linha][j] == 0)   return 0;
        soma_linha += q[linha][j];
    }
    if (soma_linha == soma) return 0;
    else    return 1;
}

int somas_dif_diag1(int q[][3], int soma)
{
    int soma_diag = 0;
    for (int i = 0; i < 3; i++)
    {
        if (q[i][i] == 0)   return 0;
        soma_diag += q[i][i];
    }
    if (soma_diag == soma)  return 0;
    else    return 1;
}

int somas_dif_diag2(int q[][3], int soma)
{
    int soma_diag = 0, j = 2;
    for (int i = 0; i < 3; i++)
    {
        if (q[i][j] == 0)   return 0;
        soma_diag += q[i][j];
        j--;
    }
    if (soma_diag == soma)    return 0;
    else    return 1;
}

int somas_dif(int q[][3], int k)
{
    int soma = q[0][0] + q[0][1] + q[0][2];
    int coluna = k%3;
    int linha = k/3;
    
    if (somas_dif_coluna(q, coluna, soma) == 1) return 1;
    if (somas_dif_linha(q, linha, soma) == 1)   return 1;
    
    if (coluna == linha) // pertence a diag principal
    {
        if (somas_dif_diag1(q, soma) == 1)  return 1;
    }
    if (coluna == 2-linha) // diag secundaria
    {
        if (somas_dif_diag2(q, soma) == 1)  return 1;
    }
    
    return 0;
}

int Usado(int usados[], int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (usados[i] == 0) return 0;
        else if (usados[i] == x)    return 1;
    }
    return 0;
}

void ImprimirMatriz(int q[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void QM(int q[][3], int k, int usados[])
{
    if (k == 9)
    {
        ImprimirMatriz(q);
        return;
    }
    int l = 1;
    while (l <= 9)
    {
        q[k/3][k%3] = l;
        // se nao da ruim a soma e se o numero nao foi usado ainda
        if (somas_dif(q, k) == 0 && Usado(usados, l) == 0)
        {
            usados[k] = l;
            QM(q, k+1, usados);
        }
        
        // lixo
        q[k/3][k%3] = 0;
        usados[k] = 0;
        
        l++;
    }
}

int main()
{
    int q[3][3];
    int usados[9];
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            q[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 9; i++)
    {
        usados[i] = 0;
    }
    
    QM(q, 0, usados);

    return 0;
}
