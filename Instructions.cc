
#include "Instructions.h"
#include <iostream>

void Instructions::StartingInstructions(){
    std::cout << "Instructions:" << std::endl;
    std::cout << "Your marine will be made of eleven ships" << std::endl;
    std::cout << "You will have to position: " << std::endl;
    std::cout << "4x one-masted ships" << std::endl;
    std::cout << "3x two-masted ships" << std::endl;
    std::cout << "2x three-masted ships" << std::endl;
    std::cout << "1x four-masted ship" << std::endl;
    std::cout << std::endl;
    std::cout << "You will switch seats while game ongoing" << std::endl;
    std::cout <<"Press Enter when first player is ready" << std::endl;
    getchar();

}

void Instructions::OneMastedInstructions(int i){
switch(i) {
    case 0: std::cout << "Select coordinates of where you want to place first one-masted ship:";
    break;

    case 1: std::cout << "Select coordinates of where you want to place second one-masted ship:";
    break;

    case 2: std::cout << "Select coordinates of where you want to place third one-masted ship:";
    break;

    case 3: std::cout << "Select coordinates of where you want to place fourth one-masted ship:";
    break;
}


}

void Instructions::TwoMastedInstructions(int i) {
    switch(i) {
        case 0: std::cout << "Select coordinates of where you want to place first Two-masted ship and which\n geographical direction it should head(V/h):";
        break;
        case 1: std::cout << "Select coordinates of where you want to place second Two-masted ship and which\n geographical direction it should head:";
        break;
        case 2: std::cout << "Select coordinates of where you want to place Third Two-masted ship and which\n geographical direction it should head:";
        break;
    }
}

void Instructions::ThreeMastedInstructions(int i) {
    switch(i) {
        case 0: std::cout << "Select coordinates of where you want to place first Three-masted ship and which\n geographical direction it should head(V/h):";
        break;
        case 1: std::cout << "Select coordinates of where you want to place second Three-masted ship and which\n geographical direction it should head:";
        break;

    }
}

void Instructions::FourMastedInstructions(int i){
std::cout << "Select coordinates of where you want to place Four-masted ship and which\n geographical direction it should head:";
}

Instructions::~Instructions(){}
