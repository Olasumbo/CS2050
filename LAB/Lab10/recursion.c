 #include "mineesweeper.h"

void updateBoard(Board* board, int row, int column)
{
	if(row < 0 || row > board->numRows - 1) return;
	if(column < 0 || column > board->numColumns - 1) return;
	if(board->squares[row][column].C == UNCOVERED) return;

	if(board->squares[row][column].T == MINE)
	{
		board->s = LOST;
		return;
	}
	else
	{
		board->squares[row][column].C = UNCOVERED;
		board->numRemaining -= 1;
		if(board->squares[row][column].surroundingMines == 0)
		{
			
			updateBoard(board, row - 1, column);
			updateBoard(board, row - 1, column - 1);
			updateBoard(board, row - 1, column + 1);

			
			updateBoard(board, row + 1, column);
			updateBoard(board, row + 1, column - 1);
			updateBoard(board, row + 1, column + 1);

			updateBoard(board, row, column - 1);
			updateBoard(board, row, column + 1);
		}
	}

	if(board->numRemaining <= 0) board->s = WON;


}

int countMines(Board* board, int x, int y)
{
	
	if( x < 0 || x > board->numRows - 1) return 0;
	if( y < 0 || y > board->numColumns - 1) return 0;

	Square** squares = board->squares;

	if(squares[x][y].T == MINE) 
	{
		squares[x][y].surroundingMines = -1;
		return 1;
	}

	if(squares[x][y].surroundingMines != -2) return 0;
	 
	squares[x][y].surroundingMines = 0;
	 
	squares[x][y].surroundingMines = 
			countMines(board, x - 1, y) +
			countMines(board, x - 1, y - 1) +
			countMines(board, x - 1, y + 1) +
			countMines(board, x + 1, y) +
			countMines(board, x + 1, y - 1) +
			countMines(board, x + 1, y + 1) +
			countMines(board, x, y - 1) +
			countMines(board, x, y + 1);

	return 0;
}

