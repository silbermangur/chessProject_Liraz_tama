#include "Bishop.h"
Bishop::Bishop(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}
Bishop::Bishop(int col, int row, Board& board) :
    Tool(col, row, board, NULL, 0)
{}

void Bishop::move(int col, int row)
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
        else if (dest != nullptr)
        {
            delete(B._board[row][col]);
        }
        return;
    }
    throw LocationException();
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
