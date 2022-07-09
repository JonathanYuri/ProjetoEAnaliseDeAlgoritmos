#include <stdio.h>

int somas_dif_coluna(int q[][3], int coluna, int soma)
{
    if (q[0][coluna] == 0 || q[1][coluna] == 0 || q[2][coluna] == 0)
    {
        return 0;
    }
    else
    {
        if (q[0][coluna] + q[1][coluna] + q[2][coluna] == soma)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int somas_dif_linha(int q[][3], int linha, int soma)
{
    if (q[linha][0] == 0 || q[linha][1] == 0 || q[linha][2] == 0)
    {
        return 0;
    }
    else
    {
        if (q[linha][0] + q[linha][1] + q[linha][2] == soma)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int somas_dif_diag1(int q[][3], int soma)
{
    if (q[0][0] == 0 || q[1][1] == 0 || q[2][2] == 0)
    {
        return 0;
    }
    else
    {
        if (q[0][0] + q[1][1] + q[2][2] == soma)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int somas_dif_diag2(int q[][3], int soma)
{
    if (q[0][2] == 0 || q[1][1] == 0 || q[2][0] == 0)
    {
        return 0;
    }
    else
    {
        if (q[0][2] + q[1][1] + q[2][0] == soma)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int somas_dif(int q[][3], int pos)
{
    int soma = q[0][0] + q[0][1] + q[0][2];
    // 0 1 2    (0,0) (0,1) (0,2)
    // 3 4 5    (1,0) (1,1) (1,2)
    // 6 7 8    (2,0) (2,1) (2,2)
    
    int coluna = pos%3; // coluna -> pos % 3
    int linha = pos/3;
    if (somas_dif_coluna(q, coluna, soma) == 1) return 1;
    if (somas_dif_linha(q, linha, soma) == 1)   return 1;
    
    if (coluna == linha) // pertence a diag principal
    {
        if (somas_dif_diag1(q, soma) == 1)
        {
            return 1;
        }
    }
    if (coluna == 2-linha) // diag secundaria
    {
        if (somas_dif_diag2(q, soma) == 1)
        {
            return 1;
        }
    }
    
    return 0;
}

int Usado(int usados[], int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (usados[i] == 0)
        {
            return 0;
        }
        else if (usados[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

void QM(int q[][3], int k, int usados[])
{
    if (k == 9)
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
        return;
    }
    int l = 1;
    while (l <= 9)
    {
        q[k/3][k%3] = l;
        if (somas_dif(q, k) == 0) // se nao da ruim a soma
        {
            if (Usado(usados, l) == 0) // e se nao foi usado o numero ainda
            {
                /* ETAPAS
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        printf("%i ", q[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");*/
                
                usados[k] = l;
                QM(q, k+1, usados);
            }
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
