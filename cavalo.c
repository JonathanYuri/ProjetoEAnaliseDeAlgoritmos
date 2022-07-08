#include <stdio.h>
#include <stdlib.h>

void ImprimirMatriz(int mat[][16])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            printf("%i ", mat[i][j]);
        }
        printf("\n");
    }
}

int Cavalo(int mat[][16], int k, int x, int y, int movx[], int movy[])
{
    if (k == (16*16)+1)
    {
        //exit(0);
        return 1;
    }
    
    int l = 0;
    while (l < 8)
    {
        int x1 = x + movx[l];
        int y1 = y + movy[l];
        
        if (x1 >= 0 && x1 <= 15 && y1 >= 0 && y1 <= 15 && mat[x1][y1] == -1)
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
    int mat[16][16];
    
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
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
