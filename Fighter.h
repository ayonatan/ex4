//
// Created by yonat on 06/06/2022.
//

#ifndef MTM_HW4_FIGHTER_H
#define MTM_HW4_FIGHTER_H
#include "Player.h"

class Fighter : public Fighter
{
public:
    Fighter(std::string name) = default;
    ~Fighter() = default;
    int getAttackStrength() const override;
    void printInfo() const override;
    Fighter* clone() const override;
};
#endif //MTM_HW4_FIGHTER_H
