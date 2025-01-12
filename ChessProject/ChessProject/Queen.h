#pragma once

#include "Tool.h"
#include "Rook.h"
#include "Bishop.h"
class Board;

class Queen :  public Tool
{
public:
	Queen(int col, int row, Board& board, char type);
	virtual void move(int col, int row);
	virtual bool isBlocked(int col, int row) const;
	virtual bool isMoveLegal(int col, int row) const;

};
