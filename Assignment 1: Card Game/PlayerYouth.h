//
//  YouthPlayer.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-21.
//

#ifndef YouthPlayer_h
#define YouthPlayer_h

#include "PlayerBase.h"
#include <vector>

template<typename T>
class PlayerYouth: public PlayerBase<T> {
    

//    
public:
    PlayerYouth() : PlayerBase<T>() {}
    
    PlayerYouth(std::string name) : PlayerBase<T>(name) {}
    
    PlayerYouth(const PlayerYouth& player) : PlayerBase<T>(player) {}
    
    PlayerYouth& operator=(const PlayerYouth& other) {
        PlayerBase<T>::operator=(other);
        return *this;
    }
    
    void addOneAttackCards() {
        srand(unsigned(time(0))); // seeding
        this->attackCards.push_back(T((rand()%10)+1));
    }
    

    ~PlayerYouth() {
        
    }
    
};

#endif /* YouthPlayer_h */
