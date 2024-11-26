#include "Board.h"
#include <iostream>
Board::Board(){}




void Board::displayPlayerGrid() const {

    std::cout << "  =========================================\n";
    std::cout << "              PLAYER'S BOARD               \n";
    std::cout << "  =========================================\n";

    std::cout << std::endl;

    std::cout << "    a  b  c  d  e  f  g  h  i  j " << std::endl;
    std::cout << "  +------------------------------+" << std::endl;


    for (int i = 0; i < boardSize; ++i)
    {

        if(i < 9)
        std::cout << (i + 1) << " |";
        else
            std::cout << (i + 1) << "|";



        for (int j = 0; j < boardSize; ++j)
        {
            if(j < 9)
            std::cout <<' '<< playerGrid[i][j] << " ";
            else
                std::cout <<' '<< playerGrid[i][j] << " |";
        }
        std::cout << std::endl;


    }
    std::cout << "  +------------------------------+" << std::endl;


}

void Board::displayShootingGrid() const {

    std::cout << "  =========================================\n";
    std::cout << "              SHOOTING BOARD               \n";
    std::cout << "  =========================================\n";

    std::cout << std::endl;

    std::cout << "    a  b  c  d  e  f  g  h  i  j " << std::endl;
    std::cout << "  +------------------------------+" << std::endl;

    for (int i = 0; i < boardSize; ++i)
    {

        if(i < 9)
            std::cout << (i + 1) << " |";
        else
            std::cout << (i + 1) << "|";

        for (int j = 0; j < boardSize; ++j)
        {
            if(j < 9)
            std::cout <<' '<< shootingGrid[i][j] << " ";
            else
                std::cout <<' '<< shootingGrid[i][j] << " |";


        }
        std::cout << std::endl;
    }
    std::cout << "  +------------------------------+" << std::endl;
}


void Board::fillBoard()

{

    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)
        {
            playerGrid[i][j] = char(196);
            shootingGrid[i][j] = char(196);
        }
    }
}


bool Board::CheckIfAvaliable(int startRow, int startCol, int shipSize, char direction) {


    if (direction == 'H' ? startCol + shipSize > playerGrid.size() : startRow + shipSize > playerGrid.size()) return false;

    for (int i{}; i < shipSize + 2; i++) {
        for (int j{}; j < 3; j++) {
            int r{direction == 'H' ? startRow + j - 1 : startRow + i - 1};
            int c{direction == 'H' ? startCol + i - 1 : startCol + j - 1};
            if (!checkSquare(r, c)) return false;
        }
    }

    return true;

}


bool Board::checkSquare(int row, int col)
{
    if (row >= 0 && row < 10 && col >= 0 && col < 10) {
        const int val{playerGrid[row][col]};
        return !(val != char(196) && val == char(254));
    }
    else return true;
}

// Function to place a ship
void Board::PlaceShip(int startRow, int startCol, int shipSize, char direction) {
    if (CheckIfAvaliable(startRow, startCol, shipSize, direction)) {
        if (direction == 'H') { // Horizontal placement
            for (int i = 0; i < shipSize; i++) {
                playerGrid[startRow][startCol + i] = char(254); // Place ship
            }
        } else if (direction == 'V') { // Vertical placement
            for (int i = 0; i < shipSize; i++) {
                playerGrid[startRow + i][startCol] = char(254); // Place ship
            }
        }
    } else {
        std::cout << "Cannot place ship at this location.\n";
    }
}
;


bool Board::CheckIfHit(int coor1, int coord2) {
    if (playerGrid[coor1][coord2] == char(254))
        return true;
    else
        return false;
}

void Board::MarkHit(int coordinate1, int coordinate2) {
    playerGrid[coordinate1][coordinate2] = 'X' ;
}

void Board::UpdateShootingGrid(int coord1, int coord2, char c) {
    shootingGrid[coord1][coord2] = c;
}

bool Board::AllShipsSunk() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (playerGrid[i][j] == char(254)) {
                return false; // Found char(254), return false
            }
        }
    }
    return true; // No char(254) found, return true
}

Board::~Board(){}