//PlayerMain.cpp - main program for the card player
//  Modified by Yiyuan Dong 2022-03-18.
//  Student ID: 065-182-131

#include<iostream>
#include "GameManagerAdapter.h"

using namespace std;

int main(void) {
    
    GameManagerAdapter* gameManager = CreateGame();

    gameManager->gameStart();

    delete gameManager;

    return 0;
}

/*
In the main() function, the number of players is hardcoded to 2. How could we modify the main() function to let the players decide how many players there are? (0.5 mark)
 
 In my case, I would need to changed use PlayerBase<T>** player;  instead of PlayerBase<T>* player[2];
 
 Next, a factory method to create PlayerBase pointers
 
 PlayerBase<T>* CreatePlayer(bool youth, std::string name) {

    return youth ? PlayerYouth<T>(name) : PlayerAdult<T>(name);
 
 }
 
 The factory method would be called when the GameManager object is initialized.
 
 Also a member variable of numPlayer is needed to keep track of the number of players.
 
 
For this product, compare and contrast polymorphism via the use of inheritance with parametric polymorphism. (1 mark)
 
 
 
If we wished to add a nice graphical interface to this program, how would we do it? With C++? By interacting with another program? By adding a library? By using a different language entirely? (0.5 mark)
 
 
 
 
*/
