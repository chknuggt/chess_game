#include "Board.h"
#include "Piece.h"
#include <iostream>

Board::Board() {
    _board.resize(8, std::vector<Piece*>(8, nullptr));
    initializeBoard();
}

Board::~Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            delete _board[i][j];
        }
    }
}

bool Board::movePiece(int fromX, int fromY, int toX, int toY) {
    Piece* movedPiece = _board[fromX][fromY];
    _board[fromX][fromY] = nullptr;
    _board[toX][toY] = movedPiece;

    bool isWhiteTurn = (movedPiece->getSymbol() == "K" || movedPiece->getSymbol() == "Q");

    if (isKingDead(!isWhiteTurn)) {
        std::cout << (isWhiteTurn ? "White" : "Black") << " wins!\n";
        return true;
    }
    return false;
}



void Board::printBoard() const {
    std::cout << "   A  B  C  D  E  F  G  H\n";
    for (int i = 7; i >= 0; --i) {
        std::cout << i + 1 << "  ";
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0)
                std::cout << "\033[47m";
            else
                std::cout << "\033[40m";

            Piece* piece = _board[i][j];
            if (piece) {
                std::cout << ' ' << piece->getSymbol() << ' ';
            } else {
                std::cout << "   ";
            }
            std::cout << "\033[0m";
        }
        std::cout << " " << i + 1 << "\n";
    }
    std::cout << "   A  B  C  D  E  F  G  H\n";
}

bool Board::isKingDead(bool isWhite) const {
    std::string kingSymbol = isWhite ? "K" : "k";
    for (const auto& row : _board) {
        for (const auto& piece : row) {
            if (piece && piece->getSymbol() == kingSymbol) {
                return false;
            }
        }
    }
    return true;
}

void Board::initializeBoard() {
    for (int i = 0; i < 8; ++i) {
        _board[1][i] = new Piece("Pawn", "P");
        _board[6][i] = new Piece("Pawn", "p");
    }

    _board[0][0] = new Piece("Rook", "R");
    _board[0][7] = new Piece("Rook", "R");
    _board[7][0] = new Piece("Rook", "r");
    _board[7][7] = new Piece("Rook", "r");

    _board[0][1] = new Piece("Knight", "N");
    _board[0][6] = new Piece("Knight", "N");
    _board[7][1] = new Piece("Knight", "n");
    _board[7][6] = new Piece("Knight", "n");

    _board[0][2] = new Piece("Bishop", "B");
    _board[0][5] = new Piece("Bishop", "B");
    _board[7][2] = new Piece("Bishop", "b");
    _board[7][5] = new Piece("Bishop", "b");

    _board[0][3] = new Piece("Queen", "Q");
    _board[7][3] = new Piece("Queen", "q");

    _board[0][4] = new Piece("King", "K");
    _board[7][4] = new Piece("King", "k");
}