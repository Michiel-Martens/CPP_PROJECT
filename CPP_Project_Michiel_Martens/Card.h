#ifndef CARD_H
#define CARD_H

#include <string>
#include <ostream>

enum class Suit { Hearts, Diamonds, Clubs, Spades };

enum class Rank {
    Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack = 11, Queen = 12, King = 13, Ace = 14
};

class Card {
public:
    // Vraag 12: default constructor
    Card();
    
    // Vraag 13: parameterized constructor
    Card(Rank rank, Suit suit);

    // Vraag 23: getters
    // Vraag 30: const function
    Rank getRank() const;
    Suit getSuit() const;

    // Vraag 20: useful member function
    // Vraag 30: const function
    int value() const;

    // Vraag 35: useful string class usage
    // Vraag 30: const function
    std::string toString() const;

    // Vraag 26: useful friend function
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    // Vraag 22: useful member variables
    Rank m_rank;
    Suit m_suit;
};

// Vraag 25: useful template function
// Template functie om twee waardes te vergelijken op basis van een member functie
template<typename T, typename Func>
bool compareBy(const T& a, const T& b, Func getter) {
    return getter(a) < getter(b);
}

// Vraag 25: Template specialization voorbeeld
// Nuttig om kaarten te vergelijken op waarde
template<typename T>
T maxValue(const T& a, const T& b) {
    return (a.value() > b.value()) ? a : b;
}

#endif // CARD_H
