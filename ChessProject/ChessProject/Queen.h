#pragma once

#include "Tool.h"
#include "Bishop.h"
#include "Rook.h"
class Board;

class Queen : public Bishop, public Rook
{
public:
	Queen(int col, int row, Board& board, char type);
	virtual void move(int col, int row);
	virtual bool isBlocked(int col, int row) const;
	virtual bool isMoveLegal(int col, int row) const;

};
