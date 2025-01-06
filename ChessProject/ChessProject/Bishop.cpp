#include "Bishop.h"
Bishop::Bishop(int col, int row, Tool***& board, char type) :
    Tool(col, row, board, type)
{}

void Bishop::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        _board[row][col] = _board[getRow()][getCol()];
        _board[getRow()][getCol()] = nullptr;
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
    if (_board[getRow()][col] != nullptr && std::islower(getType()) == std::islower(_board[row][col]->getType()))
    {
        return true;
    }
    if (getRow() == row)
    {
        int minCol = std::min(getCol(), col);
        int maxCol = std::max(getCol(), col);
        for (col = minCol + 1; col < maxCol; col++)
        {
            if (_board[getRow()][col] != nullptr)
            {
                return true;
            }
        }
    }
    if (getCol() == col)
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
            if (_board[row][firstCol] != nullptr)
            {
                return true;
            }
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
