//
//  Player.h
//  Assignment 1: Card Game
//
//  Created by Yiyuan Dong on 2022-02-21.
//  Student ID: 065-182-131

#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <numeric>

template<typename T>
class PlayerBase {
    
protected:
    
    std::string name;
    double cash;
    const int maxPoint = 15;
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
    
    void setName(std::string name) { this->name = name; }
    
    std::string getName() const { return name; }
    
    void addCash(double cash) { this->cash+=cash; }
    
    double getCash() const { return this->cash; }

    void addOneDependentCard() {
        
        this->dependentCards.push_back((rand()%5)+1);
        
    }
    
    void addDependentCards(short numCards) {

        for (int i = 0; i < numCards; i++)  addOneDependentCard();
        
    }
    
    virtual void addOneAttackCard() {
        
        this->attackCards.push_back(1 + (T)(rand()) / ((T)(RAND_MAX/(maxPoint - 1))));
        
    }
    
    void addAttackCards(short numCards){
       
        for (int i = 0; i < numCards; ++i)  addOneAttackCard();
        
    }
    
    int sumDependentCards() const {
        
        return std::accumulate(dependentCards.cbegin(), dependentCards.cend(), 0);
        
    }
    
    T sumAttackCards() const {
        
        return std::accumulate(attackCards.cbegin(), attackCards.cend(), T(0));
        
    }
    
    T sumAllCards() const {
        
        return T(sumAttackCards() - sumDependentCards());
        
    }
    
    bool isOverLimit(const int& max) const {  return sumAllCards() > max; }
    
    void clearCards() {
        dependentCards.clear();
        attackCards.clear();
    }
    
    bool operator==(const PlayerBase& other) const {
        return this->sumAllCards() == other.sumAllCards();
    }
    bool operator>(const PlayerBase& other) const{
        return this->sumAllCards() > other.sumAllCards();
    }
    bool operator<(const PlayerBase& other) const{
        return this->sumAllCards() < other.sumAllCards();
    }
    
    void operator>>(double cash){ this->cash += cash; }
    void operator<<(double cash){ this->cash -= cash; }
  
    ~PlayerBase() {}
    
};



#endif /* Player_h */

