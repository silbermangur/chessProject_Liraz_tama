#pragma once

#include <iostream>
#include <string>
#include "Tool.h"

class Tool;
class Board
{
public:
	Tool* _board[8][8] = {nullptr};
	Tool* _kingWhite;
	Tool* _kingBlack;
	int _code;
	int _player = 0;

	Board();
	~Board();
	
	void print();
	std::string boardString();
	void move(char fromR, int fromC, char toR, int toC);
	bool checkChess() const;
};

