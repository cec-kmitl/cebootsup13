#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int clues[16];
int board[SIZE][SIZE];

int is_valid(int row, int col, int num);
int check_visibility();
int solve(int row, int col);

int main()
{
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &clues[i]);
    }
    if (
        solve(0, 0))
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                printf("%d", board[i][j]);
                if (j < SIZE - 1)
                {
                    printf(" ");
                }
            }
            if (i == SIZE - 1)
            {
                printf("\n");
            }
            printf("\n");
        }
    }
    else
    {
        printf("Error");
    }

    return 0;
}

int is_valid(int row, int col, int num)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num || board[i][col] == num)
            return 0;
    }
    return 1;
}

int visible_from_line(int *line, int clue_left, int clue_right)
{
    int max = 0, visible = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (line[i] > max)
        {
            max = line[i];
            visible++;
        }
    }
    if (clue_left != 0 && visible != clue_left)
        return 0;

    max = 0, visible = 0;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (line[i] > max)
        {
            max = line[i];
            visible++;
        }
    }
    if (clue_right != 0 && visible != clue_right)
        return 0;

    return 1;
}

int check_visibility()
{
    int line[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            line[j] = board[i][j];
        if (!visible_from_line(line, clues[8 + i], clues[12 + i]))
            return 0;
    }

    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
            line[i] = board[i][j];
        if (!visible_from_line(line, clues[j], clues[4 + j]))
            return 0;
    }

    return 1;
}

int solve(int row, int col)
{
    if (row == SIZE)
    {
        return check_visibility();
    }

    int next_row = (col == SIZE - 1) ? row + 1 : row;
    int next_col = (col + 1) % SIZE;

    for (int num = 1; num <= SIZE; num++)
    {
        if (is_valid(row, col, num))
        {
            board[row][col] = num;
            if (solve(next_row, next_col))
                return 1;
            board[row][col] = 0;
        }
    }

    return 0;
}
