#include <iostream>
#include <limits>

#include "Game.h"

using namespace ChinesePoepen;

// Vraag 2: clean main (i.e. nothing in the main that should be in a class)
// Vraag 3: no globals, but statics if needed
// Alle logica zit in de classes, main doet enkel setup en start het spel

int main() {
    // Vraag 39: useful exception handling
    try {
        std::cout << "=== Chinees Poepen - C++ Implementatie ===\n";

        // Vraag 20: Game class usage
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

        // Vraag 35: string class usage
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
        // Vraag 20: member function call
        game.run();

    } catch (const std::exception& e) {
        // Vraag 39: exception handling
        std::cerr << "\nFout opgetreden: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
