#ifndef GAME_H
#define GAME_H

#include "PlayerBase.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Deck.h"

#include <memory>
#include <vector>

namespace ChinesePoepen {

class Game {
public:
    Game();

    void addHumanPlayer(const std::string& name);
    void addAIPlayer(const std::string& name);
    void setLives(int lives);
    void run();

private:
    std::vector<std::unique_ptr<PlayerBase>> m_players;
    int m_startLives;

    void playRound();
    void dealHands(Deck& deck);
    void showHands(bool revealAll = false) const;
    void eliminatePlayers();
};

} // namespace ChinesePoepen

#endif // GAME_H
