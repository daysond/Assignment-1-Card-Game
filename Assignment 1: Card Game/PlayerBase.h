//
//  Player.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-21.
//

#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
//template<typename T>
class PlayerBase {
    
protected:
    std::string name;
    double cash;
    std::vector<int> dependentCards; // list of dependent cards of value 1-5
    int numDependentCards = 0;
    int numAttackCards = 0;
    
public:
    PlayerBase() {
        cash = 1000;
    }
    
    PlayerBase(std::string name) {
        this->name = name;
    }
    
    PlayerBase(PlayerBase& player) {
        *this = player;
        
    }
    
    virtual PlayerBase& operator=(PlayerBase& player) {
        this->name = player.name;
        this->cash = player.cash;
        this->numDependentCards = player.numDependentCards;
        this->numAttackCards = player.numAttackCards;
        this->dependentCards = player.dependentCards;
        return *this;
    }
    
    void setName(std::string name) {
        this->name = name;
    }
    
    std::string getName() {
        return name;
    }
    
    bool addDependentCards(short numCards) {
        
//        bool ret = false;
        
//        this->numDependentCards = numCards;
//
//        if (dependentCards != nullptr) {
//            delete [] dependentCards;
//            dependentCards = nullptr;
//        }
//
//        srand(unsigned(time(0))); // seeding
//
//        this->dependentCards = new int[numCards];
//
//        for (int i = 0; i < numCards; i++) {
//            this->dependentCards[i] = (rand()%5)+1;
//        }
        return true;
    }
    bool addOneDependentCard(int&) {
        return true;
    }
    int sumDependentCards() {
        return 1;
    }
    bool addCash(double) {
        return true;
    }
    
    bool operator==(PlayerBase&) {
        return true;
    }
    bool operator>(PlayerBase&){
        return true;
    }
    bool operator<(PlayerBase&){
        return true;
    }
    
    void operator>>(double){
        
    }
    void operator<<(double){
        
    }
  
    ~PlayerBase() {
        
    }
};

#endif /* Player_h */

//PlayerBase();
//PlayerBase(std::string);
//PlayerBase(PlayerBase&);
//
//virtual PlayerBase& operator=(PlayerBase&);
//
//bool setName(std::string);
//std::string getName();
//
//bool addDependentCards(int*);
//bool addOneDependentCard(int&);
//int sumDependentCards();
//bool addCash(double);
//
//bool operator==(PlayerBase&);
//bool operator>(PlayerBase&);
//bool operator<(PlayerBase&);
//
//void operator>>(double);
//void operator<<(double);
//
//~PlayerBase();
