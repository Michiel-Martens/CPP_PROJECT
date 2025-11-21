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
    Card();
    Card(Rank rank, Suit suit);

    Rank getRank() const;
    Suit getSuit() const;

    // Geeft een numerieke waarde die je kunt gebruiken voor scoring / vergelijkingen
    int value() const;

    // Tekstweergave, bijvoorbeeld: "A♠" of "10♥"
    std::string toString() const;

    // Voor makkelijk printen: std::cout << card;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    Rank m_rank;
    Suit m_suit;
};

#endif // CARD_H
