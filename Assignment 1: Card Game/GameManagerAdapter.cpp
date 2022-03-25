//
//  GameManagerAdapter.cpp
//  Assignment 1: Card Game
//
//  Created by Yiyuan Dong on 2022-03-18.
//  Student ID: 065-182-131


#include "GameManager.h"

GameManagerAdapter* CreateGame() {
    
    std::cout << "Would you like to play in High-Definition Mode? [Y/N]: ";
    GameMode mode = GetBoolFromYN() ? HD : Regular;
    std::cout << std::endl;
    
    GameManagerAdapter*  gm;
    
    if(mode == HD)
        gm = new GameManager<double>();
    else
        gm = new GameManager<int>();
    
    gm->setMode(mode);
    
    
    return gm;
}

