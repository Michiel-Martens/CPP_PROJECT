#include <iostream>
#include <limits>

#include "Game.h"

using namespace ChinesePoepen;

int main() {
    std::cout << "=== Chinees Poepen - C++ Implementatie ===\n";

    Game game;

    int lives = 3;
    std::cout << "Aantal levens per speler (standaard 3): ";
    std::cin >> lives;
    if (lives < 1) {
        lives = 1;
    }
    game.setLives(lives);

    int numPlayers = 0;
    std::cout << "Aantal spelers: ";
    std::cin >> numPlayers;

    int numAI = 0;
    std::cout << "Aantal AI-spelers: ";
    std::cin >> numAI;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numPlayers; ++i) {
        std::string name;
        std::cout << "Naam menselijke speler " << (i + 1) << ": ";
        std::getline(std::cin, name);
        if (name.empty()) {
            name = "Speler" + std::to_string(i + 1);
        }
        game.addHumanPlayer(name);
    }

    for (int i = 0; i < numAI; ++i) {
        std::string name = "AI" + std::to_string(i + 1);
        game.addAIPlayer(name);
    }

    std::cout << "\nStart spel. Veel plezier!\n";
    game.run();

    return 0;
}
