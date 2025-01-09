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
    return !((abs(col - getCol()) == 1 && abs(row - getRow()) == 2) || (abs(col - getCol()) == 2 && abs(row - getRow()) == 1));
}

bool Knight::isMoveLegal(int col, int row) const
{
    if (isBlocked(col, row))
        return true;
    return false;
}