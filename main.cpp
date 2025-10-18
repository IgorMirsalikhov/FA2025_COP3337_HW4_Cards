#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"

#include <iostream>

int main(void) {
    ////////////// Test Card ////////////////
    Card c(1, 2);
    std::cout << c.toString() << std::endl;
    
    ////////////// Test Deck ////////////////
    int seed;
    std::cout << "Enter seed: ";
    std::cin >> seed; 
    
    Deck myDeck(seed);
    while (myDeck.moreCards()) {    
        std::cout << myDeck.dealCard().toString() << std::endl;
    }
    
    myDeck.shuffle();   
    std::cout << "******************AFTER SHUFFLING******************" << std::endl;
    while (myDeck.moreCards()){
        std::cout << myDeck.dealCard().toString() << std::endl;
    }
    
    ////////////// Test Hand ////////////////
    for (int i = 0; i < 5; i++) {
        myDeck.shuffle();
        while (myDeck.moreCards()){
            std::cout << "------------------\n";
            Hand h(myDeck);
            h.printHand();
            if (h.threeOfAKind()) {
                std::cout << "Hand contains three of a kind" << std::endl;
            } 
            else if (h.twoPair()) {
                std::cout << "Hand contains two pairs" << std::endl;
            } 
            else if (h.pair()) {
                std::cout << "Hand contains a pair" << std::endl;
            }
            std::cout << "------------------\n";
        }
    }

    return 0;
}
