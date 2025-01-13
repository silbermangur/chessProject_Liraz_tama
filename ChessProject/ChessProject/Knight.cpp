#include "Knight.h"

Knight::Knight(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
	B._board[row][col] = this;
}

void Knight::move(int col, int row)
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

bool Knight::isBlocked(int col, int row) const
{
    return false;
}

bool Knight::isMoveLegal(int col, int row) const
{
    int rowDiff = abs(getRow() - row);
    int colDiff = abs(getCol() - col);

    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2))
    {
        return true;
    }

    B._code = 6;
    return false;
}