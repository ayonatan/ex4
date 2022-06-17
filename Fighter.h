#ifndef MTM_HW4_FIGHTER_H
#define MTM_HW4_FIGHTER_H

#include "Player.h"

class Fighter : public Player {
public:
    Fighter(std::string name);

    ~Fighter() = default override;

    Fighter(const Fighter &fighter) = default;

    Fighter &operator=(const Fighter &fighter) = default; 

    int getAttackStrength() const override;

    void printInfo() const override;

    virtual std::unique_ptr<Fighter> clone() const override;
};

#endif //MTM_HW4_FIGHTER_H
