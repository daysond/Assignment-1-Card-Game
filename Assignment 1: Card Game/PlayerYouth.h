//
//  YouthPlayer.h
//  Assignment 1: Card Game
//
//  Created by Yiyuan Dong on 2022-02-21.
//  Student ID: 065-182-131

#ifndef YouthPlayer_h
#define YouthPlayer_h

#include "PlayerBase.h"

template<typename T>
class PlayerYouth: public PlayerBase<T> {
    
    const int maxPoint = 10; // max point of an attack card
    
public:
    PlayerYouth() : PlayerBase<T>() {}
    
    PlayerYouth(std::string name) : PlayerBase<T>(name) {}
    
    PlayerYouth(const PlayerYouth& player) : PlayerBase<T>(player) {}
    
    PlayerYouth& operator=(const PlayerYouth& other) {
        PlayerBase<T>::operator=(other);
        return *this;
    }
    
    void addOneAttackCard() {
        
        this->attackCards.push_back(1 + (T)(rand()) / ((T)(RAND_MAX/(maxPoint - 1))));
        
    }
    

    ~PlayerYouth() { }

};

#endif /* YouthPlayer_h */
