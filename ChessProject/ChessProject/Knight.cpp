#include "Knight.h"

Knight::Knight(int col, int row, Board& board, char type) :
    Tool(col, row, board, type)
{
	B._board[row][col] = this;
}

void Knight::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        if (B._board[row][col] != nullptr)
        {
            delete(B._board[row][col]);
        }
        B._board[row][col] = B._board[getRow()][getCol()];
        B._board[getRow()][getCol()] = nullptr;
        setCol(col);
        setRow(row);
        return;
    }
    throw LocationException();
}

bool Knight::isBlocked(int col, int row) const
{
    return false;
}

bool Knight::isMoveLegal(int col, int row) const
{
    int rowDiff = abs(getRow() - row);
    int colDiff = abs(getCol() - col);

    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2))
    {
        return true;
    }

    B._code = 6;
    return false;
}