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
	for (r = 0; r < 8; r++)
	{
		std::cout << "a b c d e f g h\n\n";
		for (c = 0; c < 8; c++)
		{

			std::cout << r + 1 << "  ";
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
	return boardString;
}