#pragma once

#include <iostream>
#include <string>
#include "LocationException.h"


class Tool
{
	char _type;
	int _row;
	int _col;
public:
	Tool(int col, int row, Tool***& board, char type);
	virtual ~Tool() {}
	
	virtual void move(int col, int row) = 0; 
	virtual bool isBloced(int col, int row) const = 0;
	virtual bool isMoveLegal(int col, int row) const = 0;

	int getCol() const;
	int getRow() const;
	void setRow(int row);
	void setCol(int col);
	std::string getLocation() const;
	char getType() const;

	Tool***& _board;
};
