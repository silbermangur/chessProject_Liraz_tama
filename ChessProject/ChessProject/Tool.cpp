#include "Tool.h"

Tool::Tool(char cul, int row, /*Board& board*/ char type)
	:_cul(cul), _row(row), _type(type)
{}

char Tool::getCul() const
{
	return _cul;
}
int Tool::getRow() const
{
	return _row;
}
void Tool::setRow(int row)
{
	_row = row;
}
void Tool::setCul(char cul)
{
	_cul = cul;
}
std::string Tool::getLocation() const
{
	return std::to_string(_cul) + std::to_string(_row);
}
char Tool::getType() const
{
	return _type;
}
