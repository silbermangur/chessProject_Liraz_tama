#include "Bishop.h"
Bishop::Bishop(int row, int col, Board& board, char type) :
    Tool(col, row, board, type)
{
    B._board[row][col] = this;
}

void Bishop::move(int col, int row)
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

bool Bishop::checkChess() const
{
    return false;
}

bool Bishop::isBlocked(int col, int row) const
{

    int i = 1;
    int  firstCol = getCol();
    int  lestCol = col;
    int minRow = std::min(getRow(), row);
    int maxRow = std::max(getRow(), row);
    if (maxRow == getRow())
    {
        firstCol = col;
        lestCol = getCol();
    }
    if (firstCol > lestCol)
    {
        i = -1;
    }
    for (int row = minRow + 1; row < maxRow; row++)
    {
        firstCol += i;
        if (B._board[row][firstCol] != nullptr)
        {
            return true;
        }
    }

    return false;
}

bool Bishop::isMoveLegal(int col, int row) const
{
    if (abs(col - getCol()) != abs(row - getRow()))
    {
        B._code = 6;
        return false;
    }
    if (isBlocked(col, row))
    {
        B._code = 6;
        return false;
    }

    return true;
}
