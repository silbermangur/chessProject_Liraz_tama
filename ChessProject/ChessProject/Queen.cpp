#include "Queen.h"
Queen::Queen(int col, int row, Board& board, char type) :
    Tool(col, row, board, type)
{
    B._board[row][col] = this;
}

void Queen::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        if (B._board[row][col] != nullptr)
        {
            delete B._board[row][col];
        }
        B._board[row][col] = B._board[getRow()][getCol()];
        B._board[getRow()][getCol()] = nullptr;
        setCol(col);
        setRow(row);
        return;
    }
    throw LocationException();
}


bool Queen::isBlocked(int col, int row) const
{
    if (getRow() == row || getCol() == col)
    {
        Rook tempRook(getRow(), getCol(), B);
        return tempRook.isBlocked(col, row);
    }
    else
    {
        Bishop tempBishop(getRow(), getCol(), B);
        return tempBishop.isBlocked(col, row);
    }
}

bool Queen::isMoveLegal(int col, int row) const
{
    if ((getRow() == row || getCol() == col) || (abs(getRow() - row) == abs(getCol() - col)))
    {
        if (!isBlocked(col, row))
        {
            return true;
        }
        B._code = 6; 
        return false;
    }
    B._code = 6; 
    return false;
}
