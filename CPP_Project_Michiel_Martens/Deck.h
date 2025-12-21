#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <vector>

class Deck {
public:
    // Vraag 12: default constructor
    Deck();
    
    // Vraag 20: useful member functions
    void shuffle();
    Card draw();
    
    // Vraag 30: const functions
    // Vraag 31: useful bool
    bool empty() const;
    int size() const;
    
private:
    // Vraag 36: useful container class
    std::vector<Card> m_cards;
};

#endif // DECK_H
