#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include "Player.cc"
#include "Board.cc"
#include "greetings.cc"
#include "ships.cc"
#include "Instructions.cc"


void GameManager::GameStartup() {

    Player Player1Info;
    Player Player2Info;
    Player Shooting;
    Player BothInfo;
for (int i=0; i < i+1; i++) {

    ships Positioning;
    Instructions instructions;
    Board Player1Board;
    Board Player2Board;
    ships Clearing;
    Greetings Greetings;
    Clearing.Clear();


    instructions.StartingInstructions();
    Clearing.Clear();

    int GameOngoing = 1; // Set to 1 to start the game

    while (GameOngoing)
    {
        Player1Board.fillBoard();
        Player1Board.displayPlayerGrid();

        // Placing One-Masted Ships
        for (int i = 0; i <= 3; i++) {
            instructions.NMastedInstructions(i,1);

            Positioning.getShipPosition();

            Positioning.CreateCoordinates();
            if (Positioning.isCorrect()){
                Positioning.Divide();
                int coordinate1 = Positioning.Coordinate1Getter();
                int coordinate2 = Positioning.Coordinate2Getter();
                char direction = 'H';

                bool IsAvaliable = Player1Board.CheckIfAvaliable(coordinate1, coordinate2,1,direction);
                getchar();
                if (IsAvaliable == true)
                {

                    Clearing.Clear();
                    Player1Board.PlaceShip(coordinate1, coordinate2,1,direction);
                    Player1Board.displayPlayerGrid();
                    Positioning.~ships();

                }
                else
                {


                    Clearing.Clear();
                    Player1Board.displayPlayerGrid();
                    std::cout << "There is ship already standing here or position you\n provided is out of bounds.Try again\n";
                    i--;
                    Positioning.~ships();
                }
            }
            else {
                Clearing.Clear();
                Player1Board.displayPlayerGrid();
                std::cout << "You have provided coordinates in a wrong format try again!\n";
                i--;
            }
        }
        // Placing N-Masted Ships
        int rep = 2;
        int size = 2;
        for (int i = 0; i <= rep+2; i++) {
            for (int i = 0; i <= rep; i++) {

                instructions.NMastedInstructions(i,size);

                Positioning.getShipPosition();
                Positioning.CreateCoordinates();
                if (Positioning.isCorrectNMasted()){
                    Positioning.Divide2();

                    char direction = Positioning.DirectionGetter();
                    int coordinate1 = Positioning.Coordinate1Getter();
                    int coordinate2 = Positioning.Coordinate2Getter();

                    bool IsAvaliable = Player1Board.CheckIfAvaliable(coordinate1, coordinate2,size, direction);
                    getchar();
                    if (IsAvaliable == true)
                    {
                        Clearing.Clear();
                        Player1Board.PlaceShip(coordinate1, coordinate2,size, direction);
                        Player1Board.displayPlayerGrid();
                        Positioning.~ships();
                    }
                    else
                    {
                        Clearing.Clear();
                        Player1Board.displayPlayerGrid();
                        std::cout << "There is ship already standing here or position you\n provided is out of bounds.Try again\n";
                        i--;
                        Positioning.~ships();
                    }
                }else {
                    Clearing.Clear();
                    Player1Board.displayPlayerGrid();
                    std::cout << "You have provided coordinates in a wrong format try again!\n";
                    i--;
                }

                if (i == rep) {
                    size++;
                    rep--;
                }

            }
        }

        Clearing.Clear();
        std::cout << "=========================================================================\n";
        std::cout << "Now it's Second player ships positioning turn, swap seats and press Enter\n";
        std::cout << "=========================================================================\n";
        getchar();
        Clearing.Clear();

        Player2Board.fillBoard();
        Player2Board.displayPlayerGrid();

        // Placing One-Masted Ships
        for (int i = 0; i <= 3; i++) {

            instructions.NMastedInstructions(i,1);

            Positioning.getShipPosition();

            Positioning.CreateCoordinates();
            if (Positioning.isCorrect()){
                Positioning.Divide();
                int coordinate1 = Positioning.Coordinate1Getter();
                int coordinate2 = Positioning.Coordinate2Getter();
                char direction = 'V';



                bool IsAvaliable = Player2Board.CheckIfAvaliable(coordinate1, coordinate2,1,direction);
                getchar();
                if (IsAvaliable == true)
                {
                    Clearing.Clear();
                    Player2Board.PlaceShip(coordinate1, coordinate2,1,direction);
                    Player2Board.displayPlayerGrid();
                    Positioning.~ships();
                }
                else
                {
                    Clearing.Clear();
                    Player2Board.displayPlayerGrid();
                    std::cout << "There is ship already standing here or position you\n provided is out of bounds.Try again\n";
                    i--;
                    Positioning.~ships();
                }

            }else {
                Clearing.Clear();
                Player2Board.displayPlayerGrid();
                std::cout << "You have provided coordinates in a wrong format try again!\n";
                i--;
            }
        }
        // Placing N-Masted Ships
        int rep2 = 2;
        int size2 = 2;
        for (int i = 0; i <= rep2+2; i++) {
            for (int i = 0; i <= rep2; i++) {

                instructions.NMastedInstructions(i,size2);

                Positioning.getShipPosition();
                Positioning.CreateCoordinates();
                if (Positioning.isCorrectNMasted()){
                    Positioning.Divide2();

                    char direction = Positioning.DirectionGetter();
                    int coordinate1 = Positioning.Coordinate1Getter();
                    int coordinate2 = Positioning.Coordinate2Getter();

                    bool IsAvaliable = Player2Board.CheckIfAvaliable(coordinate1, coordinate2,size2, direction);
                    getchar();
                    if (IsAvaliable == true)
                    {
                        Clearing.Clear();
                        Player2Board.PlaceShip(coordinate1, coordinate2,size2, direction);
                        Player2Board.displayPlayerGrid();
                        Positioning.~ships();
                    }
                    else
                    {
                        Clearing.Clear();
                        Player2Board.displayPlayerGrid();
                        std::cout << "There is ship already standing here or position you\n provided is out of bounds.Try again\n";
                        i--;
                        Positioning.~ships();
                    }
                }else {
                    Clearing.Clear();
                    Player2Board.displayPlayerGrid();
                    std::cout << "You have provided coordinates in a wrong format try again!\n";
                    i--;
                }

                if (i == rep2) {
                    size2++;
                    rep2--;
                }

            }
        }
        Clearing.Clear();

        std::cout << "===============================\n";
        std::cout << "Now it's time to begin shooting\n";
        std::cout << "===============================\n";
        getchar();
        Clearing.Clear();
bool alwaysFALSE = false;
Player1Info.additionalRoundSave(alwaysFALSE);

Player2Info.additionalRoundSave(alwaysFALSE);

        for (int rounds = 0; rounds <= rounds+1; rounds++) {
            if (Player1Info.IsMyTurnnPlayer1(rounds)) {
                
                // Player 1's turn
                std::cout <<"=============\n";
                std::cout <<"Player 1 Turn\n";
                std::cout <<"=============\n";
                Player1Board.displayPlayerGrid();
                Player1Board.displayShootingGrid();
                Player1Info.shooting();
                Player1Info.CreateCoordinatesOfShotPoint();
                if (Player1Info.isCorrectShooting()) {
                    Player1Info.Divide();

                    int coordinate1 = Player1Info.Coordinate1Getter();
                    int coordinate2 = Player1Info.Coordinate2Getter();


                    if (Player2Board.playerGrid[coordinate1][coordinate2] !='X') {
                        // Check for hit
                        if (Player2Board.CheckIfHit(coordinate1, coordinate2)) {
                            Player2Board.MarkHit(coordinate1, coordinate2);
                            Player1Board.UpdateShootingGrid(coordinate1, coordinate2, 'X');
                            std::cout << "\033[32m" << "Hit!\n"<< "\033[0m";
                            getchar();
                            getchar();
                            Clearing.Clear();
                            bool nextRound = true;
                            Player1Info.additionalRoundSave(nextRound);
                        } else {
                            bool nextRound = false;
                            Player1Info.additionalRoundSave(nextRound);
                            Player1Board.UpdateShootingGrid(coordinate1, coordinate2, '0');
                            std::cout << "\033[31m" <<  "Miss!\n" << "\033[0m";
                            getchar();
                            getchar();

                            std::cout <<"Press Enter to Swap";
                            getchar();
                            getchar();
                            Clearing.Clear();

                            std::cout <<"Press Enter when you are ready";
                            getchar();
                            getchar();
                            Clearing.Clear();
                        }

                        // Check win condition for Player 2
                        if (Player2Board.AllShipsSunk()) {
                            std::cout << "Player 1 wins!\n";
                            Player1Info.WinsAdder();
                            GameOngoing = 0; // End the game
                            std::cout << "Press Enter to continue\n";
                            getchar();
                            getchar();
                            break;
                        }
                    }else {
                        bool nextRound = false;
                            Player1Info.additionalRoundSave(nextRound);
                        std::cout << "You aimed for the same spot second time and lost your turn\n";
                            std::cout <<"Press Enter to Swap";
                            getchar();
                            getchar();
                            Clearing.Clear();

                            std::cout <<"Press Enter when you are ready";
                            getchar();
                            getchar();
                            Clearing.Clear();

                    }
                }else {
                    std::cout <<"You have provided coordinates in a wrong format. Try again!\n";
                    getchar();
                    getchar();
                    Clearing.Clear();
                }
            }
            if (Player2Info.IsMyTurnnPlayer2(rounds)){
                // Player 2's turn
                std::cout <<"=============\n";
                std::cout <<"Player 2 Turn\n";
                std::cout <<"=============\n";
                Player2Board.displayPlayerGrid();
                Player2Board.displayShootingGrid();
                Player2Info.shooting();
                Player2Info.CreateCoordinatesOfShotPoint();
                if (Player2Info.isCorrectShooting()) {
                    Player2Info.Divide();

                    int coordinate1 = Player2Info.Coordinate1Getter();
                    int coordinate2 = Player2Info.Coordinate2Getter();

                    if (Player1Board.playerGrid[coordinate1][coordinate2] != 'X') {

                        // Check for hit
                        if (Player1Board.CheckIfHit(coordinate1, coordinate2)) {
                            Player1Board.MarkHit(coordinate1, coordinate2);
                            Player2Board.UpdateShootingGrid(coordinate1, coordinate2, 'X');

                            std::cout << "\033[32m" << "Hit!\n"<< "\033[0m";
                            getchar();
                            getchar();
                            Clearing.Clear();
                            bool nextRound = true;
                            Player2Info.additionalRoundSave(nextRound);
                        } else {
                            bool nextRound = false;
                            Player2Info.additionalRoundSave(nextRound);
                            Player2Board.UpdateShootingGrid(coordinate1, coordinate2, '0');
                            std::cout <<  "\033[31m" <<  "Miss!\n" << "\033[0m";
                            getchar();
                            getchar();

                            std::cout <<"Press Enter to Swap";
                            getchar();
                            Clearing.Clear();

                            std::cout <<"Press Enter when you are ready";
                            getchar();
                            getchar();
                            Clearing.Clear();
                        }

                        // Check win condition for Player 1
                        if (Player1Board.AllShipsSunk()) {
                            Player2Info.WinsAdder();
                            std::cout << "Player 2 wins!\n";
                            GameOngoing = 0; // End the game
                            std::cout << "Press Enter to continue\n";
                            getchar();
                            getchar();
                            break;
                        }
                    }else {
                        std::cout<<"You aimed for the same spot second time and lost your turn\n";
                            
                            bool nextRound = false;
                            Player2Info.additionalRoundSave(nextRound);
                            std::cout <<"Press Enter to Swap";
                            getchar();
                            getchar();
                            Clearing.Clear();

                            std::cout <<"Press Enter when you are ready";
                            getchar();
                            getchar();
                            Clearing.Clear();

                    }
                }else {
                    std::cout <<"You have provided coordinates in a wrong format. Try again!\n";
                }

            }else{}

            if(Player1Info.additionalRoundGetter()) {
                rounds=1;
            }else{}
            if (Player2Info.additionalRoundGetter()) {
                rounds=0;
            }else {}
        }
    }
    Clearing.Clear();
    Player1Info.WinsDisplayer1();
    Player2Info.WinsDisplayer2();
getchar();
    Clearing.Clear();

    BothInfo.doYouWantToRepeat();
    bool shouldRepeat = BothInfo.repeatGetter();

    if (shouldRepeat) {}
    else {
        break;
    }

    Clearing.Clear();
    Positioning.~ships();
    instructions.~Instructions();
    Player1Board.~Board();
    Player2Board.~Board();
    Clearing.~ships();
    Greetings.~Greetings();
}

}
