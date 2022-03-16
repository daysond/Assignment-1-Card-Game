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
    
//    std::vector<T> attackCards;
    
public:
    
    PlayerAdult() : PlayerBase<T>()  {}
    
    PlayerAdult(std::string name) : PlayerBase<T>(name) {}
    
    PlayerAdult(const PlayerAdult& player): PlayerBase<T>(player){}
    
    PlayerAdult& operator=(PlayerAdult& other) {
        PlayerBase<T>::operator=(other);
//        attackCards = other.attackCards;
        return *this;
        
    }
    
//    bool addAttackCards(short numCards) {
//        for (int i = 0; i < numCards; ++i) {
//            addOneAttackCards();
//        }
//    }
//
//    bool addOneAttackCards() {
//        srand(unsigned(time(0))); // seeding
//        this->attackCards.push_back(T((rand()%15)+1));
//    }
//
//    T sumAttackCards() {
//        return std::accumulate(attackCards.cbegin(), attackCards.cend(), 0);
//    }
//
    ~PlayerAdult() {
        
    }
    
};


#endif /* AdultPlayer_h */
