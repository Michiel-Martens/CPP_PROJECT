#ifndef GAME_H
#define GAME_H

#include "PlayerBase.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Deck.h"

#include <memory>
#include <vector>
#include <string>

namespace ChinesePoepen {

// Vraag 27: everything in namespace
class Game {
public:
    // Vraag 12: default constructor
    Game();

    // Vraag 20: useful member functions
    void addHumanPlayer(const std::string& name);
    void addAIPlayer(const std::string& name);
    void setLives(int lives);
    void run();
    
    // Vraag 21: default values in function definition
    // Vraag 38: useful usage of (modern) file-I/O
    void saveGame(const std::string& filename = "savegame.txt") const;
    void loadGame(const std::string& filename = "savegame.txt");

private:
    // Vraag 32: dynamic memory allocation (unique_ptr)
    // Vraag 36: useful container class
    std::vector<std::unique_ptr<PlayerBase>> m_players;
    int m_startLives;

    void playRound();
    void dealHands(Deck& deck);
    
    // Vraag 21: default values in function definition
    void showHands(bool revealAll = false) const;
    void eliminatePlayers();
};

} // namespace ChinesePoepen

#endif // GAME_H
