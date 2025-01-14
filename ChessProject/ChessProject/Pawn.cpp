#include "Pawn.h"

Pawn::Pawn(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}

/*
Role: Moves the Pawn to a specified location
Input: Target column (col) and row (row)
Output: Updates the Pawn's position, or throws an exception if the move is illegal.
*/
void Pawn::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        int c = getCol();
        int r = getRow();
        Tool* dest = B._board[row][col]; // Save destination piece
        B._board[row][col] = this;
        B._board[getRow()][getCol()] = nullptr; // Clear previous position
        setCol(col);
        setRow(row);
        if (B.checkChess()) // Check if move puts King in check
        {
            B._board[r][c] = this; // Revert position
            B._board[row][col] = dest; // Restore destination piece
            setCol(c);
            setRow(r);
            B._code = 4;
            throw LocationException();
        }
        else if (dest)
        {
            delete(dest); // Delete the captured piece
        }
        return;
    }
    throw LocationException(); // Throw exception if move is illegal
}

/*
 Role: Checks if a move is legal for the Pawn
 Input: Target column (col) and row (row)
 Output: Returns true if the move is legal, false otherwise, updating the board's error code if invalid.
*/
bool Pawn::isMoveLegal(int col, int row) const
{
    int different = 1; // the move - up -1 down 1
    int start = 1; // start row
    if (std::islower(getType())) // set the different and start according to the pawn color
    {
        different = -1;
        start = 6;
    }
    // check if the pown try to move to 1 step in the same column - return true
    if (row == getRow() + different && col == getCol() && !isBlocked(col, row))
    {
        return true;
    }
    // check if the pawn in it's start position then it can move 2 steps
    if (getRow() == start && row == getRow() + 2 * different && col == getCol() && B._board[getRow() + different][col] == nullptr && !isBlocked(col, row))
    {
        return true;
    }
    // check if the pawn try to eat and can do it 
    if (row == getRow() + different && abs(col - getCol()) == 1 && isBlocked(col, row))
    {
        return true;
    }
    B._code = 6;
    return false;

}

/*
 Role: Checks if the Pawn's path to a target position is blocked
 Input: Target column (col) and row (row)
 Output: Returns true if the path is blocked, false otherwise.
*/
bool Pawn::isBlocked(int col, int row) const
{
    return B._board[row][col] != nullptr;
}