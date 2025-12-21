#include "PlayerBase.h"

#include <numeric>

namespace ChinesePoepen {

PlayerBase::PlayerBase()
    : m_name(""), m_lives(3), m_hand()
{
}

PlayerBase::PlayerBase(const std::string& name, int lives)
    : m_name(name), m_lives(lives), m_hand()
{
}

// copy ctor (OOP-eis)
PlayerBase::PlayerBase(const PlayerBase& other)
    : m_name(other.m_name),
      m_lives(other.m_lives),
      m_hand(other.m_hand)
{
}

PlayerBase::~PlayerBase() = default;

const std::string& PlayerBase::getName() const { return m_name; }
int PlayerBase::getLives() const { return m_lives; }

void PlayerBase::setLives(int lives) {
    m_lives = lives;
}

void PlayerBase::loseLife() {
    if (m_lives > 0) {
        --m_lives;
    }
}

const std::vector<Card>& PlayerBase::getHand() const {
    return m_hand;
}

void PlayerBase::addCard(const Card& c) {
    m_hand.push_back(c);
}

void PlayerBase::clearHand() {
    m_hand.clear();
}

int PlayerBase::handValue() const {
    int sum = 0;
    for (const auto& c : m_hand) {
        sum += c.value();
    }
    return sum;
}

} // namespace ChinesePoepen
