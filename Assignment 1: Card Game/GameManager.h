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
    
    bool gameOn = true;
    void betMoney();
    void gameLogic();
    void reportPoints();
    void determineWinner();
    void reportCash(bool rounding = false);
    void updateGameState();
    void reportResult();
    
public:
    GameManager();
    void gameStart();
    bool isGameOn() { return gameOn; }
    
};

// - MARK: HELPER FUNCTIONS
short GetShort();
bool GetBoolFromYN();
#endif /* PlayerManager_h */
