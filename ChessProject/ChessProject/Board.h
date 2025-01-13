#pragma once

#include <iostream>
#include <string>
#include "Tool.h"

class Tool;
class Board
{
	int _player = 0;
	Tool* _kingWhite;
	Tool* _kingBlack;
public:
	Tool* _board[8][8] = {nullptr};
	int _code;

	Board();
	~Board();
	
	void print();
	std::string boardString();
	void move(char fromR, char fromC, char toR, char toC);
	bool checkChess() ;
};

