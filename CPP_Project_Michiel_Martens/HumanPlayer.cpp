#include "HumanPlayer.h"

#include <iostream>

namespace ChinesePoepen {

// Vraag 17: constructor forwarding
HumanPlayer::HumanPlayer()
    : PlayerBase()
{
}

// Vraag 16: member initialization via base class constructor
HumanPlayer::HumanPlayer(const std::string& name, int lives)
    : PlayerBase(name, lives)
{
}

// Vraag 14: copy ctor
HumanPlayer::HumanPlayer(const HumanPlayer& other)
    : PlayerBase(other)
{
}

HumanPlayer::~HumanPlayer() = default;

// Vraag 18: polymorphism - override virtual function
// Vraag 34: modern call-by-reference (Deck& deck)
void HumanPlayer::takeTurn(Deck& deck) {
    std::cout << "\nBeurt van " << getName()
              << " (levens: " << getLives() << ")\n";
    std::cout << "Huidige hand: ";
    
    // Vraag 29: const reference
    const auto& hand = getHand();
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << (i + 1) << ":" << hand[i] << " ";
    }
    std::cout << "\n";

    // Vraag 31: useful bool
    if (deck.empty()) {
        std::cout << "Deck is leeg — geen ruil mogelijk.\n";
        return;
    }

    Card top = deck.draw();
    std::cout << "Top kaart van deck is: " << top << "\n";
    std::cout << "Wens je deze kaart te ruilen met één van je kaarten? (y/n): ";

    char ans {};
    std::cin >> ans;
    
    // Vraag 31: useful bool
    if (ans == 'y' || ans == 'Y') {
        int idx = 0;
        // Vraag 39: input validation with loop (implicit exception prevention)
        while (true) {
            std::cout << "Welke kaart ruil je? (1-" << getHand().size() << "): ";
            std::cin >> idx;
            if (idx >= 1 && idx <= static_cast<int>(getHand().size())) {
                break;
            }
            std::cout << "Ongeldige keuze. Probeer opnieuw.\n";
        }

        // Vraag 36: container class usage
        std::vector<Card> newHand = getHand();
        Card replaced = newHand[static_cast<size_t>(idx - 1)];
        newHand[static_cast<size_t>(idx - 1)] = top;

        clearHand();
        // Vraag 29: const reference in range-based for
        for (const auto& c : newHand) {
            addCard(c);
        }

        std::cout << getName() << " ruilt kaart " << replaced
                  << " voor " << top << "\n";
    } else {
        std::cout << getName()
                  << " passeert. (top kaart wordt weggegooid)\n";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

} // namespace ChinesePoepen
