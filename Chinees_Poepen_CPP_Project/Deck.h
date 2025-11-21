#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <vector>

class Deck {
public:
    Deck();
    void shuffle();
    Card draw();
    bool empty() const;
    int size() const;
private:
    std::vector<Card> m_cards;
};

#endif // DECK_H
