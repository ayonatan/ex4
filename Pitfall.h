#ifndef MTM_HW4_PITFALL_H
#define MTM_HW4_PITFALL_H
#include "Card.h"

class Pitfall : public Card{
public:
    Pitfall();

    ~Pitfall() = default override;

    Pitfall(const Pitfall& pitfall) = default;

    Pitfall& operator=(const Pitfall& pitfall) = default;

    void applyEncounter(Player& player)const override;

    void printInfo() const override;

    std::unique_ptr<Pitfall> clone() const override;
};
#endif //MTM_HW4_PITFALL_H
