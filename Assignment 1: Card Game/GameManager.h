//
//  GameManager.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-22.
//

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
    
    const int MAX = 21;
    static const int NUM = 2;
    double bet = 0;
    bool gameOn = true;
    GameMode mode;
    PlayerBase<T>* player[NUM];
    
    void setMode(GameMode mode) {
        this->mode = mode;
    }
    
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
    void gameLogic() {
        
        for(PlayerBase<T> *p: player ) {
            
            auto sumCards = [this](PlayerBase<T>* player) {
                std::cout << std::fixed << std::setprecision(this->mode) << player->getName() << ", the sum of your cards is " << player->sumAllCards() << std::endl;
            };
            
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
        //Report the name and points for each player
        for(PlayerBase<T> *p: player )
            std::cout << std::fixed << std::setprecision(this->mode) << p->getName() << " has " << p->sumAllCards() << " points." << std::endl;
        
        std::cout<<std::endl;
    }
    
    void determineWinner() const {
        
        if (*player[0] == *player[1]) {
            //tie game, same points
            std::cout<<"Both players have the same points. There's no winner." << std::endl;
            
        } else if (player[0]->hasGoneOverLimit(MAX) && player[1]->hasGoneOverLimit(MAX)) {
            //both player gone over limit, both disqualified
            for(PlayerBase<T> *p: player ) {
                std::cout << std::fixed << std::setprecision(this->mode)
                << p->getName() << " has a sum of " << p->sumAllCards() << ", which is over the limit." << std::endl;
            }
            std::cout<<"Both players are over the limit and have been disqualified. " << std::endl;
            
        } else {
            
            short winnerIndex; // either 0 or 1, can be altered with ! operator.
            
            //both player has less than 21 points
            if(player[0]->sumAllCards() <= MAX && player[1]->sumAllCards() <= MAX) {
                
                winnerIndex = player[0]->sumAllCards() > player[1]->sumAllCards() ? 0 : 1;
                
                std::cout << player[winnerIndex]->getName()<< " has won!" << std::endl;
                
            } else { // one player has gone over limit, which means player with less point wins
                
                winnerIndex = player[0]->sumAllCards() < player[1]->sumAllCards() ? 0 : 1;
                
                std::cout<< std::fixed << std::setprecision(this->mode) << player[!winnerIndex]->getName() << " has a sum of "<< player[!winnerIndex]->sumAllCards() <<", which is over the limit." << std::endl;
                
                std::cout<< player[!winnerIndex]->getName() << " has been disqualified for going over the limit. "<< player[winnerIndex]->getName() << " has won." << std::endl;
            }
            
            *player[winnerIndex] >> bet; // adds cash
            *player[!winnerIndex] << bet; // remove cash
            
        }
        
        std::cout << std::endl;
    }
    
    void reportCash(bool rounding = false) const {
        //Report the name and cash for each
        for(PlayerBase<T> *p: player ) {
            p->clearCards(); // delete cards, start anew.
            if (rounding) std::cout << std::fixed << std::setprecision(2);
            std::cout<< p->getName() << " has $" << p->getCash() << "." << std::endl;
        }
        std::cout<<std::endl;
    }
    
    void updateGameState() {
        gameOn = player[0]->getCash() > 0 && player[1]->getCash() > 0;
    }
    
    void reportResult() const {
        std::cout<<"The game is over." << std::endl;
        reportCash(true); // round to 2 decimals
    }
    
public:
    
    GameManager(){
        player[0] = new PlayerYouth<T>("Noah");
        player[1] = new PlayerAdult<T>("Kenneth");
        
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
        for(PlayerBase<T> *p: player) {
            delete p;
            p = nullptr;
        }
    }

};

// - MARK: HELPER FUNCTIONS

GameManagerAdapter* gameManager() {
    
    std::cout << "Would you like to play in High-Definition Mode? [Y/N]: ";
    GameMode mode = GetBoolFromYN() ? HD : Regular;
    std::cout << std::endl;
    
    GameManagerAdapter*  gm;
    
    if(mode == HD)
        gm = new GameManager<double>();
    else
        gm = new GameManager<int>();
    
    gm->setMode(mode);
    
    return gm;
}



#endif /* PlayerManager_h */
