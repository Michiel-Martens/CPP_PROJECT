#include "Game.h"

#include <iostream>
#include <limits>
#include <algorithm>

namespace ChinesePoepen {

Game::Game()
    : m_players(),
      m_startLives(3)
{
}

void Game::addHumanPlayer(const std::string& name) {
    m_players.push_back(std::make_unique<HumanPlayer>(name, m_startLives));
}

void Game::addAIPlayer(const std::string& name) {
    m_players.push_back(std::make_unique<AIPlayer>(name, m_startLives));
}

void Game::setLives(int lives) {
    m_startLives = lives;
    for (auto& p : m_players) {
        p->setLives(lives);
    }
}

void Game::run() {
    while (m_players.size() > 1) {
        playRound();
        eliminatePlayers();

        std::cout << "\nStand na ronde:\n";
        for (const auto& p : m_players) {
            std::cout << p->getName()
                      << " - levens: " << p->getLives() << "\n";
        }

        if (m_players.size() <= 1) {
            break;
        }

        std::cout << "\nDruk op Enter om naar de volgende ronde te gaan...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (m_players.size() == 1) {
        std::cout << "\n🎉 Winnaar: " << m_players[0]->getName() << "!\n";
    } else {
        std::cout << "\nGeen spelers meer over.\n";
    }
}

void Game::playRound() {
    Deck deck;
    deck.shuffle();

    dealHands(deck);

    // elke speler doet zijn eigen takeTurn (polymorfisme)
    for (auto& p : m_players) {
        p->takeTurn(deck);
    }

    std::cout << "\nEindstanden deze ronde:\n";
    int lowest = std::numeric_limits<int>::max();
    for (const auto& p : m_players) {
        std::cout << p->getName() << " -> hand: ";
        for (const auto& c : p->getHand()) {
            std::cout << c << " ";
        }
        int val = p->handValue();
        std::cout << " (waarde: " << val << ")\n";
        if (val < lowest) {
            lowest = val;
        }
    }

    for (auto& p : m_players) {
        if (p->handValue() == lowest) {
            p->loseLife();
            std::cout << p->getName() << " verliest een leven!\n";
        }
    }
}

void Game::dealHands(Deck& deck) {
    const int cardsPerPlayer = 3;

    for (auto& p : m_players) {
        p->clearHand();
    }

    for (int i = 0; i < cardsPerPlayer; ++i) {
        for (auto& p : m_players) {
            if (!deck.empty()) {
                p->addCard(deck.draw());
            }
        }
    }
}

void Game::showHands(bool revealAll) const {
    std::cout << "\nHuidige handen:\n";
    for (const auto& p : m_players) {
        std::cout << p->getName() << ": ";
        if (revealAll) {
            for (const auto& c : p->getHand()) {
                std::cout << c << " ";
            }
        } else {
            std::cout << "(verborgen)";
        }
        std::cout << "\n";
    }
}

void Game::eliminatePlayers() {
    auto it = std::remove_if(
        m_players.begin(),
        m_players.end(),
        [](const std::unique_ptr<PlayerBase>& p) {
            return !p->isAlive();
        });

    if (it != m_players.end()) {
        for (auto itr = it; itr != m_players.end(); ++itr) {
            std::cout << (*itr)->getName() << " is uitgeschakeld!\n";
        }
        m_players.erase(it, m_players.end());
    }
}

} // namespace ChinesePoepen
