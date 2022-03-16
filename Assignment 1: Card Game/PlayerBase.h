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
#include <numeric>
#include <time.h>
template<typename T>
class PlayerBase {
    
protected:
    std::string name;
    double cash;
    std::vector<int> dependentCards; // list of dependent cards of value 1-5
    std::vector<T> attackCards;      // 1-10, or 1-15 adult HD mode 3 decimal
    int numDependentCards = 0;
    int numAttackCards = 0;
    
public:
    PlayerBase() {
        cash = 1000;
    }
    
    PlayerBase(std::string name) {
        this->name = name;
        cash = 1000;
    }
    
    PlayerBase(const PlayerBase& player) {
        *this = player;
    }
    
    virtual PlayerBase& operator=(const PlayerBase& player) {
        this->name = player.name;
        this->cash = player.cash;
        this->numDependentCards = player.numDependentCards;
        this->numAttackCards = player.numAttackCards;
        this->dependentCards = player.dependentCards;
        this->attackCards = player.attackCards;
        return *this;
    }
    
    void setName(std::string name) {
        this->name = name;
    }
    
    std::string getName() {
        return name;
    }
    
    void addDependentCards(short numCards) {

        for (int i = 0; i < numCards; i++) {
            addOneDependentCard();
        }
        std::cout<< "D cards for" << name << " ";
        for (int i = 0; i < numCards; ++i) {
            std::cout<< dependentCards.at(i) << " ";
        }
        
    }
    
    void addOneDependentCard() {
        
//        srand(unsigned(time(0))); // seeding
        this->dependentCards.push_back((rand()%5)+1);
        ++numDependentCards;
    }
    
    void addAttackCards(short numCards){
        for (int i = 0; i < numCards; ++i) {
            addOneAttackCards();
        }
        
        std::cout<< "A cards for" << name << " ";
        for (int i = 0; i < numCards; ++i) {
            std::cout<< attackCards.at(i) << " ";
        }
        
        std::cout << std::endl;
    }
    virtual void addOneAttackCards() {
        srand(unsigned(time(0))); // seeding
        this->attackCards.push_back(T(rand()%15)+1);
        ++numAttackCards;
    }
    
    int sumDependentCards() {
        return std::accumulate(dependentCards.cbegin(), dependentCards.cend(), 0);
    }
    
    T sumAttackCards() {
        return std::accumulate(attackCards.cbegin(), attackCards.cend(), 0);
//        return static_cast<T>(3);
    }
    
    T sumAllCards() {
        return T(sumAttackCards() - sumDependentCards());
    }
    
    double getCash() { return this->cash; }
    
    void addCash(double cash) {
        this->cash+=cash;
    }
    
    bool hasGoneOver(const int& max){
        return sumAllCards() > max;
    }
    
    bool operator==(PlayerBase& other) {
        return this->sumAllCards() == other.sumAllCards();
    }
    bool operator>(PlayerBase& other){
        return this->sumAllCards() > other.sumAllCards();
    }
    bool operator<(PlayerBase& other){
        return this->sumAllCards() < other.sumAllCards();
    }
    
    void operator>>(double cash){
        this->cash += cash;
    }
    void operator<<(double cash){
        this->cash -= cash;
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
