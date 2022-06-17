//
// Created by yonat on 06/06/2022.
//

#include "Rouge.h"

Rouge::Rouge(std::string name): Player(name){}

void Rouge::addCoins(int coinsToAdd)
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

void Rouge::printInfo() const
{
    printPlayerDetails(os, m_name, "Rouge", m_level, m_force, m_HP, m_coins);
}

std::unique_ptr<Rouge> Rouge::clone() const
{
    return std::unique_ptr<Rouge>(new Rouge(m_name));
}
