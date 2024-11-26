
#include "Player.h"
#include <string>
#include <algorithm>
using namespace std;

bool Player::IsMyTurnnPlayer1(int i) {

    int EverTurn = i%2;
    switch (EverTurn) {
        case 0: return false;
        case 1: return true;
    }
    return false;
}

bool Player::IsMyTurnnPlayer2(int i) {

    int EverTurn = i%2;
    switch (EverTurn) {
        case 0: return true;
        case 1: return false;
    }
    return false;
}




void Player::shooting() {
    std::string position;
std::cout<<"Select coordinates of the point you want to shoot: ";
    std::cin>> position;

    this->coordinatesOfShotPosition = position;


}
bool Player::isCorrectShooting() {
    std::string Shooting = this->coordinatesOfShotPosition;


    if (Shooting.size()==2) {
        char first_char = coordinatesOfShotPosition[0];
        int ascii_value = static_cast<int>(first_char);
        char second_char = coordinatesOfShotPosition[1];
        int ascii_value2 = static_cast<int>(second_char);

        if (ascii_value >= 49 && ascii_value <=57) {
            if (ascii_value2 >= 65 && ascii_value2 <= 74) {
                return true;
            }return false;
        }return false;
    }

    if (Shooting.size()==3) {
        char first_char = coordinatesOfShotPosition[0];
        int ascii_value = static_cast<int>(first_char);
        char second_char = coordinatesOfShotPosition[1];
        int ascii_value2 = static_cast<int>(second_char);
        char third_char = coordinatesOfShotPosition[2];
        int ascii_value3 = static_cast<int>(third_char);

        if (ascii_value == 49 && ascii_value2 == 48) {
            if (ascii_value3 >= 65 && ascii_value3 <= 74) {
                return true;
            }return false;
        }return false;
    }return false;
}

void Player::CreateCoordinatesOfShotPoint() {
    std::string Coordinates = this->coordinatesOfShotPosition;
    std::transform(Coordinates.begin(), Coordinates.end(), Coordinates.begin(), ::toupper);
    this->coordinatesOfShotPosition = Coordinates;

}

int Player::repeatGetter() {
    return this->repeatGame;
}

void Player::doYouWantToRepeat() {

    for(int i=1; i > 0;i++) {
        std::string RepeatGame;
        std::cout<<"Do you want to repeat the game? (y/n) ";
        std::cin>>RepeatGame;

        if (RepeatGame.length()==1) {
            if (RepeatGame[0]=='y'|| RepeatGame[0]=='Y') {
                this->repeatGame = true;
                break;
            }else if(RepeatGame[0]=='n'|| RepeatGame[0]=='N') {
                this->repeatGame = false;
                break;
            }else {
                std::cout <<"Input only (y/n)\n";
                getchar();

            }
        }
    }
}

bool Player::If10() {
    std::string ShotCoordinates = this->coordinatesOfShotPosition;

    if (coordinatesOfShotPosition.size()==3) {

        return true;
    }else
        return false;
    }

void Player::additionalRoundSave(bool i) {
    this ->AdditionalRound = i;
}

int Player::additionalRoundGetter() {
    return this->AdditionalRound;
}

void Player::DivideFalse(){

        std::string DividE = this->coordinatesOfShotPosition;

        char DividE1 = DividE[0];
        char DividE2 = DividE[1];
        int DivideE1 = char(DividE1 - 49);
        int DivideE2 = char(DividE2 - 65);




        this->FirstCoordinate = DivideE1;
        this->SecondCoordinate = DivideE2;

    }
    void Player::DivideTrue() {
        std::string Divide = this->coordinatesOfShotPosition;

        char Divide2 = Divide[2];
        int Divided1 = 9;
        int Divided2 = char(Divide2 - 65);

        this->FirstCoordinate = Divided1;
        this->SecondCoordinate = Divided2;
    }

void Player::Divide() {

    switch(bool IfWas10 = If10()) {
        case true: DivideTrue();
        break;
        case false:DivideFalse();
        break;

    }
};

int Player::Coordinate1Getter() {
    return this->FirstCoordinate;
}
int Player::Coordinate2Getter() {
    return this->SecondCoordinate;
}

bool Player::CheckIfHit(char value) {
    if (value == char(254)) {
        return true;
    }else {
        return false;
    }
}

void Player::WinsAdder() {
    this -> playerWins++;
};

void Player::WinsDisplayer1() {
    std::cout <<"Player one wins: ";
    std::cout << this -> playerWins << std::endl;
};

void Player::WinsDisplayer2() {
    std::cout <<"Player two wins: ";
    std::cout << this -> playerWins << std::endl;
};

Player::~Player() {}



