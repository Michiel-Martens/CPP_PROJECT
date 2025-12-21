#include "PlayerBase.h"

#include <numeric>
#include <stdexcept>

namespace ChinesePoepen {

// Vraag 16: member initialization in constructors (the stuff behind a colon)
// Vraag 17: constructor forwarding - delegates to parameterized constructor
PlayerBase::PlayerBase()
    : PlayerBase("", 3) // Constructor forwarding
{
}

// Vraag 16: member initialization in constructors
PlayerBase::PlayerBase(const std::string& name, int lives)
    : m_name(name), m_lives(lives), m_hand()
{
    // Vraag 39: useful exception handling
    if (lives < 0) {
        throw std::invalid_argument("Lives cannot be negative");
    }
}

// Vraag 14: copy ctor (OOP-eis)
// Vraag 16: member initialization in constructors
PlayerBase::PlayerBase(const PlayerBase& other)
    : m_name(other.m_name),
      m_lives(other.m_lives),
      m_hand(other.m_hand)
{
}

PlayerBase::~PlayerBase() = default;

// Vraag 23: useful getters and setters
// Vraag 30: const reference for function
const std::string& PlayerBase::getName() const { return m_name; }
int PlayerBase::getLives() const { return m_lives; }

void PlayerBase::setLives(int lives) {
    // Vraag 39: useful exception handling
    if (lives < 0) {
        throw std::invalid_argument("Lives cannot be negative");
    }
    m_lives = lives;
}

void PlayerBase::loseLife() {
    if (m_lives > 0) {
        --m_lives;
    }
}

// Vraag 30: const reference for function
const std::vector<Card>& PlayerBase::getHand() const {
    return m_hand;
}

// Vraag 29: const reference for variable
void PlayerBase::addCard(const Card& c) {
    m_hand.push_back(c);
}

void PlayerBase::clearHand() {
    m_hand.clear();
}

// Vraag 30: const function
int PlayerBase::handValue() const {
    int sum = 0;
    // Vraag 29: const reference in range-based for loop
    for (const auto& c : m_hand) {
        sum += c.value();
    }
    return sum;
}

} // namespace ChinesePoepen
