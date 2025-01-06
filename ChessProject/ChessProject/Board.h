#pragma once

#include <iostream>
#include <string>
#include "Tool.h"

class Board
{
	
public:
	Tool* _board[8][8];
	Board();
	void remove(int, char);
	void print();
	std::string boardString();
};
#pragma once
