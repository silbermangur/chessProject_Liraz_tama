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
    if (getRow() + different == row && abs(col - getCol()) == 1 && isBlocked(col, row))
        return true;
    if (getRow() != start && ((row - getRow() != different || B._board[row][col] != nullptr) || col - getCol() != 0))
        return false;
    else if (getRow() == start && (((row - getRow() != different || row - getRow() != 2*different) || B._board[row][col] != nullptr) || col - getCol() != 0))
        return false;
    return true;
}

bool Pawn::isBlocked(int col, int row) const
{
    return B._board[row][col] != nullptr && std::islower(B._board[row][col]->getType()) != std::islower(getType());
}