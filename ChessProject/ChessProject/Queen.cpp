#include "Queen.h"
Queen::Queen(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}

void Queen::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        int c = getCol();
        int r = getRow();
        Tool* dest = B._board[row][col];
        B._board[row][col] = this;
        B._board[getRow()][getCol()] = nullptr;
        setCol(col);
        setRow(row);
        if (B.checkChess())
        {
            B._board[r][c] = this;
            B._board[row][col] = dest;
            setCol(c);
            setRow(r);
            B._code = 4;
            throw LocationException();
        }
        else if (dest)
        {
            delete(dest);
        }
        return;
    }
    throw LocationException();
}


bool Queen::isBlocked(int col, int row) const
{
    if (getRow() == row || getCol() == col)
    {
        Rook tempRook(getCol(), getRow(), B);
        return tempRook.isBlocked(col, row);
    }
    else
    {
        Bishop tempBishop(getCol(), getRow(), B);
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
