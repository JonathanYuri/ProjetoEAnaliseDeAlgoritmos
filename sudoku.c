#include <stdio.h>
#include <stdlib.h>

int linha_ok(int sudoku[][9], int linha, int elem)
{
    int q = 0;
    for (int j = 0; j < 9; j++)
    {
        if (sudoku[linha][j] == elem) q++;
        if (sudoku[linha][j] == 0)  return 1;
        if (q == 2) return 0;
    }
    return 1;
}

int coluna_ok(int sudoku[][9], int coluna, int elem)
{
    int q = 0;
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][coluna] == elem) q++;
        if (sudoku[i][coluna] == 0)  return 1;
        if (q == 2) return 0;
    }
    return 1;
}

int adicionar(int usados[], int elem)
{
    for (int i = 0; i < 9; i++)
    {
        if (usados[i] == 0)
        {
            usados[i] = elem;
            return 1;
        }
        if (usados[i] == elem) return 0;
    }
    return 1;
}

int blocos_ok(int sudoku[][9], int linha, int coluna)
{
    int blocoX = -1;
    int blocoY = -1;
    
    if (coluna >= 0 && coluna <= 2)
    {
        blocoY = 0;
    }
    else if (coluna >= 3 && coluna <= 5)
    {
        blocoY = 1;
    }
    else if (coluna >= 6 && coluna <= 8)
    {
        blocoY = 2;
    }
    
    if (linha >= 0 && linha <= 2) // primeiros 3 blocos
    {
        blocoX = 0;
    }
    else if (linha >= 3 && linha <= 5) // 3 blocos depois
    {
        blocoX = 1;
    }
    else if (linha >= 6 && linha <= 8) // 3 ultimos blocos
    {
        blocoY = 2;
    }
    
    int usados[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int x = blocoX * 3; x < (blocoX * 3) + 3; x++)
    {
        for (int y = blocoY * 3; y < (blocoY * 3) + 3; y++)
        {
            if (sudoku[x][y] == 0) return 1;
            //if (sudoku[x][y] == 0)  continue;
            if (adicionar(usados, sudoku[x][y]) == 0)   return 0;
        }
    }
    
    return 1;
}

void Sudoku(int sudoku[][9], int k)
{
    //printf("%i\n", k);
    if (k == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%i  ", sudoku[i][j]);
                if (sudoku[i][j] < 10) printf(" ");
            }
            printf("\n");
        }
        exit(0);
    }
    
    if (sudoku[k/9][k%9] != 0)
    {
        Sudoku(sudoku, k+1);
        return;
    }
    
    int l = 1;
    while (l < 10)
    {
        sudoku[k/9][k%9] = l;
        if (linha_ok(sudoku, k / 9, sudoku[k/9][k%9]) == 1 && coluna_ok(sudoku, k % 9, sudoku[k/9][k%9]) == 1 && blocos_ok(sudoku, k/9, k%9))
        {
            Sudoku(sudoku, k+1);
        }
        sudoku[k/9][k%9] = 0;
        l++;
    }
}

int main()
{
    int sudoku[9][9];
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = 0;
        }
    }
    
    /*
    sudoku[2][0] = 2;
    sudoku[0][2] = 6;
    sudoku[2][4] = 6;
    sudoku[2][3] = 9;
    sudoku[0][5] = 8;
    sudoku[1][5] = 1;
    sudoku[1][7] = 9;
    sudoku[2][6] = 7;
    
    sudoku[3][3] = 1;
    sudoku[4][2] = 4;
    sudoku[5][1] = 5;
    sudoku[4][3] = 2;
    sudoku[4][4] = 9;
    sudoku[4][7] = 5;
    sudoku[5][6] = 8;
    
    sudoku[7][0] = 7;
    sudoku[8][2] = 2;
    sudoku[8][3] = 5;
    sudoku[8][4] = 4;
    sudoku[8][7] = 8;
    sudoku[7][8] = 3;
    sudoku[6][5] = 6;*/
    
    Sudoku(sudoku, 0);

    return 0;
}
