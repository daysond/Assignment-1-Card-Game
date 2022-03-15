//
//  PlayerManager.cpp
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-02-22.
//

#include "PlayerManager.h"

PlayerManager::PlayerManager() {
    
    player[0] = new PlayerYouth<double>("Noah");
    player[1] = new PlayerAdult<double>("Kenneth");
    
    //    player[0] = new PlayerYouth<int>("Noah");
    //    player[1] = new PlayerAdult<int>("Kenneth");
    
    gameOver = false;
}

//bool gameOn() {return !gameOver; }
//void endGame() { gameOver = true;}

void PlayerManager::betMoney() {
    // Prompt the players for the amount they want to bet. It has to be between $10 and $300
    // If they enter a value below $10, set the amount to $10
    // If they enter a value above $300, set the amount to $300
    
}
void PlayerManager::gameStart() {
    // Prompt the player for the number of dependent cards

    // Prompt the player for the number of attack cards

    // Report the player's name and the sum of the player's cards

    // Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards

    // Report the player's name and the sum of the player's cards

    // Ask the player if (s)he wishes to add an attack card to the existing list of attack cards

    // Report the player's name and the sum of the player's cards
    
}
void PlayerManager::reportPoints(){
    //Report the name and points for each player
    
}
void PlayerManager::determineWinner(){
    
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
void PlayerManager::reportCash(){
    //Report the name and cash for each
    
}
void PlayerManager::shouldEndGame(){
    
    // Determine whether it is time to quit by checking to see if one player has run out of cash.
}
void PlayerManager::reportResult(){
    
    // Print out the final report for each player. Give the player's name and the player's cash.
    // Be sure to print the cash to two decimal places.
    // Be sure to clean up before finishing the program.
}
