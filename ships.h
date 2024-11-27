#ifndef SHIPS_H
#define SHIPS_H



class ships {
public:

void getShipPosition();

    void Clear();

    int FirstCoordinate;
    int SecondCoordinate;
    char direction;
    std::string ShipPosition;
    void DivideTrue();
    void DivideFalse();
    bool If10();
    bool If10ForNMasted();
    void Divide2True();
    void Divide2False();
    bool isCorrect();
    bool isCorrectNMasted();

void CreateCoordinates();
void Divide();
    void Divide2();

void Player1NMastedShipsPlacement(int size);

int Coordinate1Getter();
    int Coordinate2Getter();
    int DirectionGetter();

~ships();
};




#endif
