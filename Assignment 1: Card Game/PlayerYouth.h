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
class PlayerYouth: public PlayerBase {
    
    std::vector<T> attackCards;
    
public:
    PlayerYouth() {
        
    }
    PlayerYouth(std::string) {
        
    }
    PlayerYouth(PlayerYouth&) {
        
    }
    
    PlayerYouth& operator=(PlayerYouth&) {
        
    }
    
    bool addAttackCards(T*){
        return true;
    }
    
    bool addOneAttackCards(T*) {
        return true;
    }
    
    T sumAttackCards() {
        
        return static_cast<T>(3);
    }
    
    ~PlayerYouth() {
        
    }
    
};

#endif /* YouthPlayer_h */
