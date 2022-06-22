//
// Created by yonat on 06/06/2022.
//

#include "Rogue.h"
#include "../utilities.h"


Rogue::Rogue(std::string name): Player(name){}

void Rogue::addCoins(int coinsToAdd)
{
    if (coinsToAdd > 0) 
    {
        m_coins += 2*coinsToAdd;
    }
    else
    {
        //throw?
    }
}

void Rogue::printInfo() const
{
    printPlayerDetails(std::cout, m_name, "Rogue", m_level, m_force, m_HP, m_coins);
}

std::unique_ptr<Player> Rogue::clone() const
{
    return std::unique_ptr<Rogue>(new Rogue(*this));
}
