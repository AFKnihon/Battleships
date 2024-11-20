#include "ships.h"
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <iostream>
#include <cstdlib>

void ships::getShipPosition() {
    std::string Position;
    std::cin >> Position;


    this->ShipPosition = Position;

}

void ships::Clear() {
#if __linux__
    system("clear");
#elif __APPLE__
    system("clear");
#elif _WIN32
    system("cls");
#else
    printf("\033[2J");
#endif
}


void ships::CreateCoordinates() {

std::string Coordinates = this->ShipPosition;
std::transform(Coordinates.begin(), Coordinates.end(), Coordinates.begin(), ::toupper);
    this->ShipPosition = Coordinates;
}


bool ships::If10() {
    std::string ShipPosition = this->ShipPosition;

    if (ShipPosition.size()==3) {

        return true;
    }else
        return false;
}

void ships::DivideTrue() {
    std::string Divide = this->ShipPosition;

    char Divide2 = Divide[2];
    int Divided1 = 9;
    int Divided2 = char(Divide2 - 65);

    this->FirstCoordinate = Divided1;
    this->SecondCoordinate = Divided2;


}
    void ships::DivideFalse(){

        std::string DividE = this->ShipPosition;

        char DividE1 = DividE[0];
        char DividE2 = DividE[1];
        int DivideE1 = char(DividE1 - 49);
        int DivideE2 = char(DividE2 - 65);




        this->FirstCoordinate = DivideE1;
        this->SecondCoordinate = DivideE2;
    }

void ships::Divide() {

    switch(bool IfWas10 = If10()) {
        case true: DivideTrue();
        break;
        case false:DivideFalse();
        break;

    }
}


bool ships::If10ForNMasted() {
    std::string ShipPosition = this->ShipPosition;

    if (ShipPosition.size()==4) {

        return true;
    }else
        return false;
}
void ships::Divide2True() {

    std::string Divide = this->ShipPosition;
    char Divide3 = Divide[3];
    char Divide2 = Divide[2];
    int Divided1 = 9;
    int Divided2 = char(Divide2 - 65);






    this->FirstCoordinate = Divided1;
    this->SecondCoordinate = Divided2;
    this->direction = Divide3;

}
void ships::Divide2False() {

    std::string DividE = this->ShipPosition;

    char DividE1 = DividE[0];
    char DividE2 = DividE[1];
    char DividE3 = DividE[2];
    int DivideE1 = char(DividE1 - 49);
    int DivideE2 = char(DividE2 - 65);




    this->FirstCoordinate = DivideE1;
    this->SecondCoordinate = DivideE2;
    this->direction = DividE3;

}

bool ships::isCorrect() {
    std::string ShipPosition = this->ShipPosition;

    if (ShipPosition.size()==2) {
        if (ShipPosition[0]== '1' || ShipPosition[0]== '2' || ShipPosition[0]== '3' || ShipPosition[0] == '4' || ShipPosition[0]== '5' || ShipPosition[0]== '6' || ShipPosition[0]== '7' || ShipPosition[0]== '8' || ShipPosition[0]== '9') {
            if (ShipPosition[1] == 'A' || ShipPosition[1] == 'B' || ShipPosition[1] == 'C' || ShipPosition[1] == 'D' || ShipPosition[1] == 'E' || ShipPosition[1] == 'F' || ShipPosition[1] == 'G' || ShipPosition[1] == 'H' || ShipPosition[1] == 'I' || ShipPosition[1] == 'J') {
                return true;
            }return false;
        }return false;
    }else if(ShipPosition.size()==3) {
         if(ShipPosition[0] == '1') {
            if(ShipPosition[1] == '0') {
                if (ShipPosition[2] == 'A' || ShipPosition[2] == 'B' || ShipPosition[2] == 'C' || ShipPosition[2] == 'D'
                    || ShipPosition[2] == 'E' || ShipPosition[2] == 'F' || ShipPosition[2] == 'G' || ShipPosition[2] ==
                    'H' || ShipPosition[2] == 'I' || ShipPosition[2] == 'J') return true;
            }return false;
        }return false;
    }return false;
}



bool ships::isCorrectNMasted() {
    std::string ShipPosition = this->ShipPosition;

    if (ShipPosition.size()==3) {
        if (ShipPosition[0]== '1' || ShipPosition[0]== '2' || ShipPosition[0]== '3' || ShipPosition[0] == '4' || ShipPosition[0]== '5' || ShipPosition[0]== '6' || ShipPosition[0]== '7' || ShipPosition[0]== '8' || ShipPosition[0]== '9') {
            if (ShipPosition[1] == 'A' || ShipPosition[1] == 'B' || ShipPosition[1] == 'C' || ShipPosition[1] == 'D' || ShipPosition[1] == 'E' || ShipPosition[1] == 'F' || ShipPosition[1] == 'G' || ShipPosition[1] == 'H' || ShipPosition[1] == 'I' || ShipPosition[1] == 'J') {
                if (ShipPosition[2] == 'H' || ShipPosition[2] == 'V') return true;
                return false;
            }return false;
        }return false;
    }else if(ShipPosition.size()==4) {
        if(ShipPosition[0] == '1') {
            if(ShipPosition[1] == '0') {
                if (ShipPosition[2] == 'A' || ShipPosition[2] == 'B' || ShipPosition[2] == 'C' || ShipPosition[2] == 'D'
                    || ShipPosition[2] == 'E' || ShipPosition[2] == 'F' || ShipPosition[2] == 'G' || ShipPosition[2] ==
                    'H' || ShipPosition[2] == 'I' || ShipPosition[2] == 'J') {
                    if (ShipPosition[3] == 'H' || ShipPosition[3] == 'V') return true;
                    return false;
                }return false;
            }return false;
        }return false;
    }return false;
}



void ships::Divide2() {
    switch(bool IfWas10 = If10ForNMasted()) {
        case true: Divide2True();
        break;
        case false:Divide2False();
        break;

    }
}





int ships::Coordinate1Getter() {
return this->FirstCoordinate;

}
int ships::Coordinate2Getter() {
return this->SecondCoordinate;

}

int ships::DirectionGetter() {
    return this->direction;
}







ships::~ships() {}






