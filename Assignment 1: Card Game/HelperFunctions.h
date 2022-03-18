//
//  HelperFunctions.h
//  Assignment 1: Card Game
//
//  Created by Dayson Dong on 2022-03-18.
//

#ifndef HelperFunctions_h
#define HelperFunctions_h

//validate if the user has input an integer
short GetShort() {
    
    short num;
    
    while(!(std::cin >> num)) {
        
        std::cout << "Invalid number. Please enter an INTEGER: ";
        
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    
    return num;
    
}

//ask user to input [y/n] and returns true or false base on the input
bool GetBoolFromYN() {
    
    std::string str;
    
    while(true) {
        
        getline(std::cin, str);
        
        if(str == "y" || str == "Y")  return true;
        
        else if(str == "n" || str == "N")  return false;
        
        else std::cout << "Invalid input. Try again: [Y/N] ";
        
    }
    
}

#endif /* HelperFunctions_h */
