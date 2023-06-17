#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
private:
    std::string name;
    std::string symbol;

public:
    Piece(std::string name, std::string symbol) : name(name), symbol(symbol) {}
    std::string getSymbol() const { return symbol; }
};

#endif
