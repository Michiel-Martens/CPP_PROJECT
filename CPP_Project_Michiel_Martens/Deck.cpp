#include "Deck.h"

#include <random>
#include <algorithm>
#include <chrono>
#include <stdexcept>

// Vraag 16: member initialization happens in body for this class
Deck::Deck() {
    m_cards.clear();
    
    // Vraag 28: 2 useful unsigned chars or other better usage of memory efficient type
    // unsigned char is voldoende voor 4 suits en 13 ranks
    const unsigned char numSuits = 4;
    const unsigned char maxRank = 14;
    const unsigned char minRank = 2;
    
    for (unsigned char s = 0; s < numSuits; ++s) {
        for (unsigned char r = minRank; r <= maxRank; ++r) {
            m_cards.emplace_back(static_cast<Rank>(r), static_cast<Suit>(s));
        }
    }
}

// Vraag 20: useful member function
void Deck::shuffle() {
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(m_cards.begin(), m_cards.end(), std::mt19937(seed));
}

// Vraag 20: useful member function
Card Deck::draw() {
    // Vraag 39: useful exception handling
    if (m_cards.empty()) {
        throw std::runtime_error("Cannot draw from empty deck");
    }
    Card c = m_cards.back();
    m_cards.pop_back();
    return c;
}

// Vraag 30: const function
// Vraag 31: useful bool
bool Deck::empty() const { return m_cards.empty(); }

// Vraag 30: const function
int Deck::size() const { return static_cast<int>(m_cards.size()); }
