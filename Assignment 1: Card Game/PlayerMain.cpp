//PlayerMain.cpp - main program for the card player
//  Modified by Yiyuan Dong 2022-03-18.
//  Student ID: 065-182-131

#include<iostream>
#include "GameManagerAdapter.h"

using namespace std;

int main(void) {
    
    GameManagerAdapter* gameManager = CreateGame();

    gameManager->gameStart();

    delete gameManager;

    return 0;
}
