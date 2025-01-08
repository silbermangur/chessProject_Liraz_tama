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

	Board();
	~Board();
	
	void print();
	std::string boardString();
};

