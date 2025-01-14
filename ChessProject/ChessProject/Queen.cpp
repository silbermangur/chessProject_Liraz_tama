#include "Queen.h"

Queen::Queen(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}

// Role: Moves the Queen to a specified location
// Input: Target column (col) and row (row)
// Output: Updates the Queen's position, or throws an exception if the move is illegal.
void Queen::move(int col, int row)
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

// Role: Checks if the Queen's path to a target position is blocked
// Input: Target column (col) and row (row)
// Output: Returns true if the path is blocked, false otherwise.
bool Queen::isBlocked(int col, int row) const
{
    if (getRow() == row || getCol() == col) // Straight path (rook-like)
    {
        Rook tempRook(getCol(), getRow(), B); // Use Rook logic
        return tempRook.isBlocked(col, row);
    }
    else // Diagonal path (bishop-like)
    {
        Bishop tempBishop(getCol(), getRow(), B); // Use Bishop logic
        return tempBishop.isBlocked(col, row);
    }
}

// Role: Checks if a move is legal for the Queen
// Input: Target column (col) and row (row)
// Output: Returns true if the move is legal, false otherwise, updating the board's error code if invalid.
bool Queen::isMoveLegal(int col, int row) const
{
    if ((getRow() == row || getCol() == col) || (abs(getRow() - row) == abs(getCol() - col))) // Check valid Queen move
    {
        if (!isBlocked(col, row)) // Ensure path is not blocked
        {
            return true;
        }
        B._code = 6; 
        return false;
    }
    B._code = 6; 
    return false;
}
