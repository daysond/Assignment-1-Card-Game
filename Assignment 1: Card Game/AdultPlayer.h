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
class AdultPlayer: public PlayerBase<T> {
    
    T* attachCards;
    
public:
    AdultPlayer();
    AdultPlayer(std::string);
    AdultPlayer(AdultPlayer&);
    
    AdultPlayer& operator=(AdultPlayer&);
    
    bool addAttackCards(T*);
    bool addOneAttackCards(T*);
    T sumAttackCards();
    
    ~AdultPlayer();
    
};


#endif /* AdultPlayer_h */
