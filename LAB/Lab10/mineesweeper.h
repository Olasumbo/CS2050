#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum status
{
	PLAYING,
	WON,
	LOST
} Status;

typedef enum type
{
	MINE, 
	NOTAMINE 
} Type;

typedef enum cover
{
	COVERED, 
	UNCOVERED 
} Cover;
 
typedef struct square
{
    int surroundingMines; 
    Cover C; 
	Type T; 
} Square;

typedef struct board
{
	int numRows; 
	int numColumns;
	int numMines; 
	int numRemaining; 
	Status s; 
	Square** squares; 
} Board;

Board* randomizeBoard(int rows, int columns, int numMines);
void printBoard(Board* board);
void printUncoveredBoard(Board* board);
void updateBoard(Board* board, int x, int y);
void updateBoard2(Board* board, int x, int y);
int countMines(Board* board, int x, int y);
int countMines2(Board* board, int x, int y);
void freeBoard(Board* board);
