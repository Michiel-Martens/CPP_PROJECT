#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "PlayerBase.h"
#include <limits>

namespace ChinesePoepen {

class HumanPlayer : public PlayerBase {
public:
    HumanPlayer();
    HumanPlayer(const std::string& name, int lives);

    // copy ctor
    HumanPlayer(const HumanPlayer& other);

    // destructor
    ~HumanPlayer() override;

    // override van virtuele functie
    void takeTurn(Deck& deck) override;
};

} // namespace ChinesePoepen

#endif // HUMANPLAYER_H
