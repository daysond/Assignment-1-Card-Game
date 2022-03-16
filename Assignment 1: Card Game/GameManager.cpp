//
//  PlayerManager.cpp
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-22.
//

#include "GameManager.h"

using namespace std;

GameManager::GameManager() {

    player[0] = new PlayerYouth<double>("Noah");
    player[1] = new PlayerAdult<double>("Kenneth");
    
    //    player[0] = new PlayerYouth<int>("Noah");
    //    player[1] = new PlayerAdult<int>("Kenneth");
    
    gameOver = false;
}

//bool gameOn() {return !gameOver; }
//void endGame() { gameOver = true;}

void GameManager::betMoney() {
    
    cout <<  "How much do you both want to bet? (min$10, max $300): ";
    
    while(!(cin >> bet)) {
        
        cout << "Invalid number."<<endl << "How much do you both want to bet? (min$10, max $300): ";
        
        cin.clear();
        
        cin.ignore(1000, '\n');
    }

    if(bet > 300) bet = 300;
    if(bet < 10) bet = 10;
    
    
}
void GameManager::gameStart() {
    
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
        
        
    }
    // Prompt the player for the number of dependent cards

    // Prompt the player for the number of attack cards

    // Report the player's name and the sum of the player's cards

    // Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards

    // Report the player's name and the sum of the player's cards

    // Ask the player if (s)he wishes to add an attack card to the existing list of attack cards

    // Report the player's name and the sum of the player's cards
    
}
void GameManager::reportPoints(){
    //Report the name and points for each player
    for(PlayerBase<double> *p: player )
        cout<< p->getName() << " has " << p->sumAllCards() << " points." << endl;
    
}
void GameManager::determineWinner(){
    
    if (*player[0] == *player[1]) {
        //tie game, same points
        cout<<" Both players have the same points. There's no winner." << endl;
        
    } else if (player[0]->hasGoneOver(MAX) && player[1]->hasGoneOver(MAX)) {
        //both disqualified
        for(PlayerBase<double> *p: player ) {
            cout<< p->getName() << " has a sum of " << p->sumAllCards() << ", which is over the limit." << endl;
        }
        cout<<" Both players are over the limit and have been disqualified. " << endl;
        
    } else {
       
        short winnerIndex;
        //both player has less than 21 points
        if(player[0]->sumAllCards() <= MAX && player[1]->sumAllCards() <= MAX) {
   
            winnerIndex = player[0]->sumAllCards() > player[1]->sumAllCards() ? 0 : 1;
            
            cout << player[winnerIndex]->getName()<< " has won!" << endl;
            
        } else { // one plaer has gone over limit, which means player with less point wins
            winnerIndex = player[0]->sumAllCards() < player[1]->sumAllCards() ? 0 : 1;
            
            cout<< player[!winnerIndex]->getName() << " has a sum of 31.518, which is over the limit." << endl;
            cout<< player[!winnerIndex]->getName() << " has been disqualified for going over the limit. "<< player[winnerIndex]->getName() << " has won." << endl;
        }
        
        *player[winnerIndex] >> bet; // adds cash
        *player[!winnerIndex] << bet; // remove cash
        
    }
    
    //Determine a winner

    // If a player has a sum over the limit of 21, the player is disqualified. Print the player's name,
    // the sum of the player's cards, and a message that states this is over the limit.
    // Apply this test to both players

    // If both players are disqualified, print that both players are over the limit and have been disqualified.

    // If just player 1 is disqualified, print player 1's name and a message that (s)he has been disqualified
    // for going over the limit. Print player 2's name and indicate that (s)he has won.
    // Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.

    // If just player 2 is disqualified, print player 2's name and a message that (s)he has been disqualified
    // for going over the limit. Print player 1's name and indicate that (s)he has won.
    // Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.

    // If player 1 and player 2 are tied, print that both players drew the same number of points and that
    // there is no winner. In doing this comparison, use the == operator.

    // If player 1 has more points than player 2, then print the name of player 1 and that (s)he has won.
    // Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.
    // In doing this comparison, use the > operator

    // If player 2 has more points than player 1, then print the name of player 2 and that (s)he has won.
    // Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.
    // In doing this comparison, use the < operator

    
}
void GameManager::reportCash(){
    //Report the name and cash for each
    for(PlayerBase<double> *p: player )
        cout<< p->getName() << " has $" << p->getCash() << "." << endl;
}
void GameManager::shouldEndGame(){
    // Determine whether it is time to quit by checking to see if one player has run out of cash.
    gameOver = player[0]->getCash() < 0 || player[1]->getCash() < 0;
}
void GameManager::reportResult(){
    
    // Print out the final report for each player. Give the player's name and the player's cash.
    // Be sure to print the cash to two decimal places.
    // Be sure to clean up before finishing the program.
    cout<<"The game is over." << endl;
    reportCash();
}

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
