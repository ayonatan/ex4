//
// Created by yonat on 06/06/2022.
//

#ifndef MTM_HW4_ROUGE_H
#define MTM_HW4_ROUGE_H

#include "Player.h"

class Rogue : public Player {
public:
    Rogue(std::string name);

    ~Rogue()override = default ;

    Rogue(const Rogue &rouge) = default;

    Rogue &operator=(const Rogue &rouge) = default; 

    void addCoins(int coinsToAdd) override;

    void printInfo() const override;

    std::unique_ptr<Player> clone() const override;
};

#endif //MTM_HW4_ROUGE_H
