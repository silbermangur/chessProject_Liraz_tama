#include "Rook.h"
Rook::Rook(int col, int row, Tool***& board, char type):
	Tool(col, row, board, type)
{}

void Rook::move(int col, int row)
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

bool Rook::checkChess() const
{
	return false;
}

bool Rook::isBlocked(int col, int row) const
{
    if (_board[row][col] != nullptr && std::islower(getType()) == std::islower(_board[row][col]->getType()))
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
        int minRow = std::min(getRow(), row);
        int maxRow = std::max(getRow(), row);
        for (int row = minRow + 1; row < maxRow; row++) 
        {
            if (_board[row][getCol()] != nullptr)
            {
                return true;
            }
        }
    }

    return false;
}

bool Rook::isMoveLegal(int col, int row) const
{
	if (col > 7 || col < 0 || row < 0 || row > 7 || !((col == getCol()) ^ (row == getRow())))
	{
		return false;
	}
	if (isBlocked(col, row))
	{
		return false;
	}
    
	return true;
}
