#include "ships.h"
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>


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

    return ShipPosition.size()==3;

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

    return ShipPosition.size()==4;

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
        char first_char = ShipPosition[0];
        int ascii_value = static_cast<int>(first_char);
        char second_char = ShipPosition[1];
        int ascii_value2 = static_cast<int>(second_char);

        if(ascii_value >= 49 && ascii_value <=57)
        {
            if(ascii_value2 >= 65 && ascii_value2 <= 74) {
                return true;
            }
        }return false;
        
    }else if(ShipPosition.size()==3) {
        char first_char = ShipPosition[0];
        int ascii_value = static_cast<int>(first_char);
        char second_char = ShipPosition[1];
        int ascii_value2 = static_cast<int>(second_char);
        char third_char = ShipPosition[2];
        int ascii_value3 = static_cast<int>(third_char);


         if(ascii_value == 49) {
            if(ascii_value2 == 48) {
                if (ascii_value3 >= 65 && ascii_value3 <= 74) return true;
            }return false;
        }return false;
    }return false;
}



bool ships::isCorrectNMasted() {
    std::string ShipPosition = this->ShipPosition;

    char first_char = ShipPosition[0];
    int ascii_value = static_cast<int>(first_char);
    char second_char = ShipPosition[1];
    int ascii_value2 = static_cast<int>(second_char);
    char third_char = ShipPosition[2];
    int ascii_value3 = static_cast<int>(third_char);
    char fourth_char = ShipPosition[3];
    int ascii_value4 = static_cast<int>(fourth_char);


    if (ShipPosition.size()==3) {
        if (ascii_value >= 49 && ascii_value <=57) {
            if (ascii_value2 >= 65 && ascii_value2 <= 74) {
                if (ascii_value3 == 72 || ascii_value3 == 86) return true;
                return false;
            }return false;
        }return false;
    }else if(ShipPosition.size()==4) {
        if(ascii_value == 49) {
            if(ascii_value2 == 48) {
                if (ascii_value3 >= 65 && ascii_value3 <=74) {
                    if (ascii_value4 == 72 || ascii_value4 == 86) return true;
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



void ships::Player1NMastedShipsPlacement(int size) {



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






