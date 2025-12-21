#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "PlayerBase.h"
#include <limits>

namespace ChinesePoepen {

// Vraag 18: useful proven (dynamic) polymorphism - derived class
class HumanPlayer : public PlayerBase {
public:
    // Vraag 12: default constructor
    HumanPlayer();
    
    // Vraag 13: parameterized constructor
    HumanPlayer(const std::string& name, int lives);

    // Vraag 14: copy ctor
    HumanPlayer(const HumanPlayer& other);

    // Vraag 15: destructor
    ~HumanPlayer() override;

    // Vraag 18: polymorphism - override van virtuele functie
    // Vraag 20: useful member function
    void takeTurn(Deck& deck) override;
};

} // namespace ChinesePoepen

#endif // HUMANPLAYER_H
