#include "Knight.h"

Knight::Knight(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
	B._board[row][col] = this;
}

/*
Role: Moves the Knight to a specified location
Input: Target column (col) and row (row)
Output: Updates the Knight's position, or throws an exception if the move is illegal.
*/
void Knight::move(int col, int row)
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

bool Knight::isBlocked(int col, int row) const
{
    return false;
}

/*
 Role: Checks if a move is legal for the Knight
 Input: Target column (col) and row (row)
 Output: Returns true if the move is legal, false otherwise, updating the board's error code if invalid.
*/
bool Knight::isMoveLegal(int col, int row) const
{
    int rowDiff = abs(getRow() - row); // The distance from the current row to the target row
    int colDiff = abs(getCol() - col); // The distance from the current column to the target column

    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) // check if the move is legal
    {
        return true;
    }

    B._code = 6;
    return false;
}