//
// Created by yonat on 06/06/2022.
//

#include "Fighter.h"
#include "../utilities.h"


Fighter::Fighter(std::string name) : Player(name) {}

int Fighter::getAttackStrength() const 
{
    return (2 * m_force) + m_level;
}

void Fighter::printInfo() const 
{
    printPlayerDetails(std::cout, m_name, "Fighter", m_level, m_force, m_HP, m_coins);
}

std::unique_ptr<Player> Fighter::clone() const 
{
    return std::unique_ptr<Fighter>(new Fighter(*this));
}
