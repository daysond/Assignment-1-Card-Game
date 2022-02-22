//
//  YouthPlayer.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-21.
//

#ifndef YouthPlayer_h
#define YouthPlayer_h

#include "PlayerBase.h"

template<typename T>
class YouthPlayer: public PlayerBase<T> {
    
    T* attachCards;
    
public:
    YouthPlayer();
    YouthPlayer(std::string);
    YouthPlayer(YouthPlayer&);
    
    YouthPlayer& operator=(YouthPlayer&);
    
    bool addAttackCards(T*);
    bool addOneAttackCards(T*);
    T sumAttackCards();
    
    ~YouthPlayer();
    
};

#endif /* YouthPlayer_h */
