#include "AIPlayer.h"

#include <iostream>

namespace ChinesePoepen {

// Vraag 17: constructor forwarding
AIPlayer::AIPlayer()
    : PlayerBase("AI", 3)
{
}

// Vraag 16: member initialization via base class constructor
AIPlayer::AIPlayer(const std::string& name, int lives)
    : PlayerBase(name, lives)
{
}

// Vraag 14: copy constructor
AIPlayer::AIPlayer(const AIPlayer& other)
    : PlayerBase(other)
{
}

AIPlayer::~AIPlayer() = default;

// Vraag 18: polymorphism - override virtual function
// Vraag 34: modern call-by-reference (Deck& deck)
void AIPlayer::takeTurn(Deck& deck) {
    std::cout << "\nBeurt van (AI) " << getName()
              << " (levens: " << getLives() << ")\n";

    // Vraag 31: useful bool
    if (deck.empty()) {
        std::cout << "Deck is leeg — AI kan niet ruilen.\n";
        return;
    }

    Card top = deck.draw();
    std::cout << "AI ziet top kaart: " << top << "\n";

    if (getHand().empty()) {
        return;
    }

    // zoek kaart met laagste value
    size_t worstIndex = 0;
    int worstValue = getHand()[0].value();
    for (size_t i = 1; i < getHand().size(); ++i) {
        int v = getHand()[i].value();
        if (v < worstValue) {
            worstValue = v;
            worstIndex = i;
        }
    }

    // Vraag 31: useful bool - AI ruilt enkel als topkaart beter is
    if (top.value() > worstValue) {
        // Vraag 36: container class usage
        std::vector<Card> newHand = getHand();
        Card replaced = newHand[worstIndex];
        newHand[worstIndex] = top;

        clearHand();
        // Vraag 29: const reference in range-based for
        for (const auto& c : newHand) {
            addCard(c);
        }

        std::cout << getName() << " (AI) ruilt " << replaced
                  << " voor " << top << "\n";
    } else {
        std::cout << getName()
                  << " (AI) beslist om te passen. (top kaart wordt weggegooid)\n";
    }
}

} // namespace ChinesePoepen
