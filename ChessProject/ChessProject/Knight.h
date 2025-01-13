#pragma once
#include "Tool.h"
class Board;

class Knight : public Tool
{
public:
	Knight(int col, int row, Board& board, char type, int player);
	virtual void move(int col, int row);
	virtual bool isBlocked(int col, int row) const;
	virtual bool isMoveLegal(int col, int row) const;

};
