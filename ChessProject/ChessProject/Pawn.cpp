#include "Pawn.h"

Pawn::Pawn(int col, int row, Board& board, char type) :
    Tool(col, row, board, type)
{
    B._board[row][col] = this;
}

void Pawn::move(int col, int row) 
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

bool Pawn::isMoveLegal(int col, int row) const
{
    int different = 1;
    int start = 1;
    if (std::islower(getType()))
    {
        different = -1;
        start = 6;
    }
    if (row == getRow() + different && col == getCol() && B._board[row][col] == nullptr)
    {
        return true;
    }
    if (getRow() == different && row == getRow() + 2 * different && col == getCol() &&
        B._board[getRow() + different][col] == nullptr && B._board[row][col] == nullptr)
    {
        return true;
    }
    if (row == getRow() + different && abs(col - getCol()) == 1 && !isBlocked(col, row))
    {
        return true;
    }
    B._code = 6;
    return false;

}

bool Pawn::isBlocked(int col, int row) const
{
    return B._board[row][col] == nullptr;
}