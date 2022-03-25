//
//  PlayerMain.cpp - main program for the card player
//  Created by Yiyuan Dong 2022-03-18.
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
  
  In my case, I would need to use PlayerBase<T>** player; instead of PlayerBase<T>* player[2];
  
  Next, a factory method to create PlayerBase pointers
  
  PlayerBase<T>* CreatePlayer(bool youth, std::string name) {

   return youth ? PlayerYouth<T>(name) : PlayerAdult<T>(name);
  
  }
  
  The factory method would be called when the GameManager object is initialized, so the GameManager object could be initialized with players.
  
 A member variable of int numPlayer is needed to keep track of the number of players.
  
  
 For this product, compare and contrast polymorphism via the use of inheritance with parametric polymorphism. (1 mark)
  
  Polymorphism via the use of inheritance is called Inclusion polymorphism. The term inclusion refers to the base type including the derived types within the hierarchy, All member function definitions share the same name throughout the hierarchy.
  
  In this product, PlayerAdult and PlayerYouth are on the same level in the hierarchy. Both classes have the same parent class PlayerBase.
  Both PlayerYouth and PlayerAdult inherit all the public/protected member functions definitions from PlayerBase yet they could have their own version of implementation. For instance, addOneAttackCard() in the base or adult class draws a car with a maximum point of 15, but addOneAttackCard() in the youth class draws a card with maximum point of 10. In a word, inclusion polymorphism allows different implementations for the same function definition.
  Also, inclusion polymorphism allows a static class type to have dynamic behaviours. In this product, the PlayerBase references are interpreted as PlayerAdult and PlayerYouth respectively.
  
  
  Parametric Polymorphism addresses differences between argument types in a function call or a class and eliminates duplicate logic. It allows the same piece of code to be used for different types.
  
  In this product, Type PlayerBase<int>, PlayerBase<double> and their sub-classes are generated with the same code during compile time. The implementation logic of these different class types (<int> and <double>) are the same.
  
  In conclusion, Inclusion allows PlayerAdult<>, PlayerYouth<> and PlayerBase<> to have same behavior definition and different implementation while Parametric Polumorphism allows PlayerBase<int> and PlayerBase<double>, PlayerAdult<int> and PlayerAdult<double> etc. to have the same implementation logic even if the class types are different.
  
 In addition, in this product, inclusion and parametric are used together to increase code reusability and allow the class type selection during runtime (GameManagerAdapter enables the creation and use of different GameManager concrete types, so different types of Players can be created accordingly during runtime ).
 
 
 If we wished to add a nice graphical interface to this program, how would we do it? With C++? By interacting with another program? By adding a library? By using a different language entirely? (0.5 mark)
  
  1. We could use the UI Libraries - C++ User Interface Boost library.
  2. Objective C is a combination of C++ and Objective C. Objective can be used to build UI. So, we could import the project into an Objective C project and create a UI using Objective-C. To go even further, Objective C code can be used in a Swift project as well if bridging header files are provided.
  3. Create a REST API of the game in C++. Then, a web application can be built for the game using the API.
  

*/
