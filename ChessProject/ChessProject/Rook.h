#pragma once
#include <iostream>
#include <string>
#include "Tool.h"

class Rook : public Tool
{
public:
	Rook(int col, int row, Tool***& board, char type);
	void move(int col, int row);
	bool checkChess() const;
	bool isBloced(int col, int row) const;
	virtual bool isMoveLegal(int cul, int row) const;
};


