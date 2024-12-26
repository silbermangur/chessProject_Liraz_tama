#pragma once

#include <iostream>
#include <string>

class Tool
{
	char _type;
	int _row;
	char _cul;
public:
	Tool(char cul, int row, /*Board& board*/ char type);	
	virtual ~Tool() {}
	
	virtual void move(char cul, int row);
	virtual bool isBloced(char cul, int row) const;
	virtual bool isMoveLegal(char cul, int row) const;
	char getCul() const;
	int getRow() const;
	void setRow(int row);
	void setCul(char cul);
	std::string getLocation() const;
	char getType() const;
protected:
	//Board board;
};
