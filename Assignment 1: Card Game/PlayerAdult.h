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
    
    
public:
    
    PlayerAdult() : PlayerBase<T>()  {}
    
    PlayerAdult(std::string name) : PlayerBase<T>(name) {}
    
    PlayerAdult(const PlayerAdult& player): PlayerBase<T>(player){}
    
    PlayerAdult& operator=(PlayerAdult& other) {
        PlayerBase<T>::operator=(other);
        return *this;
    }
    
    ~PlayerAdult() { }
    
};


#endif /* AdultPlayer_h */
