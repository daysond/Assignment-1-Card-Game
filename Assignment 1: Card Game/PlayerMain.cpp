//PlayerMain.cpp - main program for the card player

#include<iostream>
#include "PlayerYouth.h"
#include "PlayerAdult.h"
#include "PlayerManager"

using namespace std;

int main(void) {
    
    PlayerManager playerManager = PlayerManager();
    
//	const int MAX = 21;
//	const int NUM = 2;
////	PlayerBase<int>* player[NUM];
////	player[0] = new PlayerYouth<int>("Noah");
////	player[1] = new PlayerAdult<int>("Kenneth");
//	PlayerBase<double>* player[NUM];
//	player[0] = new PlayerYouth<double>("Noah");
//	player[1] = new PlayerAdult<double>("Kenneth");

	bool gameOver = false;
	do {

        
        playerManager.betMoney();

		cout << endl;
		for (int i = 0; i < NUM; ++i) {
            // gameStart()

			cout << endl;
		}

		//reportPoints

		cout << endl;

		//Determine a winner


		cout << endl;

		//Report the name and cash for each

		cout << endl;

		// shouldEndGame()
        
	} while (!gameOver);

	cout << "The game is over." << endl;

    // reportResult

	return 0;
}
