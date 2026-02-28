#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"

#include <iostream>

int main() {
    ////////////// Test Card ////////////////
    Card c(10, 2);
    std::cout << c.toString() << std::endl;
    
    ////////////// Test Deck ////////////////
    int seed;
    std::cout << "Enter seed: ";
    std::cin >> seed; 
    
    Deck myDeck(seed);
    std::cout << "\n******************BEFORE SHUFFLING******************" << std::endl;
    while (myDeck.moreCards()) {    
        std::cout << myDeck.dealCard().toString() << ' ';
    }
    
    myDeck.shuffle();   
    std::cout << "\n******************AFTER SHUFFLING******************" << std::endl;
    while (myDeck.moreCards()){
        std::cout << myDeck.dealCard().toString() << ' ';
    }
    std::cout << '\n';

    ////////////// Test Hand ////////////////
    Hand h;
    myDeck.shuffle();

    bool pair = false;
    bool two_pairs = false;
    bool three = false;

    while (true) {
        h.takeCards(myDeck);
        if (!h.isFullHand()) {
            myDeck.shuffle();
            h.takeCards(myDeck);
        }            
        std::cout << "------------------\n";
        h.print();
        if (h.hasThreeOfAKind()) {
            std::cout << "Hand contains three of a kind" << std::endl;
            three = true;
        } 
        else if (h.hasTwoPairs()) {
            std::cout << "Hand contains two pairs" << std::endl;
            two_pairs = true;
        } 
        else if (h.hasPair()) {
            std::cout << "Hand contains a pair" << std::endl;
            pair = true;
        }
        std::cout << "------------------\n";

        if (pair && two_pairs && three) {
            break;
        }
    }


    return 0;
}
