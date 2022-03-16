//PlayerMain.cpp - main program for the card player

#include<iostream>
#include "PlayerYouth.h"
#include "PlayerAdult.h"
#include "GameManager.h"

using namespace std;

int main(void) {

    GameManager gameManager = GameManager();

    gameManager.gameStart();

    return 0;
}
