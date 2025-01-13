#include "King.h"
King::King(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}

void King::move(int col, int row)
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

bool King::isBlocked(int col, int row) const
{
    return false;
}

bool King::isMoveLegal(int col, int row) const
{
    if (abs(col - getCol()) > 1 || abs(row - getRow()) > 1)
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
