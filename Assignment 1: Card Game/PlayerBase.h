//
//  Player.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-21.
//

#ifndef Player_h
#define Player_h

#include <iostream>

template<typename T>
class PlayerBase {
    
    std::string name;
    double cash;
    int *cards; // list of dependent cards of value 1-5
    
public:
    PlayerBase() {
        
    }
    PlayerBase(std::string) {
        
    }
    PlayerBase(PlayerBase&) {
        
    }
    
    virtual PlayerBase& operator=(PlayerBase&) {
        
        return *this;
    }
    
    bool setName(std::string) {
        
    }
    std::string getName() {
        
    }
    
    bool addDependentCards(int*) {
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
