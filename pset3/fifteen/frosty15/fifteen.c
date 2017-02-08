#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


struct Direction
{
	int row;
	int col;
};

const struct Direction s_north = {1, 0};
const struct Direction s_south = {-1, 0};
const struct Direction s_east = {0, 1};
const struct Direction s_west = {0, -1};

bool FindTileCoordinates(int& tileRow, int& tileCol)
{
	for (int row = 0; row < d; ++row)
	{
		for (int col = 0; col < d; ++col)
		{
			if (tile == board[row][col])
			{
				tileRow = row;
				tileCol = col;
				return true;
			}
		}
	}
	return false;
}

bool IsValidMove(int srcRow, int srcCol, int desRow, int desCol)
{
	return srcRow < d && srcRow >= 0 && desRow < d && desCol >= 0;
}

bool PerformMove(int srcRow, int srcCol, Direction direction, int tile)
{
	int desRow = srcRow + direction.row;
	int desCol = srcCol + direction.col;
	if (IsValidMove(srcRow, srcCol, desRow, desCol))
	{
		board[desRow][desCol] = tile;
		board[srcRow][srcCol] = 0;
		return true;
	}
	return false;
}

bool IsSpaceEmpty(int row, int col)
{
	return board[row][col] == 0;
}

bool move(int tile)
{
	int row = 0;
	int col = 0;
	if (!FindTileCoordinates(row, col))
	{
		// Noop, couldn't find piece.
		return false;
	}
	bool movedPiece = false;
	int tile = board[row][col];
	if (IsSpaceEmpty(row + 1, col))
	{
		movedPiece = PerformMove(row, col, s_north, tile);
	}
	else if (IsSpaceEmpty(row - 1, col))
	{
		movedPiece = PerformMove(row, col, s_south, tile);
	}
	else if (IsSpaceEmpty(row, col + 1))
	{
		movedPiece = PerformMove(row, col, s_east, tile);
	}
	else if (IsSpaceEmpty(row, col - 1))
	{
		movedPiece = PerformMove(row, col, s_west, tile);
	}

	return movedPiece;
}