#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include "Card.h"
#include "Deck.h"

#include <string>
#include <vector>

namespace ChinesePoepen {

class PlayerBase {
public:
    // default ctor
    PlayerBase();

    // parameterized ctor
    PlayerBase(const std::string& name, int lives);

    // copy ctor (OOP-eis)
    PlayerBase(const PlayerBase& other);

    // virtual destructor (polymorfisme, base class)
    virtual ~PlayerBase();

    const std::string& getName() const;
    int getLives() const;
    void setLives(int lives);
    void loseLife();

    const std::vector<Card>& getHand() const;
    void addCard(const Card& c);
    void clearHand();
    int handValue() const;

    // nuttig gebruik van this: code faalt als je this weghaalt
    bool isAlive() const { return this->m_lives > 0; }

    // pure virtual: abstracte basisklasse + polymorfisme
    virtual void takeTurn(Deck& deck) = 0;

protected:
    std::string m_name;
    int m_lives;
    std::vector<Card> m_hand;
};

} // namespace ChinesePoepen

#endif // PLAYERBASE_H
