#include "Tool.h"
Tool::Tool(int col, int row, Board& board, char type, int player)
	:_col(col), _row(row), _type(type), B(board), _player(player)
{}



int Tool::getCol() const
{
	return _col;
}
int Tool::getRow() const
{
	return _row;
}
void Tool::setRow(int row)
{
	_row = row;
}
void Tool::setCol(int col)
{
	_col = col;
}
std::string Tool::getLocation() const
{
	return std::to_string(_col) + std::to_string(_row);
}
char Tool::getType() const
{
	return _type;
}
