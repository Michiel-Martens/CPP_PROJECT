#include "Game.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <stdexcept>

namespace ChinesePoepen {

// Vraag 16: member initialization in constructors
Game::Game()
    : m_players(),
      m_startLives(3)
{
}

void Game::addHumanPlayer(const std::string& name) {
    // Vraag 32: dynamic memory allocation (make_unique)
    m_players.push_back(std::make_unique<HumanPlayer>(name, m_startLives));
}

void Game::addAIPlayer(const std::string& name) {
    // Vraag 32: dynamic memory allocation (make_unique)
    m_players.push_back(std::make_unique<AIPlayer>(name, m_startLives));
}

void Game::setLives(int lives) {
    m_startLives = lives;
    // Vraag 29: const reference in range-based for loop
    for (auto& p : m_players) {
        // Vraag 37: useful usage of nullptr
        if (p != nullptr) {
            p->setLives(lives);
        }
    }
}

void Game::run() {
    // Vraag 39: useful exception handling
    try {
        while (m_players.size() > 1) {
            playRound();
            eliminatePlayers();

            std::cout << "\nStand na ronde:\n";
            // Vraag 29: const reference
            for (const auto& p : m_players) {
                if (p != nullptr) {
                    std::cout << p->getName()
                              << " - levens: " << p->getLives() << "\n";
                }
            }

            if (m_players.size() <= 1) {
                break;
            }

            std::cout << "\nDruk op Enter om naar de volgende ronde te gaan...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (m_players.size() == 1 && m_players[0] != nullptr) {
            std::cout << "\n🎉 Winnaar: " << m_players[0]->getName() << "!\n";
        } else {
            std::cout << "\nGeen spelers meer over.\n";
        }
    } catch (const std::exception& e) {
        // Vraag 39: exception handling
        std::cerr << "Error tijdens spel: " << e.what() << "\n";
    }
}

void Game::playRound() {
    Deck deck;
    deck.shuffle();

    dealHands(deck);

    // Vraag 18: polymorfisme - elke speler doet zijn eigen takeTurn
    for (auto& p : m_players) {
        // Vraag 37: nullptr check
        if (p != nullptr) {
            p->takeTurn(deck);
        }
    }

    std::cout << "\nEindstanden deze ronde:\n";
    int lowest = std::numeric_limits<int>::max();
    // Vraag 29: const reference
    for (const auto& p : m_players) {
        if (p == nullptr) continue;
        
        std::cout << p->getName() << " -> hand: ";
        // Vraag 29: const reference
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
        if (p != nullptr && p->handValue() == lowest) {
            p->loseLife();
            std::cout << p->getName() << " verliest een leven!\n";
        }
    }
}

void Game::dealHands(Deck& deck) {
    const int cardsPerPlayer = 3;

    for (auto& p : m_players) {
        if (p != nullptr) {
            p->clearHand();
        }
    }

    for (int i = 0; i < cardsPerPlayer; ++i) {
        for (auto& p : m_players) {
            if (p != nullptr && !deck.empty()) {
                p->addCard(deck.draw());
            }
        }
    }
}

// Vraag 21: default parameter value used here
void Game::showHands(bool revealAll) const {
    std::cout << "\nHuidige handen:\n";
    // Vraag 29: const reference
    for (const auto& p : m_players) {
        if (p == nullptr) continue;
        
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
    // Vraag 40: useful usage of lambda function
    auto it = std::remove_if(
        m_players.begin(),
        m_players.end(),
        [](const std::unique_ptr<PlayerBase>& p) {
            // Vraag 37: nullptr check in lambda
            return p == nullptr || !p->isAlive();
        });

    if (it != m_players.end()) {
        for (auto itr = it; itr != m_players.end(); ++itr) {
            if (*itr != nullptr) {
                std::cout << (*itr)->getName() << " is uitgeschakeld!\n";
            }
        }
        m_players.erase(it, m_players.end());
    }
}

// Vraag 38: useful usage of (modern) file-I/O
// Vraag 21: default parameter value
void Game::saveGame(const std::string& filename) const {
    // Vraag 39: exception handling
    try {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Kan bestand niet openen voor schrijven: " + filename);
        }

        file << m_startLives << "\n";
        file << m_players.size() << "\n";

        // Vraag 29: const reference
        for (const auto& p : m_players) {
            if (p != nullptr) {
                file << p->getName() << "\n";
                file << p->getLives() << "\n";
            }
        }

        file.close();
        std::cout << "Spel opgeslagen naar " << filename << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error bij opslaan: " << e.what() << "\n";
        throw;
    }
}

// Vraag 38: useful usage of (modern) file-I/O
// Vraag 21: default parameter value
void Game::loadGame(const std::string& filename) {
    // Vraag 39: exception handling
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Kan bestand niet openen voor lezen: " + filename);
        }

        int lives;
        size_t numPlayers;
        file >> lives >> numPlayers;
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        m_startLives = lives;
        m_players.clear();

        for (size_t i = 0; i < numPlayers; ++i) {
            std::string name;
            int playerLives;
            std::getline(file, name);
            file >> playerLives;
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Voor nu laden we als human players
            auto player = std::make_unique<HumanPlayer>(name, playerLives);
            m_players.push_back(std::move(player));
        }

        file.close();
        std::cout << "Spel geladen van " << filename << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error bij laden: " << e.what() << "\n";
        throw;
    }
}

} // namespace ChinesePoepen
