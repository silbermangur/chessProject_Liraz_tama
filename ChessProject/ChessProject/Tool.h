#pragma once

#include <iostream>
#include <string>
#include "LocationException.h"
#include "Board.h"

class Board;

class Tool
{
	char _type;
	int _row;
	int _col;
public:
	int _player;
	Tool(int col, int row, Board& board, char type, int player);
	virtual ~Tool() {}
	
	virtual void move(int col, int row) = 0; 
	virtual bool isBlocked(int col, int row) const = 0;
	virtual bool isMoveLegal(int col, int row) const = 0;

	int getCol() const;
	int getRow() const;
	void setRow(int row);
	void setCol(int col);
	std::string getLocation() const;
	char getType() const;

	Board& B;
};
