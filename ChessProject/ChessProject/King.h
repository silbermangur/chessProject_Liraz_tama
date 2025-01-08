#pragma once

#include <iostream>
#include <string>
#include "Tool.h"
class Board;

class King : public Tool
{
public:
    King(int row, int col, Board& board, char type);
    void move(int col, int row);
    bool checkChess() const;
    bool isBlocked(int col, int row) const;
    bool isMoveLegal(int col, int row) const;
};
