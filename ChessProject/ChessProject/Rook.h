#pragma once

#include <iostream>
#include <string>
#include "Tool.h"
class Board;

class Rook : public Tool {
public:
    Rook(int col, int row, Board& board, char type, int player);
    Rook(int col, int row, Board& board);
    void move(int col, int row) ;
    bool isBlocked(int col, int row) const ;
    bool isMoveLegal(int col, int row) const ;
};
