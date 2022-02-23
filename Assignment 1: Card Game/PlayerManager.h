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

class PlayerManager {
  
    const int MAX = 21;
    static const int NUM = 2;
    
//    PlayerBase<int>* player[NUM];
    PlayerBase<double>* player[NUM];
    
    bool gameOver;

    PlayerManager();
    
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

#endif /* PlayerManager_h */
