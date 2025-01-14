#include "Bishop.h"

Bishop::Bishop(int col, int row, Board& board, char type, int player) :
    Tool(col, row, board, type, player)
{
    B._board[row][col] = this;
}
Bishop::Bishop(int col, int row, Board& board) :
    Tool(col, row, board, NULL, 0)
{}

/*
Role: Moves the Bishop to a specified location
Input: Target column (col) and row (row)
Output: Updates the Bishop's position, or throws an exception if the move is illegal.
*/
void Bishop::move(int col, int row)
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
 Role: Checks if the Bishop's path to a target position is blocked
 Input: Target column (col) and row (row)
 Output: Returns true if the path is blocked, false otherwise.
*/
bool Bishop::isBlocked(int col, int row) const
{
    int i = 1; // Direction of horizontal movement: 1 for right, -1 for left
    int firstCol = getCol(); // Column of the current position of the bishop
    int lastCol = col; // Target column
    int minRow = std::min(getRow(), row); // The lower of the two rows
    int maxRow = std::max(getRow(), row); // The higher of the two rows

    // Determine which column starts first based on the row direction
    if (maxRow == getRow())
    {
        firstCol = col;
        lastCol = getCol();
    }

    // Determine the horizontal movement direction
    if (firstCol > lastCol)
    {
        i = -1; // Move left if the starting column is greater than the ending column
    }

    // Check for any blocking pieces in the path
    for (int currentRow = minRow + 1; currentRow < maxRow; currentRow++)
    {
        firstCol += i; // Move horizontally in the specified direction
        if (B._board[currentRow][firstCol] != nullptr) // If there's a piece on the path
        {
            return true; // Path is blocked
        }
    }

    return false; // Path is clear
}


/*
 Role: Checks if a move is legal for the Queen
 Input: Target column (col) and row (row)
 Output: Returns true if the move is legal, false otherwise, updating the board's error code if invalid.
*/
bool Bishop::isMoveLegal(int col, int row) const
{
    // The Bishop's movement will always be the same number of rows and columns from its current position
    if (abs(col - getCol()) != abs(row - getRow())) // if it's not return false with code 6 error
    {
        B._code = 6;
        return false;
    }
    if (isBlocked(col, row)) // if the Bishop blocked return false with code 6 error
    {
        B._code = 6;
        return false;
    }

    return true;
}
