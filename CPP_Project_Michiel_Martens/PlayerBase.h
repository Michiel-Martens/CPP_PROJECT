#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include "Card.h"
#include "Deck.h"

#include <string>
#include <vector>

namespace ChinesePoepen {

// Vraag 27: everything in one or more self-made namespace(s)
class PlayerBase {
public:
    // Vraag 12: at least 2 default constructors
    PlayerBase();

    // Vraag 13: at least 2 parameterized constructors
    PlayerBase(const std::string& name, int lives);

    // Vraag 14: at least 2 copy constructors
    PlayerBase(const PlayerBase& other);

    // Vraag 15: at least 2 destructors
    // Vraag 18: useful proven (dynamic) polymorphism - virtual destructor
    virtual ~PlayerBase();

    // Vraag 23: useful getters and setters for member variables
    // Vraag 30: at least 4 useful const references for functions
    const std::string& getName() const;
    int getLives() const;
    void setLives(int lives);
    void loseLife();

    // Vraag 30: const reference for function
    const std::vector<Card>& getHand() const;
    
    // Vraag 29: at least 4 useful const references for variables
    void addCard(const Card& c);
    void clearHand();
    int handValue() const;

    // Vraag 19: useful usage of "this" (if the code does not work without it)
    // Vraag 24: correct usage of inline function
    // Vraag 31: at least 4 useful bool
    inline bool isAlive() const { return this->m_lives > 0; }

    // Vraag 18: pure virtual: abstracte basisklasse + polymorfisme
    // Vraag 20: useful member function
    virtual void takeTurn(Deck& deck) = 0;

protected:
    // Vraag 4: correct protections
    // Vraag 22: useful member variabel
    std::string m_name;
    int m_lives;
    std::vector<Card> m_hand;
};

} // namespace ChinesePoepen

#endif // PLAYERBASE_H
