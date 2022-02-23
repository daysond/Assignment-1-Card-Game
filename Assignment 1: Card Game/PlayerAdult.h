//
//  AdultPlayer.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-21.
//

#ifndef AdultPlayer_h
#define AdultPlayer_h

#include "PlayerBase.h"

template<typename T>
class PlayerAdult: public PlayerBase<T> {
    
    T* attachCards;
    
public:
    
    PlayerAdult() {
        
        
    }
    PlayerAdult(std::string) {
        
        
    }
    PlayerAdult(PlayerAdult&){
        
        
    }
    
    PlayerAdult& operator=(PlayerAdult&) {
        
        
    }
    
    bool addAttackCards(T*) {
        
        return true;
    }
    
    bool addOneAttackCards(T*) {
        
        return true;
    }
    
    T sumAttackCards() {
        
        
    }
    
    ~PlayerAdult() {
        
    }
    
};


#endif /* AdultPlayer_h */
