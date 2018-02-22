#include "mineesweeper.h"

int main(int argc, char** argv) 
{
        srand(time(NULL));

	if(argc != 4)
	{
		printf("Correct usage: ./a.out <number of rows> <number of columns> <number of mines>\n");
		return -1;
	}

	Board* b = randomizeBoard(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

	while(b->s == PLAYING)
	{
		printBoard(b);
		printf("\nSelect a row: ");
		int r;
		scanf("%d", &r);
		while(r < 0 || r > b->numRows - 1)
		{
			printf("Invalid entry. Try again: ");
			scanf("%d", &r);
		}

		printf("Select a column: ");
		int c;
		scanf("%d", &c);
		while(c < 0 || c > b->numColumns - 1)
		{
			printf("Invalid entry. Try again: ");
			scanf("%d", &c);
		}
		if(b->squares[r][c].C == UNCOVERED)
		{
			printf("\nThat square is already uncovered!\n");
		}
		else
		{
			updateBoard(b, r, c);
		}
	}

	if(b->s == WON) printf("\nYou won! Congrats!\n");
	else printf("\nYou hit a mine! Oh no!\n");
	printUncoveredBoard(b);

	freeBoard(b);

	return 0;
}

void freeBoard(Board* board)
{
	int i;
	for(i = 0; i < board->numRows; i++)
	{
		free(board->squares[i]);
	}
	free(board->squares);
	free(board);
}

Board* randomizeBoard(int rows, int columns, int numMines)
{
    Square** squares = malloc(sizeof(Square*)*rows);
    int i, j;
    for(i = 0; i < rows; i++)
    {
        squares[i] = malloc(sizeof(Square)*columns);
    }
    
	int tmp = numMines;

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			squares[i][j].T = NOTAMINE;
			squares[i][j].C = COVERED;
			squares[i][j].surroundingMines = -2;
		}
	}

    while(numMines > 0)
    {
        i = rand() % rows;
        j = rand() % columns;
        while(squares[i][j].T == MINE)
        {
            i = rand() % rows;
            j = rand() % columns;
        }
        squares[i][j].T = MINE;
        numMines--;
    }
    
	Board* b = malloc(sizeof(Board));
	b->numRows = rows;
	b->numColumns = columns;
	b->numMines = tmp;
	b->numRemaining = rows*columns - tmp;
	b->s = PLAYING;
	b->squares = squares;

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			if(squares[i][j].T == NOTAMINE && squares[i][j].surroundingMines == -2)
			{
				countMines(b, i, j);
			}
		}
	}
    
	return b;
}

