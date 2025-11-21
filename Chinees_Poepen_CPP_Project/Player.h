#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

#include <string>
#include <vector>

class Player {
public:
    Player();
    Player(const std::string& name, int lives = 3);

    const std::string& getName() const;
    int getLives() const;
    void loseLife();

    void addCard(const Card& c);
    void clearHand();
    const std::vector<Card>& getHand() const;
    int handValue() const;

private:
    std::string m_name;
    int m_lives;
    std::vector<Card> m_hand;
};

#endif // PLAYER_H
