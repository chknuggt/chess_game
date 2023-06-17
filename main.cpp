#include "Board.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>

void chessGame()
{
    Board board;
    std::string from, to;
    bool isWhiteTurn = true;

    while (true) {
        board.printBoard(); // Print the current board

        std::cout << (isWhiteTurn ? "White's turn. " : "Black's turn. ");
        std::cout << "Enter move (e.g., E2 E4): ";
        std::cin >> from >> to;

        int fromX = from[1] - '1';
        int fromY = from[0] - 'A';
        int toX = to[1] - '1';
        int toY = to[0] - 'A';

        if(board.movePiece(fromX, fromY, toX, toY)){ 
            return; 
        }

        isWhiteTurn = !isWhiteTurn; 
        std::cout << std::endl;
    }
}



int main()
{

std::ifstream file("ascii_art.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Unable to open the file.";
    }

    while (true) {
        std::cout << "Please select an option:\n";
        std::cout << "1. Play Chess\n";
        std::cout << "2. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                chessGame();
                break;
            case 2:
                std::cout << "Exiting the program...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
