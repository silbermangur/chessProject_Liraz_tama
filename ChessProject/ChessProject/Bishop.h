#pragma once
#include <iostream>
#include <string>
#include "Tool.h"
class Board;

class Bishop : public Tool
{
public:
	Bishop(int col, int row, Board& board, char type, int player);
	Bishop(int col, int row, Board& board);
	void move(int col, int row);
	bool checkChess() const;
	bool isBlocked(int col, int row) const;
	virtual bool isMoveLegal(int cul, int row) const;
};


