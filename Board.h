
#ifndef BOARD_H
#define BOARD_H
#include <array>

class Board
{

public:
    Board();

    static constexpr int boardSize = 10;
    std::array<std::array<char, 10>, 10> playerGrid;
    std::array<std::array<char, 10>, 10> shootingGrid;

    auto getPlayerGrid(){ return playerGrid;}

    bool CheckIfHit(int coordinate1, int coordinate2);
    bool checkSquare(int r, int c);

    void UpdateShootingGrid(int coordinate1, int coordinate2, char c);
    auto getShootingGrid(){ return shootingGrid;}
    bool AllShipsSunk();

    ~Board();

    bool CheckIfAvaliable(int startRow, int startCol, int shipSize, char direction);
    void PlaceShip(int startRow, int startCol, int shipSize, char direction);

    void MarkHit(int coordinate1, int coordinate2);

    void displayPlayerGrid() const;
    void displayShootingGrid() const;

    void fillBoard();

    bool CheckIfShipSunk(int startRow, int startCol, int shipSize, char direction);
};
#endif
