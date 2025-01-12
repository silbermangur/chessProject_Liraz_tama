#include "Rook.h"

Rook::Rook(int col, int row, Board& board, char type) :
    Tool(col, row, board, type)
{
    B._board[row][col] = this;
}
Rook::Rook(int col, int row, Board& board) :
    Tool(col, row, board, NULL)
{}

void Rook::move(int col, int row)
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

bool Rook::checkChess() const
{
	return false;
}

bool Rook::isBlocked(int col, int row) const
{
    if (getRow() == row)
    {
        int minCol = std::min(getCol(), col);
        int maxCol = std::max(getCol(), col);
        for (col = minCol + 1; col < maxCol; col++)
        {
            if (B._board[getRow()][col] != nullptr)
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
            if (B._board[row][getCol()] != nullptr)
            {
                return true;
            }
        }
    }

    return false;
}

bool Rook::isMoveLegal(int col, int row) const
{
	if (!((col == getCol()) ^ (row == getRow())))
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
