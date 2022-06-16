//
// Created by yonat on 06/06/2022.
//

#ifndef MTM_HW4_ROUGE_H
#define MTM_HW4_ROUGE_H

#include "Player.h"

class Rouge : public Player {
public:
    Rouge(std::string name);

    ~Rouge() = default;

    Rouge(const Rouge &rouge) = delete;

    Rouge &operator=(const Rouge &rouge) = default; ////?

    void addCoins(int coinsToAdd) override;

    void printInfo() const override;

    Rouge *clone() const override;
};

#endif //MTM_HW4_ROUGE_H
