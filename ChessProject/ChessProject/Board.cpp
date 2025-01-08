#include "Board.h"
#include "Rook.h"
#include "King.h"
Board::Board()
{
	_kingBlack = new King(0, 3, *this, 'k');
	_kingWhite = new King(7, 3, *this, 'K');
	new Rook(0, 7, *this, 'r');
	new Rook(0, 0, *this, 'r');
	new Rook(7, 0, *this, 'R');
	new Rook(7, 7, *this, 'R');
}

Board::~Board()
{
	int r = 0;
	int c = 0;
	for (r = 0; r < 8; r++)
	{
		for (c = 0; c < 8; c++)
		{
			if (_board[r][c] != nullptr)
			{
				delete(_board[r][c]);
			}
		}
	}
}

void Board::print()
{
	int r = 0;
	int c = 0;
	std::cout << "a b c d e f g h\n\n";
	for (r = 0; r < 8; r++)
	{
		std::cout << r + 1 << "  ";
		for (c = 0; c < 8; c++)
		{
			if (_board[r][c] == nullptr)
			{
				std::cout << "# ";
				continue;
			}
			std::cout << _board[r][c]->getType() << " ";
		}
		std::cout << "\n";
	}
}

std::string Board::boardString()
{
	std::string boardString = "";
	int r = 0;
	int c = 0;
	for (r = 0; r < 8; r++)
	{
		for (c = 0; c < 8; c++)
		{
			std::cout << r + 1 << "  ";
			if (_board[r][c] == nullptr)
			{
				boardString += "#";
				continue;
			}
			boardString += _board[r][c]->getType();
		}
	}
	boardString += std::to_string(_player);
	boardString += "f";
	boardString[65] = NULL;
	return boardString;
}

void Board::move(char fromR, int fromC, char toR, int toC)
{
	fromC -= 'a';
	fromR -= 1;
	toC -= 'a';
	toR -= 1;
	if (fromC > 7 || fromC < 0 || toC > 7 || toC < 0 || fromR < 0 || fromR > 7 || toR < 0 || toR > 7)
	{
		_code = 5;
		return;
	}
	if (fromC == toC  && fromR == toR)
	{
		_code = 7;
		return;
	}
	if (_board[fromR][fromC] == nullptr || std::islower(_board[fromR][fromC]->getType()) != (_player != 0))
	{
		_code = 2;
		return;
	}
	if (_board[toR][toC] != nullptr && std::islower(_board[toR][toC]->getType()) == (_player != 0))
	{
		_code = 3;
		return;
	}
	_board[fromR][fromC]->move(toC, toR);
}
