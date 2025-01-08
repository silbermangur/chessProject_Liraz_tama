#include "Bishop.h"
Bishop::Bishop(int col, int row, Board& board, char type) :
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
    if (B._board[getRow()][col] != nullptr && std::islower(getType()) == std::islower(B._board[row][col]->getType()))
    {
        return true;
    }
 
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
    if (col > 7 || col < 0 || row < 0 || row > 7 || abs(col - getCol()) != abs(row - getRow()) || row == getRow())
    {
        return false;
    }
    if (isBlocked(col, row))
    {
        return false;
    }

    return true;
}
