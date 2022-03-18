//
//  GameManagerAdapter.hpp
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-03-18.
//

#ifndef GameManagerAdapter_h
#define GameManagerAdapter_h

//GameMode, int value is the number of decimal that the program should display.
enum GameMode {
    Regular = 0,
    HD = 3,
};

class GameManagerAdapter {
public:
    virtual void gameStart() = 0;
    virtual void setMode(GameMode) = 0;
    virtual ~GameManagerAdapter() {};
};

GameManagerAdapter* gameManager();


#endif /* GameManagerAdapter_h */
