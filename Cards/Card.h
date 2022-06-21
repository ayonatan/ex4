#ifndef MTM_HW2_CARD_H
#define MTM_HW2_CARD_H

#include <string>
#include <ostream>
#include <memory>
#include "../Players/Player.h"

class Card {
public:
    Card(std::string name) : m_cardName(name) {}

    Card(const Card &) = default;

    Card &operator=(const Card &other) = default;

    virtual void applyEncounter(Player &player) const = 0;

    virtual void printInfo() const = 0;

    virtual ~Card() = default;

    virtual std::unique_ptr<Card> clone() const = 0;

protected:
    std::string m_cardName;
};

#endif //MTM_HW2_CARD_H
