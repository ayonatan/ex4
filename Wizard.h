//
// Created by yonat on 06/06/2022.
//

#ifndef MTM_HW4_WIZARD_H
#define MTM_HW4_WIZARD_H
#include "Player.h"

class Wizard : public Player
{
public:
    Wizard(std::string name);

    ~Wizard() = default override;

    Wizard(const Wizard &wizard) = default;

    Wizard &operator=(const Wizard &wizard) = default;

    void heal(int pointsToHeal) override;

    void printInfo() const override;
    
    std::unique_ptr<Wizard> clone() const override;
};
#endif //MTM_HW4_WIZARD_H
