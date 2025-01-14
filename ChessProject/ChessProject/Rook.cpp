#include "Rook.h"

Rook::Rook(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}
Rook::Rook(int col, int row, Board& board) :
    Tool(col, row, board, NULL, 0)
{}

// Role: Moves the Queen to a specified location
// Input: Target column (col) and row (row)
// Output: Updates the Rook's position, or throws an exception if the move is illegal.
void Rook::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        int c = getCol();
        int r = getRow();
        Tool* dest = B._board[row][col];// Save destination piece
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

// Role: Checks if the Rook's path to a target position is blocked
// Input: Target column (col) and row (row)
// Output: Returns true if the path is blocked, false otherwise.
bool Rook::isBlocked(int col, int row) const
{
    if (getRow() == row)
    {
        int minCol = std::min(getCol(), col);
        int maxCol = std::max(getCol(), col);
        for (col = minCol + 1; col < maxCol; col++)
        {
            if (B._board[getRow()][col] != nullptr)
            {
                return true;
            }
        }
    }
    if (getCol() == col)
    {
        int minRow = std::min(getRow(), row);
        int maxRow = std::max(getRow(), row);
        for (int row = minRow + 1; row < maxRow; row++) 
        {
            if (B._board[row][getCol()] != nullptr)
            {
                return true;
            }
        }
    }

    return false;
}
// Role: Checks if a move is legal for the Queen
// Input: Target column (col) and row (row)
// Output: Returns true if the move is legal, false otherwise
bool Rook::isMoveLegal(int col, int row) const
{
	if (!((col == getCol()) ^ (row == getRow())))
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
