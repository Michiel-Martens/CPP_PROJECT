#include "Player.h"

#include <numeric>

Player::Player() : m_name(""), m_lives(3) {}
Player::Player(const std::string& name, int lives) : m_name(name), m_lives(lives) {}

const std::string& Player::getName() const { return m_name; }
int Player::getLives() const { return m_lives; }
void Player::loseLife() { if (m_lives>0) --m_lives; }

void Player::addCard(const Card& c) { m_hand.push_back(c); }
void Player::clearHand() { m_hand.clear(); }
const std::vector<Card>& Player::getHand() const { return m_hand; }

int Player::handValue() const {
    int sum = 0;
    for (const auto& c : m_hand) sum += c.value();
    return sum;
}
