#ifndef MTM_HW4_BARFIGHT_H
#define MTM_HW4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    explicit Barfight(const char *name) = default;

    ~Barfight() override = default; ///override?

    void printInfo() const override;

    void applyEncounter(Player &player) const override;
};

#endif //MTM_HW4_BARFIGHT_H
