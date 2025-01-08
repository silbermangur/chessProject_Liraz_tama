#include "King.h"
King::King(int col, int row, Board& board, char type) :
    Tool(col, row, board, type)
{
    B._board[row][col] = this;
}

void King::move(int col, int row)
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

bool King::checkChess() const
{
    return false;
}

bool King::isBlocked(int col, int row) const
{
    if (B._board[getRow()][col] != nullptr && std::islower(getType()) == std::islower(B._board[row][col]->getType()))
    {
        return true;
    }

    return false;
}

bool King::isMoveLegal(int col, int row) const
{
    if (col > 7 || col < 0 || row < 0 || row > 7 || abs(col - getCol()) > 1 || abs(row - getRow()) > 1)
    {
        return false;
    }
    if (isBlocked(col, row))
    {
        return false;
    }

    return true;
}
