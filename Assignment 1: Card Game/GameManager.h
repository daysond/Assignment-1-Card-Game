//
//  PlayerManager.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-22.
//

#ifndef PlayerManager_h
#define PlayerManager_h

#include <iostream>
#include "PlayerYouth.h"
#include "PlayerAdult.h"

class GameManager {
  
    const int MAX = 21;
    static const int NUM = 2;
    double bet = 0;
//    PlayerBase<int>* player[NUM];
    PlayerBase<double> *player[NUM];
    
    bool gameOver = false;
public:
    GameManager();
    
    bool gameOn() {return !gameOver; }
    void endGame() { gameOver = true;}
    
    void betMoney();
    void gameStart();
    void reportPoints();
    void determineWinner();
    void reportCash();
    void shouldEndGame();
    void reportResult();
};

short GetShort();
bool GetBoolFromYN();
#endif /* PlayerManager_h */
