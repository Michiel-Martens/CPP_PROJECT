#include "Card.h"

#include <sstream>

Card::Card() : m_rank(Rank::Two), m_suit(Suit::Hearts) {}
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit) {}

Rank Card::getRank() const { return m_rank; }
Suit Card::getSuit() const { return m_suit; }

int Card::value() const {
    int r = static_cast<int>(m_rank);
    if (m_rank == Rank::Ace) return 11; // eenvoudige regel: Aas = 11
    if (r >= 11 && r <= 13) return 10;  // Boer, Vrouw, Koning = 10
    return r; // 2..10
}

std::string Card::toString() const {
    std::string s;
    // rank
    switch (m_rank) {
    case Rank::Ace: s += "A"; break;
    case Rank::King: s += "K"; break;
    case Rank::Queen: s += "Q"; break;
    case Rank::Jack: s += "J"; break;
    case Rank::Ten: s += "10"; break;
    case Rank::Nine: s += "9"; break;
    case Rank::Eight: s += "8"; break;
    case Rank::Seven: s += "7"; break;
    case Rank::Six: s += "6"; break;
    case Rank::Five: s += "5"; break;
    case Rank::Four: s += "4"; break;
    case Rank::Three: s += "3"; break;
    case Rank::Two: s += "2"; break;
    }
    // suit
    switch (m_suit) {
    case Suit::Hearts: s += "♥"; break;
    case Suit::Diamonds: s += "♦"; break;
    case Suit::Clubs: s += "♣"; break;
    case Suit::Spades: s += "♠"; break;
    }
    return s;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << card.toString();
    return os;
}
