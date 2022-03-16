//PlayerMain.cpp - main program for the card player

#include<iostream>
#include "PlayerYouth.h"
#include "PlayerAdult.h"
#include "GameManager.h"

using namespace std;

int main(void) {

    GameManager gameManager = GameManager();

//    const int MAX = 21;
//    const int NUM = 2;
//    PlayerBase<int>* player[NUM];
//    player[0] = new PlayerYouth<int>("Noah");
//    player[1] = new PlayerAdult<int>("Kenneth");
//    PlayerBase<double>* player[NUM];
//    player[0] = new PlayerYouth<double>("Noah");
//    player[1] = new PlayerAdult<double>("Kenneth");

//    bool gameOver = false;
    do {

        gameManager.betMoney();

        cout << endl;
//        for (int i = 0; i < NUM; ++i) {
        gameManager.gameStart();
//            playerManager.g
        cout << endl;
//        }

        //reportPoints
        gameManager.reportPoints();

        cout << endl;

        //Determine a winner
        gameManager.determineWinner();

        cout << endl;

        //Report the name and cash for each
        gameManager.reportCash();
        cout << endl;

        gameManager.shouldEndGame();

    } while (!gameManager.gameOn());
//
    cout << "The game is over." << endl;

    // reportResult

    return 0;
}
