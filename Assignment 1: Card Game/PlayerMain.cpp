//PlayerMain.cpp - main program for the card player

#include<iostream>
#include "GameManagerAdapter.h"

using namespace std;

int main(void) {
    
    GameManagerAdapter* gm = gameManager();

    gm->gameStart();

    delete gm;

    return 0;
}
