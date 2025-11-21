#include <iostream>
#include <limits>
#include "Game.h"

int main() {
    std::cout << "=== Chinees Poepen - Simpel C++ Implementatie === ";
    Game game;

    int lives = 3;
    std::cout << "Aantal levens per speler (standaard 3): ";
    std::cin >> lives;
    if (lives < 1) lives = 1;
    game.setLives(lives);

    int numPlayers = 0;
    std::cout << "Aantal spelers: ";
    std::cin >> numPlayers;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numPlayers; ++i) {
        std::string name;
        std::cout << "Naam speler " << (i+1) << ": ";
        std::getline(std::cin, name);
        if (name.empty()) name = "Speler" + std::to_string(i+1);
        game.addPlayer(name);
    }

    std::cout << "Start spel met " << numPlayers << " spelers. Veel plezier!\n";
    game.run();

    return 0;
}


// README:
// Dit project bevat een simpele implementatie van een Chinees-Poepen-achtig kaartspel.
// Bestanden aanwezig (in één document samengevoegd voor gemak):
// - Card.h / Card.cpp
// - Deck.h / Deck.cpp
// - Player.h / Player.cpp
// - Game.h / Game.cpp
// - main.cpp
//
// Compilatie (bijv. met g++):
// g++ -std=c++17 -O2 Card.cpp Deck.cpp Player.cpp Game.cpp main.cpp -o chinees_poepen
//
// Opmerkingen en vereenvoudigingen:
// - Aas = 11 punten, Boer/Vrouw/Koning = 10 punten.
// - Spelregels zijn vereenvoudigd: elke speler krijgt 3 kaarten en kan eenmaal ruilen met de bovenste kaart van de deck.
// - Ruilen gooit de geruilde kaart uit (verwijderd uit spel) om de implementatie simpel te houden.
// - Je kunt dit project uitbreiden: verbeter AI voor computer spelers, voeg saven/laders toe, maak een beter ruilmechanisme, enz.
