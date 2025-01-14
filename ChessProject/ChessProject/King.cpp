#include "King.h"

// Constructor for King class
// Input: Column (col), Row (row), Board reference (board), type (char), player (int)
// Output: Initializes the King piece and places it on the board
King::King(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}

// Role: Moves the King to the specified position if the move is valid
// Input: Target column (col) and row (row)
// Output: Updates the board state or throws LocationException if the move is invalid
void King::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        int c = getCol();
        int r = getRow();
        Tool* dest = B._board[row][col];

        // Update board positions
        B._board[row][col] = this;
        B._board[getRow()][getCol()] = nullptr;
        setCol(col);
        setRow(row);

        // Check if the move results in a check
        if (B.checkChess())
        {
            // Undo move if King is in check
            B._board[r][c] = this;
            B._board[row][col] = dest;
            setCol(c);
            setRow(r);
            B._code = 4;
            throw LocationException();
        }
        else if (dest)
        {
            delete(dest); // Capture opponent piece if present
        }
        return;
    }
    throw LocationException(); // Throw exception for invalid move
}

// Role: Checks if the King’s path to the target position is blocked
// Input: Target column (col) and row (row)
// Output: Always returns false for the King (it only moves one square at a time)
bool King::isBlocked(int col, int row) const
{
    return false;
}

// Role: Validates if the King’s move is legal
// Input: Target column (col) and row (row)
// Output: Returns true if the move is legal, false otherwise
bool King::isMoveLegal(int col, int row) const
{
    if (abs(col - getCol()) > 1 || abs(row - getRow()) > 1)
    {
        B._code = 6; // Invalid move code
        return false;
    }
    if (isBlocked(col, row))
    {
        B._code = 6;
        return false;
    }
    return true;
}
