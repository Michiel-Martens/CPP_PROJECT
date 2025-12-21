#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "PlayerBase.h"

namespace ChinesePoepen {

// Vraag 18: useful proven (dynamic) polymorphism - derived class
class AIPlayer : public PlayerBase {
public:
    // Vraag 12: default constructor
    AIPlayer();
    
    // Vraag 13: parameterized constructor
    AIPlayer(const std::string& name, int lives);

    // Vraag 14: copy ctor
    AIPlayer(const AIPlayer& other);

    // Vraag 15: destructor
    ~AIPlayer() override;

    // Vraag 18: polymorphism - override virtual function
    // Vraag 20: useful member function
    void takeTurn(Deck& deck) override;
};

} // namespace ChinesePoepen

#endif // AIPLAYER_H
