#include "mineesweeper.h"

void printBoard(Board* board)
{
	Square** squares = board->squares;

    int i, j;
    printf("\x1B[0m\n\n");
    printf("\x1B[0m\t   Columms:\n");

	printf("         ");
	for(i = 0; i < board->numColumns; i++)
	{
		printf("%d ", i);
	}
    printf("\n");
    for(i = 0; i < board->numRows; i++)
    {
        printf("\x1B[0m\nRow %d -> ", i);
        for(j = 0; j < board->numColumns; j++)
        {
            if(squares[i][j].C == COVERED)
            {
                printf("\x1B[0mx ");
            }
            else if (squares[i][j].surroundingMines == 0) 
            {
                printf("\x1B[32m%d ", squares[i][j].surroundingMines);
            } else {
                printf("\x1B[33m%d ", squares[i][j].surroundingMines);
            }
        }
    }
	printf("\n\n");
}

void printUncoveredBoard(Board* board)
{
	Square** squares = board->squares;

    int i, j;
    printf("\x1B[0m\n\n");
    printf("\x1B[0m\t   Columms:\n");
    printf("         ");
	for(i = 0; i < board->numColumns; i++)
	{
		printf("%d ", i);
	}
    printf("\n");
    for(i = 0; i < board->numRows; i++)
    {
        printf("\x1B[0m\nRow %d -> ", i);
        for(j = 0; j < board->numColumns; j++)
        {
            if(squares[i][j].T == MINE)
            {
                printf("\x1B[31mM ");
            }
            else if (squares[i][j].surroundingMines == 0) 
            {
                printf("\x1B[32m%d ", squares[i][j].surroundingMines);
            } else {
                printf("\x1B[33m%d ", squares[i][j].surroundingMines);
            }
        }
    }
	printf("\n\n");
}
