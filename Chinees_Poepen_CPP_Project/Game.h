#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"

#include <vector>

class Game {
public:
    Game();
    void addPlayer(const std::string& name);
    void setLives(int lives);
    void run();

private:
    std::vector<Player> m_players;
    int m_startLives;

    void playRound();
    void dealHands(Deck& deck);
    void playerTurn(Player& player, Deck& deck);
    void showHands(bool revealAll = false) const;
    void eliminatePlayers();
};

#endif // GAME_H
