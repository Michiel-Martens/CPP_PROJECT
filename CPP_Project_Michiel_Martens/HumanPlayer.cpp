#include "HumanPlayer.h"

#include <iostream>

namespace ChinesePoepen {

HumanPlayer::HumanPlayer()
    : PlayerBase()
{
}

HumanPlayer::HumanPlayer(const std::string& name, int lives)
    : PlayerBase(name, lives)
{
}

// copy ctor
HumanPlayer::HumanPlayer(const HumanPlayer& other)
    : PlayerBase(other)
{
}

HumanPlayer::~HumanPlayer() = default;

void HumanPlayer::takeTurn(Deck& deck) {
    std::cout << "\nBeurt van " << getName()
              << " (levens: " << getLives() << ")\n";
    std::cout << "Huidige hand: ";
    const auto& hand = getHand();
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << (i + 1) << ":" << hand[i] << " ";
    }
    std::cout << "\n";

    if (deck.empty()) {
        std::cout << "Deck is leeg — geen ruil mogelijk.\n";
        return;
    }

    Card top = deck.draw();
    std::cout << "Top kaart van deck is: " << top << "\n";
    std::cout << "Wens je deze kaart te ruilen met één van je kaarten? (y/n): ";

    char ans {};
    std::cin >> ans;
    if (ans == 'y' || ans == 'Y') {
        int idx = 0;
        while (true) {
            std::cout << "Welke kaart ruil je? (1-" << getHand().size() << "): ";
            std::cin >> idx;
            if (idx >= 1 && idx <= static_cast<int>(getHand().size())) {
                break;
            }
            std::cout << "Ongeldige keuze. Probeer opnieuw.\n";
        }

        // hand kopiëren, kaart vervangen
        std::vector<Card> newHand = getHand();
        Card replaced = newHand[static_cast<size_t>(idx - 1)];
        newHand[static_cast<size_t>(idx - 1)] = top;

        clearHand();
        for (const auto& c : newHand) {
            addCard(c);
        }

        std::cout << getName() << " ruilt kaart " << replaced
                  << " voor " << top << "\n";

        // vervangen kaart wordt weggegooid (deck krimpt)
    } else {
        std::cout << getName()
                  << " passeert. (top kaart wordt weggegooid)\n";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

} // namespace ChinesePoepen
