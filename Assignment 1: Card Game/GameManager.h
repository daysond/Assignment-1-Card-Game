//
//  GameManager.h
//  Assignment 1: Card Game
//
//  Created by Yiyuan Dong on 2022-02-22.
//  Student ID: 065-182-131

#ifndef PlayerManager_h
#define PlayerManager_h

#include <iostream>
#include <iomanip>
#include "HelperFunctions.h"
#include "GameManagerAdapter.h"
#include "PlayerYouth.h"
#include "PlayerAdult.h"


template<typename T>
class GameManager: public GameManagerAdapter {
    
    const int MAX = 21; // max point
    static const int NUM = 2; // num of players
    double bet = 0;
    bool gameOn = true;
    GameMode mode;
    PlayerBase<T>** player;
    int numPlayer = 0;
//    std::vector<PlayerBase<T>*> players;
    
public:
    
    GameManager(){
        
        numPlayer = GetShort();
        player = new PlayerBase<T>*[numPlayer]();
        std::string name = "";
        for(int i = 0; i < numPlayer; i++) {
            std::cout << "Enter the name: ";
            std::getline(std::cin, name);
            std::cout << "Are you youth? [Y/N]: ";
            
            PlayerBase<T>* p = CreatePlayer(GetBoolFromYN(), name);
            player[i] = p;
            
//            players.push_back( CreatePlayer(GetBoolFromYN(), name));
        }
        
        
//        player[0] = new PlayerYouth<T>("Noah");
//        player[1] = new PlayerAdult<T>("Kenneth");
    }
    
    
    PlayerBase<T>* CreatePlayer(bool youth, std::string name) {

        
            return youth ? PlayerYouth<T>(name) : PlayerAdult<T>(name);
      
        
    }
    
    //game procedure
    void gameStart() {
        
        do {
            
            betMoney();
            gameLogic();
            reportPoints();
            determineWinner();
            reportCash();
            updateGameState();
            
        } while (gameOn);
        
        reportResult();
        
    }
    
    ~GameManager() {
        
        for(int i = 0; i < numPlayer; i++) {
            
            delete player[i];
            
        }
        
        delete player;
        
//        for(PlayerBase<T> *p: player) {
//            delete p;
//            p = nullptr;
//        }
    }
    
private:
    
    void setMode(GameMode mode) { this->mode = mode; }
    
    void betMoney() {
        
        std::cout <<  "How much do you both want to bet? (min$10, max $300): ";
        
        while(!(std::cin >> bet)) {
            
            std::cout << std::endl << "Invalid number. How much do you both want to bet? (min$10, max $300): ";
            
            std::cin.clear();
            
            std::cin.ignore(1000, '\n');
        }
        
        if(bet > 300) bet = 300;
        if(bet < 10) bet = 10;
        
    }
    
    void gameLogic() const {
        
        auto sumCards = [this](PlayerBase<T>* player) {
            std::cout << std::fixed << std::setprecision(this->mode) << player->getName() << ", the sum of your cards is " << player->sumAllCards() << std::endl;
        };
        
//        for(PlayerBase<T> *p: player ) {
        for(int i = 0; i < numPlayer; i++) {
            
            PlayerBase<T>* p = player[i];
            
            std::cout<<std::endl<< p->getName() << ", how many dependent cards to you want? ";
            p->addDependentCards(GetShort());
            
            std::cout<< p->getName() << ", how many attack cards to you want? ";
            p->addAttackCards(GetShort());
            sumCards(p);
            
            std::cout<< "Do you want to add a dependent card? [Y,N] ";
            if(GetBoolFromYN()) p->addOneDependentCard();
            sumCards(p);
            
            std::cout<< "Do you want to add a attack card? [Y,N] ";
            if(GetBoolFromYN()) p->addOneAttackCard();
            sumCards(p);
            
            std::cout << std::endl;
            
        }
    }
    
    void reportPoints() const {
    
//        for(PlayerBase<T> *p: player )
        for(int i = 0; i < numPlayer; i++) {
            
            PlayerBase<T>* p = player[i];
            std::cout << std::fixed << std::setprecision(this->mode) << p->getName() << " has " << p->sumAllCards() << " points." << std::endl;
        }
        std::cout<<std::endl;
    }
    
    void determineWinner() const {
        
        if (*player[0] == *player[1]) {
            //Tie game, same points
            std::cout<<"Both players have the same points. There's no winner." << std::endl;
            
        } else if (player[0]->isOverLimit(MAX) && player[1]->isOverLimit(MAX)) {
            //Both player gone over limit, both disqualified
//            for(PlayerBase<T> *p: player ) {
            for(int i = 0; i < numPlayer; i++) {
                
                PlayerBase<T>* p = player[i];
                std::cout << std::fixed << std::setprecision(this->mode) //value of mode is precision of decimal places
                << p->getName() << " has a sum of " << p->sumAllCards() << ", which is over the limit." << std::endl;
            }
            std::cout<<"Both players are over the limit and have been disqualified. " << std::endl;
            
        } else {
            
            short winnerIndex; // either 0 or 1, can be altered with ! operator.
            
            //Both player has less than 21 points
            if(player[0]->sumAllCards() <= MAX && player[1]->sumAllCards() <= MAX) {
                
                winnerIndex = player[0]->sumAllCards() > player[1]->sumAllCards() ? 0 : 1;
                
                std::cout << player[winnerIndex]->getName()<< " has won!" << std::endl;
                
            } else { // One player has gone over limit, which means player with less point wins
                
                winnerIndex = player[0]->sumAllCards() < player[1]->sumAllCards() ? 0 : 1;
                
                std::cout<< std::fixed << std::setprecision(this->mode) << player[!winnerIndex]->getName() << " has a sum of "<< player[!winnerIndex]->sumAllCards() <<", which is over the limit." << std::endl;
                
                std::cout<< player[!winnerIndex]->getName() << " has been disqualified for going over the limit. "<< player[winnerIndex]->getName() << " has won." << std::endl;
            }
            
            *player[winnerIndex] >> bet; // add cash
            *player[!winnerIndex] << bet; // remove cash
            
        }
        
        std::cout << std::endl;
    }
    
    //Rounding: if true, round to 2 decimal places, used in final report
    void reportCash(bool rounding = false) const {
        
//        for(PlayerBase<T> *p: player ) {
        for(int i = 0; i < numPlayer; i++) {
            
            PlayerBase<T>* p = player[i];
            
            p->clearCards(); // delete cards, start a new round
            
            if (rounding) std::cout << std::fixed << std::setprecision(2);
            
            std::cout<< p->getName() << " has $" << p->getCash() << "." << std::endl;
            
        }
        std::cout<<std::endl;
    }
    
    //Checks if game is over (either player is out of cash)
    void updateGameState() {
        gameOn = player[0]->getCash() > 0 && player[1]->getCash() > 0;
    }
    
    void reportResult() const {
        std::cout<<"The game is over." << std::endl;
        reportCash(true); // round to 2 decimals
    }
    
};


#endif /* PlayerManager_h */
