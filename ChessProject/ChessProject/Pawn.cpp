#include "Pawn.h"

Pawn::Pawn(int col, int row, Board& board, char type) :
    Tool(col, row, board, type)
{
    B._board[row][col] = this;
}

void Pawn::move(int col, int row) 
{

}

bool Pawn::isMoveLegal(int col, int row) const
{
    int different = -1;
    int start = 6;
    if (std::islower(getType()))
    {
        different = 1;
        start = 1;
    }
    if (getRow() != start && (row - getRow() != different || B._board[row][col] != nullptr))
        return false;
    else if (getRow() == start && (row - getRow() > different || B._board[row][col] != nullptr))
        return false;

}

bool Pawn::isBlocked(int col, int row) const
{

}