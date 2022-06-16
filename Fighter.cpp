//
// Created by yonat on 06/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(std::string name) : Player(name) {}

int Fighter::getAttackStrength() const {
    return (2 * m_force) + m_level;
}

void Fighter::printInfo() const {
    printPlayerDetails(os, m_name, "Fighter", m_level, m_force, m_HP, m_coins);
}

Fighter *Fighter::clone() const {
    return new Fighter(m_name);
}
