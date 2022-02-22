//
//  Player.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-21.
//

#ifndef Player_h
#define Player_h

#include <iostream>

enum GameMode {
    regular = 0,
    highDefinition = 1
};

template<typename T>
class PlayerBase {
    
    std::string name;
    double cash;
    int *cards; // list of dependent cards of value 1-5
    
public:
    PlayerBase();
    PlayerBase(std::string);
    PlayerBase(PlayerBase&);
    
    virtual PlayerBase& operator=(PlayerBase&);
    
    bool setName(std::string);
    std::string getName();
    
    bool addDependentCards(int*);
    bool addOneDependentCard(int&);
    int sumDependentCards();
    bool addCash(double);
    
    bool operator==(PlayerBase&);
    bool operator>(PlayerBase&);
    bool operator<(PlayerBase&);
    
    void operator>>(double);
    void operator<<(double);
  
    ~PlayerBase();
};

#endif /* Player_h */
