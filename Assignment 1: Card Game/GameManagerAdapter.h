//
//  GameManagerAdapter.h
//  Assignment 1: Card Game
//
//  Created by Yiyuan Dong on 2022-03-18.
//  Student ID: 065-182-131

#ifndef GameManagerAdapter_h
#define GameManagerAdapter_h

//GameMode, int value is the number of decimal that the program should display.
enum GameMode {
    Regular = 0,
    HD = 3,
};

//Interface for GameManager class, the purpose is to allow the user to choose game mode during run time.
class GameManagerAdapter {
public:
    virtual void gameStart() = 0;
    virtual void setMode(GameMode) = 0;
    virtual ~GameManagerAdapter() {};
};

GameManagerAdapter* CreateGame();


#endif /* GameManagerAdapter_h */
