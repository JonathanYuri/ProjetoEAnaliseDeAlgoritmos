#include <stdio.h>
#include <stdlib.h>

void ImprimirMatriz(int mat[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (mat[i][j] / 10 < 1)
            {
                printf("0");
            }
            printf("%i  ", mat[i][j]);
        }
        printf("\n\n");
    }
}

int Cavalo(int mat[][8], int k, int x, int y, int movx[], int movy[])
{
    if (k == 65)
    {
        //exit(0);
        return 1;
    }
    
    int l = 0;
    while (l < 8)
    {
        int x1 = x + movx[l];
        int y1 = y + movy[l];
        
        if (x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7 && mat[x1][y1] == -1)
        {
            mat[x1][y1] = k;
            int a = Cavalo(mat, k+1, x1, y1, movx, movy);
            if (a == 1)
            {
                return 1;
            }
            mat[x1][y1] = -1;
        }
        
        l++;
    }
    
    return 0;
}

int main()
{
    int mat[8][8];
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            mat[i][j] = -1;
        }
    }
    
    mat[0][0] = 1;
    
    int movx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int movy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    
    Cavalo(mat, 2, 0, 0, movx, movy);
    ImprimirMatriz(mat);
    
    return 0;
}
