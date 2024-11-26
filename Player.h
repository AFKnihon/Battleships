#ifndef PLAYER_H
#define PLAYER_H
#include <array>


class Player {
    public:
    void shooting();

bool isCorrectShooting();

    bool IsMyTurn;
    bool IsMyTurnnPlayer1(int i);
    bool IsMyTurnnPlayer2(int i);
    std::string coordinatesOfShotPosition;
    void CreateCoordinatesOfShotPoint();

    int repeatGetter();

    bool repeatGame;
void doYouWantToRepeat();

    int playerWins = 0;

    void WinsAdder();

    void WinsDisplayer1();

    void WinsDisplayer2();

    void WinsDisplayer();

    ~Player();

    void Divide();
    void DivideTrue();
    void DivideFalse();
    bool If10();

    bool AdditionalRound;

    void additionalRoundSave(bool i);
    int additionalRoundGetter();

    int FirstCoordinate;
    int SecondCoordinate;

    int Coordinate1Getter();
    int Coordinate2Getter();
    bool CheckIfHit(char value);
};





#endif
