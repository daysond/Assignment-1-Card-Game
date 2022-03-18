//
//  GameManagerAdapter.cpp
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-03-18.
//

#include "GameManager.h"

GameManagerAdapter* gameManager() {
    
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
