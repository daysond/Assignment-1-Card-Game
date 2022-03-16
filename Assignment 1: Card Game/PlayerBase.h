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
    
public:
    
    PlayerBase() : cash(1000) {}
    
    PlayerBase(std::string name) : name(name), cash(1000) {}
    
    PlayerBase(const PlayerBase& player) {
        *this = player;
    }
    
    virtual PlayerBase& operator=(const PlayerBase& player) {
        this->name = player.name;
        this->cash = player.cash;
        this->dependentCards = player.dependentCards;
        this->attackCards = player.attackCards;
        return *this;
    }
    
    void setName(std::string name) {
        this->name = name;
    }
    
    std::string getName() { return name; }
    
    void addDependentCards(short numCards) {
//        srand(unsigned(time(0)));
        for (int i = 0; i < numCards; i++) {
            addOneDependentCard();
        }
//        std::cout<< "D cards for " << name << " ";
//        for (int i = 0; i < numCards; ++i) {
//            std::cout<< dependentCards.at(i) << " ";
//        }
//        std::cout << std::endl;
    }
    
    void addOneDependentCard() {
        this->dependentCards.push_back((rand()%5)+1);
    }
    
    void addAttackCards(short numCards){
//        srand(unsigned(time(0)));
        for (int i = 0; i < numCards; ++i) {
            addOneAttackCards();
        }
        
        std::cout<< "A cards for " << name << " ";
        for (int i = 0; i < numCards; ++i) {
            std::cout<< attackCards.at(i) << " ";
        }

        std::cout << std::endl;
    }
    
    virtual void addOneAttackCards() {
        this->attackCards.push_back(1 + (T)(rand()) / ((T)(RAND_MAX/(15 - 1))));
//        this->attackCards.push_back((T)(rand()%15)+1);
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
    
    void addCash(double cash) { this->cash+=cash; }
    
    bool hasGoneOverLimit(const int& max){  return sumAllCards() > max; }
    
    void clearCards() {
        dependentCards.clear();
        attackCards.clear();
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
    
    void operator>>(double cash){   this->cash += cash; }
    void operator<<(double cash){   this->cash -= cash; }
  
    ~PlayerBase() {}
    
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
