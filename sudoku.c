#include <stdio.h>
#include <stdlib.h>

int linha_ok(int sudoku[][9], int linha, int elem)
{
    for (int j = 0; j < 9; j++)
    {
        if (sudoku[linha][j] == elem) return 0;
    }
    return 1;
}

int coluna_ok(int sudoku[][9], int coluna, int elem)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][coluna] == elem) return 0;
    }
    return 1;
}

int blocos_ok(int sudoku[][9], int linha, int coluna, int num)
{
    int x = linha - linha % 3;
    int y = coluna - coluna % 3;
   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[i + x][j + y] == num)    return 0;
        }
    }
    
    return 1;
}

void Sudoku(int sudoku[][9], int k)
{
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
        if ((linha_ok(sudoku, k / 9, l) == 1) && (coluna_ok(sudoku, k % 9, l) == 1) && (blocos_ok(sudoku, k/9, k%9, l) == 1))
        {
            sudoku[k/9][k%9] = l;
            Sudoku(sudoku, k+1);
            sudoku[k/9][k%9] = 0;
        }
        l++;
    }
}

int main()
{
    int sudoku[9][9];
    
    int k = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = 0;
        }
    }
    
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
    sudoku[6][5] = 6;
    
    Sudoku(sudoku, 0);

    return 0;
}
