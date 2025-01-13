#pragma once

#include <iostream>
#include <string>
#include "Tool.h"
class Board;

class King : public Tool
{
public:
    King(int col, int row, Board& board, char type, int player);
    void move(int col, int row);
    bool isBlocked(int col, int row) const;
    bool isMoveLegal(int col, int row) const;
};
