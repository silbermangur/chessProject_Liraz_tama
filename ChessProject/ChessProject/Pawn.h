#pragma once

#include "Tool.h"
class Board;

class Pawn : public Tool
{
public:
	Pawn(int col, int row, Board& board, char type, int player);
	virtual void move(int col, int row);
	virtual bool isBlocked(int col, int row) const;
	virtual bool isMoveLegal(int col, int row) const;

};