#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "PlayerBase.h"

namespace ChinesePoepen {

class AIPlayer : public PlayerBase {
public:
    AIPlayer();
    AIPlayer(const std::string& name, int lives);

    // copy ctor
    AIPlayer(const AIPlayer& other);

    // destructor
    ~AIPlayer() override;

    void takeTurn(Deck& deck) override;
};

} // namespace ChinesePoepen

#endif // AIPLAYER_H
