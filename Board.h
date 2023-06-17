#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>

class Board {
public:
    Board();
    ~Board();
bool movePiece(int fromX, int fromY, int toX, int toY);

    void printBoard() const;
    bool isKingDead(bool isWhite) const;

private:
    std::vector<std::vector<Piece*>> _board;
    void initializeBoard();
};

#endif
