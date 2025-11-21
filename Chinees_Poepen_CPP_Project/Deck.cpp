#include "Deck.h"

#include <random>
#include <algorithm>
#include <chrono>

Deck::Deck() {
    m_cards.clear();
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r) {
            m_cards.emplace_back(static_cast<Rank>(r), static_cast<Suit>(s));
        }
    }
}

void Deck::shuffle() {
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(m_cards.begin(), m_cards.end(), std::mt19937(seed));
}

Card Deck::draw() {
    if (m_cards.empty()) {
        // return a default card if empty (should be handled by caller)
        return Card();
    }
    Card c = m_cards.back();
    m_cards.pop_back();
    return c;
}

bool Deck::empty() const { return m_cards.empty(); }
int Deck::size() const { return static_cast<int>(m_cards.size()); }
