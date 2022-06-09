#ifndef MTM_HW4_GOBLIN_H
#define MTM_HW4_GOBLIN_H

#include "Player.h"

class Goblin : public Player {
public:
    Goblin(const char* m_name);

    Goblin(const Goblin &goblin) = default;

    ~Goblin() =default override;

    operator=(const Goblin &goblin) = default;
    void applyEncounter(Player& player)const override;

///private: add?

};

#endif //MTM_HW4_GOBLIN_H