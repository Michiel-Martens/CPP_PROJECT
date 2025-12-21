#include "AIPlayer.h"

#include <iostream>

namespace ChinesePoepen {

AIPlayer::AIPlayer()
    : PlayerBase("AI", 3)
{
}

AIPlayer::AIPlayer(const std::string& name, int lives)
    : PlayerBase(name, lives)
{
}

AIPlayer::AIPlayer(const AIPlayer& other)
    : PlayerBase(other)
{
}

AIPlayer::~AIPlayer() = default;

// Heel simpele AI: enkel ruilen als de topkaart beter is dan de slechtste kaart in de hand
void AIPlayer::takeTurn(Deck& deck) {
    std::cout << "\nBeurt van (AI) " << getName()
              << " (levens: " << getLives() << ")\n";

    if (deck.empty()) {
        std::cout << "Deck is leeg — AI kan niet ruilen.\n";
        return;
    }

    Card top = deck.draw();
    std::cout << "AI ziet top kaart: " << top << "\n";

    if (getHand().empty()) {
        // niets te ruilen
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

    // AI ruilt enkel als topkaart beter is dan de slechtste kaart
    if (top.value() > worstValue) {
        std::vector<Card> newHand = getHand();
        Card replaced = newHand[worstIndex];
        newHand[worstIndex] = top;

        clearHand();
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
