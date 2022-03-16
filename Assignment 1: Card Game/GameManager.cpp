//
//  PlayerManager.cpp
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-22.
//

#include "GameManager.h"
#include <iomanip>
using namespace std;

GameManager::GameManager() {

    player[0] = new PlayerYouth<double>("Noah");
    player[1] = new PlayerAdult<double>("Kenneth");
    
    //    player[0] = new PlayerYouth<int>("Noah");
    //    player[1] = new PlayerAdult<int>("Kenneth");

}

void GameManager::gameStart() {
    
    do {

        betMoney();
        gameLogic();
        reportPoints();
        determineWinner();
        reportCash();
        updateGameState();
        
    } while (isGameOn());

    reportResult();

}

void GameManager::betMoney() {
    
    cout <<  "How much do you both want to bet? (min$10, max $300): ";
    
    while(!(cin >> bet)) {
        
        cout << endl << "Invalid number. How much do you both want to bet? (min$10, max $300): ";
        
        cin.clear();
        
        cin.ignore(1000, '\n');
    }

//    if(bet > 300) bet = 300;
    if(bet < 10) bet = 10;
    
    
}
void GameManager::gameLogic() {
    
    for(PlayerBase<double> *p: player ) {
        
        auto sumCards = [](PlayerBase<double>* player) {
            cout<< player->getName() << ", the sum of your cards is " << player->sumAllCards() << endl;
        };
        
        cout<<endl<< p->getName() << ", how many dependent cards to you want? ";
        p->addDependentCards(GetShort());
        cout<< p->getName() << ", how many attack cards to you want? ";
        p->addAttackCards(GetShort());
        sumCards(p);
        cout<< "Do you want to add a dependent card? [Y,N] ";
        if(GetBoolFromYN()) p->addOneDependentCard();
        sumCards(p);
        cout<< "Do you want to add a attack card? [Y,N] ";
        if(GetBoolFromYN()) p->addOneAttackCards();
        sumCards(p);
        cout << endl;
        
    }
}

void GameManager::reportPoints(){
    //Report the name and points for each player
    for(PlayerBase<double> *p: player )
        cout<< p->getName() << " has " << p->sumAllCards() << " points." << endl;
    
    cout<<endl;
}
void GameManager::determineWinner(){
    
    if (*player[0] == *player[1]) {
        //tie game, same points
        cout<<"Both players have the same points. There's no winner." << endl;
        
    } else if (player[0]->hasGoneOverLimit(MAX) && player[1]->hasGoneOverLimit(MAX)) {
        //both disqualified
        for(PlayerBase<double> *p: player ) {
            cout<< p->getName() << " has a sum of " << p->sumAllCards() << ", which is over the limit." << endl;
        }
        cout<<"Both players are over the limit and have been disqualified. " << endl;
        
    } else {
       
        short winnerIndex; // either 0 or 1, can be altered with ! operator.
        //both player has less than 21 points
        if(player[0]->sumAllCards() <= MAX && player[1]->sumAllCards() <= MAX) {
   
            winnerIndex = player[0]->sumAllCards() > player[1]->sumAllCards() ? 0 : 1;
            
            cout << player[winnerIndex]->getName()<< " has won!" << endl;
            
        } else { // one plaer has gone over limit, which means player with less point wins
            winnerIndex = player[0]->sumAllCards() < player[1]->sumAllCards() ? 0 : 1;
            
            cout<< player[!winnerIndex]->getName() << " has a sum of "<< player[!winnerIndex]->sumAllCards() <<", which is over the limit." << endl;
            cout<< player[!winnerIndex]->getName() << " has been disqualified for going over the limit. "<< player[winnerIndex]->getName() << " has won." << endl;
        }
        
        *player[winnerIndex] >> bet; // adds cash
        *player[!winnerIndex] << bet; // remove cash
        
    }
    
    cout << endl;
}

void GameManager::reportCash(bool rounding){
    //Report the name and cash for each
    for(PlayerBase<double> *p: player ) {
        p->clearCards();
        if (rounding) cout << fixed << setprecision(2);
        cout<< p->getName() << " has $" << p->getCash() << "." << endl;
    }
    cout<<endl;
}

void GameManager::updateGameState(){

    gameOn = player[0]->getCash() > 0 && player[1]->getCash() > 0;
}

void GameManager::reportResult(){
    // Be sure to print the cash to two decimal places.
    cout<<"The game is over." << endl;
    reportCash(true);
}

// - MARK: HELPER FUNCTIONS

//validate if the user has input an integer
short GetShort() {
    
    short num;
    
    while(!(cin >> num)) {
        
        cout << "Invalid number. Please enter an INTEGER: ";
        
        cin.clear();
            cin.ignore(1000, '\n');
    }
    
    cin.clear();
    cin.ignore(1000, '\n');
    
    return num;
    
}

//ask user to input [y/n] and returns true or false base on the input
bool GetBoolFromYN() {
    
    string str;
    
    while(true) {
        
        getline(cin, str);
        
        if(str == "y" || str == "Y")  return true;
        
        else if(str == "n" || str == "N")  return false;
        
        else cout << "Invalid input. Try again: [Y/N] ";
        
    }
    
}
