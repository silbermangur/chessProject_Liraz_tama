#include "Queen.h"

Queen::Queen(int col, int row, Board& board, char type) :
	Rook(col, row, board, type), Bishop(col, row, board, type)
{
}

void Queen::move(int col, int row)
{
    if (isMoveLegal(col, row))
    {
        if (Rook::B._board[row][col] != nullptr)
        {
            delete(Rook::B._board[row][col]);
        }
        Rook::B._board[row][col] = Rook::B._board[Rook::getRow()][Rook::getCol()];
        Rook::B._board[Rook::getRow()][Rook::getCol()] = nullptr;
        Bishop::B._board[row][col] = Rook::B._board[Rook::getRow()][Rook::getCol()];
        Bishop::B._board[Rook::getRow()][Rook::getCol()] = nullptr;
        Rook::setCol(col);
        Rook::setRow(row);
        Bishop::setCol(col);
        Bishop::setRow(row);
        return;
    }
    throw LocationException();
}

bool Queen::isBlocked(int col, int row) const
{
    return false;
}

bool Queen::isMoveLegal(int col, int row) const
{
    if (col == Rook::getCol() || row == Rook::getCol())
        return Rook::isMoveLegal(col, row);
    else
        return Bishop::isMoveLegal(col, row);
}