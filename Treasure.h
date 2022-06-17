#ifndef MTM_HW4_TREASURE_H
#define MTM_HW4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    Treasure();

    ~Treasure() = default override;

    Treasure(const Treasure& treasure) = default;

    Treasure& operator=(const Treasure& treasure) = default;

    void applyEncounter(Player &player) const override;

    void printInfo() const override;
    
    std::unique_ptr<Treasure> clone() const override;

};


#endif //MTM_HW4_TREASURE_H
